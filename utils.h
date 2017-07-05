/* Header utlils */
/* Autor: Bruno Cesar, bcesar.g6@gmail.com */

#ifndef __UTILS_H
#define __UTILS_H

#include "simulador.h"

void pause();
void launchError(int e);
void ajuda();
void readProgram();
void printMem();
void printaBinario(word w, char isFile, FILE* dest);

#endif
