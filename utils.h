/* Header utlils */
/* Autor: Bruno Cesar, bcesar.g6@gmail.com */

#ifndef __UTILS_H
#define __UTILS_H

#include "simulador.h"
#include "memoria.h"
#include "processador.h"
#include "registradores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLAG_NULL 0
#define INT_MAX 4294967296

#define SLL    1
#define SRL    2
#define SRA    3
#define SLLV   4
#define SRLV   5
#define SRAV   6
#define MOVZ   7
#define MOVN   8
#define TNEI   9
#define MFHI   10
#define MTHI   11
#define MFLO   12
#define MTLO   13
#define MULT   14
#define MULTU  15
#define DIV    16
#define DIVU   17
#define ADD    18
#define ADDU   19
#define SUB    20
#define SUBU   21
#define AND    22
#define OR     23
#define XOR    24
#define NOR    25
#define SLT    26
#define SLTU   27
#define TGE    28
#define TGEU   29
#define TLT    30
#define TLTU   31
#define TEQ    32
#define TNE    33
#define JR     34
#define JALR   35
#define BLTZ   36
#define BGEZ   37
#define TGEI   38
#define TGEIU  39
#define TLTI   40
#define TLTIU  41
#define TEQI   42
#define BLTZAL 43
#define BGEZAL 44
//#define J     X / Não precisa ser definido por é lidado como uma função de controle
//#define JAL   X / same as up
#define BEQ    45
#define BNE    46
#define BLEZ   47
#define BGTZ   48
#define ADDI   49
#define ADDIU  50
#define SLTI   51
#define SLTIU  52
#define ANDI   53
#define ORI    54
#define XORI   55
#define LUI    56
#define MADD   57
#define MADDU  58
#define MUL    59
#define MSUB   60
#define MSUBU  61
#define CLO    62
#define CLZ    63
#define LB     64
#define LH     65
#define LWL    66
#define LW     67
#define LBU    68
#define LHU    69
#define LWR    70
#define SB     71
#define SH     72
#define SWL    73
#define SW     74
#define SWR    75
#define LL     76
#define SC     77

typedef struct{
    int cycles;
    int op;
    int er_type;
} operation;

extern char* ER_nomes[NUM_ER];
extern char* REG_nomes[NUM_REGS];


void pause();
void launchError(int e);
void ajuda();
void readProgram();
void printMem();
void printaBinario(word w, char isFile, FILE* dest);
void printaInstrucao(inst instruction);

void insereFila(inst instruction);
inst* pegaDaFila(int remover);
void printaFila();
void printaBloco(word w, unsigned int tam);

operation getOp(inst instruction);
void casosEspeciais(int op, estacao_reserva* er);
int identificaER(estacao_reserva* er);
int identificaREG(unsigned int er_id);
void printaER(estacao_reserva* er, char isFile, FILE* dest);
void printaRegs(char isFile, FILE* dest);
int prompt();

#endif /* __UTILS_H */
