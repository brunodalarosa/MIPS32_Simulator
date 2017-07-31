/* Tradutor Assembly MIPS32 */
/* Autor Bruno, bcesar.g6@gmail.com */

#include "tradutor.h"

node lista = NULL;
label_node labels = NULL;
int lbl_count = 0;

void checkSizesLocal(var_t* variaveis){
	if(variaveis->tam > values_tam){
		variaveis->valores = realloc(variaveis->valores, sizeof(int) * variaveis->tam + 1); //Aumenta em 1 o espaço
	}
}

void checkSizes(){
	if (lbl_count == lbl_tam){
		lbl_tam = lbl_tam + 5;
		lbl_values = realloc(lbl_values, sizeof(int) * lbl_tam);
	}

	if (val_count == var_tam){
		if (val_count >= 100) launchError(3); //limite maximo de variaveis
		var_tam = var_tam + 5;
		var_names = realloc(var_names, sizeof(char*) * var_tam);
	 	variaveis = realloc(variaveis, sizeof(var_t) * var_tam);
	}
}

/* Identifica e retorna a posição da label na lista de labels */
/* retorna -1 caso a label não esteja na lista				  */
/* Args| char* label : Uma label a ser identificada 		  */
int labelMatch(char* label){
	int i = 0;
	char* lbl_name;
	label_node walker = labels;

	while(walker->prox != NULL){
		lbl_name = walker->prox->nome;
		if(strcmp(label, lbl_name) == 0){
			return i;
		}

		i++;

		walker = walker->prox;
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
			return var_adress[i];
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

		case 3: //Syscall
			*bi = n->func;
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

		case 5: //NOP
			*bi = n->op | n->func;
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

		case 9: //LS
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
	int i = 0;
	fprintf(log_t_file, "\nNumero de linhas computadas = %d\n",line);

	if (lbl_count > 0) fprintf(log_t_file, "\nLabels:\n");

	label_node walker = labels->prox;
	while(walker != NULL){
		fprintf(log_t_file, "%s = %d\n",walker->nome, lbl_values[i]);
		walker = walker->prox;
		i++;
	}


	fprintf(log_t_file, "\nFim do log de tradução.");

	fclose(log_t_file);
}

/* Escreve a seção de dados do arquivo de saída, preenche a primeira parte */
/* com as variaveis declaradas e o restante dos 400 Bytes com zeros		   */
void escreveDados(){
	unsigned int* zeros;
	int i, j, size = 100 - val_count;
	int aux = 0;


	if(get_flag(FLAG_VERBOSE)) fprintf(log_t_file, "Numero de variaveis = %d\n Numero de valores totais = %d\n", var_count, val_count);

	for(i = 0; i < var_count ; i++){
		for(j = variaveis[i].tam-1; j >=0; j--){
			fwrite(&variaveis[i].valores[j], sizeof(unsigned int), 1, bin_file);
		}
	}

	/* Inverte o endereço das variaveis, necessário pois o parsing é na ordem inversa */
	if(var_count > 1){
		char** str_aux;
		str_aux = malloc(sizeof(char*) * var_count);

		for(i = var_count -1; i >= 0; i--){
			str_aux[aux] = var_names[i];
			aux++;
		}

		for(i = 0; i < var_count; i++){
			var_names[i] = str_aux[i];
		}

	}

	/* Preenche com zero o espaço que sobrou */
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
		if(get_flag(FLAG_DEBUG)){
			printaBinario(bi, 1, log_t_file);
			fprintf(log_t_file, "\n");
	 	}
		free(bi);
		lista = lista->prox;
	}
}


/* Insere um nó na lista de nós */
/* Arg| O nó a ser inserido     */
void insereLista(node n){
	node ultimo = lista;
	while(ultimo->prox != NULL){
		ultimo = ultimo->prox;
	}

	ultimo->prox = n;
}


void insereLabel(char* nome, int pos){
	//printf("passou do labelMatch: POS = %d len = %d -> %s\n",pos, strlen(nome), nome);
	label_node ultimo = labels;

	while(ultimo->prox != NULL){
		ultimo = ultimo->prox;
	}

	label_node label = malloc(sizeof(label_t));
	label->nome = nome;
	label->pos = pos;
	label->prox = NULL;
	lbl_values[pos] = line * INST_SIZE;

	ultimo->prox = label;
}


/* Inicialização do tradutor */
void tradutorInit(){
	int i ;

	/* Inicialização das listas */
	lista = malloc(sizeof(node_t));
	lista->prox = NULL;

	labels = malloc(sizeof(label_t));
	labels->prox = NULL;

	/* Definição das declarações externas */
	line = 0;
	//lbl_count = 0;
	var_count = 0;
	var_name_count = 0;
	val_count = 0;
	lbl_tam = INITIAL_SIZE;
	var_tam = INITIAL_SIZE;
	values_tam = INITIAL_SIZE;

	/* Inicialização dos Vetores para controle de Labels e variaveis */
	lbl_values = malloc(sizeof(unsigned int) * lbl_tam);

	var_names = malloc(sizeof(char*) * var_tam);
	var_adress = malloc(sizeof(unsigned int) * var_tam);

	variaveis = malloc(sizeof(var_t) * var_tam);

	for(i = 0; i < var_tam; i++){
		variaveis[i].valores = malloc(sizeof(int) * values_tam);
	}

	set_input();

	if (get_flag(FLAG_DEBUG)) fprintf(log_t_file, "\t\tLog da tradução da entrada %s\n", nome_input);

}

void tradutor(){
	yyparse();

	/*Pós parsing*/

	if(get_flag(FLAG_DEBUG)) printaNos();

	escreveDados();

	escreveTexto(lista);

	fechaLog();
	fclose(bin_file);
}
