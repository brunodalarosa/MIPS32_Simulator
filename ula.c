/* Unidade Lógica Aritmética do simulador MIPS 32 */
/* Autor Bruno Cesar, bcesar.g6@gmail.com         */

#include "ula.h"

void ulaInit(){

    p[0] = NULL;
    p[1] = sll;
    p[2] = srl;
    p[3] = sra;
    p[4] = sllv;
    p[5] = srlv;
    p[6] = movz;
    p[7] = movn;
    p[8] = tnei;
    p[9] = mfhi;
    p[10] = mthi;
    p[11] = mflo;
    p[12] = mtlo;
    p[13] = mult;
    p[14] = multu;
    p[15] = div_;
    p[16] = divu;
    p[17] = add;
    p[18] = addu;
    p[19] = sub;
    p[20] = subu;
    p[21] = and;
    p[22] = or;
    p[23] = xor;
    p[24] = nor;
    p[25] = slt;
    p[26] = sltu;
    p[27] = tge;
    p[28] = tgeu;
    p[29] = tlt;
    p[30] = tltu;
    p[31] = teq;
    p[32] = tne;
    p[33] = jr;
    p[34] = jalr;
    p[35] = bltz;
    p[36] = bgez;
    p[37] = tgei;
    p[38] = tgeiu;
    p[39] = tlti;
    p[40] = tltiu;
    p[41] = teqi;
    p[42] = bltzal;
    p[43] = bgezal;
    p[44] = jmp;
    p[45] = jal;
    p[46] = beq;
    p[47] = bne;
    p[48] = blez;
    p[49] = bgtz;
    p[50] = addi;
    p[51] = addiu;
    p[52] = slti;
    p[53] = sltiu;
    p[54] = andi;
    p[55] = ori;
    p[56] = xori;
    p[57] = lui;
    p[58] = madd;
    p[59] = maddu;
    p[60] = mul;
    p[61] = msub;
    p[62] = msubu;
    p[63] = clo;
    p[64] = clz;
    p[65] = lb;
    p[66] = lh;
    p[67] = lwl;
    p[68] = lw;
    p[69] = lbu;
    p[70] = lhu;
    p[71] = lwr;
    p[72] = sb;
    p[73] = sh;
    p[74] = swl;
    p[75] = sw;
    p[76] = swr;
    p[77] = ll;
    p[78] = sc;

}

void sll(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void srl(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void sra(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void sllv(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void srlv(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void movz(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void movn(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void tnei(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void mfhi(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void mthi(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void mflo(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void mtlo(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void mult(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void multu(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void div_(estacao_reserva er){
    printf("DIV BEM LOUCO\n");
}

void divu(estacao_reserva er){
    printf("DIVU BEM LOUCO\n");
}

void add(estacao_reserva er){
    printf("ADD BEM LOUCO\n");
}

void addu(estacao_reserva er){
    printf("ADDU BEM LOUCO\n");
}

void sub(estacao_reserva er){
    printf("SUB BEM LOUCO\n");
}

void subu(estacao_reserva er){
    printf("SUBU BEM LOUCO\n");
}

void and(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void or(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void xor(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void nor(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void slt(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void sltu(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void tge(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void tgeu(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void tlt(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void tltu(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void teq(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void tne(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void jr(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void jalr(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void bltz(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void bgez(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void tgei(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void tgeiu(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void tlti(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void tltiu(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void teqi(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void bltzal(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void bgezal(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void jmp(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void jal(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void beq(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void bne(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void blez(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void bgtz(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void addi(estacao_reserva er){
    printf("ADDI BEM LOUCO\n");
}

void addiu(estacao_reserva er){
    printf("ADDIU BEM LOUCO\n");
}

void slti(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void sltiu(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void andi(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void ori(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void xori(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void lui(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void madd(estacao_reserva er){
    printf("MADD BEM LOUCO\n");
}

void maddu(estacao_reserva er){
    printf("MADDU BEM LOUCO\n");
}

void mul(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void msub(estacao_reserva er){
    printf("MSUB BEM LOUCO\n");
}

void msubu(estacao_reserva er){
    printf("MSUBU BEM LOUCO\n");
}

void clo(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void clz(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void lb(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void lh(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void lwl(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void lw(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void lbu(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void lhu(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void lwr(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void sb(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void sh(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void swl(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void sw(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void swr(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void ll(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}

void sc(estacao_reserva er){
    printf("SLL BEM LOUCO\n");
}
