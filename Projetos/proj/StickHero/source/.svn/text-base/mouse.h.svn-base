#ifndef _MOUSE_H_
#define _MOUSE_H_

#include <minix/sysutil.h>
#include <minix/syslib.h>
#include <minix/drivers.h>
#include <stdio.h>
#include "macros.h"
#include "timer.h"
#include "BMP.h"
#include <math.h>

typedef struct {
	Imagem * sprite; /**< @brief Imagem do rato */
	int x; /**< @brief Coordenada x do rato*/
	int y; /**< @brief Coordenada y do rato */
	unsigned int leftClick; /**< @brief Verificador do botao do lado esquerdo*/
} Mouse;

signed int x; /**< @brief Coordenada global x da lab anterior */
signed int y; /**< @brief Coordenada global y da lab anterior */

/**
 * @brief Cria uma struct com uma imagem do rato, coordenadas do rato e um verificador
 * 		para saber se o botao do lado esquerdo esta clicado. Se leftClick estiver a 1
 * 		o botao esta a ser clickado, se estiver a 0 esta normal.
 *
 * @return Um apontador para uma struct do rato.
 */
Mouse* newMouse();

/**
 * @brief Apaga uma struct que foi alocado anteriormente.
 *
 *	@param m a struct que queremos apagar da memoria.
 * @return void.
 */
void deleteMouse(Mouse* m);

/**
 * @brief Atualiza a struct do rato com as novas coordenadas e se o botao esquerdo do
 * 		rato esta pressionado.
 *
 *	@param packet_info o local da informacao das coordenadas e se o botao esta pressionado.
 *	@param m a struct que queremos atualizar.
 * @return void.
 */
void updateMouse(long int *packet_info, Mouse* m);

/**
 * @brief Garantir que se leu com sucesso o byte 1 do array.
 *
 * 	Temos que verificar se o primeiro byte tem sempre o bit 3 a 1.
 *	Caso o byte seja lido com sucesso incrementa-se o indice para nao proxima chamada
 *	se ler o proximo byte.
 *
 *	@param packet_info o local da informacao que queremos ler.
 *	@param index o indice do byte do array.
 * @return 0 se lemos com sucesso um byte, -1 em caso de insucesso.
 */
int mouse_handler_proj(long int *packet_info, int *index);

/**
 * @brief Leitura da informacao do KBC se nao existir qualquer erro.
 *
 * @return a data do rato em caso de sucesso e -1 em caso de insucesso.
 */
int mouse_read_data();

/**
 * @brief Envio de um comando para o endereço dado com argumento do KBC
 *
 * 	Tem-se que verificar tambem se o input buffer esta vazio.
 *
 * @param adress endereço do KBC para onde queremos mandar o comando.
 * @param command comando que queremos mandar para o KBC.
 * @return 0 em caso de sucesso e -1 em caso de insucesso.
 */
int mouse_send_cmd(unsigned char adress, unsigned char command);

/**
 * @brief Envio de um comando para o endereço dado com argumento do KBC
 *
 * 	Tem-se que verificar se o retorno e igual a ACK (0xFA if everything OK).
 * 	Tem-se que verificar tambem se o input buffer esta vazio.
 *
 * @param adress endereço do KBC para onde queremos mandar o comando.
 * @param command comando que queremos mandar para o KBC.
 * @return 0 em caso de sucesso.
 */
int mouse_send_cmd_ack(unsigned char adress, unsigned char command);

/**
 * @brief Subescreve e ativa as interrupcoes do rato.
 *
 * @return retorna -1 em caso de erro e 0 em caso de sucesso.
 */
int mouse_subscribe_int(void);

/**
 * @brief Desubescreve as interrupcoes do rato
 *
 * @return retorna -1 em caso de erro e 0 em caso de sucesso.
 */
int mouse_unsubscribe_int();

/**
 * @brief Faz o display de todas as informacoes contidas no pacote recebido como argumento.
 *
 * @param packet_info o pacote que queremos mostrar no ecra.
 * @return void.
 */
void display(long int *packet_info);

/**
 * @brief Caso o array esteja "cheio" faz o display das suas caracteristicas
 *
 *	Se o array estiver cheio, "limpasse o array", aumentar o contador (limite) e fazer o seu display.
 *
 *	@param packet_info o local onde esta a informacao que queremos verificar.
 *	@param limite para verificar se ja lemos todos os packets que queriamos como argumento.
 *	@param index indice do preenchimento do array (packet_info).
 * 	@return 0 se o packet_info estiver cheio, -1 se nao estiver.
 */
int test_display(long int *packet_info, int *limite, int *index);

/**
 * @brief Garantir que se leu com sucesso o byte 1 do array.
 *
 * 	Temos que verificar se o primeiro byte tem sempre o bit 3 a 1.
 *	Caso o byte seja lido com sucesso incrementa-se o indice para nao proxima chamada
 *	se ler o proximo byte.
 *
 *	@param packet_info o local da informacao que queremos ler.
 *	@param index o indice do byte do array.
 *	@param limite o numero de vezes que ja foi lido um pacote.
 * @return 0 se lemos com sucesso um byte, -1 em caso de insucesso.
 */
int mouse_handler(long int *packet_info, int *limite, int *index);

/**
 * @brief Garantir que o o primeiro byte tem sempre o bit 3 e 7 a 0
 *
 *	Caso o bit 3 ou 7 seja 1 saimos da funcao para voltar a ler para o 1 byte do array.
 *	Se tivermos lido o primeiro byte com sucesso e o bit 3 e 1, preparar para ler o proximo.
 *
 *	@param packet_info o local onde esta a informacao que queremos verificar.
 *	@param limite indice do numero de pacotes que queriamos ler na funcao principal.
 *	@param index indice do preenchimento do array (packet_info).
 * 	@return 0 em caso de sucesso e -1 em caso de insucesso
 */

int aux_config(long int *packet_info, int *limite, int *index);

/**
 * @brief Caso o array esteja "cheio" faz o display das suas caracteristicas
 *
 *	Se o array estiver cheio, "limpasse o array", aumentar o contador (limite) e fazer o seu display.
 *
 *	@param packet_info o local onde esta a informacao que queremos verificar.
 *	@param limite para verificar se ja lemos todos os packets que queriamos como argumento.
 *	@param index indice do preenchimento do array (packet_info).
 * 	@return 0 se o packet_info estiver cheio, -1 se nao estiver.
 */
int test_aux_status(long int *packet_info, int *limite, int *index);

/**
 * @brief Faz o display dos 3 bytes do packet e de toda a informacao la contida.
 *
 *	Mostra se o botao do lado direito, do meio ou esquerdo estao pressionados.
 *	Mostra se o rato esta em escala 1:1 ou 2:1. Mostra tambem se o Data reporting esta ativo
 *	ou desativo e se está em Stream mode ou remote mode.
 *	@param packet_info o local onde esta a informacao que queremos mostrar.
 * 	@return void.
 */
void show_status(long int *packet_info);

/**
 * @brief Atualiza as variaveis globais x e y se o botao do lado direito estiver pressionado
 * 		Com as novas coordenadas.
 *
 *	@param packet_info o local onde esta a informacao que queremos testar.
 * 	@return void.
 */
void test_moviment(long int *packet_info);

#endif 	
