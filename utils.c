/* Funções utilitárias do simulador MIPS32 */
/* Autor: Bruno Cesar, bcesar.g6@gmail.com */

#include "utils.h"

/* Printa a seção de ajuda */
void ajuda(){
		printf("\nUso: ./simulador [opções] <arquivo de entrada>\n\n");
		printf("Opções:\n");

		printf("\nOpções gerais\n");
		printf("\t[ -o ] <valor>\tDefine o nome do aquivo de saida da simulação. Padrão: saida.txt\n");
		printf("\t[ -t ] <valor>\tDefine o nome do aquivo de saida da tradução.  Padrão: bin\n");
		printf("\t[ -v ] 	    \tExecuta a simulador no modo Verbose.	       Padrão: Desativado\n");
		printf("\t[ -d ] 	    \tExecuta o simulador no modo Debug. 	       Padrão: Desativado\n");
		printf("\t[ -h ] 	    \tExibe esta mensagem.\n");


		printf("\nOpções de Log\n");
		printf("\t[ -l ] <valor>\tDefine o nome do aquivo de log geral. 	       Padrão: log.txt\n");
		printf("\t[ -m ] <valor>\tDefine o nome do arquiv de log de tradução.    Padrão: lot_tradutor.txt\n");

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

	if(get_flag(FLAG_VERBOSE)) printf("\nSeção de dados estaticos\n");
	/* Print Static Data */
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

	pause();

	//free(w);
	fclose(bin_file);
}
