#Makefile do simulador

.PHONY: clean tar

CC = gcc

CFLAGS = -I. -Wall -c

LFLAGS = -I. -Wall -lfl

DEPS = utils.h parser.h

OBJ = simulador.o tradutor.o memoria.o utils.o processador.o cdb.o clock.o ula.o cache.o parser.tab.o lex.yy.o

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
		cdb.c cdb.h clock.c clock.h ula.c ula.h cache.c cache.h

all: simulador
