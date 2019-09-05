
COMPILER_TYPE= gnu

CC=gcc

PROG=	StickHero
SRCS=	main.c BMP.c Graficos.c kbd.c Menu.c timer.c Utilidades.c Jogo.c mouse.c menufinal.c RTC.c

CCFLAGS= -Wall -O3

DPADD+=	${LIBDRIVER} ${LIBSYS}
LDADD+= -ldriver -lsys

LDFLAGS+= -L .

MAN=

.include <bsd.prog.mk>
.include <bsd.gcc.mk>
