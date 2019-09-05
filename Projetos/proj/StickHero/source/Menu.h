#ifndef MENU_H
#define MENU_H

#include "kbd.h"
#include "BMP.h"
#include "macros.h"
#include "mouse.h"

typedef struct {
	Imagem * sprite; /**< @brief Imagem do menu principal */
	Imagem * sprite2; /**< @brief Imagem do menu de score */
	Imagem * sprite3; /**< @brief Imagem do menu do relogio */
	int stateOfGame; /**< @brief Estado do jogo */
} Menu;

/**
 * @brief Cria uma struct com as imagens dos menus.
 *
 * @return Um apontador para uma struct do menu.
 */
Menu* newMenu();

/**
 * @brief Apaga uma struct de menu que foi alocado anteriormente.
 *
 *	@param m a struct do menu que queremos apagar da memoria.
 * @return void.
 */
void deleteMenu(Menu* m);

/**
 * @brief Inicia o menu principal do jogo.
 *
 * 	Cria um rato para poder usar no menu para poder escolher as opcoes do menu.
 * 	Utiliza as interrupcoes do timer, do rato e do teclado.
 *
 *	@param m a struct de menu que contem as imagem de fundo que queremos mostrar e o estado do jogo.
 * @return 0 em caso de sucesso.
 */
int menuInicial(Menu* m);

/**
 * @brief Inicia o menu de pontuacao maxima do jogo.
 *
 * 	E passado o rato do menu anterior como argumento.
 * 	Utiliza as interrupcoes do timer, do rato e do teclado.
 *
 *	@param m a struct de menu que contem as imagem de fundo que queremos mostrar e o estado do jogo.
 *	@param mouse o rato que contem a imagem do rato que queremos mostrar no ecra.
 * @return 0 em caso de sucesso.
 */
int maxScore(Menu* m, Mouse* mouse);

/**
 * @brief Inicia o menu do relogio.
 *
 * 	Para retornar ao menu principal e necessario carregar em enter.
 * 	Utiliza as interrupcoes do timer e do teclado.
 * 	Le o RTC para saber as horas atuais.
 *
 *	@param m a struct de menu que contem as imagem de fundo que queremos mostrar e o estado do jogo.
 * @return 0 em caso de sucesso.
 */
int showClock(Menu* m);

#endif
