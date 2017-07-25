/* Memoria do simulador MIPS32             */
/* Autor: Bruno Cesar, bcesar.g6@gmail.com */

#include "memoria.h"

/* Lê [size]Bytes da memória começando da posição[adress] e copia estes dados para [w] */
void read(word w, unsigned int adress, unsigned int size){
    memcpy(w, mem + adress, size);
}

/* Escreve [size]Bytes de [w] na memória começando da posição[adress] */
void write(unsigned int adress, word w, unsigned int size){
    memcpy(mem+adress, w, size);
}
