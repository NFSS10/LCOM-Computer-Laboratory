#include "mouse.h"
#include <math.h>

static int hook_id = IRQ_MOUSE;

int mouse_read_data(){
	unsigned long stat, data;

	while( 1 ) {
		sys_inb(STAT_REG, &stat); /* assuming it returns OK */
		if( (stat & OBF) ) {
			sys_inb(OUT_BUF, &data); /* assuming it returns OK */
			if ( (stat &(PARITY | TIMEOUT )) == 0 )
				return data;
			else
				return -1;
		}
		tickdelay(micros_to_ticks(DELAY_US));
	}
	return 1;
}

int mouse_send_cmd_ack(unsigned char adress, unsigned char command){  // Similar ao anterior, mas temos que verificar se o Input Buffer esta vazio
	unsigned long stat;				// E verificar se o retorno e igual a ACK (0xFA if everything OK)
	do {
		//printf("Debug: 1111 \n");
		if (sys_inb(STAT_REG, &stat) != OK)
			printf ("STAT_REG, STAT"); /* assuming it returns OK */
		if(!( stat & IBF ))// Do not forget to check the IBF bit in the STATUS_REG, before writing to either port
		{
		if (sys_outb(adress, command) != OK)
			printf ("adress, command error");
		if (sys_inb(OUT_BUF, &stat) != OK)
			printf ("OUT_BUF, stat");
		}
		tickdelay(micros_to_ticks(DELAY_US));
	} while (stat != ACK);
	return 0;

}

int mouse_send_cmd(unsigned char adress, unsigned char command){  // Similar ao anterior, mas temos que verificar se o Input Buffer esta vazio
	unsigned long stat;				// E verificar se o retorno e igual a ACK (0xFA if everything OK)

	do {// Do not forget to check the IBF bit in the STATUS_REG, before writing to either port
		//printf ("teste");
		sys_inb(STAT_REG, &stat); /* assuming it returns OK */
		if( !(stat & IBF) )
		{
			if (sys_outb(adress, command) != OK)
				printf ("adress, command error");
			if (sys_inb(OUT_BUF, &stat) != OK)
				printf ("OUT_BUF, stat");
			if ( (stat &(PARITY | TIMEOUT )) == 0 )
				return 0;
			else
				return -1;
		}
		tickdelay(micros_to_ticks(DELAY_US));
	} while (1);

	return 0;
}



int mouse_subscribe_int(void) {


	if (sys_irqsetpolicy(IRQ_MOUSE,IRQ_REENABLE | IRQ_EXCLUSIVE,&hook_id) != OK)
		return -1;
	if (sys_irqenable(&hook_id) != OK)
		return -1;
		
	return 0;
}


int mouse_unsubscribe_int() {

	if (sys_irqrmpolicy(&hook_id) != OK)
		return -1;
	if (sys_irqdisable(&hook_id) != OK)
		return -1;

	return 0;
}

void display(long int *packet_info)
{
	int byte = pow(2,8);

	printf("B1=0x%02x |" , packet_info[0]);
	printf("B2=0x%02x |" , packet_info[1]);
	printf("B3=0x%02x |" , packet_info[2]);

	if ((packet_info[0] & BIT(0)) == 0)
		printf("LB=0 |");
	else
		printf("LB=1 |");

	if ((packet_info[0] & BIT(2)) == 0)
		printf("MB=0 |");
	else
		printf("MB=1 |");
		
	if ((packet_info[0] & BIT(1)) == 0)
		printf("RB=0 |");
	else
		printf("RB=1 |");

	if ((packet_info[0] & BIT(6)) == 0)
		printf("XOV=0 |");
	else
		printf("XOV=1 |");
		
	if ((packet_info[0] & BIT(7)) == 0)
		printf("YOV=0 |");
	else
		printf("YOV=1 |");
		
	if ((packet_info[0] & BIT(4)) == 0)
		printf("Sign X=0 |");
	else
		printf("Sign X=1 |");
		
	if ((packet_info[0] & BIT(5)) == 0)
		printf("Sign Y=0 |");
	else
		printf("Sign Y=1 |");
		
	if((packet_info[0] & BIT(4)) == 0)
		printf("X=%d |",packet_info[1]);
	else
		printf("X=%d |",packet_info[1]-byte);

	if((packet_info[0] & BIT(5)) == 0)
		printf("Y=%d \n",packet_info[2]);
	else
		printf("Y=%d \n",packet_info[2]-byte);

	test_moviment(packet_info); // para a funcao gesture

}

int test_display(long int *packet_info, int *limite, int *index)  // Caso o array esteja "cheio" fazer display das suas caracteristicas
{
	if ((*index) > 2)  // Se chegarmos ao fim, "limpar o array", aumentar o contador e fazer o seu display
	{
		(*index) = 0;
		(*limite) = (*limite) +1;
		display(packet_info);
	}
	else
		return -1;
return 0;
}

int mouse_handler(long int *packet_info, int *limite, int *index)
{
	if ((packet_info[0] & BIT(3)) == 0)   // Garantir que o o primeiro byte tem sempre o bit 3 a 1
		return -1;			// Caso o bit 3 seja 0 saimos da funcao para voltar a ler para o 1 byte do array

	(*index) = (*index) + 1; // Lemos o primeiro byte com sucesso e o bit 3 e 1, preparar para ler o proximo

	/*if (test_display(packet_info, limite, index) == -1)
		printf ("O Pacote ainda nao esta cheio.\n");
	else
		printf ("O Pacote foi limpo. Numero de Pacotes Lidos= %d\n" , (*limite));*/



	return 0;
}

int aux_config(long int *packet_info, int *limite, int *index)
{
	if (((packet_info[0] & BIT(3)) == 1) || ((packet_info[0] & BIT(7)) == 1))   // Garantir que o o primeiro byte tem sempre o bit 3 e 7 a 0
			return -1;			// Caso o bit 3 ou 7 seja 1 saimos da funcao para voltar a ler para o 1 byte do array

		if ((*index == 1) && (packet_info[1] > 3))
				return -1;

		(*index) = (*index) + 1; // Lemos o primeiro byte com sucesso e o bit 3 e 1, preparar para ler o proximo

	if (test_aux_status(packet_info, limite, index) == -1)
		printf ("O Pacote ainda nao esta cheio.\n");

return 0;
}

int test_aux_status(long int *packet_info, int *limite, int *index)  // Caso o array esteja "cheio" fazer display das suas caracteristicas
{
	if ((*index) > 2)  // Se chegarmos ao fim, "limpar o array", aumentar o contador e fazer o seu display
	{

		(*index) = 0;
		(*limite) = (*limite) +1;
		show_status(packet_info);
	}
	else
		return -1;
return 0;
}

void show_status(long int *packet_info)
{
	printf ("%d\n" , packet_info[0]);
	printf ("%d\n" , packet_info[1]);
	printf ("%d\n\n" , packet_info[2]);

	if ((packet_info[0] & BIT(6)) == 0)
		printf("Stream mode\n");
	else
		printf("Remote (polled) mode\n");

	if ((packet_info[0] & BIT(5)) == 0)
		printf ("Data reporting disable. This bit only has effect in Stream mode\n");
	else
		printf ("Data reporting enabled. This bit only has effect in Stream mode\n");

	if ((packet_info[0] & BIT(4)) == 0)
		printf ("Scaling is 1:1\n");
	else
		printf ("Scaling is 2:1\n");

	if ((packet_info[0] & BIT(2)) == 0)
		printf ("Left button is currently released\n");
	else
		printf ("Left button is currently pressed\n");

	if ((packet_info[0] & BIT(1)) == 0)
		printf ("Middle button is currently released\n");
	else
		printf("Middle button is currently pressed\n");

	if ((packet_info[0] & BIT(0)) == 0)
		printf("Right button is currently released\n");
	else
		printf("Right button is currently pressed\n");

}

void test_moviment(long int *packet_info)
{
	int byte = pow(2,8);

	//printf("Debug0: x: %d ", x);
	//printf("y: %d \n", y);

	if ((packet_info[0] & BIT(1)) != 0) // Verifica se o botao lado direito esta pressionado
	{
		if ((packet_info[0] & BIT(4)) == 0) // Verifica se o movimento horizontal e positivo
			x = x + packet_info[1];
		else
			x = x + (packet_info[1]-byte);

		if ((packet_info[0] & BIT(5)) == 0) // verifica se o movimento vertical e positivo
			y = y + packet_info[2];
		else
			y = y + (packet_info[2]-byte);
	}

	//printf("Debug1: x: %d ", x);
	//printf("y: %d \n", y);
}


