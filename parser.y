/* Bison: Teste do tradutor (Simulador MIPS32)*/
%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estrutura.h"
#include "parser.h"
%}

/* Declaração dos tokens */
%token reg
/* 0 a 31 respectivamente, bison gera com +258, logo $zero = 258 */
%token number virg EOL END_OF_FILE
%token opcoder opcoders opcoderd opcodel opcodei opcodelui
%token opcodeb opcodej opcodejr opcodet opcodemf opcodemt
%token abreparents fechaparents colon
%token data text id

%code requires{
	typedef struct{
  		int code;
		int rs;
		int rt;
		int rd;
		int aux; //shift amount | imm | address | offset
  		int func;
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
| secao_text END_OF_FILE {fprintf(log, "\nsem secao de dados\n"); return 0;}
;

secao_data: data EOL var
| data
;

secao_text: text EOL instrucao
;

instrucao: linha EOL instrucao {}
| label linha EOL instrucao {}
| /*Vazio*/
;

linha: operacao {line++;}

operacao: /* nada */
| R {fprintf(log,"Op tipo R: %d %d %d %d %d %d\n",
 						  		$<op.code>1, $<op.rs>1, $<op.rt>1,
						  		$<op.rd>1, $<op.aux>1, $<op.func>1);}

| RD {fprintf(log,"Op tipo RD: %d %d %d %d %d\n",
 								  $<op.code>1, $<op.rs>1, $<op.rt>1,
							  	  $<op.aux>1, $<op.func>1);}

| L {fprintf(log,"Op tipo L: %d %d %d %d\n",
 								$<op.code>1, $<op.rs>1, $<op.rt>1, $<op.aux>1);}

| I {fprintf(log,"Op tipo I: %d %d %d %d\n",
  						        $<op.code>1, $<op.rs>1, $<op.rt>1,
							    $<op.aux>1);}

| B {fprintf(log,"Op tipo B: %d %d %d %d\n",
  						        $<op.code>1, $<op.rs>1, $<op.func>1,
							    $<op.aux>1);}

| BC {fprintf(log,"Op tipo BC: %d %d %d %d %d\n",
 								  $<op.code>1, $<op.rs>1, $<op.rt>1,
							  	  $<op.func>1, $<op.aux>1);}

| J {fprintf(log,"Op tipo J: %d %d\n", $<op.code>1, $<op.aux>1);}

| JR {fprintf(log,"Op tipo JR: %d %d %d %d\n",
 								  $<op.code>1, $<op.rs>1,
								  $<op.aux>1, $<op.func>1);}

| T {fprintf(log, "Op tipo T: %d %d %d %d %d\n", $<op.code>1,
 						       $<op.rs>1,$<op.rt>1, $<op.aux>1, $<op.func>1);}

| M {fprintf(log, "Op tipo M: %d %d %d %d %d\n",
 								  $<op.code>1, $<op.rs>1, $<op.rt>1, $<op.rd>1,
							      $<op.func>1);}

| MT {fprintf(log, "Op tipo M: %d %d %d %d %d\n",
 						  	       $<op.code>1, $<op.rs>1, $<op.rt>1,
						           $<op.rd>1, $<op.func>1);}

| MF {fprintf(log, "Op tipo MF: %d %d %d %d %d\n",
 						           $<op.code>1, $<op.rs>1, $<op.rd>1,
								   $<op.aux>1, $<op.func>1);}

| MS {fprintf(log, "Op tipo M Especial: %d %d %d %d %d %d %d\n",
 						  $<op.code>1, $<op.rs>1, $<op.aux>1, $<op.func>1,
					   	  $<op.rd>1, 0, 1);}
;


R: opcoder reg virg reg virg reg {
	$<op.rs>$  = $<val>2;
	$<op.rt>$  = $<val>4;
	$<op.rd>$  = $<val>6;
	$<op.aux>$ = 0;}

| opcoder reg virg reg {
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
;

RD: opcoderd reg virg reg {
	$<op.rs>$ = $<val>2;
	$<op.rt>$ = $<val>4;
	$<op.aux>$ = 0;}
;

L: opcodel reg virg offset abreparents reg fechaparents {
	$<op.rt>$  = $<val>2;
	$<op.aux>$ = $<val>4; //offset
	$<op.rs>$  = $<val>6;
};

I: opcodei reg virg reg virg imm{
	$<op.rs>$  = $<val>2;
	$<op.rt>$  = $<val>4;
	$<op.aux>$ = $<val>6;} //imm

|  opcodelui reg virg imm{
	$<op.rs>$  = 0;
    $<op.rt>$  = $<val>2;
	$<op.aux>$ = $<val>4;} //imm

|  opcodeb reg virg reg virg label{ //beq
	$<op.rs>$  = $<val>2;
	$<op.rt>$  = $<val>4;
	$<op.aux>$ = $<val>6;} //label | offset

|  opcodet reg virg imm{  //TESTAR DEVE ESTAR ERRADO
	$<op.rs>$  = $<val>2;
	$<op.rt>$  = $<op.func>1;
	$<op.aux>$ = $<val>4;
}
;

B: opcodeb reg virg label{
	$<op.rs>$  = $<val>2;
	$<op.aux>$ = $<val>4;} //label | offset
;

BC: opcodeb cc label{
	$<op.rs>$ = 8;
	$<op.rt>$ = $<val>2;
	$<op.aux>$ = $<val>3;}
;

J: opcodej address{ $<op.aux>$ = $<val>2;}
; //address

JR: opcodejr reg{
	$<op.rs>$ = $<val>2;
	$<op.aux>$ = 0;}
;

T: opcodet reg virg reg {
	$<op.rs>$  = $<val>2;
	$<op.rt>$  = $<val>4;
	$<op.aux>$ = 0;}
;

M: opcodemf reg virg reg {
	$<op.rs>$ = 0;
	$<op.rt>$ = $<val>2;
	$<op.rd>$ = $<val>4;}

| opcodemt reg virg reg {
	$<op.rs>$ = 4;
	$<op.rt>$ = $<val>2;
	$<op.rd>$ = $<val>4;}

| opcodemf reg virg reg virg reg{ //movn & movz
	$<op.rd>$ = $<val>2;
	$<op.rs>$ = $<val>4;
	$<op.rt>$ = $<val>6;}
;

MF: opcodemf reg{
	$<op.rs>$ = 0;
	$<op.rd>$ = $<val>2;
	$<op.aux>$ = 0;}
;

MT: opcodemt reg{
	$<op.rs>$ = $<val>2;
	$<op.rd>$ = 0;}
;

MS: opcodemf reg virg reg virg cc{ //movf & movt
	$<op.rd>$  = $<val>2;
	$<op.rs>$  = $<val>4;
	$<op.aux>$  = $<val>6;}
;

label: id colon { checkSizes();
				  lbl_names[lbl_count] = $<text>1;
				  lbl_values[lbl_count] = DATA_OFFSET + line * INST_SIZE;
		    	  lbl_count++; line++;}

| id EOL colon { checkSizes();
				 lbl_names[lbl_count] = $<text>1;
		   		 lbl_values[lbl_count] = DATA_OFFSET + line * INST_SIZE;
		   		 lbl_count++; line++;}
;

var: id colon number EOL var { checkSizes();
							   var_names[var_count] = $<text>1;
							   var_adress[var_count] = var_count * INST_SIZE;
							   var_values[var_count] = $<val>3;
				    		   var_count++;}

| id colon number EOL { checkSizes();
						var_names[var_count] = $<text>1;
						var_adress[var_count] = var_count * INST_SIZE;
						var_values[var_count] = $<val>3;
				    	var_count++;}
;

address: number;
shamt: number;
label: number; //**
offset: number;
imm: number;
cc: number;
%%

yyerror(char *s) {
	fprintf(stderr, "error: %s\n", s);
}
