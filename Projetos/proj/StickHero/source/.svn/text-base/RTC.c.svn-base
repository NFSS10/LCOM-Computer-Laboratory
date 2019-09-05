#include "RTC.h"

int rtc_subscribe_int(void){
	hook_id=IRQ_RTC;

	if( sys_irqsetpolicy(IRQ_RTC, IRQ_REENABLE|IRQ_EXCLUSIVE, &hook_id) != OK)
		return -1;
	if (sys_irqenable(&hook_id) != OK)
		return -1;

	return 0;
}

int rtc_unsubscribe_int(){
	if (sys_irqdisable(&hook_id) != OK)
		return -1;
	if (sys_irqrmpolicy(&hook_id) != OK)
		return -1;
	return 0;
}

int rtc_write_bcd_to_binary(void){
	unsigned long regB;
	sys_outb(RTC_ADDR_REG, 11);
	sys_inb(RTC_DATA_REG, &regB);
	regB |= RTC_BCD_TO_BINARY;
	sys_outb(RTC_ADDR_REG, 11);
	sys_outb(RTC_DATA_REG, regB);
	return 0;
}
