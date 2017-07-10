/* Memoria do simulador MIPS32             */
/* Autor: Bruno Cesar, bcesar.g6@gmail.com */

#include "memoria.h"


void read(word w, char adress, int size){
    memcpy(w, mem + adress,  size * 4);
}

void write(word words, char* adress, int size){

}
