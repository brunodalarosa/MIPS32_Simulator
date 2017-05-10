/* Tradutor Assembly MIPS32 */
/* Autor Bruno, bcesar.g6@gmail.com */

#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include "tradutor.h"
#include "parser.h"
#include "estrutura.h"

/* Definição das declarações externas */
int line = 0;
int lbl_count = 0;
int lbl_tam = 10; //lbl_tamanho inicial do vetor de labels
int var_count = 0;
int var_tam = 10; //lbl_tamanho inicial do vetor de labels

typedef unsigned int binst;

void checkSizes(){
	if (lbl_count == lbl_tam){
		lbl_tam = lbl_tam + 10;
		lbl_names = realloc(lbl_names, sizeof(char*) * lbl_tam);
		lbl_values = realloc(lbl_values, sizeof(int) * lbl_tam);
	}

	if (var_count == var_tam){
		var_tam = var_tam + 10;
		var_names = realloc(var_names, sizeof(char*) * var_tam);
		var_values = realloc(var_values, sizeof(int) * var_tam);
	}

}

binst traduz(node i){
    /*TODO recebe um nó, identifica seu tipo e constroi um objeto binst: */
    /*Uma palavra de 32 bits pronta pra ser escrita no arquivo de saida */
}

void parseargs(int argc, char **argv){
	extern char *optarg;
    char op;

	struct option longopts[] = {
		{"saida", 0, NULL, 's'},
	    {"debug", 0, NULL, 'd'}
	};

	while ((op = getopt_long(argc, argv, "sd", longopts, NULL)) != -1) {
		switch (op) {
			case 's':
				opt_saida = 1;
				break;

			case 'd':
				opt_debug = 1;
				break;
			default:

				break;
		}
	}
}

void init(){

	/* Inicialização dos Vetores para controle de Labels e variaveis */
	lbl_names  = malloc(sizeof(char*) * lbl_tam);
	lbl_values = malloc(sizeof(int) * lbl_tam);

	var_names = malloc(sizeof(char*) * var_tam);
	var_values = malloc(sizeof(int) * var_tam);
	var_adress = malloc(sizeof(int) * var_tam);
}

int main(int argc, char **argv){
	int i;

	parseargs(argc, argv);
	char nome[99] = "saida.txt";

	if(opt_saida){
		printf("Nome do arquivo de saida: ");
		scanf("%99s",nome);
		__fpurge(stdin);
	}

	if ((output = fopen(nome,"w")) == NULL) {
		printf("ERRO!\nProblema na criação do arquivo\n");
		exit(1);
	}

	if (opt_debug) {
		/* DEBUG */
		printf("Debugging pesado\n");
	}

	init();

	printf("\nIniciar magias negras MIPS32:\n\n");

	yyparse();

	/*Pós parsing*/
	fprintf(output, "\nnumero de instrucoes = %d\n",line);

	if (lbl_count > 0) fprintf(output, "\nLABELS:\n");
	for(i = 0; i < lbl_count; i++){
		fprintf(output, "%s = %d\n",lbl_names[i], lbl_values[i]);
	}

	if (var_count > 0) fprintf(output, "\nVariaveis:\n");
	for(i = 0; i < var_count; i++){
		fprintf(output, "%s (%d) = %d\n",var_names[i],
		 				var_adress[i], var_values[i]);
	}

	fprintf(output, "\nFIM\n");

	fclose(output);
	return 0;
}
