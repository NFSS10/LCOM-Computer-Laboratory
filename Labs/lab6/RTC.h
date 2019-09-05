#ifndef __RTC_H
#define __RTC_H

#include <minix/syslib.h>
#include <minix/drivers.h>
#include <minix/com.h>
#include <minix/sysutil.h>


#define RTC_IRQ 8

static int hook_id = RTC_IRQ;


int RTC_subscribe_int(void);


int RTC_unsubscribe_int();

#endif
