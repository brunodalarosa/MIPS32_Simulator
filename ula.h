/* Header da ULA                          */
/* Autor Bruno Cesar, bcesar.g6@gmail.com */

#ifndef __ULA_H
#define __ULA_H

#include <stdarg.h>
#include "processador.h"
#include "simulador.h"
#include "utils.h"
#include "cache.h"

unsigned int sll(int num, ...);
unsigned int srl(int num, ...);
unsigned int sra(int num, ...);
unsigned int sllv(int num, ...);
unsigned int srlv(int num, ...);
unsigned int srav(int num, ...);
unsigned int movz(int num, ...);
unsigned int movn(int num, ...);
unsigned int tnei(int num, ...);
unsigned int mfhi(int num, ...);
unsigned int mthi(int num, ...);
unsigned int mflo(int num, ...);
unsigned int mtlo(int num, ...);
unsigned int mult(int num, ...);
unsigned int multu(int num, ...);
unsigned int div_(int num, ...);
unsigned int divu(int num, ...);
unsigned int add(int num, ...);
unsigned int addu(int num, ...);
unsigned int sub(int num, ...);
unsigned int subu(int num, ...);
unsigned int and(int num, ...);
unsigned int or(int num, ...);
unsigned int xor(int num, ...);
unsigned int nor(int num, ...);
unsigned int slt(int num, ...);
unsigned int sltu(int num, ...);
unsigned int tge(int num, ...);
unsigned int tgeu(int num, ...);
unsigned int tlt(int num, ...);
unsigned int tltu(int num, ...);
unsigned int teq(int num, ...);
unsigned int tne(int num, ...);
unsigned int jr(int num, ...);
unsigned int jalr(int num, ...);
unsigned int bltz(int num, ...);
unsigned int bgez(int num, ...);
unsigned int tgei(int num, ...);
unsigned int tgeiu(int num, ...);
unsigned int tlti(int num, ...);
unsigned int tltiu(int num, ...);
unsigned int teqi(int num, ...);
unsigned int bltzal(int num, ...);
unsigned int bgezal(int num, ...);
unsigned int beq(int num, ...);
unsigned int bne(int num, ...);
unsigned int blez(int num, ...);
unsigned int bgtz(int num, ...);
unsigned int addi(int num, ...);
unsigned int addiu(int num, ...);
unsigned int slti(int num, ...);
unsigned int sltiu(int num, ...);
unsigned int andi(int num, ...);
unsigned int ori(int num, ...);
unsigned int xori(int num, ...);
unsigned int lui(int num, ...);
unsigned int madd(int num, ...);
unsigned int maddu(int num, ...);
unsigned int mul(int num, ...);
unsigned int msub(int num, ...);
unsigned int msubu(int num, ...);
unsigned int clo(int num, ...);
unsigned int clz(int num, ...);
unsigned int lb(int num, ...);
unsigned int lh(int num, ...);
unsigned int lwl(int num, ...);
unsigned int lw(int num, ...);
unsigned int lbu(int num, ...);
unsigned int lhu(int num, ...);
unsigned int lwr(int num, ...);
unsigned int sb(int num, ...);
unsigned int sh(int num, ...);
unsigned int swl(int num, ...);
unsigned int sw(int num, ...);
unsigned int swr(int num, ...);
unsigned int ll(int num, ...);
unsigned int sc(int num, ...);

unsigned int (*p[80]) (int num, ...); //Vetor de ponteiros para funções

void ulaInit();

#endif /* __ULA_H */
