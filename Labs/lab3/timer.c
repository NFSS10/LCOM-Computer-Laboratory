#include <minix/syslib.h>
#include <minix/drivers.h>

#include <minix/com.h>

#include "i8254.h"
#include "timer.h"


static int contador;
static int hook_id;

int timer_set_square(unsigned long timer, unsigned long freq) {

	unsigned long frequencia;
	unsigned char msb, lsb = 0x00, timerR = TIMER_0, comando = TIMER_SEL0;

	// Calculo da frequencia e passagem para o msb e lsb
	frequencia = TIMER_FREQ / freq;
	lsb = frequencia;
	// Deslocamento de 8 bits para a direita para passar os 8 bits mais significativos da frequencia.
	msb = frequencia >> 8;

	switch(timer) {  // De acordo com o timer recebido iremos adicionar esse bit ao comando
	case 0:
		comando= comando | TIMER_SEL0;
		timerR = TIMER_0;
		break;
	case 1:
		comando= comando | TIMER_SEL1;
		timerR = TIMER_1;
		break;
	case 2:
		comando= comando | TIMER_SEL2;
		timerR = TIMER_2;
		break; }

	// Seleccao do timer e passagem da frequencia.
	// Inicializar LSB primeiro, e depois MSB, Modo 3 "square wave generator", Contador em Binario
	if (sys_outb(TIMER_CTRL, comando | TIMER_LSB_MSB | TIMER_SQR_WAVE) != OK)
	{
		printf("sys_outb (TIMER_CTRL, comando) falhou\n");
		return 1;
	}
	if (sys_outb(timerR, lsb) != OK)
	{
		printf("sys_outb (timerR, lsb) falhou\n");
		return 1;
	}
	if (sys_outb (timerR, msb) != OK)
	{
		printf("sys_outb (timerR, msb) falhou\n");
		return 1;
	}

	return 0;
}

int timer_subscribe_int(void ) {

	// Ordem interessa na chamada das funcoes
	if (sys_irqsetpolicy(TIMER0_IRQ, IRQ_REENABLE, &hook_id) != OK)
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

int timer_unsubscribe_int() {

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

void timer_int_handler()
{
	contador++; // incrementa o contador
}

int timer_get_conf(unsigned long timer, unsigned char *st) {
	
	unsigned long cntrl;

	//////////////////////////////////////////////////////
	// TIMER_CTRL e o endereco do controlo do timer
	// TIMER_RB_CMD informam acerca do comando do Read Back.
	if (sys_outb(TIMER_CTRL, TIMER_RB_CMD | TIMER_RB_SEL(timer)) != OK)
		return 1;

	// A variavel data ira servir para armazenar a informacao sobre o timer
	unsigned long data;

	// Dependentemente do timer iremos chamar a funcao com o endereco respetivo.
	switch (timer) {
		case 0:
	sys_inb(TIMER_0, &data);
	break;
		case 1:
	sys_inb(TIMER_1, &data);
	break;
		case 2:
	sys_inb(TIMER_2, &data);
	break;
	default:
		return 1; }

	*st = data;
	return 0;
}

int timer_display_conf(unsigned char conf) {

	/////////////////////////////////////
	// Timer Usado - Os bits y em yyxxxxxx dao informacao sobre o
	// tipo de acesso, logo temos que fazer 6 deslocamentos para a
	// direita e fazer "and" com 3 (11 em binario) para isolarmos os
	// os 2 bits.
	printf("Timer: %d \n", conf >> 6 & 3); // 11111xx -> 00000xx

	///////////////////////////////////////////////////////////////////
	// Tipo de acesso - Os bits y em xxyyxxxx dao informacao sobre
	// o tipo de acesso, logo temos que fazer 4 deslocamentos para a
	// direita e fazer "and" com 3 (11 em binario) para isolarmos os 2 bits.
	if ((conf >> 4 & 3) == 3)
		printf("Access Type = LSB followed by MSB \n");
	else if((conf >> 4 & 3)==2)
		printf("Access Type = MSB \n");
	else
		printf("Access Type = LSB \n");

	///////////////////////////////////////////////////////////////
	// Modo de operacao - Os bits y em xxxxyyyx dao informacao sobre
	// o modo de operacao, logo temos que fazer um deslocamento para a
	// direita e fazer "and" com 7 (111 em binario) para termos apenas
	// os ultimos 3 bits.
	if ((conf >> 1 & 7) == 0)
		printf("Operation Mode = 0 \n");
	else if ((conf >> 1 & 7) == 1)
		printf("Operation Mode = 1 \n");
	else if (((conf >> 1 & 7) == 2) || ((conf >> 1 & 7) == 6))
		printf("Operation Mode = 2 \n");
	else if (((conf >> 1 & 7) == 3) || ((conf >> 1 & 7) == 7))
		printf("Operation Mode = 3 \n");
	else if ((conf >> 1 & 7) == 4)
		printf("Operation Mode = 4 \n");
	else
		printf("Operation Mode = 5 \n");

	////////////////////////////////////////////////////////////////
	// Modo de contagem - O bit 0 tem informacao sobre o contador
		if ((conf & BIT(0)) == TIMER_BIN)
			printf("Counting Mode = Binary \n"); // Se for igual a 0x00, estamos perante contador Binario
		else
			printf("Counting Mode = BCD \n"); // Se for igual a 0x01, estamos perante contador BCD

	return 0;
}

int timer_test_square(unsigned long freq) {
	
	if(timer_set_square(0,freq))
	{
		printf("A funcao timer_set_square falhou\n");
		return 1;
	}
	return 0;
}

int timer_test_int(unsigned long time)
{
//esta funcao tem de mostrar uma mensagem na consola a cada segundo usando printf()

	int irq_set = BIT(TIMER0_IRQ);
	int ipc_status;
 	message msg;
 	unsigned long segundos=0;

 	if(timer_subscribe_int()) // Subscreve
 	{
 		   printf("timer_subscribe_int falhou");
 		   return 1;
 	   }

   contador= 0; // volta a por contador a 0 para utilizar novamente a funcao
   
   while( segundos <time ) // Enquanto nao chegar ao valor do argumento executa o ciclo
   { 
 	/* Get a request message. */ 
	   int r= driver_receive(ANY, &msg, &ipc_status);
 	if ( r != 0 )
	{ 
	printf("driver_receive failed with: %d", r); 
 	continue; 
 	}
 	if (is_ipc_notify(ipc_status)) /* received notification */
	{ 
 		switch (_ENDPOINT_P(msg.m_source))
		{ 
 			case HARDWARE: /* hardware interrupt notification */ 
 				if (msg.NOTIFY_ARG & irq_set)/* subscribed interrupt */
			 	{ 
				timer_int_handler(); // chama o interrupt handler
				if( (contador%60)==0){	//Porque frequencia e 60hz
					printf("Passou um segundo.\n");
					segundos++;}

			 	}
 				break; 
 				default: 
 				break; /* no other notifications expected: do nothing */ 
 		}
	} 
	else /* received a standard message, not a notification */  
	{ 
 	/* no standard messages expected: do nothing */ 
	 }
   }

   if(timer_unsubscribe_int()) //Retira a subscricao
   {
	   printf("timer_unsubscribe_int falhou");
	   return 1;
   }

return 0;
}

int timer_test_config(unsigned long timer) {
	
	unsigned char endereco;

	if (timer_get_conf(timer, &endereco))
	{
		printf("A funcao timer_get_conf falhou\n");
		return 1;
	}
	if (timer_display_conf(endereco))
	{
		printf("A funcao timer_display_conf falhou\n");
		return 1;
	}
	return 0;
}
