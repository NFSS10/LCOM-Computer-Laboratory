#include "Jogo.h"



unsigned int larg(unsigned int n)
{
	switch (n)
	{
	case 0:
		return PLAT0;
		break;
	case 1:
		return PLAT1;
		break;
	case 2:
		return PLAT2;
		break;
	case 3:
		return PLAT3;
		break;
	case 4:
		return PLAT4;
		break;
	case 5:
		return PLAT5;
		break;
	case 6:
		return PLAT6;
		break;
	case 7:
		return PLAT7;
		break;
	case 8:
		return PLAT8;
		break;
	}
}

void Tratamento_barra_V(unsigned int tamanho)
{
	if (tamanho >= T_BARRA_MAX_V)
	{
		drawn_aumenta_barra(T_BARRA_MAX_V);
	}
	else
		drawn_aumenta_barra(tamanho);
}

int Tratamento_barra_H(unsigned int tamanho,unsigned int x_ale, unsigned int plat_ale, unsigned int n_plat_antiga)
{
	unsigned int estado=0;
	unsigned int cont=0;
	unsigned int posJogador;
	posJogador=J_X;

	//Perdeu_______________________________________
	if (tamanho > (x_ale + larg(plat_ale) - 100)) {
		drawn_jogo_i(x_ale, plat_ale, n_plat_antiga, Pontuacao);
		if (tamanho >= T_BARRA_MAX_H)
		{
			while (posJogador < J_X+tamanho+J_X+J_X)
			{
				atualiza_fundo();
				cont++;
				posJogador+=JOG_MOV;
				estado=percorrer_barra(posJogador,estado, cont, x_ale, plat_ale, n_plat_antiga, Pontuacao);
				drawn_barra_horizontal(T_BARRA_MAX_H);
				tickdelay(micros_to_ticks(10));
			}
			quedaJogador(posJogador,x_ale, plat_ale, n_plat_antiga, Pontuacao);
		}
		else
		{
			while (posJogador < J_X+tamanho+J_X+J_X)
			{
				atualiza_fundo();
				cont++;
				posJogador+=JOG_MOV;
				estado=percorrer_barra(posJogador,estado, cont,x_ale, plat_ale, n_plat_antiga, Pontuacao);
				drawn_barra_horizontal(tamanho + 4);
				tickdelay(micros_to_ticks(10));
			}
			quedaJogador(posJogador,x_ale, plat_ale, n_plat_antiga, Pontuacao);
		}
		return 1;
	}
	//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
	if (tamanho < (x_ale - 100))
	{
		drawn_jogo_i(x_ale, plat_ale, n_plat_antiga, Pontuacao);
		if (tamanho >= T_BARRA_MAX_H)
		{
			while (posJogador < J_X+tamanho+J_X+J_X)
			{
				atualiza_fundo();
				cont++;
				posJogador+=JOG_MOV;
				estado=percorrer_barra(posJogador,estado, cont,x_ale, plat_ale, n_plat_antiga, Pontuacao);
				drawn_barra_horizontal(T_BARRA_MAX_H);
				tickdelay(micros_to_ticks(10));
			}
			quedaJogador(posJogador,x_ale, plat_ale, n_plat_antiga, Pontuacao);
		}
		else
		{
			while (posJogador < J_X+tamanho+J_X+J_X)
			{
				atualiza_fundo();
				cont++;
				posJogador+=JOG_MOV;
				estado=percorrer_barra(posJogador,estado, cont, x_ale, plat_ale, n_plat_antiga, Pontuacao);
				drawn_barra_horizontal(tamanho);
				tickdelay(micros_to_ticks(10));
			}
			quedaJogador(posJogador,x_ale, plat_ale, n_plat_antiga, Pontuacao);
		}
		return 1;
	}
	//PERDEU_________________________

	//Ganhou:::::::::::::::::::::::::::::::::::::::::::
	Pontuacao++;

	drawn_jogo_i(x_ale, plat_ale, n_plat_antiga, Pontuacao);

	unsigned int posNaPlat;
	posNaPlat = x_ale + larg(plat_ale) - JOG_L;

	if (tamanho >= T_BARRA_MAX_H)
	{
		while (posJogador < posNaPlat)
		{
			atualiza_fundo();
			cont++;
			posJogador += JOG_MOV;
			estado = percorrer_barra(posJogador, estado, cont, x_ale, plat_ale,	n_plat_antiga, Pontuacao);
			drawn_barra_horizontal(T_BARRA_MAX_H);
			tickdelay(micros_to_ticks(10));
		}
		percorrer_barra(posNaPlat, 0, MOV_V, x_ale, plat_ale, n_plat_antiga, Pontuacao);
	}
	else
	{
		while (posJogador < posNaPlat)
		{
			atualiza_fundo();
			cont++;
			posJogador += JOG_MOV;
			estado = percorrer_barra(posJogador, estado, cont, x_ale, plat_ale,	n_plat_antiga, Pontuacao);
			drawn_barra_horizontal(tamanho+4);
			tickdelay(micros_to_ticks(10));
		}
		percorrer_barra(posNaPlat, 0, MOV_V, x_ale, plat_ale, n_plat_antiga, Pontuacao);
	}

	return 0; //acaba a jogada
	//Ganhou:::::::::::::::::::::::::::::::::::::::::::
}

int jogar()
{
	unsigned int tamanho = 0;
	Pontuacao=0;
	Perdeu=0;
	coordNuvens=0;
	coordErvas=0;
	unsigned int x_ale;
	unsigned int plat_ale;
	unsigned int N_plat_Antiga = 6;  //plataforma 6, com largura 100

	plat_ale = rand()%9;	//0 a 8
	x_ale = (rand() % (LIMITE_S - LIMITE_I)) + LIMITE_I;	//limitar o local das plataformas


	// Timer
	int irq_set_timer = BIT(TIMER0_IRQ);
	unsigned short segundos = 0;
	contador = 0;
	timer_test_square(60);

	// Teclado
	int irq_set = BIT(KBD_IRQ);
	int ipc_status;
	unsigned long state;
	message msg;

	while (1)
	{
		int d = driver_receive(ANY, &msg, &ipc_status);
		if (d != 0)
		{
			printf("driver_receive failed with: %d", d);
			continue;
		}
		if (is_ipc_notify(ipc_status))
		{
			switch (_ENDPOINT_P(msg.m_source))
			{
			case HARDWARE:
				if (msg.NOTIFY_ARG & irq_set) {
					state = kbd_read();

					if (state == BREAKCODE_I)
						Perdeu = 1;
				}

				if (msg.NOTIFY_ARG & irq_set_timer)
				{
					atualiza_fundo();

					if(Perdeu) //perdeu o jogo
					{
						// Mostra menu de final do jogo
						MenuFinal* menu = newMenuFinal(Pontuacao);
						endMenu(menu);
						deleteMenuFinal(menu);
						saveScore(Pontuacao);
						return 0;
					}

					drawn_jogo_i(x_ale,plat_ale, N_plat_Antiga, Pontuacao);
					if (state == ESPACO)
					{
						drawn_aumenta_barra(tamanho);	//para minimizar o lag do teclado
						Perdeu=fazjogada(SENSIBILIDADE_BARRA,x_ale,plat_ale,N_plat_Antiga); //SENSIBILIDADE_BARRA porque ja esta a contar com o pressionar o espaço a 1a vez
						if(!Perdeu)
							move_plataforma_antiga(x_ale, plat_ale, Pontuacao); //Movimenta o jogador e a plataforma para o inicio
						N_plat_Antiga=plat_ale; //a plataforma nova e agora antiga
						plat_ale = rand()%9;	//0 a 8
						x_ale = (rand() % (LIMITE_S - LIMITE_I)) + LIMITE_I;	//limitar o local das plataformas

						if(!Perdeu)
							move_plataforma_nova(x_ale, plat_ale, N_plat_Antiga, Pontuacao);
					}

					contador++;
				}

				break;
			default:
				break;
			}
		}
	}
	return 0;
}

int fazjogada(unsigned int tamanho,unsigned int x_ale, unsigned int plat_ale , unsigned int N_plat_Antiga)
{
	//Timer
	int irq_set_timer = BIT(TIMER0_IRQ);
	unsigned short segundos = 0;
	contador = 0;
	timer_test_square(60);

	//Tratamento do teclado
	int irq_set = BIT(KBD_IRQ);
	int ipc_status;
	unsigned long state;
	message msg;

	while (1)
	{
		int d = driver_receive(ANY, &msg, &ipc_status);
		if (d != 0) {
			printf("driver_receive failed with: %d", d);
			continue;
		}
		if (is_ipc_notify(ipc_status))
		{
			switch (_ENDPOINT_P(msg.m_source))
			{
			case HARDWARE:
				if (msg.NOTIFY_ARG & irq_set)
					state = kbd_read();

				if (msg.NOTIFY_ARG & irq_set_timer)
				{
					//________________________________________________________________________________________________________________
					atualiza_fundo();
					drawn_jogo_i(x_ale,plat_ale, N_plat_Antiga, Pontuacao);

					if(state == BREAKCODE_I) //Saiu
						return 1;

					if (state == ESPACO) //Enquanto esta a premir espaco
					{
						tamanho += SENSIBILIDADE_BARRA;
						Tratamento_barra_V(tamanho);
					}

					if (state == ESPACO_R) //Quando larga o espaco
					{
						return Tratamento_barra_H(tamanho,x_ale , plat_ale, N_plat_Antiga);
					}
					contador++;
					//___________________________________________________________________________________________________
				}
				break;
			default:
				break;
			}
		}
	}
	return 0;
}

