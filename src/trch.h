/* 
 * Definitions for TRCH Hardware
 *
 * (C) Copyright 2021
 *         Space Cubics, LLC
 *
 */

/*
 * Hardware Configuration
 */
#define _XTAL_FREQ 4000000

/*
 * PORTA Hardware
 *  bit 0: TRCH_CFG_MEM_SEL
 *  bit 1: FPGA_BOOT0
 *  bit 2: FPGA_BOO11
 *  bit 3: FPGA_PROGRAM_B
 *  bit 4: FPGA_INIT_B
 *  bit 5: FPGA_CDRST_B
 */
#define TRISA_INIT         0x3E
#define TRISA_FPGA_READY   0x00
#define TRCH_CFG_MEM_SEL   PORTAbits.RA0
#define FPGA_PROGRAM_B     PORTAbits.RA0
#define FPGA_PROGRAM_B_DIR TRISAbits.TRISA0
#define FPGA_INIT_B        PORTAbits.RA1
#define FPGA_INIT_B_DIR    TRISAbits.TRISA1

/*
 * PORTB Hardware
 *  bit 0: SPICAN_INT_B
 *  bit 1: CFG_DONE (Reserved)
 *  bit 2: TRCJ_CFG_MEM_MONI
 *  bit 3: No Function (High Level)
 *  bit 4: FPGA_WATCHDOG
 *  bit 5: FPGA_CFG_MEM_SEL
 *  bit 6: No Function (for Debug: ICSP_PGC)
 *  bit 7: No Function (for Debug: ICSP_PGD)
 */
#define TRISB_INIT 0xFF
#define FPGA_CFG_MEM_SEL   PORTBbits.RB5

/*
 * PORTC Hardware
 *  bit 0: TRCH_CAN_SLEEP_N
 *  bit 1: SPICAN_CS_B
 *  bit 2: TRCH_UART_EN
 *  bit 3: SPICAN_SCK
 *  bit 4: SPICAN_MISO
 *  bit 5: SPICAN_MOSI
 *  bit 6: TRCH_UART_TX
 *  bit 7: TRCH_UART_RX
 */
#define TRISC_INIT         0xFF
#define SPICAN_CS_B_DIR    TRISCbits.TRISC1
#define SPICAN_CS_B        PORTCbits.RC1
#define SPICAN_SCK_DIR     TRISCbits.TRISC3
#define SPICAN_MOSI_DIR    TRISCbits.TRISC5

/*
 * PORTD Hardware
 *  bit 0: I2C_INT_SCL
 *  bit 1: I2C_INT_SDA
 *  bit 2: I2C_EXT_SCL
 *  bit 3: I2C_EXT_SDA
 *  bit 4: UIO3_00
 *  bit 5: UIO3_01
 *  bit 6: UIO3_02
 *  bit 7: FPGA_RESERVE
 */
#define TRISD_INIT         0xFF
#define INT_SCL_DIR        TRISDbits.TRISD0
#define INT_SCL_DAT        PORTDbits.RD0
#define INT_SDA_DIR        TRISDbits.TRISD1
#define INT_SDA_DAT        PORTDbits.RD1
#define EXT_SCL_DIR        TRISDbits.TRISD2
#define EXT_SCL_DAT        PORTDbits.RD2
#define EXT_SDA_DIR        TRISDbits.TRISD3
#define EXT_SDA_DAT        PORTDbits.RD3

/*
 * PORTE Hardware
 *  bit 0: WDOG_OUT
 *  bit 1: FPGA_PROGRAM_B_IN
 *  bit 2: FPGA_INIT_B_IN
 */
#define TRISE_INIT 0x06
#define VDD_3V3 PORTBbits.RB3
