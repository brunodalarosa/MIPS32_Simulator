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
#define MFHI   9
#define MTHI   10
#define MFLO   11
#define MTLO   12
#define MULT   13
#define MULTU  14
#define DIV    15
#define DIVU   16
#define ADD    17
#define ADDU   18
#define SUB    19
#define SUBU   20
#define AND    21
#define OR     22
#define XOR    23
#define NOR    24
#define SLT    25
#define SLTU   26
#define JR     27
#define JALR   28
#define BLTZ   29
#define BGEZ   30
#define BLTZAL 31
#define BGEZAL 32
#define BEQ    33
#define BNE    34
#define BLEZ   35
#define BGTZ   36
#define ADDI   37
#define ADDIU  38
#define SLTI   39
#define SLTIU  40
#define ANDI   41
#define ORI    42
#define XORI   43
#define LUI    44
#define MADD   45
#define MADDU  46
#define MUL    47
#define MSUB   48
#define MSUBU  49
#define CLO    50
#define CLZ    51
#define LB     52
#define LH     53
#define LW     54
#define LBU    55
#define LHU    56
#define SB     57
#define SH     58
#define SW     59
#define SYSCALL 60
#define NOPE    61

#define NUM_OPS 61

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
void flushes();
int identificaREG(unsigned int er_id);
void printaER(estacao_reserva* er, char isFile, FILE* dest);
void printaQi(unsigned int* Qi);
void printaRegs(char isFile, FILE* dest);
int prompt();

#endif /* __UTILS_H */
