/*
 * Space Cubics OBC TRCH Software
 *  FPGA Control Utility
 *
 * (C) Copyright 2021-2022
 *         Space Cubics, LLC
 *
 */

#include "fpga.h"

#include <pic.h>
#include <stdbool.h>
#include "trch.h"

void fpga_init (struct fpga_management_data *fmd) {
        fmd->state = FPGA_STATE_POWER_OFF;
        fmd->config_ok = 0;
        fmd->config_mem = 0;
        fmd->boot_mode = 1;
        fmd->count = 0;
        fmd->time = 0;
}

bool fpga_is_i2c_accessible (enum FpgaState state) {
        return state == FPGA_STATE_POWER_OFF || state == FPGA_STATE_READY;
}

static void f_power_off (struct fpga_management_data *fmd) {
        if (VDD_3V3) {
                fmd->state = FPGA_STATE_READY;
                FPGA_INIT_B_DIR = 0;
                FPGA_PROGRAM_B = 1;
                FPGA_PROGRAM_B_DIR = 0;
        }
}

static void f_fpga_ready (struct fpga_management_data *fmd) {
        if (fmd->config_ok) {
                TRCH_CFG_MEM_SEL = fmd->config_mem;
                FPGA_BOOT0 = (0b01 & fmd->boot_mode);
                FPGA_BOOT1 = (0b01 & fmd->boot_mode >> 1);
                if (fmd->count == 0)
                        FPGA_INIT_B_DIR = 1;
                else
                        FPGA_PROGRAM_B = 1;
                fmd->state = FPGA_STATE_CONFIG;
                fmd->count++;
        }
}

static void f_fpga_config (struct fpga_management_data *fmd) {
        if (!fmd->config_ok) {
                FPGA_PROGRAM_B = 0;
                fmd->state = FPGA_STATE_READY;
        } else if (CFG_DONE)
                fmd->state = FPGA_STATE_ACTIVE;
}

static void f_fpga_active (struct fpga_management_data *fmd) {
        if (!fmd->config_ok) {
                FPGA_PROGRAM_B = 0;
                fmd->state = FPGA_STATE_READY;
        } else if (CFG_DONE)
                TRCH_CFG_MEM_SEL = FPGA_CFG_MEM_SEL;
        else
                fmd->state = FPGA_STATE_CONFIG;
}

STATEFUNC fpgafunc[] = {
        f_power_off,
        f_fpga_ready,
        f_fpga_config,
        f_fpga_active };
