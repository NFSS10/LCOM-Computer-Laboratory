#include "menufinal.h"

MenuFinal* newMenuFinal(int score) {
	MenuFinal* menu = (MenuFinal*) malloc(sizeof(MenuFinal));
	menu->sprite = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/endmenu.bmp");
	menu->score = score;

	return menu;
}

void deleteMenuFinal(MenuFinal* m) {
	apagaImagem(m->sprite);
	free(m);
}


int endMenu(MenuFinal* m) {

	unsigned int opcao = 0;
	Mouse* mouse = newMouse();

	drawEndMenu(mouse, m);

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
				if (msg.NOTIFY_ARG & irq_set_kbd)
					state = kbd_read();

				if (msg.NOTIFY_ARG & irq_set) { /*subscribed interrupt*/

					while(index < 3)
					{
						packet_info[index]=mouse_read_data();
						mouse_handler_proj(packet_info, &index);
					}

					updateMouse(packet_info, mouse);

					if (mouse->x >= 300 && mouse->x <= 720 && mouse->y >= 425 && mouse->y <= 560)
						opcao = 1;

					drawEndMenu(mouse, m);
					drawOptionEnd(opcao);

					if (mouse->leftClick == 1)
						if (opcao == 1) {
							mouse_send_cmd(IN_BUF, KBCMOUSE);
							mouse_send_cmd_ack(OUT_BUF, DEFAULT);
							deleteMouse(mouse);
							return 0;
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
