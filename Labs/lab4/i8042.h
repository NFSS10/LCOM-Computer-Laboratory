#ifndef _I8042_H_
#define _I8042_H_

#define KBD_IRQ        1        /**< @brief Keyboard IRQ line */
#define MAKECODE_I 0X01
#define BREAKCODE_I 0X81
#define BIT(n) (0x01<<(n))
#define STAT_REG    0x64
#define KBC_CMD_REG 0x64
#define DELAY_US 20000
#define OUT_BUF 0X60
#define PARITY BIT(7)
#define TIMEOUT BIT(6)
#define OBF BIT(0)
#define SET_LEDS 0xED
#define RESEND 0xFE //the latest byte should be written again
#define ERROR 0xFC //the entire sequence should be restarted

//Mouse
#define KBCMOUSE 0xD4
#define ACK 0xFA
#define NACK 0xF3
#define ERROR 0xFC
#define IRQ_MOUSE 12
#define RESET_CMD 0xFF
#define RESEND_CMD 0xFE
#define DEFAULT 0xF6
#define DIS_DATA_REP 0xF5
#define EN_SEND_DATA 0xF4
#define SET_SAMPLE_RATE 0xF3
#define REMOTE_MODE 0xF0
#define READ_DATA 0xEB
#define SET_STREAM_MODE 0xEA
#define STATUS_REQ 0xE9
#define SET_RES 0xE8
#define SET_SCA2 0xE7
#define SET_SCA1 0xE6
#define IN_BUF 0x64
#define IBF BIT(1)


#endif // _LCOM_I8042_H
