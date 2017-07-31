/* Arquivo Main do simulador Assembly MIPS32 */
/* Autor Bruno, bcesar.g6@gmail.com */


#include "simulador.h"

int flag = 0;
FILE *input_file  = NULL;
FILE *bin_file    = NULL;
FILE *output_file = NULL;
FILE *log_file    = NULL;
FILE *log_t_file  = NULL;

/* Valores padrões de execução */
char* saida      = "saida.txt";
char* t_saida    = "bin";
char* log_nome   = "log.txt";
char* t_log_nome = "log_tradutor.txt";
char* nome_input = "input.txt";

/* Função de leitura dos parametros de execução */
void parseargs(int argc, char **argv){
	extern char *optarg;
    char op;

	struct option longopts[] = {
		{"saida", required_argument, NULL, 'o'},
        {"log", required_argument, NULL, 'l'},
        {"t_saida", required_argument, NULL, 't'},
        {"t_log", required_argument, NULL, 'm'},
        {"verbose", no_argument, NULL, 'v'},
        {"debug", no_argument, NULL, 'd'},
		{"step-by-step", no_argument, NULL, 's'},
		{"register-print", no_argument, NULL, 'r'},
		{"help", no_argument, NULL, 'h'}
	};

	while ((op = getopt_long(argc, argv, "o:l:t:m:dvsrh", longopts, NULL)) != -1) {
		switch (op) {
			case 'o':
				saida = optarg;
				break;

            case 'l':
                log_nome = optarg;
                break;

            case 't':
                t_saida = optarg;
                break;

            case 'm':
                t_log_nome = optarg;
                break;

            case 'v':
                set_flag(FLAG_VERBOSE);
                break;

            case 'd':
                set_flag(FLAG_DEBUG);
                break;

			case 's':
				set_flag(FLAG_STEP_BY_STEP);
				break;

			case 'r':
				set_flag(FLAG_REGISTRADORES);
				break;

            case 'h':
                ajuda();
                exit(0);
		}
	}

    /* Argumento de entrada */
    if (optind < argc){
        nome_input = malloc(sizeof(char) * strlen(argv[optind])+1);
        strcpy(nome_input, argv[optind++]);

        /* verificar se foi passado algum argumento a mais */
        if (optind < argc) launchError(2);
    }

}

/* Inicializa o simulador */
void init(){
	if ((input_file = fopen(nome_input,"r")) == NULL){
		launchError(1);
	}

	if ((output_file = fopen(saida,"w+")) == NULL) {
		launchError(0);
	}

	if ((bin_file = fopen(t_saida,"w+")) == NULL) {
		launchError(0);
	}

	if ((log_file = fopen(log_nome,"w+")) == NULL) {
		launchError(0);
	}

	if ((log_t_file = fopen(t_log_nome,"w+")) == NULL) {
		launchError(0);
	}

	/* Inicializa a memoria */
	mem = calloc(MEM_SIZE, 1); //Malloc + inicia como 0

	tradutorInit();
	processadorInit();
	ulaInit();
	cacheInit();
	registradoresInit();
}


void printBanner(){
							       printf("\n|               ===== Simulador MIPS-32 ====              |\n");
								     printf("|     Versao 1.0  / Desenvolvido por bcesar.g6@gmail.com  |\n");
									 printf("-----------------------------------------------------------\n");
									 printf("| Tamanho da memoria = %d bytes ( %d MB)          |\n", MEM_SIZE, (MEM_SIZE/ 1024 / 1024));

	if(get_flag(FLAG_DEBUG))         printf("| Debugging ativado                                       |\n");
	if(get_flag(FLAG_VERBOSE)) 	     printf("| Execução modo Verbose                                   |\n");
	if(get_flag(FLAG_STEP_BY_STEP))  printf("| Execução passo-a-passo ativada                          |\n");
	if(get_flag(FLAG_REGISTRADORES)) printf("| Printando o banco de registradores durante a execução   |\n");

}

/* Função main */
int main(int argc, char **argv){

    parseargs(argc, argv);

	init();

	if(get_flag(FLAG_VERBOSE)) printBanner();

	tradutor();

	if(get_flag(FLAG_VERBOSE)) printf("\n> Tradução realizada com sucesso!\n");

	readProgram();

	if(get_flag(FLAG_DEBUG)){
		printf("\nDeseja printar parte inicial da memoria?\n");
		if(prompt()) printMem();
		getchar();
	}

	if(get_flag(FLAG_STEP_BY_STEP)){
		printf("\nPressione ENTER para inicar a simulação do programa\n");
		getchar();
	}

	if(get_flag(FLAG_VERBOSE)) system("clear");

	while(run()); //Loop do clock

	printf("\nExecução concluída com sucesso\n");
	fprintf(output_file, "\nExecução concluída com sucesso\n");

	fclose(output_file);
	fclose(log_file);
	return 0;
}
