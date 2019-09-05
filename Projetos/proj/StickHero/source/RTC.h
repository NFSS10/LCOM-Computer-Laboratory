#ifndef __RTC_H
#define __RTC_H

#include <minix/syslib.h>
#include <minix/drivers.h>
#include <minix/com.h>
#include <minix/sysutil.h>
#include "macros.h"

static int hook_id = IRQ_RTC;

/**
 * @brief Subescreve e ativa as interrupcoes do RTC.
 *
 * @return retorna -1 em caso de erro e 0 em caso de sucesso.
 */
int rtc_subscribe_int(void);

/**
 * @brief Desubescreve as interrupcoes do RTC
 *
 * @return retorna -1 em caso de erro e 0 em caso de sucesso.
 */
int rtc_unsubscribe_int();

/**
 * @brief Altera o RTC de BCD para Binario.
 *
 * @return 0, sempre sucesso.
 */
int rtc_write_bcd_to_binary();

#endif
