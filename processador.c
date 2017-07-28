/* Processador do simulador MIPS32         */
/* Autor: Bruno Cesar, bcesar.g6@gmail.com */

#include "processador.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int pc = 0;
static unsigned int IR; // instruction Register
unsigned int process; //Variável de controle do processo
int jump; // Variável de controle de saltos (Trava a busca e decodificação)
barr_aux* barr_Lo = NULL; //Barramento auxiliar do registrador Lo
barr_aux* barr_Hi = NULL; //Barramento auxiliar do registrador Hi


estacao_reserva* er_add1  = NULL;
estacao_reserva* er_add2  = NULL;
estacao_reserva* er_add3  = NULL;
estacao_reserva* er_mult1 = NULL;
estacao_reserva* er_mult2 = NULL;
estacao_reserva* er_load1 = NULL;
estacao_reserva* er_load2 = NULL;
estacao_reserva* er_load3 = NULL;
estacao_reserva* er_load4 = NULL;
estacao_reserva* er_load5 = NULL;


/* Simula função de controle: Salto inconcidional */
void inconditionalJump(){
    inst* ptr_instruction = pegaDaFila(1);
    pc = ptr_instruction->J.target; //TODO função PC_recebe(unsigned int target)
    if(get_flag(FLAG_VERBOSE)) printf("Salto inconcidional para %d\n", pc);
    jump = 0; //Reseta o controle de salto
}

/* Se identificar um salto condicional altera o controle de saltos para pular a etapa de busca */
void checkConditionalJump(inst instruction){
    // Opcodes de Branch
    // 4 1-1 1-17 7 6 1-0 1-16 5

    switch (instruction.I.op) {
        case 1:
            if(instruction.I.rt == 0  || instruction.I.rt == 1 ||
               instruction.I.rt == 16 || instruction.I.rt == 17){
                   jump = 1;
               }
            break;

        case 4:
        case 5:
        case 6:
        case 7:
            jump = 1;
            break;

        default:
            break;
    }
}

/* Etapa de busca                                              */
/* Nesta etapa do pipeline uma instrução, na forma de palavra, */
/* é buscada na memoria na posição do PC atual                 */
/* Ela é então copiada para o registrador de instrução IR      */
void busca(){
    endereco addr;
    addr.i = pc;
    IR = cRead(CACHE_TEXTO, addr);

    if (get_flag(FLAG_VERBOSE)){

    printf("\nPalavra lida da cache: ");
    printaBinario(&IR, 0, NULL);
    printf("\n");
    }

    pc+=4; //Fazer componente PC+4 TODO
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

    memcpy(aux, &IR, 4);
    *aux = *aux >> 26;
    opcode = *aux;

    switch (opcode) {
        case 0:
        case 28:
            memcpy(aux, &IR, 4);
            *aux = *aux << 26;
            *aux = *aux >> 26;
            func = *aux;

            //Instrução R
            instruction.R.op = opcode;
            instruction.R.func = func;

            memcpy(aux, &IR, 4);
            *aux = *aux << 6;
            *aux = *aux >> 27;
            instruction.R.rs = *aux;

            memcpy(aux, &IR, 4);
            *aux = *aux << 11;
            *aux = *aux >> 27;
            instruction.R.rt = *aux;

            memcpy(aux, &IR, 4);
            *aux = *aux << 16;
            *aux = *aux >> 27;
            instruction.R.rd = *aux;

            memcpy(aux, &IR, 4);
            *aux = *aux << 21;
            *aux = *aux >> 27;
            instruction.R.aux = *aux;

            if(get_flag(FLAG_VERBOSE)) printf("Instrução tipo R decodificada e adicionada a fila\n");
            break;

        case 2:
        case 3:
            instruction.J.op = opcode;

            memcpy(aux, &IR, 4);
            *aux = *aux << 6;
            *aux = *aux >> 6;
            instruction.J.target = *aux;
            jump = -1; //Sinaliza salto incondicional
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

            memcpy(aux, &IR, 4);
            *aux = *aux << 6;
            *aux = *aux >> 27;
            instruction.I.rs = *aux;

            memcpy(aux, &IR, 4);
            *aux = *aux << 11;
            *aux = *aux >> 27;
            instruction.I.rt = *aux;

            memcpy(aux, &IR, 4);
            *aux = *aux << 16;
            *aux = *aux >> 16;
            instruction.I.imm = *aux;
            if(get_flag(FLAG_VERBOSE)) printf("Instrução tipo I decodificada e adicionada a fila\n");
            checkConditionalJump(instruction);
            break;

        default:
            break;
    }

    insereFila(instruction);
    free(aux);
    IR = FLAG_NULL;
}

/* Função auxiliar, verifica se existe uma ER livre para a operação op             */
/* Params = int er_type : O tipo da Operação a ser verificada                      */
/* return = estacao_reserva* : O ponteiro para a ER ou NULL se não existe ER livre */
estacao_reserva* checa_er(int er_type){
    switch(er_type){
        case ADD_T:
        case BRANCH:
        case ADDI_T:
            if (er_add1->busy == 0) return er_add1;
            if (er_add2->busy == 0) return er_add2;
            if (er_add3->busy == 0) return er_add3;
            break;

        case MUL_T:
        case MULTI_T:
            if (er_mult1->busy == 0) return er_mult1;
            if (er_mult2->busy == 0) return er_mult2;
            break;

        case LOAD:
        case STORE:
            if (er_load1->busy == 0) return er_load1;
            if (er_load2->busy == 0) return er_load2;
            if (er_load3->busy == 0) return er_load3;
            if (er_load4->busy == 0) return er_load4;
            if (er_load5->busy == 0) return er_load5;

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
    //if(get_flag(FLAG_DEBUG)) printf("identificador = %d\n", identificaER(er));

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
                er->vj = regs[instruction.R.rs];
                er->qj = 0;
            }

            if(Qi[instruction.R.rt] != 0){
                er->qk = Qi[instruction.R.rt];
            } else{
                er->vk = regs[instruction.R.rt];
                er->qk = 0;
            }

            er->A = instruction.R.aux;

            if(instruction.R.rd != 0){
                Qi[instruction.R.rd] = identificaER(er);
                if(get_flag(FLAG_DEBUG)) printf("\nReservando Qi[%d] para saida de %s\n", instruction.R.rd, ER_nomes[identificaER(er) - 1]);
            }

            casosEspeciais(op.op, er);

            break;

        case BRANCH:
            if(get_flag(FLAG_DEBUG)) printf("Operação de Branch identificada\n");
            if(Qi[instruction.I.rs] != 0){
                er->qj = Qi[instruction.I.rs];
            } else{
                er->vj = regs[instruction.I.rs];
                er->qj = 0;
            }

            if(Qi[instruction.I.rt] != 0){
                er->qk = Qi[instruction.I.rt];
            } else{
                er->vk = regs[instruction.I.rt];
                er->qk = 0;
            }

            er->A = instruction.I.imm;
            break;

        case LOAD:
        case ADDI_T:
            if(Qi[instruction.I.rs] != 0){
                er->qj = Qi[instruction.I.rs];
            } else{
                er->vj = regs[instruction.I.rs];
                er->qj = 0;
            }

            er->A = instruction.I.imm;

            Qi[instruction.I.rt] = identificaER(er);
            if(get_flag(FLAG_DEBUG)) printf("\nReservando Qi[%d] para a saida de %s\n", instruction.I.rt , ER_nomes[identificaER(er) - 1]);
            break;

        case STORE:
            if(Qi[instruction.I.rs] != 0){
                er->qj = Qi[instruction.I.rs];
            } else{
                er->vj = regs[instruction.I.rs];
                er->qj = 0;
            }

            er->A = instruction.I.imm;

            if(Qi[instruction.R.rt] != 0){
                er->qk = Qi[instruction.R.rt];
            } else{
                er->vk = regs[instruction.R.rt];
                er->qk = 0;
            }
            break;

    }

    if(get_flag(FLAG_DEBUG)) printaER(er, 0, NULL);
    return 1;
}

/* Ativa uma estação de reserva para processar sua operação        */
/* Params = estacao_reserva* er : Estação de reserva a ser ativada */
int ativaER_add(estacao_reserva* er){
    unsigned int identificador = identificaER(er) - 1;

    /* Checa se a operação deve ser realizada */
    if(er->busy == 1){
        if(er->qj == 0 && er->qk == 0){
            /* A ULA executára a operação */
            if(get_flag(FLAG_DEBUG)) printf("\n| ER %s executando > ", ER_nomes[identificador]);

            ulaRet retorno;

             retorno = (*p[er->op]) (3, er->vj, er->vk, er->A);

             switch (retorno.flag) {
                 case FLAG_SUCCESS:
                    buffer_resultados[identificador] = retorno.resultado;
                    break;

                case FLAG_FAIL:
                    if(get_flag(FLAG_DEBUG)) printf("Operação retornou FAIL\n");
                    identificaER(identificador); //Limpa Qi na posição de RD da instrução que falhou.
                    break;

                case FLAG_MTHI:
                    buffer_resultados[identificador] = retorno.resultado;
                    break;

                case FLAG_MTLO:
                    buffer_resultados[identificador] = retorno.resultado;
                    break;

                case FLAG_MUL_OP:
                    barr_Lo->er_id = identificador;
                    barr_Hi->er_id = identificador;
                    break;

                case FLAG_NO_RETURN:
                default:
                    break;
             }

            er->busy = 0;

        } else {
            /* Operando não estão prontos */
            if(get_flag(FLAG_DEBUG)) printf("Operação na ER %s não pode ser executada: Operandos não estão prontos.\n", ER_nomes[identificador]);
        }


    } else{
        if(er->busy > 1){
            er->busy = er->busy - 1; //Representa um ciclo gasto na operação
            if(get_flag(FLAG_DEBUG)) printf("\n| ER %s -> Ciclos restantes = %d |\n", ER_nomes[identificador], er->busy );
        } else {
            return 0;
        }

    }

    return 1;
}

/* Ativa uma estação de reserva LS para processar sua operação     */
/* Params = estacao_reserva* er : Estação de reserva a ser ativada */
int ativaER_load(estacao_reserva* er){
    unsigned int identificador = identificaER(er) - 1;

    /* Checa se a operação deve ser realizada */
    if(er->busy == 1){
        /* Parte 1 calculo do endereço real */
        er->A = er->vj + er->A;

        /* Parte 2 Operação */
        if(get_flag(FLAG_DEBUG)) printf("\n| ER %s executando > ", ER_nomes[identificador]);

        ulaRet retorno;

        retorno = (*p[er->op]) (2, er->A);

        switch (retorno.flag) {
            case FLAG_SUCCESS:
               buffer_resultados[identificador] = retorno.resultado;
               break;

           case FLAG_FAIL:
               if(get_flag(FLAG_DEBUG)) printf("Operação retornou FAIL\n");
               break;

           case FLAG_NO_RETURN:
           default:
               break;
        }

        er->busy = 0;

    } else{
        if(er->busy > 1){
            er->busy = er->busy - 1; //Representa um ciclo gasto na operação
            if(get_flag(FLAG_DEBUG)) printf("\n| ER %s -> Ciclos restantes = %d |\n", ER_nomes[identificador], er->busy );
        } else {
            return 0;
        }

    }

    return 1;
}

/* */
int execucao(){
    /* Chamar a execução de cada estacao de reserva */
    int process = 0;

    process += ativaER_add(er_add1);
    process += ativaER_add(er_add2);
    process += ativaER_add(er_add3);
    process += ativaER_add(er_mult1);
    process += ativaER_add(er_mult2);
    process += ativaER_load(er_load1);
    process += ativaER_load(er_load2);
    process += ativaER_load(er_load3);
    process += ativaER_load(er_load4);
    process += ativaER_load(er_load5);


    if(get_flag(FLAG_DEBUG)){
        if(process == 0){
            printf("Pulando etapa de execução (Estações de reserva vazias)\n");
        }
    }

    return process;
}

/* Etapa de escrita do pipeline */
/* Utiliza o CDB para transferir os dados do buffer_resultados */
/* para seus respectivos destinos e ERs que precisam do dado   */
void escrita(){

    unsigned int dado;
    int i;
    int process = 0;

    /* Tratamento para as operações de divisão e multiplicação */
    if(barr_Hi->er_id != -1){
        if(get_flag(FLAG_VERBOSE)) printf("Stremando o dado %d vindo de %s\n",barr_Hi->dado, ER_nomes[barr_Hi->er_id - 1]);
        stream(barr_Hi->dado, barr_Hi->er_id+1);
        barr_Hi->er_id = -1;
        process++;
    }

    if(barr_Lo->er_id != -1){
        if(get_flag(FLAG_VERBOSE)) printf("Stremando o dado %d vindo de %s\n",barr_Lo->dado, ER_nomes[barr_Lo->er_id - 1]);
        stream(barr_Lo->dado, barr_Lo->er_id+1);
        barr_Lo->er_id = -1;
        process++;
    }

    for(i = 0; i < NUM_ER; i++){
        if (buffer_resultados[i] != FLAG_BUFFER_VAZIO){
            dado = buffer_resultados[i];
            if(get_flag(FLAG_VERBOSE)) printf("Stremando o dado %d vindo da %s...\n", dado, ER_nomes[i]);
            stream(dado, i+1);
            process++;
        }

    /* No fim do processo limpar o buffer_resultados */
        buffer_resultados[i] = FLAG_BUFFER_VAZIO;
    }

    /* Caso uma escrita ocorreu printa o banco de registradores se a flag estiver ativa */
    if(process){
        if(get_flag(FLAG_REGISTRADORES)) printaRegs(0, NULL);
    } else{
        if(get_flag(FLAG_VERBOSE)) printf("Pulando etapa de escrita (Nada a ser escrito)\n\n");
    }
}


/* Função principal, simula o pipeline*/
unsigned int pipeline(int ciclo){ //pipeline reverso
    inst* ptr_instruction;
    ptr_instruction = NULL;

    int emissao_v = 0;
    process = 0;

    if(get_flag(FLAG_VERBOSE))      printf("\n======== Ciclo %d ========\n", ciclo);

    if(get_flag(FLAG_VERBOSE))      printf("| Escrita >>\n");
    escrita();

    if(get_flag(FLAG_VERBOSE))      printf("| Execução >>\n");
    process = execucao();

    if(get_flag(FLAG_VERBOSE))      printf("\n| Emissão >>\n");

    ptr_instruction = pegaDaFila(0);

    if(ptr_instruction != NULL){
        if(get_flag(FLAG_DEBUG))    printaFila();

        process = 1;
        emissao_v = emissao(*ptr_instruction);

        /* Se a emissão ocorreu corretamente retira a instrução da fila */
        if (emissao_v){
            pegaDaFila(1);
            emissao_v = 0;
        } else{
            if(get_flag(FLAG_DEBUG)) printf("Emissão falhou! Stall criado no pipeline\n");
        }

    } else {
        if(get_flag(FLAG_VERBOSE)) printf("Pulando etapa de emissão (Fila vazia) \n");
    }

    if(get_flag(FLAG_VERBOSE))      printf("\n| Decodificação >>\n");

    if (IR != FLAG_NULL){
        process = 1;
        decodifica();
    } else {
        if(get_flag(FLAG_VERBOSE)) printf("Pulando etapa de decodicação (instruction register vazio)\n");
    }

    if (jump == -1) inconditionalJump(); // Salto inconcidional

    if(get_flag(FLAG_VERBOSE))      printf("\n| Busca >>\n");

    if (jump > 0){
        if(get_flag(FLAG_VERBOSE)) printf("Pulando etapa de busca (Operação de Salto identificada)\n");

    }else{

        if(get_flag(FLAG_DEBUG)) printf("(PC = %d)\n", pc);
        if (&mem[pc] < mem_text_end){
            process = 1;
            busca();
        } else {
            if(get_flag(FLAG_DEBUG)) printf("Pulando etapa de busca (PC = END_OF_TEXT)\n");
            IR = FLAG_NULL;
        }
    }

    if(get_flag(FLAG_VERBOSE))      printf("\n======== Fim do ciclo %d ========\n", ciclo);

    return process;
}

/* Função auxiliar: Inicializa o pipeline */
void processadorInit(){
    int i;

    er_load1 = malloc(sizeof(estacao_reserva));
    er_load2 = malloc(sizeof(estacao_reserva));
    er_load3 = malloc(sizeof(estacao_reserva));
    er_load4 = malloc(sizeof(estacao_reserva));
    er_load5 = malloc(sizeof(estacao_reserva));
    er_add1  = malloc(sizeof(estacao_reserva));
    er_add2  = malloc(sizeof(estacao_reserva));
    er_add3  = malloc(sizeof(estacao_reserva));
    er_mult1 = malloc(sizeof(estacao_reserva));
    er_mult2 = malloc(sizeof(estacao_reserva));

    er_load1->busy = 0;
    er_load2->busy = 0;
    er_load3->busy = 0;
    er_load4->busy = 0;
    er_load5->busy = 0;
    er_add1->busy  = 0;
    er_add2->busy  = 0;
    er_add3->busy  = 0;
    er_mult1->busy = 0;
    er_mult2->busy = 0;

    fila = malloc(sizeof(fila_inst));
    fila->next = NULL;

    Qi = calloc(NUM_REGS, sizeof(unsigned int));

    barr_Hi = malloc(sizeof(barr_aux));
    barr_Lo = malloc(sizeof(barr_aux));

    barr_Hi->er_id = FLAG_BUFFER_VAZIO;
    barr_Lo->er_id = FLAG_BUFFER_VAZIO;

    buffer_resultados = malloc(sizeof(unsigned int) * NUM_ER);
    for(i = 0; i < NUM_ER; i++){
        buffer_resultados[i] = FLAG_BUFFER_VAZIO;
    }

    jump = 0;
}
