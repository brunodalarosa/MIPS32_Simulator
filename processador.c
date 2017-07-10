/* Processador do simulador MIPS32         */
/* Autor: Bruno Cesar, bcesar.g6@gmail.com */

#include "processador.h"
#include <stdio.h>
#include <stdlib.h>
#include "memoria.h"
#include "simulador.h"

void busca(word w){
    printf("pc = %d |\t", pc);
    read(w, pc, 1);
    pc+=4;
    return;
}

inst decode(word w){
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

void execute(inst instruction){
    unsigned int opcode = 0;
    opcode = instruction.R.op;

    switch (opcode) {
        case 0: //instruction R
            unsigned int func = instruction.R.func;
            switch (func){
                case 0:
                //sll
                case 2:
                //srl
                case 3:
                //sra
                case 4:
                //sllv
                case 6:
                //srlv
                case 7:
                //srav
                case 10:
                //movz
                case 11:
                //movn
                case 16:
                //mfhi
                case 17:
                //mthi
                case 18:
                //mflo
                case 19:
                //mtlo
                case 24:
                //mult
                case 25:
                //multu
                case 26:
                //div
                case 27:
                //div
                case 32:
                //add
                case 33:
                //addu
                case 36:
                //and
                case 34:
                //sub
                case 35:
                //subu
                case 36:
                //and
                case 37:
                //or
                case 38:
                //xor
                case 39:
                //nor
                case 42:
                //slt
                case 43:
                //sltu
            }

    }
}


void pipeline(){ //PIPELINE FUCKING REVERSO
    word w;
    while(&mem[pc] < mem_text_end){
        w = malloc(sizeof(unsigned int));
        busca(w);
        decode(w);
        free(w);
    }

    if(get_flag(FLAG_VERBOSE)) printf("Fim do ciclo\n");
}
