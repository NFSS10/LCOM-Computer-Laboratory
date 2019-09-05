#ifndef MENU_H
#define MENU_H

#include "kbd.h"
#include "BMP.h"
#include "macros.h"
#include "mouse.h"

typedef struct {
	Imagem * sprite; /**< @brief Imagem de fundo do menu final*/
	int score; /**< @brief Pontuacao do jogo realizado */
} MenuFinal;

/**
 * @brief Cria uma struct com a imagem de fundo e a pontuacao do jogo.
 *
 *	@param score A pontuacao obtida pelo jogador.
 * @return Um apontador para uma struct do menu final.
 */
MenuFinal* newMenuFinal(int score);

/**
 * @brief Apaga uma struct de menu final que foi alocado anteriormente.
 *
 *	@param m a struct de menu final que queremos apagar da memoria.
 * @return void.
 */
void deleteMenuFinal(MenuFinal* m);

/**
 * @brief Inicia o menu de final de jogo.
 *
 * 	Cria um rato para poder usar no menu e mostra a pontuacao do jogador ate
 * 	o jogador pressionar para voltar ao menu principal.
 *
 *	@param m a struct de menu final que contem a imagem de fundo que queremos mostrar e a pontuacao do jogador.
 * @return 0 em caso de sucesso.
 */
int endMenu(MenuFinal* m);

#endif

