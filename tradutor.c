/* Tradutor Assembly MIPS32 */
/* Autor Bruno, bcesar.g6@gmail.com */

#include "tradutor.h"

void checkSizes(){
	if (lbl_count == lbl_tam){
		lbl_tam = lbl_tam + 5;
		lbl_names = realloc(lbl_names, sizeof(char*) * lbl_tam);
		lbl_values = realloc(lbl_values, sizeof(int) * lbl_tam);
	}

	if (var_count == var_tam){
		if (var_count >= 100) launchError(3); //limite maximo de variaveis
		var_tam = var_tam + 5;
		var_names = realloc(var_names, sizeof(char*) * var_tam);
		var_values = realloc(var_values, sizeof(int) * var_tam);
	}
}

/* Identifica e retorna a posição da label na lista de labels */
/* retorna -1 caso a label não esteja na lista				  */
/* Args| char* label : Uma label a ser identificada 		  */
int labelMatch(char* label){
	int i;
	for(i = 0; i < lbl_count; i++){
		if(strcmp(label, lbl_names[i]) == 0){
			return i;
		}
	}
	return -1;
}

/* Identifica e retorna o endereço de uma variavel		 */
/* retorna -1 caso a variavel não exista				 */
/* Args| char* id : O endereço da variavel identificada  */
int varMatch(char* id){
	int i;
	for(i = 0; i < var_count; i++){
		if(strcmp(id, var_names[i]) == 0){
			return (i * 32);
		}
	}
	return -1;
}


/* Identifica o tipo da instrução e constrói um objeto word */
/* Arg| Node n : Um nó a ser traduzido						 */
word traduz(node n){
	int shift = 26; //32 - 6(op)
	word bi = malloc(sizeof(int));
	n->op <<= shift;
	int tipo = n->tipo;

	switch (tipo) {
		case 1: //R
			shift -= 5; //21
			n->rs <<= shift;
			shift -= 5; //16
			n->rt <<= shift;
			shift -= 5; //11
			n->rd <<= shift;
			shift -= 5; //6
			n->aux <<= shift;

			*bi = n->op | n->rs | n-> rt | n-> rd | n->aux | n->func;
			break;

		case 2: //I
			shift -= 5; //21
			n->rs <<= shift;
			shift -= 5; //16
			n->rt <<= shift;

			*bi = n->op | n->rs | n-> rt | n->aux;
			break;

		case 4: //J
			if (n-> label != NULL){
				int p = labelMatch(n->label);
				if (p == -1) launchError(2);

				*bi = n->op | lbl_values[p];
			} else{

				*bi = n->op | n->aux;
			}
			break;

		case 7: //M
			shift -= 5; //21
			n->rs <<= shift;
			shift -= 5; //16
			n->rt <<= shift;
			shift -= 5; //11
			n->rd <<= shift;
			shift -= 5; //6
			n->aux <<= shift;

			*bi = n->op | n->rs | n-> rt | n-> rd | n->aux | n->func;
			break;

		case 8: //B
			shift -= 5; //21
			n->rs <<= shift;
			shift -= 5; //16
			n->rt <<= shift;

			if (n-> label != NULL){
				int p = labelMatch(n->label);
				if (p == -1) launchError(4);

				*bi = n->op | n->rs | n-> rt | lbl_values[p];
			}
			break;

		case 9: //SL
			shift -= 5; //21
			n->rs <<= shift;
			shift -= 5; //16
			n->rt <<= shift;

			if (n-> label != NULL){
				int p = varMatch(n->label);
				if (p == -1) launchError(6);

				*bi = n->op | n->rs | n-> rt | p;
			} else{
				*bi = n->op | n->rs | n-> rt | n->aux;
			}
			break;

		default:
			break;
	}

	return bi;
}

/* Insere um nó na lista de nós */
/* Arg| O nó a ser inserido     */
void insereLista(node n){
	node ultimo = lista;
	while(ultimo->prox != NULL) ultimo = ultimo->prox;

	ultimo->prox = n;
}

/* Caminha pela lista de instruções printando uma a uma */
void printaNos(){
	int i = 1;
	node walker = lista->prox;

	fprintf(log_t_file, "\nLista de nós:\n");
	while(walker != NULL){

		fprintf(log_t_file, "%2d[%d]|Op = %2d|rs = %2d|rt = %2d|rd = %2d|aux = %2d|func = %2d %s\n",
		i, walker->tipo, walker->op, walker->rs, walker->rt, walker->rd,
		walker->aux, walker->func, walker->label);

		walker = walker->prox;
		i++;
	}
	fprintf(log_t_file,"\n\t\tfim da lista\n");
}

/* Finaliza, salva e fecha o arquivo de log */
void fechaLog(){
	int i;
	fprintf(log_t_file, "\nNumero de linhas computadas = %d\n",line);

	if (lbl_count > 0) fprintf(log_t_file, "\nLabels:\n");
	for(i = 0; i < lbl_count; i++){
		fprintf(log_t_file, "%s = %d\n",lbl_names[i], lbl_values[i]);
	}

	if (var_count > 0) fprintf(log_t_file, "\nVariaveis:\n");
	for(i = 0; i < var_count; i++){
		fprintf(log_t_file, "%s (%d) = %d\n",var_names[i],
						var_adress[i], var_values[i]);
	}

	fprintf(log_t_file, "\nFim do log de tradução.");

	fclose(log_t_file);
}

/* Escreve a seção de dados do arquivo de saída, preenche a primeira parte */
/* com as variaveis declaradas e o restante dos 400 Bytes com zeros		   */
void escreveDados(){
	unsigned int* zeros;
	int i, size = 100 - var_count;

	if(get_flag(FLAG_VERBOSE)) printf("Numero de variaveis = %d\n", var_count);

	/* Escreve na ordem certa */
	for(i = var_count-1; i >= 0; i--){
		fwrite(&var_values[i], sizeof(unsigned int), 1, bin_file);
	}

	zeros = (unsigned int*) calloc(size, sizeof(unsigned int));
	fwrite(zeros, sizeof(unsigned int), size, bin_file);
}

/* Escreve todas as instruções traduzidas	  */
/* na lista de instruções no arquivo de saida */
void escreveTexto(){
	word bi;
	lista = lista->prox;
	while(lista != NULL){
		bi = traduz(lista);
		fwrite(bi, sizeof(unsigned int), 1, bin_file);
		if(get_flag(FLAG_DEBUG)) printaBinario(bi, 1, log_t_file);
		free(bi);
		lista = lista->prox;
	}
}


/* Inicialização do tradutor */
void tradutorInit(){
	/* Inicialização da lista de instruções */
	lista = malloc(sizeof(node_t));
	lista->prox = NULL;

	/* Definição das declarações externas */
	line = 0;
	lbl_count = 0;
	lbl_tam = 10; //lbl_tamanho inicial do vetor de labels
	var_count = 0;
	var_tam = 10; //lbl_tamanho inicial do vetor de labels

	/* Inicialização dos Vetores para controle de Labels e variaveis */
	lbl_names  = malloc(sizeof(char*) * lbl_tam);
	lbl_values = malloc(sizeof(unsigned int) * lbl_tam);

	var_names = malloc(sizeof(char*) * var_tam);
	var_values = malloc(sizeof(unsigned int) * var_tam);
	var_adress = malloc(sizeof(unsigned int) * var_tam);

	set_input();

	if (get_flag(FLAG_DEBUG)){
		printf("\nDebugging : Etapa Tradução\n");
		fprintf(log_t_file, "\t\tLog da tradução da entrada %s\n", nome_input);
	}
}

void tradutor(){
	int i;

	yyparse();

	/*Pós parsing*/

	if(get_flag(FLAG_DEBUG)) printaNos();

	escreveDados();

	/* Por que isso tá aqui? */
	/*if(get_flag(FLAG_DEBUG)){
		word dados = malloc(sizeof(unsigned int) * 100);
		fseek(bin_file, 0, SEEK_SET);
		fread((void*) dados, sizeof(unsigned int), 100, bin_file);
		int q;
		for(q = 0; q < 100; q++){
			printaBinario(&dados[q],);
		}
	}*/

	escreveTexto(lista);

	/* TODO finazlizar o arquivo */

	fechaLog();
	fclose(bin_file);
}
