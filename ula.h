/* Header da ULA                          */
/* Autor Bruno Cesar, bcesar.g6@gmail.com */

#ifndef __ULA_H
#define __ULA_H

#include "processador.h"

void sll(estacao_reserva er);
void srl(estacao_reserva er);
void sra(estacao_reserva er);
void sllv(estacao_reserva er);
void srlv(estacao_reserva er);
void movz(estacao_reserva er);
void movn(estacao_reserva er);
void tnei(estacao_reserva er);
void mfhi(estacao_reserva er);
void mthi(estacao_reserva er);
void mflo(estacao_reserva er);
void mtlo(estacao_reserva er);
void mult(estacao_reserva er);
void multu(estacao_reserva er);
void div_(estacao_reserva er);
void divu(estacao_reserva er);
void add(estacao_reserva er);
void addu(estacao_reserva er);
void sub(estacao_reserva er);
void subu(estacao_reserva er);
void and(estacao_reserva er);
void or(estacao_reserva er);
void xor(estacao_reserva er);
void nor(estacao_reserva er);
void slt(estacao_reserva er);
void sltu(estacao_reserva er);
void tge(estacao_reserva er);
void tgeu(estacao_reserva er);
void tlt(estacao_reserva er);
void tltu(estacao_reserva er);
void teq(estacao_reserva er);
void tne(estacao_reserva er);
void jr(estacao_reserva er);
void jalr(estacao_reserva er);
void bltz(estacao_reserva er);
void bgez(estacao_reserva er);
void tgei(estacao_reserva er);
void tgeiu(estacao_reserva er);
void tlti(estacao_reserva er);
void tltiu(estacao_reserva er);
void teqi(estacao_reserva er);
void bltzal(estacao_reserva er);
void bgezal(estacao_reserva er);
void jmp(estacao_reserva er);
void jal(estacao_reserva er);
void beq(estacao_reserva er);
void bne(estacao_reserva er);
void blez(estacao_reserva er);
void bgtz(estacao_reserva er);
void addi(estacao_reserva er);
void addiu(estacao_reserva er);
void slti(estacao_reserva er);
void sltiu(estacao_reserva er);
void andi(estacao_reserva er);
void ori(estacao_reserva er);
void xori(estacao_reserva er);
void lui(estacao_reserva er);
void madd(estacao_reserva er);
void maddu(estacao_reserva er);
void mul(estacao_reserva er);
void msub(estacao_reserva er);
void msubu(estacao_reserva er);
void clo(estacao_reserva er);
void clz(estacao_reserva er);
void lb(estacao_reserva er);
void lh(estacao_reserva er);
void lwl(estacao_reserva er);
void lw(estacao_reserva er);
void lbu(estacao_reserva er);
void lhu(estacao_reserva er);
void lwr(estacao_reserva er);
void sb(estacao_reserva er);
void sh(estacao_reserva er);
void swl(estacao_reserva er);
void sw(estacao_reserva er);
void swr(estacao_reserva er);
void ll(estacao_reserva er);
void sc(estacao_reserva er);

void (*p[79]) (estacao_reserva er); //Vetor de ponteiros para funções

void ulaInit();

#endif /* __ULA_H */
