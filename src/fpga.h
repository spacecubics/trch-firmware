/*
 * Space Cubics OBC TRCH Software
 *  Definitions for FPGA Control Utility
 *
 * (C) Copyright 2021-2022
 *         Space Cubics, LLC
 *
 */

#pragma once

#include <stdbool.h>

#define FPGA_BOOT_24MHZ 0
#define FPGA_BOOT_48MHZ 1
#define FPGA_BOOT_96MHZ 2

enum FpgaState{
        FPGA_STATE_POWER_OFF,
        FPGA_STATE_READY,
        FPGA_STATE_CONFIG,
        FPGA_STATE_ACTIVE,
        FPGA_STATE_LAST,
};

struct fpga_management_data {
        enum FpgaState state;
        unsigned config_ok: 1;
        int mem_select;
        unsigned boot_mode: 2;
        int count;
        int time;
};

typedef void (*STATEFUNC)(struct fpga_management_data *fmd);
extern STATEFUNC fpgafunc[FPGA_STATE_LAST];

extern void fpga_init (struct fpga_management_data *fmd);
extern bool fpga_is_i2c_accessible (enum FpgaState state);
