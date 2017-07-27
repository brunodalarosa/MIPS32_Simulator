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
    p[JR]    = jr;
    p[JALR]  = jalr;
    p[BLTZ]  = bltz;
    p[BGEZ]  = bgez;
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

ulaRet sll(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int); //rs
    operando1 = va_arg(args, unsigned int); //rt
    unsigned int operando2 = va_arg(args, unsigned int); //shift amount

    unsigned int resultado = operando1 << operando2;
    if(get_flag(FLAG_DEBUG)) printf("Shift a esquerda: %d << %d = %d \n", operando1, operando2, resultado );

    va_end(args);

    ulaRet retorno;
    retorno.resultado = resultado;
    retorno.flag = FLAG_SUCCESS;

    return retorno;
}

ulaRet srl(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int); //rs
    operando1 = va_arg(args, unsigned int); //rt
    unsigned int operando2 = va_arg(args, unsigned int); //shift amount

    unsigned int resultado = operando1 >> operando2;
    if(get_flag(FLAG_DEBUG)) printf("Shift a direita: %d >> %d = %d \n", operando1, operando2, resultado );

    va_end(args);

    ulaRet retorno;
    retorno.resultado = resultado;
    retorno.flag = FLAG_SUCCESS;

    return retorno;
}

ulaRet sra(int num, ...){
    va_list args;
    va_start(args, num);
    int operando1 = va_arg(args, int); //rs
    operando1 = va_arg(args, int); //rt
    unsigned int operando2 = va_arg(args, unsigned int); //shift amount

    int resultado = operando1 >> operando2;

    //TODO checar se ta certo

    if(get_flag(FLAG_DEBUG)) printf("Shift aritmético a direita: %d >> %d = %d \n", operando1, operando2, resultado);

    va_end(args);

    ulaRet retorno;
    retorno.resultado = (unsigned int) resultado;
    retorno.flag = FLAG_SUCCESS;

    return retorno;
}

ulaRet sllv(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int); //rs
    unsigned int operando2 = va_arg(args, unsigned int); //rt

    unsigned int resultado = operando1 << operando2;
    if(get_flag(FLAG_DEBUG)) printf("Shift logico a esquerda variavel: %d << %d = %d \n", operando1, operando2, resultado);

    va_end(args);

    ulaRet retorno;
    retorno.resultado = resultado;
    retorno.flag = FLAG_SUCCESS;

    return retorno;
}

ulaRet srlv(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int); //rs
    unsigned int operando2 = va_arg(args, unsigned int); //rt

    unsigned int resultado = operando1 >> operando2;

    if(get_flag(FLAG_DEBUG)) printf("Shift logico a direita variavel: %d >> %d = %d \n", operando1, operando2, resultado);

    va_end(args);

    ulaRet retorno;
    retorno.resultado = resultado;
    retorno.flag = FLAG_SUCCESS;

    return retorno;
}

ulaRet srav(int num, ...){
    va_list args;
    va_start(args, num);
    int operando1 = va_arg(args, int); //rs
    unsigned int operando2 = va_arg(args, unsigned int); //rt

    int resultado = operando1 >> operando2;

    if(get_flag(FLAG_DEBUG)) printf("Shift aritmético a direita variavel: %d >> %d = %d \n", operando1, operando2, resultado);

    va_end(args);

    ulaRet retorno;
    retorno.resultado = (unsigned int) resultado;
    retorno.flag = FLAG_SUCCESS;

    return retorno;
}


ulaRet movz(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int); //rs
    unsigned int operando2 = va_arg(args, unsigned int); //rt

    ulaRet retorno;

    if(operando2 == 0){
        retorno.resultado = operando1;
        retorno.flag = FLAG_SUCCESS;

        if(get_flag(FLAG_DEBUG)) printf("Move condicional zero: sucesso!\n");

    } else {
        retorno.flag = FLAG_FAIL;
        if(get_flag(FLAG_DEBUG)) printf("Move condicional zero: falha (%d != 0)\n", operando2);

    }

    va_end(args);

    return retorno;
}

ulaRet movn(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int); //rs
    unsigned int operando2 = va_arg(args, unsigned int); //rt

    ulaRet retorno;

    if(operando2 == 0){
        retorno.resultado = operando1;
        retorno.flag = FLAG_SUCCESS;

        if(get_flag(FLAG_DEBUG)) printf("Move condicional diferente de zero: sucesso! (%d != 0)\n", operando2);

    } else {
        retorno.flag = FLAG_FAIL;
        if(get_flag(FLAG_DEBUG)) printf("Move condicional diferente de zero: falha\n");

    }

    va_end(args);

    return retorno;
}

ulaRet mfhi(int num, ...){
    va_list args;
    va_start(args, num);
    va_end(args);
    //Não usa variaveis

    if(get_flag(FLAG_DEBUG)) printf("Move from Hi executado\n");

    ulaRet retorno;
    retorno.resultado = regs[REG_HI];
    retorno.flag = FLAG_SUCCESS;

    return retorno;
}

ulaRet mthi(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);

    ulaRet retorno;

    if(get_flag(FLAG_DEBUG)) printf("Move to Hi executado (%d)\n", operando1);
    retorno.resultado = operando1;
    retorno.flag = FLAG_MTHI;

    va_end(args);

    return retorno;
}

ulaRet mflo(int num, ...){
    va_list args;
    va_start(args, num);
    va_end(args);
    //Não usa variaveis

    if(get_flag(FLAG_DEBUG)) printf("Move from Lo executado\n");

    ulaRet retorno;
    retorno.resultado = regs[REG_LO];
    retorno.flag = FLAG_SUCCESS;

    return retorno;
}

ulaRet mtlo(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);

    ulaRet retorno;

    if(get_flag(FLAG_DEBUG)) printf("Move to Lo executado (%d)\n", operando1);
    retorno.resultado = operando1;
    retorno.flag = FLAG_MTLO;

    va_end(args);

    return retorno;
}

ulaRet mult(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet multu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet div_(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("DIV BEM LOUCO\n");
    va_end(args);
}

ulaRet divu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("DIVU BEM LOUCO\n");
    va_end(args);
}

ulaRet add(int num, ...){
    va_list args;
    va_start(args, num);

    unsigned int operando1 = va_arg(args, unsigned int);
    unsigned int operando2 = va_arg(args, unsigned int);

    unsigned int resultado = operando1 + operando2;

    printf("ADD BEM LOUCO ACONTECENDO BEM AQUI: %i + %i = %i\n",
            operando1, operando2, resultado);

    ulaRet retorno;

    retorno.resultado = resultado;
    retorno.flag = FLAG_SUCCESS;

    va_end(args);

    return retorno;
}

ulaRet addu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("ADDU BEM LOUCO\n");
    va_end(args);
}

ulaRet sub(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SUB BEM LOUCO\n");
    va_end(args);
}

ulaRet subu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SUBU BEM LOUCO\n");
    va_end(args);
}

ulaRet and(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet or(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet xor(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet nor(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet slt(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet sltu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet jr(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet jalr(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet bltz(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet bgez(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet bltzal(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet bgezal(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet beq(int num, ...){
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

    ulaRet retorno;
    retorno.flag = FLAG_NO_RETURN;

    va_end(args);

    return retorno;
}

ulaRet bne(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet blez(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet bgtz(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet addi(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("ADDI BEM LOUCO\n");
    va_end(args);
}

ulaRet addiu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("ADDIU BEM LOUCO\n");
    va_end(args);
}

ulaRet slti(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet sltiu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet andi(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet ori(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet xori(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet lui(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet madd(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("MADD BEM LOUCO\n");
    va_end(args);
}

ulaRet maddu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("MADDU BEM LOUCO\n");
    va_end(args);
}

ulaRet mul(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet msub(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("MSUB BEM LOUCO\n");
    va_end(args);
}

ulaRet msubu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("MSUBU BEM LOUCO\n");
    va_end(args);
}

ulaRet clo(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet clz(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet lb(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet lh(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet lwl(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet lw(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int arg1 = va_arg(args, unsigned int);

    endereco addr;
    addr.i = arg1;

    unsigned int dado = cRead(CACHE_DADOS, addr);

    va_end(args);

    ulaRet retorno;
    retorno.resultado = dado;
    retorno.flag = FLAG_SUCCESS;

    return retorno;
}

ulaRet lbu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet lhu(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet lwr(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet sb(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet sh(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet swl(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet sw(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet swr(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet ll(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}

ulaRet sc(int num, ...){
    va_list args;
    va_start(args, num);
    unsigned int operando1 = va_arg(args, unsigned int);
    printf("SLL BEM LOUCO\n");
    va_end(args);
    ulaRet retorno;

    return retorno;
}
