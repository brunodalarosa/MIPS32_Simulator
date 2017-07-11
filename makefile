#Makefile do simulador

.PHONY: clean tar

CC = gcc

CFLAGS = -I. -Wall -c

LFLAGS = -I. -Wall -lfl

DEPS = utils.h parser.h #Todos os .h que TODOS os .c dependem.

OBJ = simulador.o tradutor.o memoria.o utils.o processador.o cdb.o parser.tab.o lex.yy.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

simulador: $(OBJ)
	bison -d parser.y
	flex lexic.l
	$(CC) $(LFLAGS) -o simulador $^

clean:
	\rm *.o simulador log.txt log_tradutor.txt

tar:
	tar cfv simulador.tar simulador.c simulador.h utils.c utils.h lexic.l parser.y \
		memoria.c memoria.h tradutor.h tradutor.c processador.h processador.c \
		cdb.c cdb.h

all: simulador

# Versão antiga
#simulador: simulador.c tradutor.c lexic.l parser.y utils.c processador.c memoria.c
#	bison -d parser.y
#	flex lexic.l
#	cc -o $@ simulador.c processador.c memoria.c tradutor.c parser.tab.c lex.yy.c utils.c -lfl -I.
#
#clean:
#	rm ./simulador
