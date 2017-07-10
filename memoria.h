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
#define MEM_SIZE 536870912
#define MAX_WORDS 134217728
#define TEXT_SIZE 8388608
#define STATIC_DATA_SIZE 400

/* Ponteiro global para memoria */
char* mem;

/* Ponteiro para o fim do texto */
char* mem_text_end;

void read(word w, char adress, int size);

void write(word words, char* adress, int size);

#endif
