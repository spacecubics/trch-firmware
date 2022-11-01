# Conditional Compilation for features
CONFIGS := -DCONFIG_ENABLE_WDT_RESET
#CONFIGS += -DCONFIG_FPGA_PROGRAM_MODE
CONFIGS += -DCONFIG_FPGA_WATCHDOG_TIMEOUT=3

# Design Parameter
MODULE := trch-firmware
DEVICE := 16LF877
TARGET := PPK4

# Command variables
CC     := xc8-cc -mc90lib -mcpu=$(DEVICE)
IPECMD := ipecmd.sh
RM     := rm -rf

# File Path variables
HEXDIR := hex
PRGDAT := $(HEXDIR)/$(MODULE)

# Source and object files
SRCS := src/main.c src/fpga.c src/interrupt.c src/timer.c \
        src/i2c-gpio.c \
        src/ina3221.c \
        src/spi.c \
	src/tmp175.c \
	src/usart.c

OBJS := $(SRCS:.c=.p1)
ASMS := $(SRCS:.c=.s)

# Clean File
CF      = $(HEXDIR) src/*.p1 src/*.d MPLABXLog.* log.* src/*.i src/*.sdb

.PHONY: all
all: build

.PHONY: build
build: $(PRGDAT).hex

FORCE:
src/version.h: FORCE
	git describe --dirty | sed 's/release-\(.\+\)/#define VERSION "\1"/' > src/version.h

$(PRGDAT).hex: $(OBJS)
	mkdir -p $(HEXDIR)
	echo '*' > $(HEXDIR)/.gitignore
	#$(CC) -S -o $(PRGDAT).s $^
	$(CC) -o $@ $^

include $(wildcard src/*.d)

%.p1: %.c Makefile
	$(CC) $(CONFIGS) -c -o $@ $<

src/main.p1: src/main.c Makefile src/version.h
	$(CC) $(CONFIGS) -c -o $@ $<

flash: program
.PHONY: program
program: $(PRGDAT).hex
	$(IPECMD) -P$(DEVICE) -T$(TARGET) -F$< -M -OL

.PHONY: erase
erase:
	$(IPECMD) -P$(DEVICE) -T$(TARGET) -E

.PHONY: reset
reset:
	$(IPECMD) -P$(DEVICE) -T$(TARGET) -OK -OL

.PHONY: halt
halt:
	$(IPECMD) -P$(DEVICE) -T$(TARGET) -OK

.PHONY: clean
clean:
	$(RM) $(CF)
