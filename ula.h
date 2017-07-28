/* Header da ULA                          */
/* Autor Bruno Cesar, bcesar.g6@gmail.com */

#ifndef __ULA_H
#define __ULA_H

#include <stdarg.h>
#include "processador.h"
#include "simulador.h"
#include "utils.h"
#include "cache.h"
#include "registradores.h"

#define FLAG_FAIL       0
#define FLAG_SUCCESS    1
#define FLAG_NO_RETURN  2
#define FLAG_MTHI       4
#define FLAG_MTLO       8
#define FLAG_MUL_OP     16

typedef struct{
    unsigned int resultado;
    int flag;
} ulaRet;

ulaRet sll(int num, ...);
ulaRet srl(int num, ...);
ulaRet sra(int num, ...);
ulaRet sllv(int num, ...);
ulaRet srlv(int num, ...);
ulaRet srav(int num, ...);
ulaRet movz(int num, ...);
ulaRet movn(int num, ...);
ulaRet mfhi(int num, ...);
ulaRet mthi(int num, ...);
ulaRet mflo(int num, ...);
ulaRet mtlo(int num, ...);
ulaRet mult(int num, ...);
ulaRet multu(int num, ...);
ulaRet div_(int num, ...);
ulaRet divu(int num, ...);
ulaRet add(int num, ...);
ulaRet addu(int num, ...);
ulaRet sub(int num, ...);
ulaRet subu(int num, ...);
ulaRet and(int num, ...);
ulaRet or(int num, ...);
ulaRet xor(int num, ...);
ulaRet nor(int num, ...);
ulaRet slt(int num, ...);
ulaRet sltu(int num, ...);
ulaRet jr(int num, ...);
ulaRet jalr(int num, ...);
ulaRet bltz(int num, ...);
ulaRet bgez(int num, ...);
ulaRet bltzal(int num, ...);
ulaRet bgezal(int num, ...);
ulaRet beq(int num, ...);
ulaRet bne(int num, ...);
ulaRet blez(int num, ...);
ulaRet bgtz(int num, ...);
ulaRet addi(int num, ...);
ulaRet addiu(int num, ...);
ulaRet slti(int num, ...);
ulaRet sltiu(int num, ...);
ulaRet andi(int num, ...);
ulaRet ori(int num, ...);
ulaRet xori(int num, ...);
ulaRet lui(int num, ...);
ulaRet madd(int num, ...);
ulaRet maddu(int num, ...);
ulaRet mul(int num, ...);
ulaRet msub(int num, ...);
ulaRet msubu(int num, ...);
ulaRet clo(int num, ...);
ulaRet clz(int num, ...);
ulaRet lb(int num, ...);
ulaRet lh(int num, ...);
ulaRet lwl(int num, ...);
ulaRet lw(int num, ...);
ulaRet lbu(int num, ...);
ulaRet lhu(int num, ...);
ulaRet lwr(int num, ...);
ulaRet sb(int num, ...);
ulaRet sh(int num, ...);
ulaRet swl(int num, ...);
ulaRet sw(int num, ...);
ulaRet swr(int num, ...);
ulaRet ll(int num, ...);
ulaRet sc(int num, ...);

ulaRet (*p[80]) (int num, ...); //Vetor de ponteiros para funções

void ulaInit();

#endif /* __ULA_H */
