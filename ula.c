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
    p[6] = srav;
    p[7] = movz;
    p[8] = movn;
    p[9] = tnei;
    p[10] = mfhi;
    p[11] = mthi;
    p[12] = mflo;
    p[13] = mtlo;
    p[14] = mult;
    p[15] = multu;
    p[16] = div_;
    p[17] = divu;
    p[18] = add;
    p[19] = addu;
    p[20] = sub;
    p[21] = subu;
    p[22] = and;
    p[23] = or;
    p[24] = xor;
    p[25] = nor;
    p[26] = slt;
    p[27] = sltu;
    p[28] = tge;
    p[29] = tgeu;
    p[30] = tlt;
    p[31] = tltu;
    p[32] = teq;
    p[33] = tne;
    p[34] = jr;
    p[35] = jalr;
    p[36] = bltz;
    p[37] = bgez;
    p[38] = tgei;
    p[39] = tgeiu;
    p[40] = tlti;
    p[41] = tltiu;
    p[42] = teqi;
    p[43] = bltzal;
    p[44] = bgezal;
    p[45] = jmp;
    p[46] = jal;
    p[47] = beq;
    p[48] = bne;
    p[49] = blez;
    p[50] = bgtz;
    p[51] = addi;
    p[52] = addiu;
    p[53] = slti;
    p[54] = sltiu;
    p[55] = andi;
    p[56] = ori;
    p[57] = xori;
    p[58] = lui;
    p[59] = madd;
    p[60] = maddu;
    p[61] = mul;
    p[62] = msub;
    p[63] = msubu;
    p[64] = clo;
    p[65] = clz;
    p[66] = lb;
    p[67] = lh;
    p[68] = lwl;
    p[69] = lw;
    p[70] = lbu;
    p[71] = lhu;
    p[72] = lwr;
    p[73] = sb;
    p[74] = sh;
    p[75] = swl;
    p[76] = sw;
    p[77] = swr;
    p[78] = ll;
    p[79] = sc;

}

unsigned int sll(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int srl(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int sra(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int sllv(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int srlv(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SRLV BEM LOUCO\n");
    va_end(args);
}

unsigned int srav(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SRAV BEM LOUCO\n");
    va_end(args);
}


unsigned int movz(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int movn(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int tnei(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int mfhi(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int mthi(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int mflo(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int mtlo(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int mult(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int multu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int div_(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("DIV BEM LOUCO\n");
    va_end(args);
}

unsigned int divu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("DIVU BEM LOUCO\n");
    va_end(args);
}

unsigned int add(int num, ...){
    va_list args;
    va_start(args, num);

    unsigned int operando1 = va_arg(args, unsigned int);
    unsigned int operando2 = va_arg(args, unsigned int);

    unsigned int resultado = operando1 + operando2;

    printf("ADD BEM LOUCO ACONTECENDO BEM AQUI: %i + %i = %i\n",
            operando1, operando2, resultado);

    va_end(args);
    return resultado;
}

unsigned int addu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("ADDU BEM LOUCO\n");
    va_end(args);
}

unsigned int sub(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SUB BEM LOUCO\n");
    va_end(args);
}

unsigned int subu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SUBU BEM LOUCO\n");
    va_end(args);
}

unsigned int and(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int or(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int xor(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int nor(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int slt(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int sltu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int tge(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int tgeu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int tlt(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int tltu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int teq(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int tne(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int jr(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int jalr(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int bltz(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int bgez(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int tgei(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int tgeiu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int tlti(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int tltiu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int teqi(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int bltzal(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int bgezal(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int jmp(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int jal(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int beq(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int bne(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int blez(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int bgtz(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int addi(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("ADDI BEM LOUCO\n");
    va_end(args);
}

unsigned int addiu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("ADDIU BEM LOUCO\n");
    va_end(args);
}

unsigned int slti(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int sltiu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int andi(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int ori(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int xori(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int lui(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int madd(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("MADD BEM LOUCO\n");
    va_end(args);
}

unsigned int maddu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("MADDU BEM LOUCO\n");
    va_end(args);
}

unsigned int mul(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int msub(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("MSUB BEM LOUCO\n");
    va_end(args);
}

unsigned int msubu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("MSUBU BEM LOUCO\n");
    va_end(args);
}

unsigned int clo(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int clz(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int lb(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int lh(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int lwl(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int lw(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int lbu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int lhu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int lwr(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int sb(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int sh(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int swl(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int sw(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int swr(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int ll(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}

unsigned int sc(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
}
