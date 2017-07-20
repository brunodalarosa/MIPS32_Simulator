/* Define a estrutura de arvore de instrucoes usada no tradutor */
/* Bruno, bcesar.g6@gmail.com */

/*          Tabela - Tipos de instruções             */
/* R  [1] : op(6)|rs(5)|rt(5)|rd(5)|shamt(5)|func(6) */
/* I  [2] : op(6)|rs(5)|rt(5)|imm(16)                */
/* J  [4] : op(6)|target(26)                         */
/* M  [6] : op(6)|rs(5)|rd+rt+aux(15)|func(6)        */
/* MS [7] : op(6)|rs(5)|rt(5)|rd(5)|func(11)         */
/* B  [8] : op(6)|rs(5)|aux(5)|offset(16)            */


#ifndef __TRADUTOR_H
#define __TRADUTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "parser.h"
#include "simulador.h"
#include "utils.h"
#include "processador.h"

#define DATA_OFFSET 400
#define INST_SIZE 4

int lbl_count;
char** lbl_names;
unsigned int* lbl_values;
int lbl_tam;

int var_count;
char** var_names;
unsigned int* var_adress;
unsigned int* var_values;
int var_tam; //var_tamanho inicial do vetor de variaveis

int line;
typedef struct node_t* node;

struct node_t{
    unsigned int tipo;
    unsigned int op;
    unsigned int rs;
    unsigned int rt;
    unsigned int rd;
    unsigned int func;
    unsigned int aux; //shift amount | imm | address | offset
    char* label;
    node prox;
} node_t;

node lista;

void checkSizes(void);
void insereLista(node n);
int labelMatch(char* label);
void tradutor();
void tradutorInit();

#endif /* __TRADUTOR_H  */
