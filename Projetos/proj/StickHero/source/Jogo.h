#ifndef JOGO_H
#define JOGO_H

#include "macros.h"
#include "Graficos.h"
#include "kbd.h"
#include "timer.h"
#include <stdlib.h>
#include "menufinal.h"


static int Pontuacao;	/**< @brief Onde se vai guardando a pontuacao no decorrer do jogo */
static int Perdeu;		/**< @brief Bool que verifica se perdeu ou nao */


/**
 * @brief Retorna o tamanho da plataforma gerada aleatoriamente
 *
 * @param n numero da plataforma que foi gerada aleatoriamente
 * @return tamanho da plataforma dada como argumento
 */
unsigned int larg(unsigned int n);

/**
 * @brief Inicia o jogo e todas as ferramentas para o jogo em si.
 *
 * Quando acaba o jogo, chama o menu de final de jogo e se a pontuacao for superior
 * a pontuacao maxima, atualiza a pontuacao maxima.
 *
 * @return 0 em caso de sucesso.
 */
int jogar();

/**
 * @brief Desenha a barra na vertical
 *
 * @param tamanho tamanho da barra a ser desenhada
 * @return void
 */
void Tratamento_barra_V(unsigned int tamanho);

/**
 * @brief Desenha a barra na horizontal, verifica se Perdeu e faz o jogador percorrer a barra desenhada.
 *
 * Perder significa que a barra nao chegou a plataforma ou que ultrapassou a plataforma.
 * Caso não Perca, incrementa +1 ao score.
 *
 * @param tamanho tamanho da barra a ser desenhada
 * @param x_ale a posicao da plataforma da qual o jogador esta a tentar chegar
 * @param plat_ale um numero que designa a plataforma da qual o jogador esta a tentar chegar
 * @param n_plat_antiga um numero que designa a plataforma onde o jogador esta inicialmete antes de se mover
 * @return 1 caso Perca e 0 caso ganhe a fase
 */
int Tratamento_barra_H(unsigned int tamanho,unsigned int x_ale, unsigned int plat_ale, unsigned int n_plat_antiga);

/**
 * @brief Trata da interacao do jogador com o jogo.
 *
 * Quando o jogador o premir a tecla ESPACO, a barra vai aumentar ate o mesmo largar a tecla ESPACO.
 * Se o jogador premir a tecla ESC, ele volta ao menu inicial.
 *
 * @param tamanho tamanho da barra que recebe da funcao jogar() por ter premido o space
 * @param x_ale a posicao da plataforma da qual o jogador esta a tentar chegar
 * @param plat_ale um numero que designa a plataforma da qual o jogador esta a tentar chegar
 * @param N_plat_Antiga um numero que designa a plataforma onde o jogador esta inicialmete antes de se mover
 * @return 1 caso carregue a tecla ESC ou retorna o valor de retorno da funcao Tratamento_barra_H
 */
int fazjogada(unsigned int tamanho,unsigned int x_ale, unsigned int plat_ale, unsigned int N_plat_Antiga);


#endif
