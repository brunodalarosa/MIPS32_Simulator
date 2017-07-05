/* Funções utilitárias do simulador MIPS32 */
/* Autor: Bruno Cesar, bcesar.g6@gmail.com */

#include "utils.h"
#include "memoria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	int k;
	if(isFile){ //Printa no arquivo
		while(p > 0){
			if (p & *w){

				fprintf(dest, "1");
			} else fprintf(dest,"0");
			p >>= 1;
		}
		fprintf(dest,"\n"); //TODO mudar para /t e arrumar os usos
	} else { //Printa na tela
		while(p > 0){
			if (p & *w){

				printf("1");
			} else printf("0");
			p >>= 1;
		}
		printf("\n");
	}
}

/**
* Printa uma parte da memoria
**/
void printMem(){
	if(get_flag(FLAG_VERBOSE)) fprintf(log_file, "\nPrintando a memoria\n");

	word w = malloc(sizeof(word));
	int pos = 0;

	w = memcpy(w, mem + pos, sizeof(word));


	while(pos < 13421){
		printaBinario(w, 0, log_file); //1
		pos += 4;
		w = memcpy(w, mem + pos, sizeof(word));
		// TODO Fazer printar mais de um por linha?
	}

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

	//TODO ler o arquivo
	int pos = 0;

	/*word w = malloc(sizeof(word));
	read_result = fread(w, sizeof(word), 1, bin_file);

	while(read_result > 0){
		printaBinario(w, 0, NULL); //super-debug, remover
		memcpy((mem + pos), w, sizeof(word));
	//	free(w);
	//	word w = malloc(sizeof(word)); ??? Está vazando menos memória sem os frees? WTF?
		read_result = fread(w, sizeof(int), 1, bin_file);
		pos+=4;
	} */

	do {
		read_result = fread(mem+pos, sizeof(word), 1, bin_file);
		pos += 4;
	} while(read_result > 0);

	pause();

	//free(w);
	fclose(bin_file);
}
