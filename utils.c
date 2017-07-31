/* Funções utilitárias do simulador MIPS32 */
/* Autor: Bruno Cesar, bcesar.g6@gmail.com */

#include "utils.h"

char* ER_nomes[NUM_ER] = {"ADD 1","ADD 2","ADD 3","MULT 1","MULT 2","LOAD 1","LOAD 2","LOAD 3","LOAD 4","LOAD 5",
                          "STORE 1","STORE 2","STORE 3","STORE 4","STORE 5"};

char* REG_nomes[NUM_REGS] = {"$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3",
						     "$t4", "$t5", "$t6", "$t7", "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7",
						     "$t8", "$t9", "$k0", "$k1", "$gp", "$sp", "$fp", "$ra", "Lo", "Hi"};

char* OP_nomes[NUM_OPS] = {"SLL","SRL","SRA","SLLV","SRLV","SRAV","MOVZ","MOVN","MFHI","MTHI","MFLO","MTLO","MULT","MULTU",
                      "DIV","DIVU","ADD","ADDU","SUB","SUBU","AND","OR","XOR","NOR","SLT","SLTU","JR","JALR","BLTZ","BGEZ",
                      "BLTZAL","BGEZAL","BEQ","BNE","BLEZ","BGTZ","ADDI","ADDIU","SLTI","SLTIU","ANDI","ORI","XORI","LUI",
                      "MADD","MADDU","MUL","MSUB","MSUBU","CLO","CLZ","LB","LH", "LW","LBU","LHU","SB","SH","SYSCALL","NOP"};

/* Printa a seção de ajuda */
void ajuda(){
        printf("\n|            ===== Simulador MIPS-32 ====              |\n");
        printf("|   Versao 1.0 / Desenvolvido por bcesar.g6@gmail.com  |\n");
		printf("\nUso: ./simulador [opções] <arquivo de entrada>\n\n");
		printf("Opções:\n");

		printf("\nOpções gerais\n");
		printf("\t[ -o ] <valor>\tDefine o nome do aquivo de saida da simulação. Padrão: saida.txt\n");
		printf("\t[ -t ] <valor>\tDefine o nome do aquivo de saida da tradução.  Padrão: bin\n");
		printf("\t[ -v ] 	    \tExecuta a simulador no modo Verbose.	       Padrão: Desativado\n");
		printf("\t[ -d ] 	    \tExecuta o simulador no modo Debug. 	       Padrão: Desativado\n");
		printf("\t[ -s ]        \tExecuta no modo passo-a-passo.			   Padrão: Desativado\n");
		printf("\t[ -r ]        \tImprime o conteúdo dos registradores durante a execução. Padrão: Desativado\n");
		printf("\t[ -h ] 	    \tExibe esta mensagem.\n");


		printf("\nOpções de Log\n");
		printf("\t[ -l ] <valor>\tDefine o nome do aquivo de log geral. 	       Padrão: log.txt\n");
		printf("\t[ -m ] <valor>\tDefine o nome do arquiv de log de tradução.    Padrão: lot_tradutor.txt\n");

}

/* Função auxiliar : Printa todos o conteudo de todos registradores */
void printaRegs(char isFile, FILE* dest){
	if(isFile){
		fprintf(dest, "\n|            ======= Registradores =======            \n");
		fprintf(dest, "| [$ze = %d]  [$at = %d]  [$v0 = %d]  [$v1 = %d]\n", regs[0],  regs[1],  regs[2],  regs[3]);
		fprintf(dest, "| [$a0 = %d]  [$a1 = %d]  [$a2 = %d]  [$a3 = %d]\n", regs[4],  regs[5],  regs[6],  regs[7]);
		fprintf(dest, "| [$t0 = %d]  [$t1 = %d]  [$t2 = %d]  [$t3 = %d]\n", regs[8],  regs[9],  regs[10], regs[11]);
		fprintf(dest, "| [$t4 = %d]  [$t5 = %d]  [$t6 = %d]  [$t7 = %d]\n", regs[12], regs[13], regs[14], regs[15]);
		fprintf(dest, "| [$s0 = %d]  [$s1 = %d]  [$s2 = %d]  [$s3 = %d]\n", regs[16], regs[17], regs[18], regs[19]);
		fprintf(dest, "| [$s4 = %d]  [$s5 = %d]  [$s6 = %d]  [$s7 = %d]\n", regs[20], regs[21], regs[22], regs[23]);
		fprintf(dest, "| [$t8 = %d]  [$t9 = %d]  [$k0 = %d]  [$k1 = %d]\n", regs[24], regs[25], regs[26], regs[27]);
		fprintf(dest, "| [$gp = %d]  [$sp = %d]  [$fp = %d]  [$ra = %d]\n", regs[28], regs[29], regs[30], regs[31]);
		fprintf(dest, "|             [Lo = %d]   [Hi = %d]            \n", regs[32], regs[33]);
		fprintf(dest, "-------------------------------------------------------\n\n");

	} else{
		printf("\n|         ======= Registradores =======            \n");
		printf("| [$ze = %d]  [$at = %d]  [$v0 = %d]  [$v1 = %d]\n", regs[0],  regs[1],  regs[2],  regs[3]);
		printf("| [$a0 = %d]  [$a1 = %d]  [$a2 = %d]  [$a3 = %d]\n", regs[4],  regs[5],  regs[6],  regs[7]);
		printf("| [$t0 = %d]  [$t1 = %d]  [$t2 = %d]  [$t3 = %d]\n", regs[8],  regs[9],  regs[10], regs[11]);
		printf("| [$t4 = %d]  [$t5 = %d]  [$t6 = %d]  [$t7 = %d]\n", regs[12], regs[13], regs[14], regs[15]);
		printf("| [$s0 = %d]  [$s1 = %d]  [$s2 = %d]  [$s3 = %d]\n", regs[16], regs[17], regs[18], regs[19]);
		printf("| [$s4 = %d]  [$s5 = %d]  [$s6 = %d]  [$s7 = %d]\n", regs[20], regs[21], regs[22], regs[23]);
		printf("| [$t8 = %d]  [$t9 = %d]  [$k0 = %d]  [$k1 = %d]\n", regs[24], regs[25], regs[26], regs[27]);
		printf("| [$gp = %d]  [$sp = %d]  [$fp = %d]  [$ra = %d]\n", regs[28], regs[29], regs[30], regs[31]);
		printf("|            [$lo = %d]  [$hi = %d]            \n", regs[32], regs[33]);
		printf("---------------------------------------------------\n\n");
	}
}

/* Função auxiliar printa Qi na tela */
void printaQi(unsigned int* Qi){
    int i;
    printf("Qi=[");
    for(i = 1; i < NUM_REGS; i++){
        printf("%u ", Qi[i]);
    }
    printf("]\n");
}

/* Identifica o registrador de destino através de sua posição em Qi. */
/* Atualiza Qi. Retorna -1 caso não exista 						  	 */
int identificaREG(unsigned int er_id){
	int i;
	for(i = 0; i < NUM_REGS; i++){
		if(Qi[i] == er_id){
			Qi[i] = 0;
			return i;
		}
	}

	return -1;
}

/* Função auxiliar : Printa uma estação de reserva */
void printaER(estacao_reserva* er, char isFile, FILE* dest){
	int busy = er->busy > 0 ? 1 : 0;
	int cycles = er->busy;

	if (isFile){
		fprintf(dest, "\n|  Estação de reserva %s |\n", ER_nomes[identificaER(er) - 1]);
		fprintf(dest, "-----------------------------\n");

		if(busy){
			fprintf(dest, "| Ocupada por mais %d ciclos |\n", cycles);
		} else {
			fprintf(dest, "|       --- Livre ---        |\n");
		}

		fprintf(dest, "| Op : %d (%s)\n", er->op, OP_nomes[er->op - 1]);
		fprintf(dest, "| Vj : %d\n", er->vj);
		fprintf(dest, "| Vk : %d\n", er->vk);
		fprintf(dest, "| Qj : %d\n", er->qj);
		fprintf(dest, "| Qk : %d\n", er->qk);
		fprintf(dest, "| A  : %d\n", er->A);
		fprintf(dest, "------------------------------\n");

	} else{
		printf("\n|  Estação de reserva %s |\n", ER_nomes[identificaER(er) - 1]);
		printf("-----------------------------\n");

		if(busy){
			printf("| Ocupada por mais %d ciclos \n", cycles);
		} else {
			printf("|       --- Livre ---        \n");
		}

        printf("| Op : %d (%s)\n", er->op, OP_nomes[er->op - 1]);
		printf("| Vj : %d\n", er->vj);
		printf("| Vk : %d\n", er->vk);
		printf("| Qj : %d\n", er->qj);
		printf("| Qk : %d\n", er->qk);
		printf("| A  : %d\n", er->A);
		printf("----------------------------\n");
	}
}

/* Identifica um ponteiro de estação de reserva        */
/* Retorna o inteiro definido como identificador da ER */
int identificaER(estacao_reserva* er){
	if(er == er_add1) return ADD_1;
	if(er == er_add2) return ADD_2;
	if(er == er_add3) return ADD_3;

	if(er == er_mult1) return MUL_1;
	if(er == er_mult2) return MUL_2;

	if(er == er_load1) return LOAD_1;
	if(er == er_load2) return LOAD_2;
	if(er == er_load3) return LOAD_3;
	if(er == er_load4) return LOAD_4;
	if(er == er_load5) return LOAD_5;

	if(er == er_store1) return STORE_1;
	if(er == er_store2) return STORE_2;
	if(er == er_store3) return STORE_3;
	if(er == er_store4) return STORE_4;
	if(er == er_store5) return STORE_5;

	return 0; //Caso de erro?
}

/* Recebe um identificador de estação de reserva                  */
/* retorna a estação de reserva ou -1 caso identificador invalido */
estacao_reserva* getER(int er_id){
	if(er_id == ADD_1) return er_add1;
	if(er_id == ADD_2) return er_add2;
	if(er_id == ADD_3) return er_add3;

	if(er_id == MUL_1) return er_mult1;
	if(er_id == MUL_2) return er_mult2;

	if(er_id == LOAD_1) return er_load1;
	if(er_id == LOAD_2) return er_load2;
	if(er_id == LOAD_3) return er_load3;
	if(er_id == LOAD_4) return er_load4;
	if(er_id == LOAD_5) return er_load5;

	if(er_id == STORE_1) return er_store1;
	if(er_id == STORE_2) return er_store2;
	if(er_id == STORE_3) return er_store3;
	if(er_id == STORE_4) return er_store4;
	if(er_id == STORE_5) return er_store5;

	return NULL; //identificador inválido
}


/* Executa um flush na estação de reserva */
void flushEr(estacao_reserva** er){
	free(*er);
	*er = malloc(sizeof(estacao_reserva));
	(*er)->busy = 0;
}

/* Checa todas as estações de reserva para dar flush */
void flushes(){
    int i;
    estacao_reserva* er = NULL;

    for(i = 1; i <= NUM_ER; i++){
        er = getER(i);
        if(er->busy == -1) flushEr(&er);
    }
}

operation getOp(inst instruction){
	unsigned int opcode = 0;
	unsigned int func = 0;
	unsigned int rt = 0;
	opcode = instruction.R.op;
	operation op;

	//Identifica a instrução
	switch (opcode) {
		case 0: //instruction R
			func = instruction.R.func;
			switch (func){
				case 0:
					op.op = SLL;
					op.cycles = 2;
					op.er_type = ADD_T; //verificar
					break;

				case 2:
					op.op = SRL;
					op.cycles = 2;
					op.er_type = ADD_T; //verificar
					break;

				case 3:
					op.op = SRA;
					op.cycles = 2;
					op.er_type = ADD_T; //verificar
					break;

				case 4:
					op.op = SLLV;
					op.cycles = 2;
					op.er_type = ADD_T; //verificar
					break;

				case 6:
					op.op = SRLV;
					op.cycles = 2;
					op.er_type = ADD_T; //verificar
					break;

				case 7:
					op.op = SRAV;
					op.cycles = 2;
					op.er_type = ADD_T; //verificar
					break;

				case 8:
					op.op = JR;
					op.cycles = 3;
					op.er_type = ADD_T; //verificar
					break;

				case 9:
					op.op = JALR;
					op.cycles = 3;
					op.er_type = ADD_T; //verificar
					break;

				case 10:
					op.op = MOVZ;
					op.cycles = 3;
					op.er_type = ADD_T; //verificar
					break;

				case 11:
					op.op = MOVN;
					op.cycles = 3;
					op.er_type = ADD_T; //verificar
					break;

				case 12:
					op.op = SYSCALL;
					op.cycles = 2;
					op.er_type = ADD_T;
					break;

				case 16:
					op.op = MFHI;
					op.cycles = 2;
					op.er_type = ADD_T; //verificar
					break;

				case 17:
					op.op = MTHI;
					op.cycles = 2;
					op.er_type = ADD_T; //verificar
					break;

				case 18:
					op.op = MFLO;
					op.cycles = 2;
					op.er_type = ADD_T; //verificar
					break;

				case 19:
					op.op = MTLO;
					op.cycles = 2;
					op.er_type = ADD_T; //verificar
					break;

				case 24:
					op.op = MULT;
					op.cycles = 6;
					op.er_type = MUL_T; //verificar
					break;

				case 25:
					op.op = MULTU;
					op.cycles = 6;
					op.er_type = MUL_T; //verificar
					break;

				case 26:
					op.op = DIV;
					op.cycles = 6;
					op.er_type = MUL_T; //verificar
					break;

				case 27:
					op.op = DIVU;
					op.cycles = 6;
					op.er_type = MUL_T; //verificar
					break;

				case 32:
					op.op = ADD;
					op.cycles = 3;
					op.er_type = ADD_T; //verificar
					break;

				case 33:
					op.op = ADDU;
					op.cycles = 3;
					op.er_type = ADD_T; //verificar
					break;

				case 34:
					op.op = SUB;
					op.cycles = 3;
					op.er_type = ADD_T; //verificar
					break;

				case 35:
					op.op = SUBU;
					op.cycles = 3;
					op.er_type = ADD_T; //verificar
					break;

				case 36:
					op.op = AND;
					op.cycles = 2;
					op.er_type = ADD_T; //verificar
					break;

				case 37:
					op.op = OR;
					op.cycles = 2;
					op.er_type = ADD_T; //verificar
					break;

				case 38:
					op.op = XOR;
					op.cycles = 2;
					op.er_type = ADD_T; //verificar
					break;

				case 39:
					op.op = NOR;
					op.cycles = 2;
					op.er_type = ADD_T; //verificar
					break;

				case 42:
					op.op = SLT;
					op.cycles = 3;
					op.er_type = ADD_T; //verificar
					break;

				case 43:
					op.op = SLTU;
					op.cycles = 3;
					op.er_type = ADD_T; //verificar
					break;

				default:
					launchError(0); //especificar
					break;
			}
			break;

		case 1: //instruction I
			rt = instruction.I.rt;
			switch (rt) {

				case 0:
					//bltz
					op.op = BLTZ;
					op.cycles = 3;
					op.er_type = BRANCH; //verificar
					break;

				case 1:
					//bgez
					op.op = BGEZ;
					op.cycles = 3;
					op.er_type = BRANCH; //verificar
					break;

				case 16:
					//blztal
					op.op = BLTZAL;
					break;
					op.cycles = 3;
					op.er_type = BRANCH; //verificar

				case 17:
					//bgezal
					op.op = BGEZAL;
					op.cycles = 3;
					op.er_type = BRANCH; //verificar
					break;

				default:
					//erro
					launchError(0); //especificar
					break;
			}
			break;

		case 4:
			//beq
			op.op = BEQ;
			op.cycles = 3;
			op.er_type = BRANCH; //verificar
			break;

		case 5:
			//bne
			op.op = BNE;
			op.cycles = 3;
			op.er_type = BRANCH; //verificar
			break;

		case 6:
			//blez
			op.op = BLEZ;
			op.cycles = 3;
			op.er_type = BRANCH; //verificar
			break;

		case 7:
			//bgtz
			op.op = BGTZ;
			op.cycles = 3;
			op.er_type = BRANCH; //verificar
			break;

		case 8:
			//addi
			op.op = ADDI;
			op.cycles = 3;
			op.er_type = ADDI_T;
			break;

		case 9:
			//addiu
			op.op = ADDIU;
			op.cycles = 3;
			op.er_type = ADDI_T;
			break;

		case 10:
			//slti
			op.op = SLTI;
			op.cycles = 3;
			op.er_type = ADDI_T;
			break;

		case 11:
			//sltiu
			op.op = SLTIU;
			op.cycles = 3;
			op.er_type = ADDI_T;
			break;

		case 12:
			//andi
			op.op = ANDI;
			op.cycles = 3;
			op.er_type = ADDI_T;
			break;

		case 13:
			//ori
			op.op = ORI;
			op.cycles = 2;
			op.er_type = ADDI_T;
			break;

		case 14:
			//xori
			op.op = XORI;
			op.cycles = 2;
			op.er_type = ADDI_T;
			break;

		case 15:
			//lui
			op.op = LUI;
			op.cycles = 5;
			op.er_type = ADD_T; //verificar
			break;

		case 28:
			func = instruction.R.func;
			switch (func) {
				case 0:
					//madd
					op.op = MADD;
					op.cycles = 6;
					op.er_type = MUL_T;
					break;

				case 1:
					//maddu
					op.op = MADDU;
					op.cycles = 6;
					op.er_type = MUL_T;
					break;

				case 2:
					//mul
					op.op = MUL;
					op.cycles = 6;
					op.er_type = MUL_T;
					break;

				case 4:
					//msub
					op.op = MSUB;
					op.cycles = 6;
					op.er_type = MUL_T;
					break;

				case 5:
					//msubu
					op.op = MSUBU;
					op.cycles = 6;
					op.er_type = MUL_T;
					break;

				case 32:
					//clo
					op.op = CLO;
					op.cycles = 2;
					op.er_type = ADD_T; //verificar
					break;

				case 33:
					//clz
					op.op = CLZ;
					op.cycles = 2;
					op.er_type = ADD_T; //verificar
					break;

				default:
					//erro
					launchError(0); //especificar
					break;
			}
			break;

		case 32:
			//lb
			op.op = LB;
			op.cycles = 5;
			op.er_type = LOAD;
			break;

		case 33:
			//lh
			op.op = LH;
			op.cycles = 5;
			op.er_type = LOAD;
			break;

		case 35:
			//lw
			op.op = LW;
			op.cycles = 5;
			op.er_type = LOAD;
			break;

		case 36:
			//lbu
			op.op = LBU;
			op.cycles = 5;
			op.er_type = LOAD;
			break;

		case 37:
			//lhu
			op.op = LHU;
			op.cycles = 5;
			op.er_type = LOAD;
			break;

		case 40:
			//sb
			op.op = SB;
			op.cycles = 5;
			op.er_type = STORE;
			break;

		case 41:
			//sh
			op.op = SH;
			op.cycles = 5;
			op.er_type = STORE;
			break;

		case 43:
			//sw
			op.op = SW;
			op.cycles = 5;
			op.er_type = STORE;
			break;

        case 60:
            //NOP
            op.op = NOPE;
            op.cycles = 1;
            op.er_type = ADD_T;
            break;

		default:
			//erro
			launchError(0); //especificar
			break;
	}

	return op;
}

/* Função auxiliar para tratamento de operações especiais */
void casosEspeciais(int op, estacao_reserva* er){

	switch (op) {
		case MFLO:
			if(Qi[REG_LO] != 0){
				er->qj = Qi[REG_LO];
			} else{
				er->vj = getReg(REG_LO);
				er->qj = 0;
			}
			break;

		case MFHI:
			if(Qi[REG_HI] != 0){
				er->qj = Qi[REG_HI];
			} else{
				er->vj = getReg(REG_HI);
				er->qj = 0;
			}
			break;

		case MTLO:
			Qi[REG_LO] = identificaER(er);
			if(get_flag(FLAG_DEBUG)) printf("\nReservando LO para saida de %s \n", ER_nomes[identificaER(er) - 1]);
			break;

		case MTHI:
			Qi[REG_HI] = identificaER(er);
			if(get_flag(FLAG_DEBUG)) printf("\nReservando HI para saida de %s \n", ER_nomes[identificaER(er) - 1]);
			break;

		case DIV:
		case DIVU:
		case MULTU:
		case MULT:
			Qi[REG_LO] = identificaER(er);
			Qi[REG_HI] = identificaER(er);
			if(get_flag(FLAG_DEBUG)) printf("\nReservando HI e LO para a saida de %s\n", ER_nomes[identificaER(er) - 1]);
			break;

		case BGEZAL:
		case BLTZAL:
			Qi[REG_RA] = identificaER(er);
			if(get_flag(FLAG_DEBUG)) printf("\nReservando RA para a saida de %s\n", ER_nomes[identificaER(er) - 1]);
			break;

		default:
			break;
	}
}

/* Insere uma instrução na fila de instruções */
/* Args = fila_inst : O nó a ser inserido     */
void insereFila(inst instruction){
	fila_inst node = malloc(sizeof(fila_inst));
	node->instruction = instruction;
	node->next = NULL;

	fila_inst ultimo = fila;
	while(ultimo->next != NULL) ultimo = ultimo->next;

	ultimo->next = node;
}

/* Retorna uma instrução da fila de instruções 			     */
/* Params = int remover : Se 1 remove o a instrução da fila  */
/* return = inst : A instrução ou 0 caso a fila esteja vazia */
inst* pegaDaFila(int remover){
	fila_inst f = fila->next;

	if( f != NULL){

		inst* instruction;
		instruction = malloc(sizeof(inst));
		*instruction = f->instruction;

		if(remover){
			fila_inst aux = f;
			fila->next = f->next;
			free(aux);
		}

		return instruction;
	}

	return NULL;
}

/* Printa a fila de instruções */
void printaFila(){
	fila_inst walker = fila->next;

	printf("Printando a fila de instruções:\n");
	if(walker == NULL) printf("Fila vazia!\n");

	while(walker != NULL){
		printaInstrucao(walker->instruction);
		walker = walker->next;
	}
	printf("\n");
}

/* Imprime uma instrução em formato binário  */
/* Args| word w : Instrução a ser impressa */
void printaBinario(word w, char isFile, FILE* dest){
	unsigned int p = 2147483648;
	if(isFile){ //Printa no arquivo

		while(p > 0){
			if (p & *w){

				fprintf(dest, "1");
			} else fprintf(dest,"0");
			p >>= 1;
		}
	}
	else {  //Printa na tela

		while(p > 0){
			if (p & *w){
				printf("1");
			} else printf("0");
			p >>= 1;
		}
	}
}

/* Imprime uma instrução em formato texto 	          */
/* Args = inst instruction : Instrução a ser impressa */
void printaInstrucao(inst instruction){
	unsigned int opcode = 0;
	opcode = instruction.R.op;

	switch(opcode){
		case 0:
		case 28:
			printf("\ninst R: op = %d | rs = %d | rt = %d | rd = %d | aux = %d | func = %d\n",
				instruction.R.op, instruction.R.rs, instruction.R.rt, instruction.R.rd,
				instruction.R.aux, instruction.R.func);
				break;

		case 2:
		case 3:
			printf("\ninst J: op = %d | target = %d\n", instruction.J.op, instruction.J.target);
			break;

		case 1:
		case 4 ... 15:
		case 32 ... 38:
		case 40 ... 43:
		case 46:
		case 48:
		case 56:
			printf("\ninst I: op = %d | rs = %d | rt = %d | imm = %d\n",
				instruction.I.op, instruction.I.rs, instruction.I.rt, instruction.I.imm);
			break;

		default:
			break;
	}
}


/**
* Printa uma parte da memoria
**/
void printMem(){
	if(get_flag(FLAG_VERBOSE)) fprintf(log_file, "\nPrintando a memoria\n");
	int b = 0;
	word w = malloc(sizeof(unsigned int));

	/* Print texto */
	if(get_flag(FLAG_VERBOSE)) printf("\nSeção de texto\n");
	char* p_mem = mem;
	do{
		w = memcpy(w, p_mem, sizeof(unsigned int));
		printaBinario(w, 0, log_file); //MUDAR PRA 1
		p_mem += 4;

		/* Formatação do print */
		printf("\t");
		if(b) printf("\n");
		b = !b;

	} while(p_mem < mem_text_end);

	/* Print Static Data */
	if(get_flag(FLAG_VERBOSE)) printf("\nSeção de dados estaticos\n");
	b = 0;
	p_mem = mem + TEXT_SIZE;
	do{
		w = memcpy(w, p_mem, sizeof(unsigned int));
		printaBinario(w, 0, log_file); //MUDAR PRA 1
		p_mem += 4;

		/* Formatação do print */
		printf("\t");
		if(b) printf("\n");
		b = !b;

	} while(p_mem < mem + TEXT_SIZE + STATIC_DATA_SIZE);

	if(get_flag(FLAG_VERBOSE)) fprintf(log_file, "\nFim do print\n");
}

/**
* Função para pausar a execução
**/
void pause(){
    printf("\nPressione ENTER para continuar\n");
    getchar();
}

/**
* Função auxiliar prompt (S/N)
**/
int prompt(){
	char r;

	do{
		printf("(s / n): ");
		r = getchar();

		switch (r) {
			case 'S':
			case 's':
			return 1;

			case 'N':
			case 'n':
			return 0;

			default:
			break;
		}
		getchar();
		printf("\nEntrada incorreta! Insira apenas s ou n\n");

	} while(1);
}

/* Função de tratamento de erros: Escreve a mensagem de erro, */
/* fecha os arquivos de saida e log e para a execução. 	      */
/* Args| int e: Código referente ao erro identificado.        */
void launchError(int e){
	switch (e){
        case 1:
            printf("ERRO ao abrir o arquivo de entrada!\n O arquivo existe?\nUtilize o argumento -h para consultar as instruções de uso.\n");
            exit(0);

        case 2:
            printf("ERRO! Argumentos errados! Use -h para consultar a ajuda.\n");
            exit(0);

		case 3:
			printf("ERRO na tradução do input: Declaração de Label repetido! Abortando...\n");
			fprintf(log_t_file, "ERRO na tradução do input: Declaração de Label repetidos! Abortando...\n");
			break;

		case 4:
			printf("ERRO na tradução do input: Label referenciado inexistente! Abortando...\n");
			fprintf(log_t_file, "ERRO na tradução do input: Label referenciado inexistente! Abortando...\n");
			break;

		case 5:
			printf("ERRO na tradução do input: Limite máximo de 100 variaveis! Abortando...\n");
			fprintf(log_t_file, "ERRO na tradução do input: Limite máximo de 100 variaveis! Abortando...\n");
			break;

		case 6:
			printf("ERRO na tradução do input: Variavel referenciada inexistente! Abortando...\n");
			fprintf(log_t_file, "ERRO na tradução do input: Variavel referenciada inexistente! Abortando...\n");
			break;

		case 7:
			printf("ERRO na execução: Impossível escrever na area de texto! Abortando...\n");
			fprintf(log_file, "ERRO na execução: Impossível escrever na area de texto! Abortando...\n");
			break;

		case 8:
			printf("ERRO na execução: Escrita inválida em registrador! Abortando...\n");
			fprintf(log_file, "ERRO na execução: Escrita inválida em registrador! Abortando...\n");
			break;

        case 9:
            printf("ERRO na execução: É proibido criar buracos negros!!! (Divisão por 0) Abortando...\n");
            fprintf(log_file, "ERRO na execução: É proibido criar buracos negros!!! (Divisão por 0) Abortando...\n");
            exit(0);

		default:
			printf("Abortando...\n");
			exit(0);
            break;
	}

    fclose(output_file);
	fclose(log_t_file);
	exit(0);
}

/**
* Printa um bloco de memoria de 4 palavras
**/
void printaBloco(word w, unsigned int tam){
	int i;
	printf("\n\t\t       BLOCO\n");

	for(i = 0; i < tam; i++){
		printf("       | "); printaBinario((w+i), 0, NULL); printf(" |\n");
	}

	printf("\n");
}

/* Função auxiliar checa se um syscall pode acontecer */
int checaSyscall(){
    if (Qi[REG_V0] != 0) return 1;
    if (Qi[REG_A0] != 0) return 1;

    return 0;
}

/**
* Lê o arquivo binário e carrega o programa para a memoria
**/
void readProgram(){
	/* Ponteiro arquivo de memoria */
	if ((bin_file = fopen(t_saida,"r")) == NULL) {
		launchError(0); //Muito improvável, especificar erro?
	}
	size_t read_result = 0;

	/* Read text */
	fseek(bin_file, STATIC_DATA_SIZE, SEEK_SET);

	char* p_mem = mem;
	do {
		read_result = fread(p_mem, sizeof(unsigned int), 1, bin_file);
		p_mem += 4;

		if (p_mem == mem + TEXT_SIZE) launchError(0); //especificar

	} while(read_result > 0);
	mem_text_end = p_mem - 4;

    /* Read Static Data */
	fseek(bin_file, 0, SEEK_SET);
	p_mem = mem + TEXT_SIZE;
	read_result = fread(p_mem, STATIC_DATA_SIZE, 1, bin_file);

	if(get_flag(FLAG_STEP_BY_STEP)) pause();

	//free(w);
	fclose(bin_file);
}
