/*
 * Copyright (c) 2023 Space Cubics, LLC.
 */

#pragma once

#include <stddef.h>
#include <stdint.h>

#define CAN_MAX_DLC 8U

typedef union canbuf {
        uint32_t val[2];
        uint8_t data[CAN_MAX_DLC];
} canbuf_t;

void can_init(void);
void can_set_filter(uint8_t id, uint8_t mask);
void can_send(uint32_t id, canbuf_t *buf, uint8_t len);
int can_recv(canbuf_t *buf);
