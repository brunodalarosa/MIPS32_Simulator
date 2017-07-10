/* Header Processador                      */
/* Autor: Bruno Cesar, bcesar.g6@gmail.com */

#ifndef __PROCESSADOR_H
#define __PROCESSADOR_H

#define ER_ADD 5 //Definir
#define ER_MUL 5 //Definir

static unsigned char pc = 0; // mudar? verificar!

/* Tipo de instruções Declaradas com bit-fields */

typedef struct{
    unsigned int op   : 6;
    unsigned int rs   : 5;
    unsigned int rt   : 5;
    unsigned int rd   : 5;
    unsigned int aux  : 5;
    unsigned int func : 6;
} inst_R;

typedef struct{
    unsigned int op  : 6;
    unsigned int rs  : 5;
    unsigned int rt  : 5;
    unsigned int imm : 16;
} inst_I;

typedef struct{
    unsigned int op   : 6;
    unsigned int rs   : 5;
    unsigned int rt   : 5;
    unsigned int aux  : 10;
    unsigned int func : 6;
} inst_D;

typedef struct{
    unsigned int op     : 6;
    unsigned int target : 26;
} inst_J;

typedef struct{
    unsigned int op    : 6;
    unsigned int rs    : 5;
    unsigned int aux   : 15;
    unsigned int func  : 6;
} inst_MT;

typedef struct{
    unsigned int op    : 6;
    unsigned int rs    : 5;
    unsigned int rt    : 5;
    unsigned int rd    : 5;
    unsigned int func  : 11;
} inst_M;

typedef struct{
    unsigned int op     : 6;
    unsigned int rs     : 5;
    unsigned int aux    : 5;
    unsigned int offset : 16;
} inst_B;

typedef union Inst {
    inst_R R;
    inst_I I;
    inst_D D;
    inst_J J;
    inst_M M;
    inst_B B;
} inst;

void pipeline();

#include <stdio.h>
#include <stdlib.h>
#include "memoria.h"
#include "simulador.h"
#include "utils.h"

#endif
