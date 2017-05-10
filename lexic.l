/* flex: Teste 1 tradutor (Simulador MIPS32) */
%{
# include "parser.h"
%}

%%
".data" {return data;}
".text" {return text;}

"$zero"|"$0" { yylval.val = 0; return reg;} /*Registradores*/
"$at" { yylval.val = 1;   return reg;}
"$v0" { yylval.val = 2;   return reg;}
"$v1" { yylval.val = 3;   return reg;}
"$a0" { yylval.val = 4;   return reg;}
"$a1" { yylval.val = 5;   return reg;}
"$a2" { yylval.val = 6;   return reg;}
"$a3" { yylval.val = 7;   return reg;}
"$t0" { yylval.val = 8;   return reg;}
"$t1" { yylval.val = 9;   return reg;}
"$t2" { yylval.val = 10;  return reg;}
"$t3" { yylval.val = 11;  return reg;}
"$t4" { yylval.val = 12;  return reg;}
"$t5" { yylval.val = 13;  return reg;}
"$t6" { yylval.val = 14;  return reg;}
"$t7" { yylval.val = 15;  return reg;}
"$s0" { yylval.val = 16;  return reg;}
"$s1" { yylval.val = 17;  return reg;}
"$s2" { yylval.val = 18;  return reg;}
"$s3" { yylval.val = 19;  return reg;}
"$s4" { yylval.val = 20;  return reg;}
"$s5" { yylval.val = 21;  return reg;}
"$s6" { yylval.val = 22;  return reg;}
"$s7" { yylval.val = 23;  return reg;}
"$t8" { yylval.val = 24;  return reg;}
"$t9" { yylval.val = 25;  return reg;}
"$k0" { yylval.val = 26;  return reg;}
"$k1" { yylval.val = 27;  return reg;}
"$gp" { yylval.val = 28;  return reg;}
"$sp" { yylval.val = 29;  return reg;}
"$fp" { yylval.val = 30;  return reg;}
"$ra" { yylval.val = 31;  return reg;}

"add"   {yylval.op.code = 0;   yylval.op.func = 32;  return opcoder;}/*ops R*/
"addu"  {yylval.op.code = 0;   yylval.op.func = 33;  return opcoder;}
"and"   {yylval.op.code = 0;   yylval.op.func = 36;  return opcoder;}
"clo"   {yylval.op.code = 28;  yylval.op.func = 32;  return opcoder;}/*rd-rs*/
"clz"   {yylval.op.code = 28;  yylval.op.func = 33;  return opcoder;}/*rd-rs*/
"div"   {yylval.op.code = 0;   yylval.op.func = 26;  return opcoderd;}/*rs-rt*/
"divu"  {yylval.op.code = 0;   yylval.op.func = 27;  return opcoderd;}/*rs-rt*/
"mult"  {yylval.op.code = 0;   yylval.op.func = 24;  return opcoder;}
"multu" {yylval.op.code = 0;   yylval.op.func = 25;  return opcoder;}
"mul"   {yylval.op.code = 28;  yylval.op.func = 2;   return opcoder;}
"madd"  {yylval.op.code = 28;  yylval.op.func = 0;   return opcoderd;}/*rs-rt*/
"maddu" {yylval.op.code = 28;  yylval.op.func = 1;   return opcoderd;}/*rs-rt*/
"msub"  {yylval.op.code = 28;  yylval.op.func = 4;   return opcoderd;}/*rs-rt*/
"msubu" {yylval.op.code = 28;  yylval.op.func = 5;   return opcoderd;}/*rs-rt*/
"nor"   {yylval.op.code = 0;   yylval.op.func = 39;  return opcoder;}
"or"    {yylval.op.code = 0;   yylval.op.func = 37;  return opcoder;}
"sub"   {yylval.op.code = 0;   yylval.op.func = 34;  return opcoder;}
"subu"  {yylval.op.code = 0;   yylval.op.func = 35;  return opcoder;}
"xor"   {yylval.op.code = 0;   yylval.op.func = 38;  return opcoder;}
"slt"   {yylval.op.code = 0;   yylval.op.func = 42;  return opcoder;}
"sltu"  {yylval.op.code = 0;   yylval.op.func = 43;  return opcoder;}

"sll"  {yylval.op.code = 0;   yylval.op.func = 0;  return opcoders;}/*ops RS*/
"sllv" {yylval.op.code = 0;   yylval.op.func = 4;  return opcoders;}
"sra"  {yylval.op.code = 0;   yylval.op.func = 3;  return opcoders;}
"srav" {yylval.op.code = 0;   yylval.op.func = 7;  return opcoders;}
"srl"  {yylval.op.code = 0;   yylval.op.func = 2;  return opcoders;}
"srlv" {yylval.op.code = 0;   yylval.op.func = 6;  return opcoders;}

"addi"   {yylval.op.code = 8;  return opcodei;} /*ops I*/
"addiu"  {yylval.op.code = 9;  return opcodei;}
"andi"   {yylval.op.code = 12; return opcodei;}
"ori"    {yylval.op.code = 13; return opcodei;}
"xori"   {yylval.op.code = 14; return opcodei;}
"lui"    {yylval.op.code = 15; return opcodelui;}
"slti"   {yylval.op.code = 10; return opcodei;}
"sltiu"  {yylval.op.code = 11; return opcodei;}



"bc1f"   {yylval.op.code = 17; yylval.op.func = 0;  return opcodeb;}
"bc1t"   {yylval.op.code = 17; yylval.op.func = 1;  return opcodeb;}
"beq"    {yylval.op.code = 4;  return opcodeb;}
"bgez"   {yylval.op.code = 1;  yylval.op.func = 1;  return opcodeb;}
"bgezal" {yylval.op.code = 1;  yylval.op.func = 17; return opcodeb;}
"bgtz"   {yylval.op.code = 7;  yylval.op.func = 0;  return opcodeb;}
"blez"   {yylval.op.code = 6;  yylval.op.func = 0;  return opcodeb;}
"bltzal" {yylval.op.code = 1;  yylval.op.func = 16; return opcodeb;}
"bltz"   {yylval.op.code = 1;  yylval.op.func = 0;  return opcodeb;}
"bne"    {yylval.op.code = 5;  return opcodeb;}

"j"    {yylval.op.code = 2; return opcodej;}
"jal"  {yylval.op.code = 3; return opcodej;}
"jalr" {yylval.op.code = 0; yylval.op.func = 9; return opcodej;}
"jr"   {yylval.op.code = 0; yylval.op.func = 8; return opcodejr;}

"teq"   {yylval.op.code = 0; yylval.op.func = 52; return opcodet;}
"teqi"  {yylval.op.code = 1; yylval.op.func = 12; return opcodet;}
"tne"   {yylval.op.code = 0; yylval.op.func = 54; return opcodet;}
"tnei"  {yylval.op.code = 0; yylval.op.func = 14; return opcodet;}
"tge"   {yylval.op.code = 0; yylval.op.func = 48; return opcodet;}
"tgeu"  {yylval.op.code = 0; yylval.op.func = 49; return opcodet;}
"tgei"  {yylval.op.code = 1; yylval.op.func = 8;  return opcodet;}
"tgeiu" {yylval.op.code = 1; yylval.op.func = 9;  return opcodet;}
"tlt"   {yylval.op.code = 0; yylval.op.func = 50; return opcodet;}
"tltu"  {yylval.op.code = 0; yylval.op.func = 51; return opcodet;}
"tlti"  {yylval.op.code = 1; yylval.op.func = 10; return opcodet;}
"tltiu" {yylval.op.code = 1; yylval.op.func = 11; return opcodet;}

"lb"   {yylval.op.code = 32; return opcodel;}/*ops L*/
"lbu"  {yylval.op.code = 36; return opcodel;}
"lh"   {yylval.op.code = 33; return opcodel;}
"lhu"  {yylval.op.code = 37; return opcodel;}
"lw"   {yylval.op.code = 35; return opcodel;}
"lwc1" {yylval.op.code = 49; return opcodel;}
"lwl"  {yylval.op.code = 34; return opcodel;}
"lwr"  {yylval.op.code = 38; return opcodel;}
"ll"   {yylval.op.code = 48; return opcodel;}

"sb"   {yylval.op.code = 40; return opcodel;}
"sh"   {yylval.op.code = 41; return opcodel;}
"sw"   {yylval.op.code = 43; return opcodel;}
"swc1" {yylval.op.code = 49; return opcodel;}
"sdc1" {yylval.op.code = 61; return opcodel;}
"swl"  {yylval.op.code = 42; return opcodel;}
"swr"  {yylval.op.code = 46; return opcodel;}
"sc"   {yylval.op.code = 56; return opcodel;}

"mfhi" {yylval.op.code = 0;  yylval.op.func = 16; return opcodemf;}
"mflo" {yylval.op.code = 0;  yylval.op.func = 18; return opcodemf;}
"mthi" {yylval.op.code = 0;  yylval.op.func = 17; return opcodemt;}
"mtlo" {yylval.op.code = 0;  yylval.op.func = 19; return opcodemt;}
"mfc0" {yylval.op.code = 16; yylval.op.func = 0;  return opcodemf;}
"mfc1" {yylval.op.code = 17; yylval.op.func = 0;  return opcodemf;}
"mtc0" {yylval.op.code = 16; yylval.op.func = 0;  return opcodemt;}
"mtc1" {yylval.op.code = 17; yylval.op.func = 0;  return opcodemt;}
"movn" {yylval.op.code = 0;  yylval.op.func = 11; return opcodemf;}
"movz" {yylval.op.code = 0;  yylval.op.func = 10; return opcodemf;}
"movf" {yylval.op.code = 0;  yylval.op.func = 0;  return opcodemf;}
"movt" {yylval.op.code = 0;  yylval.op.func = 1;  return opcodemf;}

[A-z]([A-z]|[0-9]|.|_)*":" {yylval.text = strdup(yytext); return id;} /*Gambiarra, o certo é usar : como um token. Tentar corrigir */

"," {return virg;}
"(" {return abreparents;}
")" {return fechaparents;}
[0-9]+ { yylval.val = atoi(yytext); return number; }
\n { return EOL;}
[ \t] { /* ignore whitespace */ }
"#".* /* ignore comments */
. { printf("\nERRO!\nCaracter desconhecido %c\n", *yytext); }
<<EOF>> {return END_OF_FILE;}
%%

//rd = $t0 | rs = $s0 | rt = $t1
//imm = 4 | shamt = 32 | label = 100
//target = 1000 | offset = 200
//clo $t0, $s0
//clz $t0, $s0