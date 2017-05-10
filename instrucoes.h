/* Define a estrutura de arvore de instrucoes usada no tradutor */
/* Bruno, bcesar.g6@gmail.com */

#ifndef __INSTRUCOES_H
#define __INSTRUCOES_H

FILE* output;

#define DATA_OFFSET 400
#define INST_SIZE 32

static int lbl_count = 0;
char** lbl_names;
int* lbl_values;
static int lbl_tam = 10; //lbl_tamanho inicial do vetor de labels

static int var_count = 0;
char** var_names;
int* var_values;
static int var_tam = 10; //var_tamanho inicial do vetor de variaveis

static int line = 0;
typedef struct node_t* node;

struct node_t{
    int tipo;
    int op;
    int rs;
    int rt;
    int rd;
    int func;
    int aux; //shift amount | imm | address | offset
    char* label;
    node prox;
};

node arvore;

#endif
