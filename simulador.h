/* Header geral do simulador Assembly MIPS32*/
/* Autor Bruno, bcesar.g6@gmail.com*/

#ifndef __SIMULADOR_H
#define __SIMULADOR_H

/* Uma palavra de 32 bits | 4 bytes*/
typedef unsigned int* word;

#include <getopt.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "parser.h"
#include "tradutor.h"
#include "memoria.h"
#include "processador.h"

/* Sistemas de flags funiona com o sistema de parametros de execução */
extern int flag;

#define FLAG_DEBUG   1
#define FLAG_VERBOSE 2



#define set_flag(opt) flag = flag | opt
#define get_flag(opt) flag & opt

/* Valores padrões de execução */
static char* saida      = "saida.txt";
static char* t_saida    = "bin";
static char* log_nome   = "log.txt";
static char* t_log_nome = "log_tradutor.txt";
static char* nome_input = "input.txt";

/* Arquivos */
extern FILE *input_file;
extern FILE *output_file;
extern FILE *bin_file;
extern FILE *log_file;
extern FILE *log_t_file;

#endif
