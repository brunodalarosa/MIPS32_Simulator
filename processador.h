/* Header Processador                      */
/* Autor: Bruno Cesar, bcesar.g6@gmail.com */

#ifndef __PROCESSADOR_H
#define __PROCESSADOR_H

#define ADD_T 1 //ADD já é o nome de uma OP
#define MUL_T 2 //MUL já é o nome de uma OP
#define LOAD  3
#define STORE 4

#define ADD_1  1
#define ADD_2  2
#define ADD_3  3
#define MUL_1  4
#define MUL_2  5
#define LOAD_1 6
#define LOAD_2 7

#define NUM_ER 7

typedef union Inst inst;
typedef struct node_ti* fila_inst;
typedef struct er_t estacao_reserva;

#include <stdio.h>
#include <stdlib.h>
#include "memoria.h"
#include "simulador.h"
#include "utils.h"
#include "registradores.h"
#include "ula.h"

extern unsigned int pc; // Program counter

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
union Inst {
    inst_R R;
    inst_I I;
    inst_J J;
};

/* Estações de reserva */
struct er_t{
    unsigned int busy; //Usado também para contar a qtd de ciclos de cada Operação
    unsigned int op;
             int vj;
             int vk;
    unsigned int qj;
    unsigned int qk;
    unsigned int A;
};

estacao_reserva* er_add1;
estacao_reserva* er_add2;
estacao_reserva* er_add3;
estacao_reserva* er_mult1;
estacao_reserva* er_mult2;
estacao_reserva* er_load1;
estacao_reserva* er_load2;

unsigned int* Qi;
unsigned int* buffer_resultados;

struct node_ti{
    inst instruction;
    fila_inst next;
} node_ti;

fila_inst fila;

unsigned int pipeline(int ciclo);
void processadorInit();
estacao_reserva* checa_er(int er_type);
int emissao(inst instruction);
void decodifica();
void busca();

#endif /* __PROCESSADOR_H */
