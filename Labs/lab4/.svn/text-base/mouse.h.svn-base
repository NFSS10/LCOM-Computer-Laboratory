#ifndef _MOUSE_H_
#define _MOUSE_H_

#include <minix/sysutil.h>
#include <minix/syslib.h>
#include <minix/drivers.h>
#include <stdio.h>
#include "i8042.h"
#include "timer.h"

signed int x;
signed int y;

int mouse_read_data();

int mouse_send_cmd(unsigned char adress, unsigned char command);

int mouse_send_cmd_ack(unsigned char adress, unsigned char command);

int mouse_subscribe_int(void);

int mouse_unsubscribe_int();

void display(long int *packet_info);

int test_display(long int *packet_info, int *limite, int *index);

int mouse_handler(long int *packet_info, int *limite, int *index);

int aux_config(long int *packet_info, int *limite, int *index);

int test_aux_status(long int *packet_info, int *limite, int *index);

void show_status(long int *packet_info);

void test_moviment(long int *packet_info);

#endif 	
