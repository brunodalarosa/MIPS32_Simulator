/* Processador do simulador MIPS32         */
/* Autor: Bruno Cesar, bcesar.g6@gmail.com */

#include "processador.h"
#include <stdio.h>
#include <stdlib.h>
#include "memoria.h"
#include "simulador.h"

unsigned int pc = 0;
static word IR; // instruction Register


/* Etapa de busca                                              */
/* Nesta etapa do pipeline uma instrução, na forma de palavra, */
/* é buscada na memoria na posição do PC atual                 */
/* Ela é então copiada para o registrador de instrução IR      */
void busca(){
    read(IR, pc, 1);
    pc+=4; //Fazer componente PC+4
}

/* Etapa de decoficação                                       */
/* Decodifica uma palavra identificando seu tipo e atribuindo */
/* seus respectivos dados aos atributos da estrutura inst     */
/* Params = word w : A palavra a ser decodificada             */
/* Return = inst : A instrução decodificada e preenchida      */
void decodifica(){
    inst instruction;
    unsigned int opcode = 0;
    unsigned int func = 0;

    word aux = malloc(sizeof(unsigned int));

    // Move pra trás e pra frente os bits para pegar o campo desejado... não tem jeito melhor?
    memcpy(aux, IR, 4);
    *aux = *aux >> 26;
    opcode = *aux;

    switch (opcode) {
        case 0:
        case 28:
            memcpy(aux, IR, 4);
            *aux = *aux << 26;
            *aux = *aux >> 26;
            func = *aux;

            //Instrução R //VERIFICAR SE PRECISA OU NÃO DAR FREE STEP-BY-STEP
            instruction.R.op = opcode;
            instruction.R.func = func;

            memcpy(aux, IR, 4);
            *aux = *aux << 6;
            *aux = *aux >> 27;
            instruction.R.rs = *aux;

            memcpy(aux, IR, 4);
            *aux = *aux << 11;
            *aux = *aux >> 27;
            instruction.R.rt = *aux;

            memcpy(aux, IR, 4);
            *aux = *aux << 16;
            *aux = *aux >> 27;
            instruction.R.rd = *aux;

            memcpy(aux, IR, 4);
            *aux = *aux << 21;
            *aux = *aux >> 27;
            instruction.R.aux = *aux;
            break;

        case 2:
        case 3:
            instruction.J.op = opcode;

            memcpy(aux, IR, 4);
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

            memcpy(aux, IR, 4);
            *aux = *aux << 6;
            *aux = *aux >> 27;
            instruction.I.rs = *aux;

            memcpy(aux, IR, 4);
            *aux = *aux << 11;
            *aux = *aux >> 27;
            instruction.I.rt = *aux;

            memcpy(aux, IR, 4);
            *aux = *aux << 16;
            *aux = *aux >> 16;
            instruction.I.imm = *aux;
            break;

        default:
            break;
    }

    //if(get_flag(FLAG_DEBUG)) printaInstrucao(instruction);

    insereFila(instruction);
    free(aux);
}

/* Função auxiliar, verifica se existe uma ER livre para a operação op             */
/* Params = int er_type : O tipo da Operação a ser verificada                      */
/* return = estacao_reserva* : O ponteiro para a ER ou NULL se não existe ER livre */
estacao_reserva* checa_er(int er_type){
    switch(er_type){
        case ADD_T:
            if (er_add1->busy == 0) return er_add1;
            if (er_add2->busy == 0) return er_add2;
            if (er_add3->busy == 0) return er_add3;
            break;

        case MUL_T:
            if (er_mult1->busy == 0) return er_mult1;
            if (er_mult2->busy == 0) return er_mult2;
            break;

        case LOAD:
        case STORE:
            if (er_load1->busy == 0) return er_load1;
            if (er_load2->busy == 0) return er_load2;
            break;

        default:
            break;
    }

    return NULL;

}

/* Etapa de emissão do pipeline                         */
/* Args = inst instruction : Instrução retirada da fila */
/* return : 1 Se a emissão ocorreu normalmente          */
/*          0 Se a emissão falhou (cria stall)          */
/*            e a instrução deve voltar para a fila     */
int emissao(inst instruction){
    /* Se existe uma ER do tipo de OP livre :                */
    /*     Se operandos estiverem nos registradores :        */
    /*         Emite op -> ER com operandos em Vj e Vk       */
    /*     Se não:                                           */
    /*           Emite op -> ER com valores de Qi em Qj e Qk */
    /* Se não:                                               */
    /*     Cria um stall (pula etapa de emissão)             */

    operation op = getOp(instruction);
    estacao_reserva* er = NULL;
    er = checa_er(op.er_type);

    if(er == NULL) return 0;

    /* Carrega a operação na ER */
    er->op = op.op;
    er->busy = op.cycles;

    switch(op.er_type){
        case ADD_T:
        case MUL_T:

            if(Qi[instruction.R.rs] != 0){
                er->qj = Qi[instruction.R.rs];
            } else{
                er->vj = instruction.R.rs;
                er->qj = 0;
            }

            if(Qi[instruction.R.rt] != 0){
                er->qk = Qi[instruction.R.rt];
            } else{
                er->vk = instruction.R.rt;
                er->qk = 0;
            }
            break;

        case LOAD:

            if(Qi[instruction.I.rs] != 0){
                er->qj = Qi[instruction.I.rs];
            } else{
                er->vj = instruction.I.rs;
                er->qj = 0;
            }

            er->A = instruction.I.imm;

            Qi[instruction.I.rt] = identificaER(er);

            printf("\nChecando: Qi[rt] = %d (er_defined)\n", Qi[instruction.I.rt]);
            break;

        case STORE:
            if(Qi[instruction.I.rs] != 0){
                er->qj = Qi[instruction.I.rs];
            } else{
                er->vj = instruction.I.rs;
                er->qj = 0;
            }

            er->A = instruction.I.imm;

            if(Qi[instruction.R.rt] != 0){
                er->qk = Qi[instruction.R.rt];
            } else{
                er->vk = instruction.R.rt;
                er->qk = 0;
            }
            break;

    }


    if(get_flag(FLAG_DEBUG)) printaER(er, 0, NULL);
    return 1;
}


/* Função principal, simula o pipeline*/
void pipeline(){ //pipeline reverso
    inst* ptr_instruction;
    ptr_instruction = NULL;
    char ativ = 1;
    int verif = 0;

    while(ativ){
        if(get_flag(FLAG_DEBUG)) printf("\nPC = %d\n", pc);

        ativ = 0;
        //if CDB != FLAG_NULL then Escrita();

        //if ER != FLAG_NULL then execucao();

        ptr_instruction = pegaDaFila(0);
        if(ptr_instruction != NULL){
            //printaInstrucao(*ptr_instruction);
            ativ = 1;
            verif = emissao(*ptr_instruction);

            /* Se a emissão ocorreu corretamente retira a instrução da fila */
            if (verif){
                pegaDaFila(1);
                verif = 0;
            } else{
                if(get_flag(FLAG_VERBOSE)) printf("Emissão falhou! Stall criado no pipeline\n");
            }

        } else {
            if(get_flag(FLAG_DEBUG)) printf("Pulando etapa de emissão (Fila vazia) \n");
        }

        if (*IR != FLAG_NULL){
            ativ = 1;
            decodifica();
        } else {
            if(get_flag(FLAG_DEBUG)) printf("Pulando etapa de decodicação (IR = NULL)\n");
        }

        if (&mem[pc] < mem_text_end){
            ativ = 1;
            busca();
        } else {
            if(get_flag(FLAG_DEBUG)) printf("Pulando etapa de busca (PC = END_OF_TEXT)\n");
            *IR = FLAG_NULL;
        }

        if(get_flag(FLAG_VERBOSE))      printf("\n======== Fim do ciclo ========\n");
        if(get_flag(FLAG_DEBUG))        printaFila();
        if(get_flag(FLAG_STEP_BY_STEP)) pause();
    }

    /*while(&mem[pc] < mem_text_end){
        busca();
        decodifica();
        //printaFila();
        ptr_instruction = removeFila();

        if(ptr_instruction != NULL){
            emissao(*ptr_instruction);
        }
    }*/

}

void processadorInit(){
    er_load1 = malloc(sizeof(estacao_reserva));
    er_load2 = malloc(sizeof(estacao_reserva));
    er_add1  = malloc(sizeof(estacao_reserva));
    er_add2  = malloc(sizeof(estacao_reserva));
    er_add3  = malloc(sizeof(estacao_reserva));
    er_mult1 = malloc(sizeof(estacao_reserva));
    er_mult2 = malloc(sizeof(estacao_reserva));

    er_load1->busy = 0;
    er_load2->busy = 0;
    er_add1->busy  = 0;
    er_add2->busy  = 0;
    er_add3->busy  = 0;
    er_mult1->busy = 0;
    er_mult2->busy = 0;

    fila = malloc(sizeof(fila_inst));
    fila->next = NULL;

    IR = malloc(sizeof(unsigned int));
    *IR = FLAG_NULL;

    Qi = calloc(NUM_REGS, sizeof(unsigned int));

}
