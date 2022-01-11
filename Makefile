
# Design Parameter
MODULE := trch-firmware
DEVICE := 16LF877
TARGET := PPK4

# Command variables
CC     := xc8-cc -mc90lib
IPECMD := ipecmd.sh
RM     := rm -rf

# File Path variables
INCDIR := src
HEXDIR := hex
PRGDAT := $(HEXDIR)/$(MODULE)

# Source and object files
SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:.c=.p1)

# Clean File
CF      = $(HEXDIR) src/*.p1 src/*.d MPLABXLog.* log.*

vpath %.c   $(src)

.PHONY: all
all: build

.PHONY: build
build: $(PRGDAT).hex

$(PRGDAT).hex: $(OBJS)
	mkdir -p $(HEXDIR)
	$(CC) -mcpu=$(DEVICE) -I $(INCDIR) -o $(HEXDIR)/$(MODULE) $^

%.p1: %.c
	$(CC) -mcpu=$(DEVICE) -I $(INCDIR) -c -o $@ $<

.PHONY: program
program: $(PRGDAT).hex
	$(IPECMD) -P$(DEVICE) -T$(TARGET) -F$< -M

.PHONY: erase
erase:
	$(IPECMD) -P$(DEVICE) -T$(TARGET) -E

.PHONY: clean
clean:
	$(RM) $(CF)
