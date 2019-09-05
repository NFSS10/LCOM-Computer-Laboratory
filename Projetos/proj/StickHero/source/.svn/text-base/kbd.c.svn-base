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

	hook_id = KBD_IRQ;
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




/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

int kbd_test_scan()
{

	int irq_set = BIT(KBD_IRQ);
	int ipc_status;
	unsigned long state;
	message msg;

	if(kbd_subscribe_int()){//Subescreve
		printf("kdb_subscribe_int falhou");
		return 1;}


	while( state != BREAKCODE_I ) { /* You may want to use a different condition*/
		/* Get a request message.*/
		int d = driver_receive(ANY, &msg, &ipc_status);
		if ( d != 0 ) {
			printf("driver_receive failed with: %d", d);
			continue;
		}
		if (is_ipc_notify(ipc_status)) { /* received notification*/
			switch (_ENDPOINT_P(msg.m_source)) {
			case HARDWARE: /*hardware interrupt notification*/
				if (msg.NOTIFY_ARG & irq_set) { /*subscribed interrupt*/


						state = kbd_read();
					if(state>>7==1)
						printf("BreakCode: 0x%02x", state);
					else
						printf("MakeCode: 0x%02x", state);
					printf ("\n\n");

				}
				break;
			default:
				break; /*no other notifications expected: do nothing*/
			}
		}
	}
	printf("O botao ESC foi primido.");

	if(kdb_unsubscribe_int()) // Unsubscribe
	{
		printf("kbd_unsubscribe_int falhou");
		return 1;
	}

return 0;
}
