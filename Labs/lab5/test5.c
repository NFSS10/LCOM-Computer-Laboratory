#include "test5.h"
#include "kbd.h"
#include "read_xpm.h"
#include "pixmap.h"
#include "timer.h"
#include "video_gr.h"
#include "i8254.h"

static int contador;


void *test_init(unsigned short mode, unsigned short delay) {
	
	char *toPrint = (char*)video_init(mode);
	//printf("Aqui1\n");
	int i = 0;
	//for(; i < 340; ++i) {
	//	*((toPrint + i + 4)) = 2;
	//}
	sleep(delay);
	video_exit();
	//printf("Aqui2\n");
	printf("Memoria mapeada em 0x%x.\n", toPrint);
	
}

int test_square(unsigned short x, unsigned short y, unsigned short size, unsigned long color) {

	video_init(0x105);

	unsigned int i = x;
	unsigned int k = y;

		while (i < x+size)
		{
			k=y;
			while (k < y+size)
			{
				 //printf("1 Print");
				 drawPixel(i,k,color);
				 k++;
			}
		 i++;
		}
	
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
					}
					break;
				default:
					break; /*no other notifications expected: do nothing*/
				}
			}
		}

		if(kdb_unsubscribe_int()) // Unsubscribe
		{
			printf("kbd_unsubscribe_int falhou");
			return 1;
		}
	video_exit();
	printf("O botao ESC foi pressionado!\n");

return 0;
}

int test_line(unsigned short xi, unsigned short yi, 
		           unsigned short xf, unsigned short yf, unsigned long color) {
	

	video_init(0x105);

	drawLine(xi, yi, xf, yf, color);



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
					}
					break;
				default:
					break; /*no other notifications expected: do nothing*/
				}
			}
		}

		if(kdb_unsubscribe_int()) // Unsubscribe
		{
			printf("kbd_unsubscribe_int falhou");
			return 1;
		}
	video_exit();
	printf("O botao ESC foi pressionado!\n");

return 0;
}


int test_xpm(unsigned short xi, unsigned short yi, char *xpm[])
{
	video_init(0x105);

	drawXPM(xi, yi, xpm);
	
	
	//Tratamento do teclado
	int irq_set = BIT(KBD_IRQ);
	int ipc_status;
	unsigned long state;
	message msg;

	if(kbd_subscribe_int())
	{//Subescreve
		printf("kdb_subscribe_int falhou");
		return 1;
	}
	while( state != BREAKCODE_I )
	{
		/* Get a request message.*/
		int d = driver_receive(ANY, &msg, &ipc_status);
		if ( d != 0 )
		{
			printf("driver_receive failed with: %d", d);
			continue;
		}
		if (is_ipc_notify(ipc_status)) /* received notification*/
		{
			switch (_ENDPOINT_P(msg.m_source))
			{
			case HARDWARE: /*hardware interrupt notification*/
				if (msg.NOTIFY_ARG & irq_set) /*subscribed interrupt*/
				{
					state = kbd_read();
				}
				break;
				default:
					break; /*no other notifications expected: do nothing*/
			}
		}
	}
	if(kdb_unsubscribe_int()) // Unsubscribe
		{
		printf("kbd_unsubscribe_int falhou");
		return 1;
		}
	video_exit();
	printf("O botao ESC foi pressionado!\n");

	return 0;
}	

int test_move(unsigned short xi, unsigned short yi, char *xpm[], 
				unsigned short hor, short delta, unsigned short time) {

	video_init(0x105);

	//Timer
	int irq_set_timer = BIT(TIMER0_IRQ);
	unsigned short segundos=0;
	contador=0;
	timer_test_square(60);

	//Tratamento do teclado
	int irq_set = BIT(KBD_IRQ);
	int ipc_status;
	unsigned long state;
	message msg;

	double pxPrInt = (double) ((double)delta/((double)time*60.0));
	//printf ("speed %d\n" , speed);
	Sprite sp;
	getSprite(&sp, xi, yi, xpm, hor, pxPrInt);


	if(kbd_subscribe_int())
	{//Subescreve
		printf("kdb_subscribe_int falhou");
		return 1;
	}
	if(timer_subscribe_int())
	{//Subescreve
		printf("timer_subscribe_int falhou");
		return 1;
	}
	drawSp(&sp);
/*
	//printf("teste x %d \n", sp.x);
	//printf("teste y %d \n", sp.y);
	deleteSp(&sp);
	//printf("teste x %d \n", sp.x);
	//printf("teste y %d \n", sp.y);
	moveSp(&sp);
	drawSp(&sp);
	deleteSp(&sp);
	moveSp(&sp);
	drawSp(&sp);
	deleteSp(&sp);
	moveSp(&sp);
	drawSp(&sp);
	deleteSp(&sp);
	moveSp(&sp);
	drawSp(&sp);
return 0;*/
	while( (contador < (time*60)) && state != BREAKCODE_I )
	{
		/* Get a request message.*/
		int d = driver_receive(ANY, &msg, &ipc_status);
		if ( d != 0 )
		{
			printf("driver_receive failed with: %d", d);
			continue;
		}
		if (is_ipc_notify(ipc_status)) /* received notification*/
		{
			switch (_ENDPOINT_P(msg.m_source))
			{
			case HARDWARE: /*hardware interrupt notification*/
				if (msg.NOTIFY_ARG & irq_set) /*subscribed interrupt*/
					state = kbd_read();

				if (msg.NOTIFY_ARG & irq_set_timer) /*subscribed interrupt*/
				{
					//Apaga
					deleteSp(&sp);

					//Move a posicao
					sp.x = sp.x + sp.xspeed;
					sp.y = sp.y + sp.yspeed;

					// Desenha
					drawSp(&sp);

					//printf ("teste\n");
					contador++;
				}
				break;
				default:
					break; /*no other notifications expected: do nothing*/
			}
		}
	}
	if(timer_unsubscribe_int()) // Unsubscribe
	{
		printf("timer_unsubscribe_int falhou");
		return 1;
	}
	if(kdb_unsubscribe_int()) // Unsubscribe
	{
		printf("kbd_unsubscribe_int falhou");
		return 1;
	}
	video_exit();
	if(state==BREAKCODE_I)
	printf("O botao ESC foi pressionado!\n");
	else
	printf("O tempo chegou ao fim!\n");

	return 0;
}


int test_controller() {
	
	/* To be completed */
	
}					
	
