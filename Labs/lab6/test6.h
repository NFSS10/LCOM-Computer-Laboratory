#ifndef __TEST6_H
#define __TEST6_H


#define RTC_ADDR_REG	0x70
#define RTC_DATA_REG	0x71


int rtc_test_conf(void);
int rtc_test_date(void);
int rtc_test_int(/* to be defined in class */);


#endif
