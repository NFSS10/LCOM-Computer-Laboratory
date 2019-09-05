#include "test3.h"
#include "timer.h"

static int contador;

int kbd_test_scan(unsigned short ass) {

	int irq_set = BIT(KBD_IRQ);
	int ipc_status;
	unsigned long state;
	message msg;

	if (ass != 0 && ass != 1)
	{
		printf ("Argumento Invalido!!!\n");
		return 1;
	}

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

					switch (ass){
					case 0:
						state = kbd_read();
						break;
					case 1:
						sys_enable_iop(SELF);
						state = kbd_scan_asm();
						break;
					default:
						break;
					}

					if(state>>7==1)
						printf("BreakCode: 0x%02x", state);
					else
						printf("MakeCode: 0x%02x", state);
					printf ("\n");

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

int kbd_test_leds(unsigned short n, unsigned short *leds) {

	int scroll = 0, num = 0, caps = 0;
	unsigned long state;
	unsigned int i;
	for (i=0;i<n;i++)
	{

		sys_outb(OUT_BUF, SET_LEDS);
		sys_inb(OUT_BUF, &state);
		if (state == RESEND)
			i--;
		else if (state == ERROR)
			i =0;
		else{
		switch(leds[i]){
		case 0:
			if (!scroll){
				scroll = BIT(0);
				printf ("ScrollLock Ligado. \n");}
			else{
				scroll = 0;
				printf ("ScrollLock Desligado. \n");}
			break;
		case 1:
			if (!num){
				num = BIT(1);
				printf ("NumLock Ligado.\n");}
			else{
				num=0;
				printf ("NumLock Desligado.\n");}
			break;
		case 2:
			if (!caps){
				caps = BIT(2);
				printf ("CapsLock Ligado.\n");}
			else{
				caps = 0;
				printf("CapsLock Desligado.\n");}
			break;
		default:
			printf ("O valor introduzido no array e invalido.\n");
			break;}

		sys_outb(OUT_BUF, scroll | num | caps);
		sys_inb(OUT_BUF, &state);

		}
	tickdelay(micros_to_ticks(1000000));	//1000000 microsegundos = 1 segundo
	}
	return 0;
}

int kbd_test_timed_scan(unsigned short n) {

	int irq_set_kbd = BIT(KBD_IRQ);
	int irq_set_timer0 = BIT(TIMER0_IRQ);
	unsigned short segundos=0;
	int ipc_status;
	unsigned long state;
	message msg;
	contador=0;

	if(kbd_subscribe_int()){//Subescreve
		printf("kdb_subscribe_int falhou");
		return 1;}

	if(timer_subscribe_int()) // Subscreve
	{
	  printf("timer_subscribe_int falhou");
	 return 1;
	}

	timer_test_square(60);

	while( (state != BREAKCODE_I) && (segundos <n*60)) { /* You may want to use a different condition*/
		/* Get a request message.*/
		int d = driver_receive(ANY, &msg, &ipc_status);
		if ( d != 0 ) {
			printf("driver_receive failed with: %d", d);
			continue;
		}
		if (is_ipc_notify(ipc_status)) { /* received notification*/
			switch (_ENDPOINT_P(msg.m_source)) {
			case HARDWARE: /*hardware interrupt notification*/
				{
					if (msg.NOTIFY_ARG & irq_set_kbd)
					{ /*subscribed interrupt*/
						segundos=0;
						state = kbd_read();

						if(state>>7==1)
						printf("BreakCode: 0x%02x", state);

						else
						printf("MakeCode: 0x%02x", state);
						printf ("\n");
					}
				if(msg.NOTIFY_ARG & irq_set_timer0)
				{
					timer_int_handler(); // chama o interrupt handler
					if( (contador%60)==0){	//Porque frequencia e 60hz
						segundos++;}
				}

			}
				break;
			default:
				break; /*no other notifications expected: do nothing*/
			}
		}
	}
	if (BREAKCODE_I == state)
		printf("O botao ESC foi premido.");
	else
		printf ("O tempo terminou!");

	if(kdb_unsubscribe_int()) // Unsubscribe
	{
		printf("kbd_unsubscribe_int falhou");
		return 1;
	}
	if(timer_unsubscribe_int()) //Retira a subscricao
	   {
		   printf("timer_unsubscribe_int falhou");
		   return 1;
	   }


return 0;
}

