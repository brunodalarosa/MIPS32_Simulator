/* Processador do simulador MIPS32         */
/* Autor: Bruno Cesar, bcesar.g6@gmail.com */

#include "processador.h"
#include <stdio.h>
#include <stdlib.h>
#include "memoria.h"
#include "simulador.h"

/* Etapa de busca                                              */
/* Nesta etapa do pipeline uma instrução, na forma de palavra, */
/* é buscada na memoria na posição do PC atual                 */
/* Params = word w : Uma palavra vazia a ser preenchida (copy) */
void busca(word w){
    printf("pc = %d ", pc);
    read(w, pc, 1);
    pc+=4;
    return;
}

/* Etapa de decoficação                                       */
/* Decodifica uma palavra identificando seu tipo e atribuindo */
/* seus respectivos dados aos atributos da estrutura inst     */
/* Params = word w : A palavra a ser decodificada             */
/* Return = inst : A instrução decodificada e preenchida      */
inst decodifica(word w){
    inst instruction;
    unsigned int opcode = 0;
    unsigned int func = 0;

    word aux = malloc(sizeof(unsigned int));

    // Move pra trás e pra frente os bits para pegar o campo desejado... não tem jeito melhor?
    memcpy(aux, w, 4);
    *aux = *aux >> 26;
    opcode = *aux;

    switch (opcode) {
        case 0:
        case 28:
            memcpy(aux, w, 4);
            *aux = *aux << 26;
            *aux = *aux >> 26;
            func = *aux;

            //Instrução R //VERIFICAR SE PRECISA OU NÃO DAR FREE STEP-BY-STEP
            instruction.R.op = opcode;
            instruction.R.func = func;

            memcpy(aux, w, 4);
            *aux = *aux << 6;
            *aux = *aux >> 27;
            instruction.R.rs = *aux;

            memcpy(aux, w, 4);
            *aux = *aux << 11;
            *aux = *aux >> 27;
            instruction.R.rt = *aux;

            memcpy(aux, w, 4);
            *aux = *aux << 16;
            *aux = *aux >> 27;
            instruction.R.rd = *aux;

            memcpy(aux, w, 4);
            *aux = *aux << 21;
            *aux = *aux >> 27;
            instruction.R.aux = *aux;
            break;

        case 2:
        case 3:
            instruction.J.op = opcode;

            memcpy(aux, w, 4);
            *aux = *aux << 6;
            *aux = *aux >> 6;
            instruction.J.target = *aux;

            break;

        case 1:
        case 4 ... 15:
        case 32 ... 38:
        case 40 ... 43:
        case 46:
        case 48:
        case 56:
            //Instrução I
            instruction.I.op = opcode;

            memcpy(aux, w, 4);
            *aux = *aux << 6;
            *aux = *aux >> 27;
            instruction.I.rs = *aux;

            memcpy(aux, w, 4);
            *aux = *aux << 11;
            *aux = *aux >> 27;
            instruction.I.rt = *aux;

            memcpy(aux, w, 4);
            *aux = *aux << 16;
            *aux = *aux >> 16;
            instruction.I.imm = *aux;
            break;

        default:
            break;
    }

    if(get_flag(FLAG_DEBUG)) printaInstrucao(instruction);
    free(aux);
    return instruction; //Colocar na fila?
}

void executa(inst instruction){ //Faltam 78 operações a serem feitas.
    unsigned int opcode = 0;
    unsigned int func;
    unsigned int rt;
    opcode = instruction.R.op;

    //Identifica a instrução
    switch (opcode) {
        case 0: //instruction R
            func = instruction.R.func;
            switch (func){
                case 0:
                    printf("sll\n\n");
                    break;

                case 2:
                    printf("srl\n\n");
                    break;

                case 3:
                    printf("sra\n\n");
                    break;

                case 4:
                    printf("sllv\n\n");
                    break;

                case 6:
                    printf("srlv\n\n");
                    break;

                case 7:
                    printf("srav\n\n");
                    break;

                case 8:
                    printf("jr\n\n");
                    break;

                case 9:
                    printf("jalr\n\n");
                    break;

                case 10:
                    printf("movz\n\n");
                    break;

                case 11:
                    printf("movn\n\n");
                    break;

                case 14:
                    printf("tnei\n\n");
                    break;

                case 16:
                    printf("mfhi\n\n");
                    break;

                case 17:
                    printf("mthi\n\n");
                    break;

                case 18:
                    printf("mflo\n\n");
                    break;

                case 19:
                    printf("mtlo\n\n");
                    break;

                case 24:
                    printf("mult\n\n");
                    break;

                case 25:
                    printf("multu\n\n");
                    break;

                case 26:
                    printf("div\n\n");
                    break;

                case 27:
                    printf("divu\n\n");
                    break;

                case 32:
                    printf("add\n\n");
                    break;

                case 33:
                    printf("addu\n\n");
                    break;

                case 34:
                    printf("sub\n\n");
                    break;

                case 35:
                    printf("subu\n\n");
                    break;

                case 36:
                    printf("and\n\n");
                    break;

                case 37:
                    printf("or\n\n");
                    break;

                case 38:
                    printf("xor\n\n");
                    break;

                case 39:
                    printf("nor\n\n");
                    break;

                case 42:
                    printf("slt\n\n");
                    break;

                case 43:
                    printf("sltu\n\n");
                    break;

                case 48:
                    printf("tge\n\n");
                    break;

                case 49:
                    printf("tgeu\n\n");
                    break;

                case 50:
                    printf("tlt\n\n");
                    break;

                case 51:
                    printf("tltu\n\n");
                    break;

                case 52:
                    printf("teq\n\n");
                    break;

                case 54:
                    printf("tne\n\n");
                    break;

                default:
                    printf("erro\n\n");
                    break;
            }
            break;

        case 1: //instruction I
            rt = instruction.I.rt;
            switch (rt) {

                case 0:
                    //bltz
                    break;

                case 1:
                    //bgez
                    break;

                case 8:
                    //tgei
                    break;

                case 9:
                    //tgeiu
                    break;

                case 10:
                    //tlti
                    break;

                case 11:
                    //tltiu
                    break;

                case 12:
                    //teqi
                    break;

                case 16:
                    //blztal
                    break;

                case 17:
                    //bgezal
                    break;

                default:
                    //erro
                    break;
            }
            break;

        case 2:
            //j
            break;

        case 3:
            //jal
            break;

        case 4:
            //beq
            break;

        case 5:
            //bne
            break;

        case 6:
            //blez
            break;

        case 7:
            //bgtz
            break;

        case 8:
            //addi
            break;

        case 9:
            //addiu
            break;

        case 10:
            //slti
            break;

        case 11:
            //sltiu
            break;

        case 12:
            //andi
            break;

        case 13:
            //ori
            break;

        case 14:
            //xori
            break;

        case 15:
            //lui
            break;

        case 28:
            func = instruction.R.func;
            switch (func) {
                case 0:
                    //madd
                    break;

                case 1:
                    //maddu
                    break;

                case 2:
                    //mul
                    break;

                case 4:
                    //msub
                    break;

                case 5:
                    //msubu
                    break;

                case 32:
                    //clo
                    break;

                case 33:
                    //clz
                    break;

                default:
                    //erro
                    break;
            }
            break;

        case 32:
            //lb
            break;

        case 33:
            //lh
            break;

        case 34:
            //lwl
            break;

        case 35:
            //lw
            break;

        case 36:
            //lbu
            break;

        case 37:
            //lhu
            break;

        case 38:
            //lwr
            break;

        case 40:
            //sb
            break;

        case 41:
            //sh
            break;

        case 42:
            //swl
            break;

        case 43:
            //sw
            break;

        case 46:
            //swr
            break;

        case 48:
            //ll
            break;

        case 56:
            //sc
            break;

        default:
            //erro
            break;
    }
}

void processadorInit(){
    /*
    er_load1 = FLAG_NULL;
    er_load2 = FLAG_NULL;
    er_add1  = FLAG_NULL;
    er_add2  = FLAG_NULL;
    er_add3  = FLAG_NULL;
    er_mult1 = FLAG_NULL;
    er_mult2 = FLAG_NULL;
    */
}

/* Função principal, simula o pipeline*/
void pipeline(){ //PIPELINE FUCKING REVERSO
    word w;
    inst instruction;

    /*while(1){
        if CDB != FLAG_NULL then Escrita();

        if ER != FLAG_NULL then executa();

        if fila_instrucao != FLAG_NULL then emissao();

        if RI<word> != FLAG_NULL then decodifica();

        if (&mem[pc] < mem_text_end){
            w = malloc(sizeof(unsigned int));
            busca(w);
            insereRI(w); // Copia a palavra pro RI?
            free(w);
        } else { RI = FLAG_NULL; } // ???
    }*/

    while(&mem[pc] < mem_text_end){
        w = malloc(sizeof(unsigned int));
        busca(w);
        instruction = decodifica(w);
        free(w);
        executa(instruction);
    }

    if(get_flag(FLAG_VERBOSE)) printf("Fim do ciclo\n");
}
