#ifndef MACROS_H_
#define MACROS_H_

//--------- BITS ----------

#define BIT(n)	(0x01<<(n)) /**< @brief bit n a 1 */
//________________________

//--------- Barra ----------

#define BARRA_X_I	96 /**< @brief Posicao x da barra */
#define BARRA_Y_I 	618 /**< @brief Posicao y da barra */

#define SENSIBILIDADE_BARRA	6 /**< @brief Sensibilidade da barra */

#define T_BARRA_MAX_V	618 /**< @brief Tamanho maximo da barra na vertical */
#define T_BARRA_MAX_H	924 /**< @brief Tamanha maximo da barra na horizontal */
//__________________________


//-------- Coordenadas ---------

#define J_X	31	/**< @brief Coordenada x do ninja */
#define J_Y	554 /**< @brief Coordenada y do ninja */
#define P_X	0	/**< @brief Coordenada x da plataforma */
#define P_Y	618 /**< @brief Coordenada y da plataforma */
#define P_MOV_NOVA		30 /**< @brief Quantidade de movimento na aparicao da nova plataforma */
#define P_MOV_ANTIGA	50 /**< @brief Quantidade de movimento da plataforma no deslocamento da plataforma a que o ninja chegou */
//_____________________________


//-------- Plataformas ---------
#define PLAT0	20  /**< @brief Tamanho da plataforma 0 */
#define PLAT1	30 /**< @brief Tamanho da plataforma 1 */
#define PLAT2	40 /**< @brief Tamanho da plataforma 2 */
#define PLAT3	50 /**< @brief Tamanho da plataforma 3 */
#define PLAT4	60 /**< @brief Tamanho da plataforma 4 */
#define PLAT5	70 /**< @brief Tamanho da plataforma 5 */
#define PLAT6	100 /**< @brief Tamanho da plataforma 6 */
#define PLAT7	130 /**< @brief Tamanho da plataforma 7 */
#define PLAT8	150 /**< @brief Tamanho da plataforma 8 */
#define LIMITE_I	100 /**< @brief Limite inferior onde uma plataforma aparece */
#define LIMITE_S	874 /**< @brief Limite superior onde uma plataforma aparece */
//___________________________________________


//---------- BMP dos Jogadores ------------

#define MOV_V	3	 /**< @brief Quanto maior o numero, mais lento parece o andar no jogador */
#define JOG_MOV 8	/**< @brief Pixeis que move */
#define JOG_L	65	/**< @brief Largura do jogador */
#define VEL_QUEDA	20  /**< @brief Velocidade da queda do jogador quando perde */
//_________________________________________


//---------- BMP dos Fundos ------------

// Velocidade de fundo
#define ERVA_VEL	4 /**< @brief Velocidade das ervas */
#define NUVENS_VEL	1 /**< @brief Velocidade das nuvens */

// Tamanho dos fundos (horizontal)
#define ERVA_H		2048 /**< @brief Tamanho das ervas */
#define NUVENS_H	4096 /**< @brief tamanho das nuvens */

// Limites de reset (coord x) dos atualizadores das imagens de fundo
#define ERVA_R		1024 /**< @brief Limite de reset (coord x) das ervas */
#define NUVENS_R	3072 /**< @brief Limite de reset (coord x) das nuvens */
//_____________________________________


//----------- BMP -------------

#define BMP_ASSINATURA 0x4D42 /**< @brief Assinatura do BMP */
//_____________________________


//---------- Video -------------
/* Constants for VBE */
/* The physical address may vary from VM to VM.
 * At one time it was 0xD0000000
 *  #define VRAM_PHYS_ADDR    0xD0000000
 * Currently on lab B107 is 0xF0000000
 * Better run my version of lab5 as follows:
 * service run `pwd`/lab5 -args "mode 0x105"
 */
#define VRAM_PHYS_ADDR	0xE0000000 /**< @brief Posicao de memoria da VRAM */
#define H_RES	1024 /**< @brief Resolucao horizontal */
#define V_RES	768 /**< @brief Resolucao vertical */
#define BITS_PER_PIXEL	16 /**< @brief Bits por pixel */
#define BYTES_PER_PIXEL	2 /**< @brief Bytes por pixel */

static unsigned char *video_mem;	/* Process address to which VRAM is mapped */
//_______________________________


//--------- Keyboard ----------
#define KBD_IRQ	1	/**< @brief Keyboard IRQ line */
#define MAKECODE_I 	0X01 /**< @brief Makecode do ESC */
#define BREAKCODE_I 0X81 /**< @brief Breakcode do ESC */
#define UP_W		0x11 /**< @brief Makecode do W */
#define UP_W_R		0x91 /**< @brief Breakcode do W */
#define DOWN_S		0x1f /**< @brief Breakcode do S */
#define ENTER		0x1c /**< @brief Breakcode do Enter */
#define ESPACO		0x39 /**< @brief Makecode do Espaco */
#define ESPACO_R	0xb9 /**< @brief Breakcode do Espaco */

#define STAT_REG    0x64 /**< @brief Posicao Registo de estado */
#define OBF BIT(0) /**< @brief Bit 0 do outpub buffer a 1*/
#define OUT_BUF 0X60 /**< @brief Posicao Output Buffer */
#define DELAY_US 20000 /**< @brief Tempo para delay */
#define PARITY BIT(7) /**< @brief Bit de paridade */
#define TIMEOUT BIT(6) /**< @brief Bit de timeout */
//__________________________


//---------- Timer ----------
static int contador; /**< @brief Contador do timer */

#define TIMER0_IRQ	0 /**< @brief Timer IRQ line */



#define TIMER_0			0x40 /**< @brief Timer 0 count register */
#define TIMER_1			0x41 /**< @brief Timer 1 count register */
#define TIMER_2			0x42 /**< @brief Timer 2 count register */
#define TIMER_CTRL		0x43 /**< @brief Control register */

#define TIMER_SEL0		0x00     /**< @brief Control Word for Timer 0 */
#define TIMER_SEL1		BIT(6)   /**< @brief Control Word for Timer 1 */
#define TIMER_SEL2		BIT(7)   /**< @brief Control Word for Timer 2 */
#define TIMER_RB_CMD		(BIT(7)|BIT(6))  /**< @brief Comando Read Back */

#define TIMER_FREQ  1193182    /**< @brief frequencia do clock para o timer no PC e AT */

#define TIMER_LSB		BIT(4)  /**< @brief Inicializa apenas o contador LSB */
#define TIMER_MSB		BIT(5)  /**< @brief Inicializa apenas o contador MSB */
#define TIMER_LSB_MSB		(TIMER_LSB | TIMER_MSB) /**< @brief Inicializa o LSB primeiro e depois o MSB */

#define TIMER_SQR_WAVE		(BIT(2)|BIT(1)) /**< @brief Modo 3: gerador square wave */

#define TIMER_BIN			0x00   /**< @brief Conta em binario */

#define TIMER_RB_SEL(n)         BIT((n)+1) /**< @brief bit (n+1) a 1 */

//__________________________


//------------ Mouse -------------
#define RATO_H	10 /**< @brief Tamanho horizontal do rato */
#define RATO_V	10 /**< @brief Tamanho vertical do rato */

#define KBCMOUSE 0xD4 /**< @brief Endereco do KBCMouse */
#define ACK 0xFA /**< @brief Se esta tudo bem o controlador do rato envia ACK */
#define NACK 0xF3 /**< @brief Se ha um byte invalido o controlador do rato envia ACK */
#define ERROR 0xFC /**< @brief Erro. Segundo byte invalido consecutivo */
#define IRQ_MOUSE 12 /**< @brief Linha do IRQ do rato */
#define RESET_CMD 0xFF /**< @brief Resetar o rato */
#define RESEND_CMD 0xFE/**< @brief Reenviar o comando para erros decomunicacoes serial */
#define DEFAULT 0xF6 /**< @brief Colocar o KBC de volta ao normal */
#define DIS_DATA_REP 0xF5 /**< @brief Desativa o modo de stream */
#define EN_SEND_DATA 0xF4 /**< @brief Permitir o envio de informacao */
#define SET_SAMPLE_RATE 0xF3 /**< @brief Colocar o estado numa taxa de amostra */
#define REMOTE_MODE 0xF0 /**< @brief Ativar o remote mode */
#define READ_DATA 0xEB /**< @brief Ler informacao */
#define SET_STREAM_MODE 0xEA /**< @brief Colocar o KBC em stream mode */
#define STATUS_REQ 0xE9 /**< @brief Pedir o estado do KBC */
#define SET_RES 0xE8 /**< @brief Colocar resolucao */
#define SET_SCA2 0xE7 /**< @brief Modo de aceleracao. Escala 2:1 */
#define SET_SCA1 0xE6/**< @brief Modo linear. Escala 1:1 */
#define IN_BUF 0x64 /**< @brief Posicao do Input Buffer */
#define IBF BIT(1) /**< @brief Bit 2 do input buffer a 1 */
//____________________________


//------------ RTC ---------------

#define RTC_ADDR_REG		0x70 /**< @brief Endereco do registo do RTC*/
#define RTC_DATA_REG		0x71 /**< @brief Endereco do registo de informacao do RTC*/
#define IRQ_RTC	    		8 /**< @brief Linha do IRQ do RTC*/
#define RTC_REG_SECONDS		0 /**< @brief Registo dos segundos do RTC*/
#define RTC_REG_MINUTES		2 /**< @brief Registo dos minutos do RTC*/
#define RTC_REG_HOURS		4 /**< @brief Registo das horas do RTC*/
#define RTC_REG_A  			10 /**< @brief Registo A do RTC*/
#define RTC_REG_B  			11 /**< @brief Registo B do RTC*/
#define RTC_REG_C  			12 /**< @brief Registo C do RTC*/
#define RTC_REG_D  			13 /**< @brief Registo D do RTC*/
#define RTC_BCD_TO_BINARY 	BIT(2) /**< @brief Bit 3 a 1 para alterar para binario*/
//______________________________


#endif
