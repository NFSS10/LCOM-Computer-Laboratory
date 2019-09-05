#ifndef UTILIDADES_H_
#define UTILIDADES_H_

#include <stdio.h>
#include "kbd.h"
#include "timer.h"
#include "Graficos.h"
#include "mouse.h"
#include <time.h>

/**
 *  @brief Inicia todos os perifericos necessario para o jogo.
 *
 *  Subescreve o rato, o teclado e o timer.
 *  Inicializa o gerador de numeros aleatorios.
 *  Inicia o modo de video no modo 0x117.
 *
 *  @return zero com sucesso, um se ocorrer algum erro.
 */
int startGame();

/**
 *  @brief Desativa todos os perifericos necessario para o jogo.
 *
 *  Desubescreve o rato, o teclado e o timer.
 *  Desliga o modo de video no modo 0x117.
 *
 *  @return zero com sucesso, um se ocorrer algum erro.
 */
int endGame();

/**
 *  @brief Guarda a pontuacao do jogo num ficheiro externo.
 *
 *  E guardada num ficheiro a pontuacao de cada jogo.
 *  Apenas e guardada a pontuacao maxima do jogo num ficheiro
 *  A funcao analiza a pontuacao ja existente no ficheiro e caso a nova
 *  pontuacao seja maior, guarda a nova.
 *
 *  @param score a pontuacao que se pretende guardar
 *
 *  @return zero com sucesso, um se ocorrer algum erro.
 */
int saveScore(unsigned int score);

/**
 *  @brief Carrega do ficheiro a pontuacao maxima do jogo
 *
 *  @return um se ocorrer algum erro na abertura do cheiro, caso contrario retorna a pontuacao maxima
 */
int loadScore();

#endif
