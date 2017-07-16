/* Header utlils */
/* Autor: Bruno Cesar, bcesar.g6@gmail.com */

#ifndef __UTILS_H
#define __UTILS_H

#include "simulador.h"
#include "memoria.h"
#include "processador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLAG_NULL 0

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
#define AND    23
#define OR     24
#define XOR    25
#define NOR    26
#define SLT    27
#define SLTU   28
#define TGE    29
#define TGEU   30
#define TLT    31
#define TLTU   32
#define TEQ    33
#define TNE    34
#define JR     35
#define JALR   36
#define BLTZ   37
#define BGEZ   38
#define TGEI   39
#define TGEIU  40
#define TLTI   41
#define TLTIU  42
#define TEQI   43
#define BLTZAL 44
#define BGEZAL 45
#define JMP    46 //J não pode um caracter apenas?
#define JAL    47
#define BEQ    48
#define BNE    49
#define BLEZ   50
#define BGTZ   51
#define ADDI   52
#define ADDIU  53
#define SLTI   54
#define SLTIU  55
#define ANDI   56
#define ORI    57
#define XORI   58
#define LUI    59
#define MADD   60
#define MADDU  61
#define MUL    62
#define MSUB   63
#define MSUBU  64
#define CLO    65
#define CLZ    66
#define LB     67
#define LH     68
#define LWL    69
#define LW     70
#define LBU    71
#define LHU    72
#define LWR    73
#define SB     74
#define SH     75
#define SWL    76
#define SW     77
#define SWR    78
#define LL     79
#define SC     80

typedef struct{
    int cycles;
    int op;
    int er_type;
} operation;


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

operation getOp(inst instruction);
int identificaER(estacao_reserva* er);
void printaER(estacao_reserva* er, char isFile, FILE* dest);

#endif /* __UTILS_H */
