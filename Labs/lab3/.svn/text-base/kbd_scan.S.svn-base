#include "i8042.h"

.global _kbd_scan_asm


.text
_kbd_scan_asm:

a:	movl $STAT_REG, %ebx  // Passa STAT_REG para registo
	mov 0xFF, %al    // METE AL A 1111
	and %bl,%al     // METE BL REGISTO DE STAT_REG
	and $OBF,%al    // VERIFICACAO AND
	cmp  $OBF,%al    // COMPARA OBF COM (ebx & OBF)
	jnz b            // Se nao for igual salta para ciclo
	movl $OUT_BUF, %edx   // Move para edx o OUT_BUF
	mov 0X00, %ah           // METE o ah a 00000000
	or $PARITY,%ah			// Mete em ah o PARITY
	or $TIMEOUT, %ah		// Faz OU logico com PARITY
	and %bl, %ah			// ebx & (PARITY|TIMEOUT))
	cmp  0, %ah				// Compara com 0
	jz final				// Salta final
b: loop a
final: xor %eax, %eax		// Limpa variavel 0
	mov %dl, %al			// Passa o comando para al para devolver da funcao

ret
