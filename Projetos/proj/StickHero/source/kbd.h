#ifndef KBD_H
#define KBD_H

#include <minix/syslib.h>
#include <minix/drivers.h>
#include <minix/com.h>
#include <minix/sysutil.h>
#include "macros.h"


/**
 * @brief Leitura da informacao do KBC se nao existir qualquer erro.
 *
 * @return a data do teclado em caso de sucesso e 1 em caso de insucesso.
 */
int kbd_read();

/**
 * @brief Subescreve e ativa as interrupcoes do teclado.
 *
 * @return retorna -1 em caso de erro e 0 em caso de sucesso.
 */
int kbd_subscribe_int(void);

/**
 * @brief Desubescreve as interrupcoes do teclado
 *
 * @return retorna 1 em caso de erro e 0 em caso de sucesso.
 */
int kdb_unsubscribe_int();

/**
 * @brief Le e faz print do breakcode e do makecode das teclas pressionadas do teclado.
 *
 * @return 1 no caso de insucesso e 0 no caso de sucesso.
 */
int kbd_test_scan();


#endif
