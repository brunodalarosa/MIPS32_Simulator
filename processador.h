/* Header Processador                      */
/* Autor: Bruno Cesar, bcesar.g6@gmail.com */

#ifndef __PROCESSADOR_H
#define __PROCESSADOR_H

#include <stdio.h>
#include <stdlib.h>
#include "memoria.h"
#include "simulador.h"
#include "utils.h"

static unsigned int pc = 0; // Program counter

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
    unsigned int op     : 6;
    unsigned int target : 26;
} inst_J;

/* União de diferentes tipos de instrução, generaliza a instrução */
typedef union Inst {
    inst_R R;
    inst_I I;
    inst_J J;
} inst;


/* Estações de reserva */
typedef struct{
    unsigned int busy : 1;
    unsigned int op   : 6;
    unsigned int vj   : 16; //checar
    unsigned int vk   : 16; //checar
    unsigned int qj   : 16; //checar
    unsigned int qk   : 16; //checar
    unsigned int A    : 16; //checar
} estacao_reserva;

estacao_reserva er_load1;
estacao_reserva er_load2;
estacao_reserva er_add1;
estacao_reserva er_add2;
estacao_reserva er_add3;
estacao_reserva er_mult1;
estacao_reserva er_mult2;

void pipeline();
void processadorInit();

#endif
