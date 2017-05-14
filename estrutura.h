/* Define a estrutura de arvore de instrucoes usada no tradutor */
/* Bruno, bcesar.g6@gmail.com */

/*          Tabela - Tipos de instruções          */
/* R[1] : op(6)|rs(5)|rt(5)|rd(5)|shamt(5)|func(6)*/
/* RD[2]: op(6)|rs(5)|rt(5)|imm(16)             */
/* D[3] : op(6)|rs(5)|rt(5)|aux(10)|func(6)*/
/* I[4] :*/
/**/


#ifndef __INSTRUCOES_H
#define __INSTRUCOES_H

FILE* output;
FILE* logFile;

#define DATA_OFFSET 400
#define INST_SIZE 32

int lbl_count;
char** lbl_names;
int* lbl_values;
int lbl_tam;

int var_count;
char** var_names;
int* var_adress;
int* var_values;
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

#endif
