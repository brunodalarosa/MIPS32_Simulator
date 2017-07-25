/* Header memoria                          */
/* Autor: Bruno Cesar, bcesar.g6@gmail.com */

#ifndef __MEMORIA_H
#define __MEMORIA_H

#include <stdlib.h>
#include <stdio.h>
#include "memoria.h"
#include "simulador.h"
#include "utils.h"
#include "processador.h"

#define CELL 1
#define WORD 4
#define MEM_SIZE 536870912 //512MB
#define MAX_WORDS 16777216
#define TEXT_SIZE 67108864 //64MB
#define STATIC_DATA_SIZE 400

/* Ponteiro global para memoria */
char* mem;

/* Ponteiro para o fim do texto */
char* mem_text_end;

void read(word w, unsigned int adress, unsigned int size);

void write(unsigned int adress, word w, unsigned int size);

#endif /* __MEMORIA_H */
