#include "RTC.h"

int RTC_subscribe_int(void) {

	// Ordem interessa na chamada das funcoes
	if (sys_irqsetpolicy(RTC_IRQ, IRQ_REENABLE|IRQ_EXCLUSIVE, &hook_id) != OK)
	{
		printf ("A funcao irqsetpolicy falhou.");
		return -1;
	}

	if (sys_irqenable(&hook_id) != OK)
	{
		printf ("A funcao irqenable falhou.");
		return -1;
	}

	return 0;
}

int RTC_unsubscribe_int() {

	if(sys_irqdisable(&hook_id) != OK)
	{
		printf("A funcao irqdisable falhou.");
		return 1;
	}

	if(sys_irqrmpolicy(&hook_id)!=OK)
	{
		printf("A funcao irqrmpolicy falhou.");
		return 1;
	}
	return 0;
}
