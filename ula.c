/* Unidade Lógica Aritmética do simulador MIPS 32 */
/* Autor Bruno Cesar, bcesar.g6@gmail.com         */

#include "ula.h"

void ulaInit(){

    p[0] = NULL;
    p[SLL]   = sll;
    p[SRL]   = srl;
    p[SRA]   = sra;
    p[SLLV]  = sllv;
    p[SRLV]  = srlv;
    p[SRAV]  = srav;
    p[MOVZ]  =  movz;
    p[MOVN]  =  movn;
    p[TNEI]  = tnei;
    p[MFHI]  = mfhi;
    p[MTHI]  = mthi;
    p[MFLO]  = mflo;
    p[MTLO]  = mtlo;
    p[MULT]  = mult;
    p[MULTU] = multu;
    p[DIV]   = div_;
    p[DIVU]  = divu;
    p[ADD]   = add;
    p[ADDU]  = addu;
    p[SUB]   = sub;
    p[SUBU]  = subu;
    p[AND]   = and;
    p[OR]    = or;
    p[XOR]   = xor;
    p[NOR]   = nor;
    p[SLT]   = slt;
    p[SLTU]  = sltu;
    p[TGE]   = tge;
    p[TGEU]  = tgeu;
    p[TLT]   = tlt;
    p[TLTU]  = tltu;
    p[TEQ]   = teq;
    p[TNE]   = tne;
    p[JR]    = jr;
    p[JALR]  = jalr;
    p[BLTZ]  = bltz;
    p[BGEZ]  = bgez;
    p[TGEI]  = tgei;
    p[TGEIU] = tgeiu;
    p[TLTI]  = tlti;
    p[TLTIU] = tltiu;
    p[TEQI]  = teqi;
    p[BLTZAL] = bltzal;
    p[BGEZAL] = bgezal;
    p[BEQ]   = beq;
    p[BNE]   = bne;
    p[BLEZ]  = blez;
    p[BGTZ]  = bgtz;
    p[ADDI]  = addi;
    p[ADDIU] = addiu;
    p[SLTI]  = slti;
    p[SLTIU] = sltiu;
    p[ANDI]  = andi;
    p[ORI]   = ori;
    p[XORI]  = xori;
    p[LUI]   = lui;
    p[MADD]  = madd;
    p[MADDU] = maddu;
    p[MUL]   = mul;
    p[MSUB]  = msub;
    p[MSUBU] = msubu;
    p[CLO]   = clo;
    p[CLZ]   = clz;
    p[LB]    = lb;
    p[LH]    = lh;
    p[LWL]   = lwl;
    p[LW]    = lw;
    p[LBU]   = lbu;
    p[LHU]   = lhu;
    p[LWR]   = lwr;
    p[SB]    = sb;
    p[SH]    = sh;
    p[SWL]   = swl;
    p[SW]    = sw;
    p[SWR]   = swr;
    p[LL]    = ll;
    p[SC]    = sc;

}

unsigned int sll(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int); //rs
    operando1 = va_arg(args, unsigned int); //rt
    unsigned int operando2 = va_arg(args, unsigned int); //shift amount

    unsigned int resultado = operando1 << operando2;
    if(get_flag(FLAG_DEBUG)) printf("Shift a esquerda: %d << %d = %d \n", operando1, operando2, resultado );

    va_end(args);

    return resultado;
}

unsigned int srl(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int); //rs
    operando1 = va_arg(args, unsigned int); //rt
    unsigned int operando2 = va_arg(args, unsigned int); //shift amount

    unsigned int resultado = operando1 >> operando2;
    if(get_flag(FLAG_DEBUG)) printf("Shift a direita: %d >> %d = %d \n", operando1, operando2, resultado );

    va_end(args);

    return resultado;
}

unsigned int sra(int num, ...){
    va_list args;
    va_start(args, num);
    int operando1 = va_arg(args, int); //rs
    operando1 = va_arg(args, int); //rt
    unsigned int operando2 = va_arg(args, unsigned int); //shift amount

    int aux = operando1 & INT_MAX;
    int resultado = operando1 >> operando2;

    //TODO checar se ta certo

    if(get_flag(FLAG_DEBUG)) printf("Shift aritmético a direita: %d >> %d = %d \n", operando1, operando2, resultado);

    va_end(args);

    return (unsigned int) resultado;
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

unsigned int beq(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    unsigned int operando2 = va_arg(args, unsigned int);
    unsigned int offset = va_arg(args, unsigned int);

    if(operando1 == operando2){
        pc = offset;
        if(get_flag(FLAG_DEBUG)) printf("\nSalto condicional ocorreu : PC = %d\n", offset );
    } else {
        if(get_flag(FLAG_DEBUG)) printf("\nSalto condicional não ocorreu. %d != %d\n ", operando1 , operando2 );
    }

    jump = 0; //Reseta o controle de salto

    va_end(args);
    return 0;
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
    unsigned int arg1 = va_arg(args, unsigned int);

    endereco addr;
    addr.i = arg1;

    unsigned int dado = cRead(CACHE_DADOS, addr);

    va_end(args);

    return dado;
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
