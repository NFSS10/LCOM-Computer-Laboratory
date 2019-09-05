#ifndef GRAFICOS_H_
#define GRAFICOS_H_

#include <math.h>
#include "macros.h"
#include "BMP.h"
#include "vbe.h"
#include "timer.h"
#include "mouse.h"
#include "kbd.h"
#include "menufinal.h"

static unsigned char next[1024*768*2];  /**< @brief Buffer */

static unsigned h_res;		 /**< @brief Resolucao horizontal do ecra */
static unsigned v_res;		 /**< @brief Resolucao vertical do ecra */
static unsigned bits_per_pixel;  /**< @brief Bits por pixel */
static unsigned int coordNuvens;  /**< @brief  Coordenadas das nuvens */
static unsigned int coordErvas;  /**< @brief Coordenadas das ervas */

/**
 * @brief Carrega todas as imagens necessarias para o jogo
 *
 * @return void
 */
void inicializaimagens();

/**
 * @brief Apaga todas as imagens do jogo inicializadas anteriormente
 *
 * @return void
 */
void apagaImagens();

/**
 * @brief Retira o minix do modo grafico para o modo de texto
 *
 * @return 0 em caso de sucesso e 1 em caso de insucesso
 */
int video_exit(void);

/**
 * @brief Inicia o minix em modo grafico
 *
 * @param mode o modo e resolucao que se quer iniciar
 * @return Apontador nulo se nao conseguir iniciar o modo grafico e a posicao se iniciar corretamente.
 */
void *video_init(unsigned short mode);

/**
 * @brief Desenha um pixel no ecra
 *
 *  @param x Posicao x do pixel que se quer desenhar
 *  @param y Posicao y do pixel que se quer desenhar
 *  @param color Cor que se quer desenhar no pixel escolhido
 * @return -1 se as coordenadas estiverem fora do ecra e 0 se desenhar com sucesso
 */
int drawnPixel(unsigned long x, unsigned long y, unsigned long color);

/**
 * @brief Desenha uma linha no ecra
 *
 *  @param xi Posicao x inicial da linha que se quer desenhar
 *  @param yi Posicao y inicial da linha que se quer desenhar
 *  @param xf Posicao x final da linha que se quer desenhar
 *  @param yf Posicao y final da linha que se quer desenhar
 *  @param color Cor que se quer desenhar na linha escolhida
 * @return -1 se as coordenadas estiverem fora do ecra e 0 se desenhar com sucesso
 */
int drawLine(unsigned short xi, unsigned short yi, unsigned short xf, unsigned short yf, unsigned long color);

/**
 * @brief Copia uma imagem para o buffer
 *
 *  @param img Imagem que se pretende desenhar no buffer
 *  @param x Posicao x onde se quer desenhar a imagem
 *  @param y Posicao ybonde se quer desenhar a imagem
 * @return void
 */
void drawn_Imagem_to_Buf(Imagem* img, int x, int y);

/**
 * @brief Desenha a barra na vertical
 *
 *  @param tamanho tamanho da barra a desenhar
 * @return void
 */
void drawn_aumenta_barra(unsigned int tamanho);

/**
 * @brief Desenha a barra do jogo na horizontal
 *
 *  @param tamanho tamanho da barra que se pretende desenhar
 * @return void
 */
void drawn_barra_horizontal(unsigned int tamanho);

/**
 * @brief Desenha o estado inicial do jogo.
 *
 * E o estado na qual o ninja esta na posicao inicial pronto para fazer a jogada
 *
 *  @param x_ale  posicao da plataforma onde o ninja tem de chegar
 *  @param plat_ale numero da plataforma na qual o ninja vai tentar alcançar
 *  @param n_plat_antiga numero da plataforma na qual o ninja esta posicionado em cima
 *  @param Pontos Pontos que o jogador fez no jogo ate ao momento
 * @return void
 */
void drawn_jogo_i(unsigned int x_ale, unsigned int plat_ale,unsigned int n_plat_antiga, int Pontos);

/**
 * @brief Desenha o estado do jogo sem o ninja.
 *
 *  @param x_ale  posicao da plataforma onde o ninja tem de chegar
 *  @param plat_ale numero da plataforma na qual o ninja vai tentar alcançar
 *  @param n_plat_antiga numero da plataforma na qual o ninja esta posicionado em cima
 *  @param Pontos Pontos que o jogador fez no jogo ate ao momento
 * @return void
 */
void drawn_jogo_estado(unsigned int x_ale, unsigned int plat_ale, unsigned int n_plat_antiga, int Pontos);

/**
 * @brief Desenha para o buffer, parte da imagem de fundo.
 *
 *  @param img imagem da qual vai ser carregada parte da imagem
 *  @param x coordenada em x para onde vai desenhar
 *  @param y coordenada em y para onde vai desenhar
 *  @param coordx coordenada em x que dita a partir de onde se deve copiar
 *  @param tamImg largura da imagem que vai ser usada
 * @return void
*/
void drawn_Fundo_to_Buf(Imagem* img, int x, int y, unsigned int coordx, unsigned int tamImg);

/**
 * @brief Modifica as coordenadas da parte da imagem de fundo das Ervas
 *
 * Atualiza "coordErvas" incrementando "ERVA_VEL" a "coordErvas"
 *
 * @return void
*/
void atualiza_fundo_ervas();

/**
 * @brief Modifica as coordenadas da parte da imagem de fundo das Nuvens
 *
 * Atualiza "coordNuvens" incrementando "NUVENS_VEL" a "coordNuvens" e verifica os limites
 * das "coordNuvens" e "coordErvas" para o movimento do fundo ser fluido
 *
 * @return void
*/
void atualiza_fundo();

/**
 * @brief Desenha para o buffer, o fundo completo do jogo e a pontuacao atual para o buffer
 *
 *  @param Pontos pontos atuais do jogador
 * @return void
*/
void drawn_fundo_buf(int Pontos);

/**
 * @brief Animacao de queda do ninja
 *
 *  @param posicao posicao em x do ninja na qual ele se encontra
 *  @param x_ale  posicao da plataforma onde o ninja tem de chegar
 *  @param plat_ale numero da plataforma na qual o ninja vai tentar alcançar
 *  @param n_plat_antiga numero da plataforma na qual o ninja esta posicionado em cima
 *  @param Pontos Pontos que o jogador fez no jogo ate ao momento
 * @return void
*/
void quedaJogador(unsigned int posicao, unsigned int x_ale, unsigned int plat_ale, unsigned int n_plat_antiga, int Pontos);

/**
 * @brief Animacao de percorrer a barra
 *
 * Nesta funcao e usado MOV_V para modificar a velocidade da animacao do andar do ninja
 *
 *  @param posicao posicao em x do ninja na qual ele se encontra
 *  @param x_ale  posicao da plataforma onde o ninja tem de chegar
 *  @param plat_ale numero da plataforma na qual o ninja vai tentar alcançar
 *  @param n_plat_antiga numero da plataforma na qual o ninja esta posicionado em cima
 *  @param Pontos Pontos que o jogador fez no jogo ate ao momento
 * @return 0 ou 1 ou 2 ou 3 que representam o estado da animacao do andar do ninja
*/
unsigned int percorrer_barra(unsigned int posicao, unsigned int estado, unsigned int cont, unsigned int x_ale, unsigned int plat_ale, unsigned int n_plat_antiga, int Pontos);

/**
 * @brief Escolhe a plataforma a usar
 *
 *  @param n numero que especifica a plataforma que se quer
 * @return apontador para a Imagem da plataforma
*/
Imagem *escolhePlataforma(unsigned int n);

/**
 * @brief Animacao de mover a plataforma que o ninja atingiu para o lado esquerdo do ecra
 *
 *  @param posI_plat_antiga posicao inicial da plataforma a que o ninja chegou
 *  @param n_plat_antiga numero da plataforma a mover
 *  @param Pontos Pontos que o jogador fez no jogo ate ao momento
 * @return void
*/
void move_plataforma_antiga(unsigned int posI_plat_antiga, unsigned int n_plat_antiga, int Pontos);

/**
 * @brief Animacao de mover a nova plataforma gerada aleatoriamente
 *
 *  @param posFinal posicao na qual a plataforma tem de estar no final da animacao
 *  @param n_Plat_Nova numero da nova plataforma gerada
 *  @param n_Plat_Antiga numero da plataforma que esta no lado esquerdo do ecra, onde o ninja se encontra
 *  @param Pontos Pontos que o jogador fez no jogo ate ao momento
 * @return void
*/
void move_plataforma_nova(unsigned int posFinal, unsigned int n_Plat_Nova, unsigned int n_Plat_Antiga, int Pontos);

/**
 * @brief Escolhe a imagem numero do score do jogo a ser usado.
 *
 * Sao os numeros de fundo azul.
 *
 *  @param number numero que especifica o numero que se quer
 * @return apontador para a Imagem do numero
*/
Imagem* chooseNumberGame(int number);

/**
 * @brief Desenha para o buffer, a pontuacao do jogador
 *
 *  @param score pontuacao a desenhar
 * @return void
*/
void printScore(int score);

/**
 * @brief Desenha no ecra o menu inicial e o rato
 *
 * Desenha-se a imagem do menu e o ponteiro do rato nas coordenadas
 * especificas do rato.
 *
 *  @param img imagem de fundo a ser usada
 *  @param m apontador para a struct do rato
 * @return void
*/
void drawMenu(Imagem* img, Mouse* m);

/**
 * @brief Desenha no ecra as horas
 *
 *  @param data tem a informacao de onde se retira a hora, minutos e segundos
 *  @param img a imagem de fundo do menu das horas
 * @return void
*/
void drawHours(unsigned long* data, Imagem* img);

/**
 * @brief Desenha no ecra, um retangulo por cima da opcao pretendida
 *
 *  @param option numero da opcao pretendida
 * @return void
*/
void drawOption(unsigned int option);

/**
 * @brief Desenha no ecra, um retangulo a volta de Return em "MaxScore"
 *
 * "MaxScore" e a segunda opcao no menu inicial.
 *
 * @return void
*/
void drawOptionScore();

/**
 * @brief Escolhe a imagem numero do score do Menu
 *
 * Sao os numeros de fundo verde.
 *
 *  @param number numero que especifica o numero que se quer
 * @return apontador para a Imagem do numero
*/
Imagem* chooseNumber(int number);

/**
 * @brief Desenha no ecra, a pontuacao maxima registada
 *
 *  @param m rato que vai ser usado
 *  @param menu2 imagem de fundo que vai ser usado
 * @return void
*/
void drawScoreMenu(Mouse* m, Imagem* menu2);

/**
 * @brief Desenha no ecra, a pontuacao que se obteve quando perdeu o jogo
 *
 *  @param m rato que vai ser usado
 *  @param menu imagem de fundo que vai ser usado
 * @return void
*/
void drawEndMenu(Mouse* m, MenuFinal* menu);

/**
 * @brief Desenha um retangulo na opcao de retornar do menu que aparece quando se perde
 *
 *  @param opcao se for 1 desenha o retangulo, caso contrario nao desenha o retangulo
 * @return void
*/
void drawOptionEnd(int opcao);

#endif
