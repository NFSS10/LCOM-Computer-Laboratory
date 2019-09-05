#ifndef KBD_H
#define KBD_H

#include <minix/syslib.h>
#include <minix/drivers.h>
#include <minix/com.h>
#include <minix/sysutil.h>
#include "i8042.h"


int kbd_read();
int kbd_subscribe_int(void );
int kdb_unsubscribe_int();



#endif
