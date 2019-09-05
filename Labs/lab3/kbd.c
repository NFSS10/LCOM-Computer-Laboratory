#include "kbd.h"

static int hook_id = KBD_IRQ;

int kbd_read()
{
	// A variavel data ira servir para armazenar a informacao sobre o keyboard
	unsigned long stat, cmd;

	while( 1 ) {
		sys_inb(STAT_REG, &stat); /*assuming it returns OK*/
		/*loop while 8042 input buffer is not empty*/
		if((stat & OBF) == OBF){
			sys_inb(OUT_BUF, &cmd);
			if( (stat & (PARITY|TIMEOUT)) == 0 ){
				return cmd;
			}
		}
		tickdelay(micros_to_ticks(DELAY_US));
	}
	return 1;
}

int kbd_subscribe_int(void ) {

	// Ordem interessa na chamada das funcoes
	if (sys_irqsetpolicy(KBD_IRQ, IRQ_REENABLE|IRQ_EXCLUSIVE, &hook_id) != OK)
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

int kdb_unsubscribe_int() {

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

