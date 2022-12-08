/*
 * Space Cubics OBC TRCH Software
 *  Definitions for USART
 *
 * (C) Copyright 2021-2022
 *         Space Cubics, LLC
 *
 */

#pragma once

#include <stdbool.h>

#define MSG_LEN 20

struct usart_rx_msg {
        char msg[MSG_LEN];
        int addr;
        unsigned active :1;
        unsigned err :1;
};

extern void usart_init (void);
extern void usart_send_msg (char *msg);
extern void usart_start_receive (void);
extern void usart_receive_msg_isr (void);
extern void usart_receive_msg_clear (void);
extern void usart_copy_received_msg (char *msg);
extern bool usart_is_received_msg_active (void);
