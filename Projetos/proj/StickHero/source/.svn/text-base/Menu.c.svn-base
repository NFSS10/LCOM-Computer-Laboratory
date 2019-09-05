#include "Menu.h"



Menu* newMenu() {
	Menu* menu = (Menu*) malloc(sizeof(Menu));
	menu->sprite = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/menu1.bmp");
	menu->sprite2 = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/menu2.bmp");
	menu->sprite3 =  LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/clockmenu.bmp");
	menu->stateOfGame = 0;

	return menu;
}

void deleteMenu(Menu* m) {
	apagaImagem(m->sprite);
	apagaImagem(m->sprite2);
	apagaImagem(m->sprite3);
	free(m);
}

int menuInicial(Menu* m) {

	unsigned int opcao = 0;
	Mouse* mouse = newMouse();


	// Teclado
	unsigned long state;
	int irq_set_kbd = BIT(KBD_IRQ);
	int ipc_status;
	message msg;

	// Rato
	int irq_set = BIT(IRQ_MOUSE);
	int index = 0;
	long int packet_info[3];
	mouse_send_cmd(IN_BUF, KBCMOUSE);
	mouse_send_cmd_ack(OUT_BUF, EN_SEND_DATA);


	//Timer
	int irq_set_timer = BIT(TIMER0_IRQ);
	timer_test_square(60);



	while (1) {
		index = 0;
		opcao = 0;

		/* Get a request message.*/
		int d = driver_receive(ANY, &msg, &ipc_status);
		if (d != 0) {
			printf("driver_receive failed with: %d", d);
			continue;
		}

		if (is_ipc_notify(ipc_status)) { /* received notification*/
			switch (_ENDPOINT_P(msg.m_source)) {
			case HARDWARE: /*hardware interrupt notification*/
				if (msg.NOTIFY_ARG & irq_set_kbd){
					state = kbd_read();
				}

				if(msg.NOTIFY_ARG & irq_set_timer)
				{
					if (mouse->x >= 320 && mouse->x <= 700 && mouse->y >= 215
							&& mouse->y <= 285)
						opcao = 1;
					if (mouse->x >= 300 && mouse->x <= 725 && mouse->y >= 300
							&& mouse->y <= 365)
						opcao = 2;
					if (mouse->x >= 385 && mouse->x <= 640 && mouse->y >= 380
							&& mouse->y <= 445)
						opcao = 3;
					if (mouse->x >= 420 && mouse->x <= 600 && mouse->y >= 460
							&& mouse->y <= 525)
						opcao = 4;


					drawMenu(m->sprite, mouse);
					drawOption(opcao);
				}

				if (msg.NOTIFY_ARG & irq_set)
				{ /*subscribed interrupt*/

					while(index < 3)
					{
						packet_info[index]=mouse_read_data();
						mouse_handler_proj(packet_info, &index);
					}

					updateMouse(packet_info, mouse);

					if (mouse->leftClick == 1) {
						switch (opcao) {
						case 1:
							m->stateOfGame = 1;
							mouse_send_cmd(IN_BUF, KBCMOUSE);
							mouse_send_cmd_ack(OUT_BUF, DEFAULT);
							jogar();
							mouse_send_cmd(IN_BUF, KBCMOUSE);
							mouse_send_cmd_ack(OUT_BUF, EN_SEND_DATA);
							m->stateOfGame = 0;
							break;
						case 2:
							maxScore(m, mouse);
							break;
						case 3:
							mouse_send_cmd(IN_BUF, KBCMOUSE);
							mouse_send_cmd_ack(OUT_BUF, DEFAULT);
							showClock(m);
							mouse_send_cmd(IN_BUF, KBCMOUSE);
							mouse_send_cmd_ack(OUT_BUF, EN_SEND_DATA);
							break;
						case 4:
							mouse_send_cmd(IN_BUF, KBCMOUSE);
							mouse_send_cmd_ack(OUT_BUF, DEFAULT);
							deleteMouse(mouse);
							return 0;
						default:
							break;
						}
					}
				}
				break;
			default:
				break; /*no other notifications expected: do nothing*/
			}
		}
	}
	return 0;
}

int maxScore(Menu* m, Mouse* mouse) {

	unsigned int opcao = 0;
	drawScoreMenu(mouse, m->sprite2);

	//Teclado
	int irq_set_kbd = BIT(KBD_IRQ);
	int ipc_status;
	unsigned long state;
	message msg;

	// Rato
	int index = 0;
	long int packet_info[3];
	int irq_set = BIT(IRQ_MOUSE);

	//Timer
	int irq_set_timer = BIT(TIMER0_IRQ);
	timer_test_square(60);

	while (1) {
		opcao = 0;
		index = 0;
		/* Get a request message.*/
		int d = driver_receive(ANY, &msg, &ipc_status);
		if (d != 0) {
			printf("driver_receive failed with: %d", d);
			continue;
		}

		if (is_ipc_notify(ipc_status)) { /* received notification*/
			switch (_ENDPOINT_P(msg.m_source)) {
			case HARDWARE: /*hardware interrupt notification*/
				if (msg.NOTIFY_ARG & irq_set_kbd){
					state = kbd_read();
				}
				if(msg.NOTIFY_ARG & irq_set_timer)
				{
					if (mouse->x >= 350 && mouse->x <= 670 && mouse->y >= 465
							&& mouse->y <= 540)
						opcao = 1;

					drawScoreMenu(mouse, m->sprite2);
					drawOptionScore(opcao);
				}

				if (msg.NOTIFY_ARG & irq_set) { /*subscribed interrupt*/
					while (index < 3) {
						packet_info[index] = mouse_read_data();
						mouse_handler_proj(packet_info, &index);
					}

					updateMouse(packet_info, mouse);

					if (mouse->leftClick == 1)
						if (opcao == 1)
							return 0;
				}

				break;
			default:
				break; /*no other notifications expected: do nothing*/
			}
		}
	}
	return 0;
}

int showClock(Menu* m) {

	// Teclado
	unsigned long state;
	int irq_set_kbd = BIT(KBD_IRQ);
	int ipc_status;
	message msg;

	//Timer
	int irq_set_timer = BIT(TIMER0_IRQ);
	timer_test_square(60);

	// RTC
	unsigned long data[13];
	unsigned long buffer[13];
	unsigned int i = 0;
	unsigned int k = 0;

	while (state != ENTER)
	{
		// Garante a boa leitura da hora
		i = 0;
		while (i <= 12) {
			sys_outb(RTC_ADDR_REG, i);
			sys_inb(RTC_DATA_REG, &data[i]);
			i++;
		}
		k = 0;
		while (k <= 12) {
			sys_outb(RTC_ADDR_REG, k);
			sys_inb(RTC_DATA_REG, &buffer[k]);
			k++;
		}
		if (data[0] != buffer[0] || data[2] != buffer[2] || data[4] != buffer[4])
		{
			i = 0;
			while (i <= 12) {
				sys_outb(RTC_ADDR_REG, i);
				sys_inb(RTC_DATA_REG, &data[i]);
				i++;
			}
		}

		/* Get a request message.*/
		int d = driver_receive(ANY, &msg, &ipc_status);
		if (d != 0)
		{
			printf("driver_receive failed with: %d", d);
			continue;
		}

		if (is_ipc_notify(ipc_status)) { /* received notification*/
			switch (_ENDPOINT_P(msg.m_source)) {
			case HARDWARE: /*hardware interrupt notification*/
				if (msg.NOTIFY_ARG & irq_set_kbd){
					state = kbd_read();
				}

				if(msg.NOTIFY_ARG & irq_set_timer)
					drawHours(data, m->sprite3);

				break;
			default:
				break; /*no other notifications expected: do nothing*/
			}
		}
	}
	return 0;
}
