/* Funções utilitárias do simulador MIPS32 */
/* Autor: Bruno Cesar, bcesar.g6@gmail.com */

#include "utils.h"

char* ER_nomes[7] = {"ADD 1","ADD 2","ADD 3","MULT 1","MULT 2","LOAD 1","LOAD 2"};

/* Printa a seção de ajuda */
void ajuda(){
		printf("\nUso: ./simulador [opções] <arquivo de entrada>\n\n");
		printf("Opções:\n");

		printf("\nOpções gerais\n");
		printf("\t[ -o ] <valor>\tDefine o nome do aquivo de saida da simulação. Padrão: saida.txt\n");
		printf("\t[ -t ] <valor>\tDefine o nome do aquivo de saida da tradução.  Padrão: bin\n");
		printf("\t[ -v ] 	    \tExecuta a simulador no modo Verbose.	       Padrão: Desativado\n");
		printf("\t[ -d ] 	    \tExecuta o simulador no modo Debug. 	       Padrão: Desativado\n");
		printf("\t[ -s ]        \tExecuta no modo passo-a-passo.			   Padrão: Desativado\n");
		printf("\t[ -h ] 	    \tExibe esta mensagem.\n");


		printf("\nOpções de Log\n");
		printf("\t[ -l ] <valor>\tDefine o nome do aquivo de log geral. 	       Padrão: log.txt\n");
		printf("\t[ -m ] <valor>\tDefine o nome do arquiv de log de tradução.    Padrão: lot_tradutor.txt\n");

}

/* Função auxiliar : Printa uma estaçaõ de reserva */
void printaER(estacao_reserva* er, char isFile, FILE* dest){
	int busy = er->busy > 0 ? 1 : 0;
	int cycles = er->busy;

	if (isFile){
		fprintf(dest, "\n|  Estação de reserva %s |\n", ER_nomes[identificaER(er)]);
		fprintf(dest, "-----------------------------\n");

		if(busy){
			fprintf(dest, "| Ocupada por mais %d ciclos |\n", cycles);
		} else {
			fprintf(dest, "|       --- Livre ---        |\n");
		}

		fprintf(dest, "| Op : %d                   |\n", er->op);
		fprintf(dest, "| Vj : %d                    |\n", er->vj);
		fprintf(dest, "| Vk : %d                    |\n", er->vk);
		fprintf(dest, "| Qj : %d                    |\n", er->qj);
		fprintf(dest, "| Qk : %d                    |\n", er->qk);
		fprintf(dest, "| A  : %d                    |\n", er->A);
		fprintf(dest, "------------------------------\n\n");

	} else{
		printf("\n|  Estação de reserva %s |\n", ER_nomes[identificaER(er)]);
		printf("-----------------------------\n");

		if(busy){
			printf("| Ocupada por mais %d ciclos \n", cycles);
		} else {
			printf("|       --- Livre ---        \n");
		}

		printf("| Op : %d\n", er->op);
		printf("| Vj : %d\n", er->vj);
		printf("| Vk : %d\n", er->vk);
		printf("| Qj : %d\n", er->qj);
		printf("| Qk : %d\n", er->qk);
		printf("| A  : %d\n", er->A);
		printf("----------------------------\n\n");
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

	return 0; //Caso de erro?
}

operation getOp(inst instruction){
	unsigned int opcode = 0;
	unsigned int func;
	unsigned int rt;
	opcode = instruction.R.op;
	operation op;

	//Identifica a instrução
	switch (opcode) {
		case 0: //instruction R
			func = instruction.R.func;
			switch (func){
				case 0:
					printf("sll\n\n");
					op.op = SLL;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 2:
					printf("srl\n\n");
					op.op = SRL;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 3:
					printf("sra\n\n");
					op.op = SRA;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 4:
					printf("sllv\n\n");
					op.op = SLLV;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 6:
					printf("srlv\n\n");
					op.op = SRLV;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 7:
					printf("srav\n\n");
					op.op = SRAV;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 8:
					printf("jr\n\n");
					op.op = JR;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 9:
					printf("jalr\n\n");
					op.op = JALR;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 10:
					printf("movz\n\n");
					op.op = MOVZ;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 11:
					printf("movn\n\n");
					op.op = MOVN;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 14:
					printf("tnei\n\n");
					op.op = TNEI;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 16:
					printf("mfhi\n\n");
					op.op = MFHI;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 17:
					printf("mthi\n\n");
					op.op = MTHI;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 18:
					printf("mflo\n\n");
					op.op = MFLO;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 19:
					printf("mtlo\n\n");
					op.op = MTLO;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 24:
					printf("mult\n\n");
					op.op = MULT;
					op.cycles = 1; //todo
					op.er_type = MUL_T; //verificar
					break;

				case 25:
					printf("multu\n\n");
					op.op = MULTU;
					op.cycles = 1; //todo
					op.er_type = MUL_T; //verificar
					break;

				case 26:
					printf("div\n\n");
					op.op = DIV;
					op.cycles = 1; //todo
					op.er_type = MUL_T; //verificar
					break;

				case 27:
					printf("divu\n\n");
					op.op = DIVU;
					op.cycles = 1; //todo
					op.er_type = MUL_T; //verificar
					break;

				case 32:
					printf("add\n\n");
					op.op = ADD;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 33:
					printf("addu\n\n");
					op.op = ADDU;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 34:
					printf("sub\n\n");
					op.op = SUB;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 35:
					printf("subu\n\n");
					op.op = SUBU;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 36:
					printf("and\n\n");
					op.op = AND;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 37:
					printf("or\n\n");
					op.op = OR;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 38:
					printf("xor\n\n");
					op.op = XOR;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 39:
					printf("nor\n\n");
					op.op = NOR;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 42:
					printf("slt\n\n");
					op.op = SLT;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 43:
					printf("sltu\n\n");
					op.op = SLTU;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 48:
					printf("tge\n\n");
					op.op = TGE;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 49:
					printf("tgeu\n\n");
					op.op = TGEU;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 50:
					printf("tlt\n\n");
					op.op = TLT;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 51:
					printf("tltu\n\n");
					op.op = TLTU;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 52:
					printf("teq\n\n");
					op.op = TEQ;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 54:
					printf("tne\n\n");
					op.op = TNE;
					op.cycles = 1; //todo
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
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 1:
					//bgez
					op.op = BGEZ;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 8:
					//tgei
					op.op = TGEI;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 9:
					//tgeiu
					op.op = TGEIU;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 10:
					//tlti
					op.op = TLTI;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 11:
					//tltiu
					op.op = TLTIU;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 12:
					//teqi
					op.op = TEQI;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 16:
					//blztal
					op.op = BLTZAL;
					break;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar

				case 17:
					//bgezal
					op.op = BGEZAL;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				default:
					//erro
					launchError(0); //especificar
					break;
			}
			break;

		case 2:
			//j
			op.op = JMP;
			op.cycles = 1; //todo
			op.er_type = ADD_T; //verificar
			break;

		case 3:
			//jal
			op.op = JAL;
			op.cycles = 1; //todo
			op.er_type = ADD_T; //verificar
			break;

		case 4:
			//beq
			op.op = BEQ;
			op.cycles = 1; //todo
			op.er_type = ADD_T; //verificar
			break;

		case 5:
			//bne
			op.op = BNE;
			op.cycles = 1; //todo
			op.er_type = ADD_T; //verificar
			break;

		case 6:
			//blez
			op.op = BLEZ;
			op.cycles = 1; //todo
			op.er_type = ADD_T; //verificar
			break;

		case 7:
			//bgtz
			op.op = BGTZ;
			op.cycles = 1; //todo
			op.er_type = ADD_T; //verificar
			break;

		case 8:
			//addi
			op.op = ADDI;
			op.cycles = 1; //todo
			op.er_type = ADD_T; //verificar
			break;

		case 9:
			//addiu
			op.op = ADDIU;
			op.cycles = 1; //todo
			op.er_type = ADD_T; //verificar
			break;

		case 10:
			//slti
			op.op = SLTI;
			op.cycles = 1; //todo
			op.er_type = ADD_T; //verificar
			break;

		case 11:
			//sltiu
			op.op = SLTIU;
			op.cycles = 1; //todo
			op.er_type = ADD_T; //verificar
			break;

		case 12:
			//andi
			op.op = ANDI;
			op.cycles = 1; //todo
			op.er_type = ADD_T; //verificar
			break;

		case 13:
			//ori
			op.op = ORI;
			op.cycles = 1; //todo
			op.er_type = ADD_T; //verificar
			break;

		case 14:
			//xori
			op.op = XORI;
			op.cycles = 1; //todo
			op.er_type = ADD_T; //verificar
			break;

		case 15:
			//lui
			op.op = LUI;
			op.cycles = 1; //todo
			op.er_type = ADD_T; //verificar
			break;

		case 28:
			func = instruction.R.func;
			switch (func) {
				case 0:
					//madd
					op.op = MADD;
					op.cycles = 1; //todo
					op.er_type = MUL_T;
					break;

				case 1:
					//maddu
					op.op = MADDU;
					op.cycles = 1; //todo
					op.er_type = MUL_T;
					break;

				case 2:
					//mul
					op.op = MUL;
					op.cycles = 1; //todo
					op.er_type = MUL_T;
					break;

				case 4:
					//msub
					op.op = MSUB;
					op.cycles = 1; //todo
					op.er_type = MUL_T;
					break;

				case 5:
					//msubu
					op.op = MSUBU;
					op.cycles = 1; //todo
					op.er_type = MUL_T;
					break;

				case 32:
					//clo
					op.op = CLO;
					op.cycles = 1; //todo
					op.er_type = ADD_T; //verificar
					break;

				case 33:
					//clz
					op.op = CLZ;
					op.cycles = 1; //todo
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
			op.cycles = 1; //todo
			op.er_type = LOAD;
			break;

		case 33:
			//lh
			op.op = LH;
			op.cycles = 1; //todo
			op.er_type = LOAD;
			break;

		case 34:
			//lwl
			op.op = LWL;
			op.cycles = 1; //todo
			op.er_type = LOAD;
			break;

		case 35:
			//lw
			op.op = LW;
			op.cycles = 1; //todo
			op.er_type = LOAD;
			break;

		case 36:
			//lbu
			op.op = LBU;
			op.cycles = 1; //todo
			op.er_type = LOAD;
			break;

		case 37:
			//lhu
			op.op = LHU;
			op.cycles = 1; //todo
			op.er_type = LOAD;
			break;

		case 38:
			//lwr
			op.op = LWR;
			op.cycles = 1; //todo
			op.er_type = LOAD;
			break;

		case 40:
			//sb
			op.op = SB;
			op.cycles = 1; //todo
			op.er_type = STORE;
			break;

		case 41:
			//sh
			op.op = SH;
			op.cycles = 1; //todo
			op.er_type = STORE;
			break;

		case 42:
			//swl
			op.op = SWL;
			op.cycles = 1; //todo
			op.er_type = STORE;
			break;

		case 43:
			//sw
			op.op = SW;
			op.cycles = 1; //todo
			op.er_type = STORE;
			break;

		case 46:
			//swr
			op.op = SWR;
			op.cycles = 1; //todo
			op.er_type = STORE;
			break;

		case 48: //Checar se precisa implementar
			//ll
			op.op = LL;
			op.cycles = 1; //todo
			op.er_type = LOAD;
			break;

		case 56: //checar se preicsa implementar
			//sc
			op.op = SC;
			op.cycles = 1; //todo
			op.er_type = STORE;
			break;

		default:
			//erro
			launchError(0); //especificar
			break;
	}

	return op;
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
		printaBinario(w, 0, log_file);
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
		printaBinario(w, 0, log_file);
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

/* Função de tratamento de erros: Escreve a mensagem de erro, */
/* fecha os arquivos de saida e log e para a execução. 	      */
/* Args| int e: Código referente ao erro identificado.        */
void launchError(int e){
	switch (e){
        case 1:
            printf("ERRO ao abrir o arquivo de entrada!\n O arquivo existe? Abortando...");
            exit(0);

        case 2:
            printf("ERRO! Argumentos errados! Use -h para consultar a ajuda.\n");
            exit(0);

		case 3:
			printf("ERRO na tradução do input: Declaração de Label repetido! Abortando... \n");
			fprintf(log_t_file, "ERRO na tradução do input: Declaração de Label repetidos! Abortando... \n");
			break;

		case 4:
			printf("ERRO na tradução do input: Label referenciado inexistente! Abortando... \n");
			fprintf(log_t_file, "ERRO na tradução do input: Label referenciado inexistente! Abortando... \n");
			break;

		case 5:
			printf("ERRO na tradução do input: Limite máximo de 100 variaveis! Abortando...\n");
			fprintf(log_t_file, "ERRO na tradução do input: Limite máximo de 100 variaveis! Abortando...\n");
			break;

		case 6:
			printf("ERRO na tradução do input: Variavel referenciada inexistente! Abortando... \n");
			fprintf(log_t_file, "ERRO na tradução do input: Variavel referenciada inexistente! Abortando... \n");
			break;

		default:
			printf("ERRO DESCONHECIDO. Abortando...\n");
			exit(0);
	}

	//fclose(log_t_file);
	//fclose();
	exit(0);
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
