# Makefile for the lab3 keyboard (based on that of hello).

COMPILER_TYPE= gnu

CC=gcc

PROG=	lab3
SRCS=	lab3.c kbd.c test3.c timer.c kbd_scan.S

CCFLAGS= -Wall

DPADD+=	${LIBDRIVER} ${LIBSYS}
LDADD+= -ldriver -lsys -lvt

LDFLAGS+= -L .

MAN=

.include <bsd.prog.mk>
.include <bsd.gcc.mk>