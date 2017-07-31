/* Bison: tradutor (Simulador MIPS32) */
/* Autor: Bruno Cesar, bcesar.g6@gmail.com */

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "simulador.h"
#include "parser.h"
#include "utils.h"
#include "tradutor.h"

extern FILE *yyin;

void set_input();
%}

/* Declaração dos tokens */
%token reg
/* 0 a 31 respectivamente, bison gera com +258, logo $zero = 258 */
%token number virg EOL END_OF_FILE
%token opcodeb opcoder opcoders opcoderd opcodel opcodei opcodelui
%token opcodej opcodet opcodemf opcodemt opcodebeq
%token abreparents fechaparents colon syscallOP NOP
%token data text id t_int

%code requires{
	typedef struct{
  		unsigned int code;
		unsigned int rs;
		unsigned int rt;
		unsigned int rd;
		unsigned int aux; //shift amount | imm | address | offset
  		unsigned int func;
		char* label;
	} strcinst; //struct instrucao
}

%defines "parser.h"

%union{
	int val;
	strcinst op;
	char* text;
}

%%
saida: secao_data secao_text END_OF_FILE { return 0;}
| secao_data EOL secao_text END_OF_FILE{ return 0;}
| secao_text END_OF_FILE {fprintf(log_t_file, "\nsem secao de dados\n"); return 0;}
;

secao_data: data EOL var
| data
;

secao_text: text EOL instrucao
;

instrucao: linha EOL instrucao {}
| labelid linha EOL instrucao {}
| /*Vazio*/
;

linha: operacao {}

operacao: /* nada */
| syscallOP {line++;
		  fprintf(log_t_file, "Op Syscall: 0 0 12\n");
	  	  node n = malloc(sizeof(node_t));
	  	  n->tipo = 3;
	  	  n->op = 0;
	      n->aux = 0;
	  	  n->func = 12;
	  	  insereLista(n); }

| NOP {line++;
		fprintf(log_t_file, "OP NOP: 60 0 0\n");
		node n = malloc(sizeof(node_t));
	    n->tipo = 5;
		n->op = 60;
		n-> aux = 0;
		n->func = 0;
		insereLista(n); }

| R {line++;
	fprintf(log_t_file,"Op tipo R: %d %d %d %d %d %d\n",
 						  		$<op.code>1, $<op.rs>1, $<op.rt>1,
						  		$<op.rd>1, $<op.aux>1, $<op.func>1);

    node n = malloc(sizeof(node_t));
	n->tipo = 1;
	n->op   = $<op.code>1;
 	n->rs   = $<op.rs>1;
	n->rt   = $<op.rt>1;
    n->rd   = $<op.rd>1;
    n->aux  = $<op.aux>1;
	n->func = $<op.func>1;
    insereLista(n); }

| I {line++;
	 if ($<op.label>1 == NULL){
		fprintf(log_t_file,"Op tipo I: %d %d %d %d\n",
	  						        $<op.code>1, $<op.rs>1, $<op.rt>1,
								    $<op.aux>1);

		node n = malloc(sizeof(node_t));
		n->tipo = 2;
		n->op   = $<op.code>1;
		n->rs   = $<op.rs>1;
		n->rt   = $<op.rt>1;
		n->aux  = $<op.aux>1;
		insereLista(n);}
	else {
		fprintf(log_t_file, "Op tipo B: %d %d %d %s\n", $<op.code>1, $<op.rs>1,
													$<op.rt>1, $<op.label>1);
		node n 	 = malloc(sizeof(node_t));
		n->tipo  = 8;
		n->op 	 = $<op.code>1;
		n->label = $<op.label>1;
 		n->rt    = $<op.rt>1;
		n->rs	 = $<op.rs>1;
		insereLista(n);}
}

| LS {line++;
	  if ($<op.label>1 == NULL){
		fprintf(log_t_file,"Op tipo LS reg: %d %d %d %d\n",
									$<op.code>1, $<op.rs>1, $<op.rt>1,
									$<op.aux>1);

		node n = malloc(sizeof(node_t));
		n->tipo = 9;
		n->op   = $<op.code>1;
		n->rs   = $<op.rs>1;
		n->rt   = $<op.rt>1;
		n->aux  = $<op.aux>1;
		insereLista(n);}
	else {
		fprintf(log_t_file, "Op tipo LS var: %d %d %d %s\n", $<op.code>1, $<op.rs>1,
													$<op.rt>1, $<op.label>1);
		node n 	 = malloc(sizeof(node_t));
		n->tipo  = 9;
		n->op 	 = $<op.code>1;
		n->label = $<op.label>1;
		n->rt    = $<op.rt>1;
		n->rs	 = $<op.rs>1;
		insereLista(n);}
}

| J {line++;
	 if ($<op.label>1 != NULL){
		fprintf(log_t_file,"Op tipo J: %d %s\n", $<op.code>1, $<op.label>1);

		node n = malloc(sizeof(node_t));
		n->tipo  = 4;
		n->op    = $<op.code>1;
		n->label = $<op.label>1;
		insereLista(n);}

		 else {
		fprintf(log_t_file,"Op tipo J: %d %d\n", $<op.code>1, $<op.aux>1);

		node n = malloc(sizeof(node_t));
		n->tipo = 4;
		n->op   = $<op.code>1;
		n->aux  = $<op.aux>1;
		insereLista(n);}
}


| M {line++;
	 fprintf(log_t_file, "Op tipo M: %d %d %d %d %d\n",
						  $<op.code>1, $<op.rs>1, $<op.rt>1, $<op.rd>1,
					      $<op.func>1);

			  node n = malloc(sizeof(node_t));
			  n->tipo = 7;
			  n->op   = $<op.code>1;
			  n->rs   = $<op.rs>1;
			  n->rt   = $<op.rt>1;
			  n->rd   = $<op.rd>1;
			  n->aux  = 0;
			  n->func = $<op.func>1;
			  insereLista(n);}

R: opcoder reg virg reg virg reg {
	$<op.rd>$  = $<val>2;
	$<op.rs>$  = $<val>4;
	$<op.rt>$  = $<val>6;
	$<op.aux>$ = 0;}

| opcoder reg virg reg { //clo & clz
	$<op.rs>$ = $<val>4;
	$<op.rt>$ = 0;
	$<op.rd>$ = $<val>2;
	$<op.aux>$ = 0;}

|  opcoders reg virg reg virg reg {
	$<op.rd>$  = $<val>2;
	$<op.rt>$  = $<val>4;
	$<op.rs>$  = $<val>6;
	$<op.aux>$ = 0;}

|  opcoders reg virg reg virg shamt {
	$<op.rd>$    = $<val>2;
	$<op.rt>$    = $<val>4;
	$<op.aux>$   = $<val>6; //shift amount
	$<op.rs>$    = 0;}

| opcodej reg virg reg {
	$<op.rs>$   = $<val>2;
	$<op.rt>$   = 0;
	$<op.rd>$   = $<val>4;
	$<op.aux>$  = 0;}

|  opcodej reg {
	$<op.rs>$   = $<val>2;
	$<op.rt>$   = 0;
	$<op.rd>$   = 0;
	$<op.aux>$  = 0;}

|  opcoderd reg virg reg { //div & divu & madd & maddu & msub & msubu
	$<op.rs>$  = $<val>2;
	$<op.rt>$  = $<val>4;
	$<op.rd>$  = 0;
	$<op.aux>$ = 0;}
;

I: opcodei reg virg reg virg imm{
	$<op.rs>$  = $<val>4;
	$<op.rt>$  = $<val>2;
	$<op.aux>$ = $<val>6;} //imm

|  opcodelui reg virg imm{
	$<op.rs>$  = 0;
    $<op.rt>$  = $<val>2;
	$<op.aux>$ = $<val>4;} //imm

|  opcodet reg virg imm{
	$<op.rs>$  = $<val>2;
	$<op.rt>$  = $<op.func>1;
	$<op.aux>$ = $<val>4;}

|  opcodet reg virg reg{
	$<op.rs>$  = $<val>2;
	$<op.rt>$  = $<val>4;
	$<op.rd>$  = 0;
	$<op.aux>$ = 0;}

| opcodeb reg virg id{
	$<op.rs>$ = $<val>2;
	$<op.rt>$ = $<op.func>1;
	$<op.label>$ = $<text>4;}

| opcodebeq reg virg reg virg id{
	$<op.rs>$ = $<val>2;
	$<op.rt>$ = $<val>4;
	$<op.label>$ = $<text>6;}
;

LS: opcodel reg virg offset abreparents reg fechaparents {
	$<op.rt>$  = $<val>2;
	$<op.aux>$ = $<val>4; //offset
	$<op.rs>$  = $<val>6;}

|  opcodel reg virg id {
	$<op.rt>$  = $<val>2;
	$<op.label>$ = $<text>4;
	$<op.rs>$ = 0;} //address = 0 + var_address
;

J: opcodej address{ $<op.aux>$ = $<val>2; }
|  opcodej id { $<op.label>$ = $<text>2; }
;

M: opcodemf reg virg reg { //mfc0 & mfc1
	$<op.rs>$ = 0;
	$<op.rt>$ = $<val>2;
	$<op.rd>$ = $<val>4;}

| opcodemt reg virg reg {
	$<op.rs>$ = 4;
	$<op.rt>$ = $<val>2;
	$<op.rd>$ = $<val>4;}

| opcodemt reg{ //mthi & mtlo
	$<op.rs>$ = $<val>2;
	$<op.aux>$ = 0;}

| opcodemf reg{ //mfhi & mflo
	$<op.rs>$ = 0;
	$<op.rt>$ = 0;
	$<op.rd>$ = $<val>2;
	$<op.aux>$ = 0;}

| opcodemf reg virg reg virg reg{ //movn & movz
	$<op.rd>$ = $<val>2;
	$<op.rs>$ = $<val>4;
	$<op.rt>$ = $<val>6;
	$<op.aux>$ = 0;}
;


labelid: id colon { checkSizes();
			if ( labelMatch($<text>1) == -1){
				  insereLabel($<text>1, lbl_count);
				  lbl_count++;
			 } else { launchError(1);}
		 }

| id colon EOL { checkSizes();
		if ( labelMatch($<text>1) == -1){
				 insereLabel($<text>1, lbl_count);
		   		 lbl_count++;
				 } else { launchError(1);}
			 }
;

var: id colon val var {
				checkSizes();
				var_names[var_name_count] = $<text>1;
				var_adress[var_name_count] = val_count * INST_SIZE;
				val_count += variaveis[var_name_count].tam;
				var_name_count++;}

| id colon val {
				checkSizes();
				var_names[var_name_count] = $<text>1;
				var_adress[var_name_count] = val_count * INST_SIZE;
				val_count += variaveis[var_name_count].tam;
				var_name_count++;}
;

val: number EOL {
		checkSizesLocal(&variaveis[var_count]);
		variaveis[var_count].valores[variaveis[var_count].tam] = $<val>1;
		variaveis[var_count].tam++;
		}

| number virg val{
	checkSizesLocal(&variaveis[var_count]);
	variaveis[var_count].valores[variaveis[var_count].tam] = $<val>1;
	variaveis[var_count].tam++;
	}

| t_int number virg val{
	checkSizesLocal(&variaveis[var_count]);
	variaveis[var_count].valores[variaveis[var_count].tam] = $<val>2;
	variaveis[var_count].tam++;
	var_count++;}

| t_int number EOL{
	checkSizesLocal(&variaveis[var_count]);
	variaveis[var_count].valores[variaveis[var_count].tam] = $<val>2;
	variaveis[var_count].tam++;
	var_count++;
}
;

address: number;
shamt: number;
offset: number;
imm: number;
%%

void set_input(){
	yyin = input_file;
}

yyerror(char *s) {
	fprintf(stderr, "erro na linha %d: %s\n", line ,s);
	fprintf(log_t_file, "erro na linha %d: %s\n", line ,s);
	launchError(0);
}
