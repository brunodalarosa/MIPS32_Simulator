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
#define JR     28
#define JALR   29
#define BLTZ   30
#define BGEZ   31
#define BLTZAL 32
#define BGEZAL 33
//#define J     X / Não precisa ser definido por é lidado como uma função de controle
//#define JAL   X / same as up
#define BEQ    34
#define BNE    35
#define BLEZ   36
#define BGTZ   37
#define ADDI   38
#define ADDIU  39
#define SLTI   40
#define SLTIU  41
#define ANDI   42
#define ORI    43
#define XORI   44
#define LUI    45
#define MADD   46
#define MADDU  47
#define MUL    48
#define MSUB   49
#define MSUBU  50
#define CLO    51
#define CLZ    52
#define LB     53
#define LH     54
#define LWL    55
#define LW     56
#define LBU    57
#define LHU    58
#define LWR    59
#define SB     60
#define SH     61
#define SWL    62
#define SW     63
#define SWR    64
#define SYSCALL 65

#define NUM_OPS 65

typedef struct{
    int cycles;
    int op;
    int er_type;
} operation;

extern char* ER_nomes[NUM_ER];

extern char* REG_nomes[NUM_REGS];

extern char* OP_nomes[NUM_OPS];

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
int checaSyscall();

operation getOp(inst instruction);
void casosEspeciais(int op, estacao_reserva* er);
int identificaER(estacao_reserva* er);
estacao_reserva* getER(int er_id);
void flushEr(estacao_reserva* er);
int identificaREG(unsigned int er_id);
void printaER(estacao_reserva* er, char isFile, FILE* dest);
void printaRegs(char isFile, FILE* dest);
int prompt();

#endif /* __UTILS_H */
