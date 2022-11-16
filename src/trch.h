/*
 * Definitions for TRCH Hardware
 *
 * (C) Copyright 2021-2022
 *         Space Cubics, LLC
 *
 */

#pragma once

#include <pic.h>

/*
 * Hardware Configuration
 */
#define _XTAL_FREQ 4000000

#define PORT_DIR_OUT (0)
#define PORT_DIR_IN (1)
#define PORT_DATA_LOW (0)
#define PORT_DATA_HIGH (1)

/*
 * PORTA Hardware
 *  Bit    Name                               Initial Dir  Initial Level
 *  bit 0: TRCH_CFG_MEM_SEL                   Out          0
 *  bit 1: FPGA_BOOT0                         Out          0
 *  bit 2: FPGA_BOO11                         Out          0
 *  bit 3: FPGA_PROGRAM_B                     In           0
 *  bit 4: FPGA_INIT_B                        In           0
 *  bit 5: FPGAPWR_EN                         Out          0
 */
#define TRISA_INIT         0x18
#define PORTA_INIT         0x00

#define TRISA_FPGA_READY   0x00
#define TRCH_CFG_MEM_SEL   PORTAbits.RA0
#define FPGA_BOOT0         PORTAbits.RA1
#define FPGA_BOOT1         PORTAbits.RA2
#define FPGA_PROGRAM_B     PORTAbits.RA3
#define FPGA_PROGRAM_B_DIR TRISAbits.TRISA3
#define FPGA_INIT_B        PORTAbits.RA4
#define FPGA_INIT_B_DIR    TRISAbits.TRISA4
#define FPGAPWR_EN         PORTAbits.RA5
#define FPGAPWR_EN_DIR     TRISAbits.TRISA5

/*
 * PORTB Hardware
 *  Bit    Name                               Initial Dir  Initial Level
 *  bit 0: SPICAN_INT_B                       In           -
 *  bit 1: FPGA_PWR_CYCLE_REQ                 In           -
 *  bit 2: TRCH_CFG_MEM_MONI                  In           -
 *  bit 3: No Function (High Level)           In           -
 *  bit 4: FPGA_WATCHDOG                      In           0
 *  bit 5: FPGA_CFG_MEM_SEL                   In           0
 *  bit 6: No Function (for Debug: ICSP_PGC)  Out          0
 *  bit 7: No Function (for Debug: ICSP_PGD)  Out          0
 */
#define TRISB_INIT         0x3F
#define PORTB_INIT         0x00

#define FPGA_PWR_CYCLE_REQ PORTBbits.RB1
#define FPGA_WATCHDOG      PORTBbits.RB4
#define FPGA_CFG_MEM_SEL   PORTBbits.RB5

/*
 * PORTC Hardware
 *  Bit    Name                               Initial Dir  Initial Level
 *  bit 0: TRCH_CAN_SLEEP_EN                  Out          0
 *  bit 1: SPICAN_CS_B                        Out          1
 *  bit 2: FPGAPROG_MODE_B                    In           -
 *  bit 3: SPICAN_SCK                         Out          0
 *  bit 4: SPICAN_MISO                        In           -
 *  bit 5: SPICAN_MOSI                        Out          0
 *  bit 6: TRCH_UART_TX                       Out          0
 *  bit 7: TRCH_UART_RX                       In           -
 */
#define TRISC_INIT         0x94
#define PORTC_INIT         0x00

#define SPICAN_CS_B_DIR    TRISCbits.TRISC1
#define SPICAN_CS_B        PORTCbits.RC1
#define FPGAPROG_MODE_B    PORTCbits.RC2
#define SPICAN_SCK_DIR     TRISCbits.TRISC3
#define SPICAN_MOSI_DIR    TRISCbits.TRISC5

/*
 * PORTD Hardware
 *  Bit    Name                               Initial Dir  Initial Level
 *  bit 0: I2C_INT_SCL                        In           -
 *  bit 1: I2C_INT_SDA                        In           -
 *  bit 2: I2C_EXT_SCL                        In           -
 *  bit 3: I2C_EXT_SDA                        In           -
 *  bit 4: UIO3_00                            Out          0
 *  bit 5: UIO3_01                            Out          0
 *  bit 6: UIO3_02                            Out          0
 *  bit 7: FPGA_RESERVE                       Out          0
 */
#define TRISD_INIT         0x0F
#define PORTD_INIT         0x00

#define I2C_PORT           PORTD
#define I2C_INT_SCL_DIR    TRISDbits.TRISD0
#define I2C_INT_SCL        PORTDbits.RD0
#define I2C_INT_SDA_DIR    TRISDbits.TRISD1
#define I2C_INT_SDA        PORTDbits.RD1
#define I2C_INT_MASK       (0x03)
#define I2C_EXT_SCL_DIR    TRISDbits.TRISD2
#define I2C_EXT_SCL        PORTDbits.RD2
#define I2C_EXT_SDA_DIR    TRISDbits.TRISD3
#define I2C_EXT_SDA        PORTDbits.RD3
#define I2C_EXT_I2C_MASK   (0x0C)
#define UIO3_00            PORTDbits.RD4
#define UIO3_01            PORTDbits.RD5
#define UIO3_02            PORTDbits.RD6

/*
 * PORTE Hardware
 *  Bit    Name                               Initial Dir  Initial Level
 *  bit 0: WDOG_OUT                           In           -
 *  bit 1: FPGA_PROGRAM_B_IN                  In           -
 *  bit 2: FPGA_INIT_B_IN                     In           -
 */
#define TRISE_INIT         0x07
#define PORTE_INIT         0x00

#define VDD_3V3            PORTEbits.RE1
