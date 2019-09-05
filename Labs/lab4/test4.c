#include "i8042.h"
#include "test4.h"
#include "mouse.h"
#include "i8254.h"

static int contador;

int test_packet(unsigned short cnt){
	int ipc_status;
	int irq_set_mouse = BIT(IRQ_MOUSE);
	message msg;
	int limite = 0;
	int index = 0;
	long int packet_info[3];

	if(mouse_subscribe_int() == -1)
		printf("Erro na subscricao!\n");

	mouse_send_cmd(IN_BUF, KBCMOUSE);
	//printf("bbbb \n");
	mouse_send_cmd_ack(OUT_BUF, EN_SEND_DATA);
	//printf("mouse send acaba \n");

	while (limite < cnt)
	{
		int r = driver_receive(ANY,&msg,&ipc_status);
		if (r != 0)
		{
			printf("driver_receive failed with: %d", r);
			continue;
		}
		//printf("cccc \n");
		if(is_ipc_notify(ipc_status))
		{
			switch (_ENDPOINT_P(msg.m_source))
			{
			case HARDWARE: 
				if(msg.NOTIFY_ARG & irq_set_mouse)
				{
				packet_info[index]=mouse_read_data();
				mouse_handler(packet_info, &limite, &index);
				}
			break;
		default: 
			break;
			}
	} else {
}
}
	mouse_send_cmd(IN_BUF, KBCMOUSE);
	//printf("dddd \n");
	mouse_send_cmd_ack(OUT_BUF, DEFAULT);
	//printf("eeee \n");
	mouse_unsubscribe_int();

	return 0;
}

int test_async(unsigned short idle_time)
{
	int ipc_status;
	int irq_set_mouse = BIT(IRQ_MOUSE);
	message msg;
	int limite = 0;
	int index = 0;
	long int packet_info[3];
	int irq_set_timer0 = BIT(TIMER0_IRQ);
	unsigned short segundos=0;
	contador=0;

	if(mouse_subscribe_int() == -1)
		printf("Erro na subscricao!\n");

	if(timer_subscribe_int() == -1)
		printf("Erro na subscricao!\n");

	mouse_send_cmd(IN_BUF, KBCMOUSE);
	mouse_send_cmd_ack(OUT_BUF, EN_SEND_DATA);

	timer_test_square(60); //para assegurar a frequencia correta

	while (segundos < (idle_time*60))
	{
		int r = driver_receive(ANY,&msg,&ipc_status);
		if (r != 0)
		{
			printf("driver_receive failed with: %d", r);
			continue;
		}
		if(is_ipc_notify(ipc_status))
		{
			switch (_ENDPOINT_P(msg.m_source))
			{
			case HARDWARE:
				if(msg.NOTIFY_ARG & irq_set_mouse)
				{
					packet_info[index]=mouse_read_data();
					mouse_handler(packet_info, &limite, &index);
					segundos = 0; //reset ao tempo
				}

				if(msg.NOTIFY_ARG & irq_set_timer0)
				{
					//printf ("teste\n");
					timer_int_handler();
					if( (contador % 60) == 0){
						segundos++;
					}
				}
			break;
			default:
			break;
			}
		}
		else
		{

		}
	}

	printf("\nPassaram %d segundos sem que tenhas usado o rato!\n", idle_time);
		mouse_send_cmd(IN_BUF, KBCMOUSE);
		mouse_send_cmd_ack(OUT_BUF, DEFAULT);

		mouse_unsubscribe_int();
		timer_unsubscribe_int();

return 0;
}

int test_config(void)
{
	int ipc_status;
	int irq_set_mouse = BIT(IRQ_MOUSE);
	message msg;
	int limite = 0;
	int index = 0;
	long int packet_info[3];

	mouse_subscribe_int();

	mouse_send_cmd(IN_BUF, KBCMOUSE);
	//printf ("chega aqui0\n")
	mouse_send_cmd(OUT_BUF, DIS_DATA_REP);
	//printf ("chega aqui1\n")
	mouse_send_cmd(IN_BUF, KBCMOUSE);
	//printf ("chega aqui2\n");
	mouse_send_cmd(OUT_BUF, STATUS_REQ);
	//printf ("chega aqui3\n");

	while (limite < 1)
	{
		//printf ("ciclo\n");

		int r = driver_receive(ANY,&msg,&ipc_status);

		//printf ("aqui2\n");
		if (r != 0)
		{
			printf("driver_receive failed with: %d", r);
			continue;
		}
		if(is_ipc_notify(ipc_status))
		{
			switch (_ENDPOINT_P(msg.m_source)) {
			case HARDWARE:
			if(msg.NOTIFY_ARG & irq_set_mouse){
				packet_info[index] = mouse_read_data();

				aux_config(packet_info, &limite, &index);
			}
			break;
		default:
			break;
		}
	} else {
}
}
	mouse_send_cmd(IN_BUF, KBCMOUSE);
	mouse_send_cmd(OUT_BUF, DEFAULT);
	mouse_unsubscribe_int();

	return 0;
}

int test_gesture(short length, unsigned short tolerance)
{
	int ipc_status;
	int irq_set_mouse = BIT(IRQ_MOUSE);
	message msg;
	int limite = 0;
	int index = 0;
	long int packet_info[3];

	mouse_subscribe_int();

	mouse_send_cmd(IN_BUF, KBCMOUSE);
	mouse_send_cmd(OUT_BUF, EN_SEND_DATA);

	if (length > 0)
	while (y<length)
	{
		int r = driver_receive(ANY,&msg,&ipc_status);
		if (r != 0)
		{
			printf("driver_receive failed with: %d", r);
			continue;
		}
		if(is_ipc_notify(ipc_status))
		{
			switch (_ENDPOINT_P(msg.m_source)) {
			case HARDWARE:
			if(msg.NOTIFY_ARG & irq_set_mouse){
				packet_info[index] = mouse_read_data();
				mouse_handler(packet_info, &limite, &index);

				//printf("\n\nDebug2: x: %d ", x);
					//printf("y: %d ", y);
				if (abs(x)> tolerance || y< 0){
					x= 0;
					y= 0;}

			}
			break;
		default:
			break;
		}
	} else {
}
}
	else
		if (length < 0)
			while (y>length)
				{
					int r = driver_receive(ANY,&msg,&ipc_status);
					if (r != 0)
					{
						printf("driver_receive failed with: %d", r);
						continue;
					}
					if(is_ipc_notify(ipc_status))
					{
						switch (_ENDPOINT_P(msg.m_source)) {
						case HARDWARE:
						if(msg.NOTIFY_ARG & irq_set_mouse){
							packet_info[index] = mouse_read_data();
							mouse_handler(packet_info, &limite, &index);

							//printf("\n\nDebug2: x: %d ", x);
								//printf("y: %d ", y);
							if (abs(x)> tolerance || y>0){
								x= 0;
								y= 0;}

						}
						break;
					default:
						break;
					}
				} else {
			}
			}
		else
			printf("\n0 como argumento nao e valido!\n");


	mouse_send_cmd(IN_BUF, KBCMOUSE);
	mouse_send_cmd(OUT_BUF, DEFAULT);
	mouse_unsubscribe_int();

	return 0;
}
