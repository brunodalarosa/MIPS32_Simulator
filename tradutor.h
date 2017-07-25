/* Define a estrutura de arvore de instrucoes usada no tradutor */
/* Bruno, bcesar.g6@gmail.com */

/*          Tabela - Tipos de instruções             */
/* R  [1] : op(6)|rs(5)|rt(5)|rd(5)|shamt(5)|func(6) */
/* I  [2] : op(6)|rs(5)|rt(5)|imm(16)                */
/* J  [4] : op(6)|target(26)                         */


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
int val_count;
int local_var_count;
char** var_names;
int *aux_val_count;
unsigned int* var_adress;
int var_tam; //var_tamanho inicial do vetor de variaveis

int line;
typedef struct node_t* node;
typedef struct list_t* list;

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

struct list_t{
    int valor;
    list prox;
} list_t;

list valores;
list* var_values;

void checkSizes(void);
void insereLista(node n);
void insereListaValores(list t);
int labelMatch(char* label);
void tradutor();
void tradutorInit();

#endif /* __TRADUTOR_H  */
