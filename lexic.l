/* flex: Teste 1 tradutor (Simulador MIPS32) */
%{
# include "parser.h"
%}

digit	[0-9]
letter	[a-zA-Z]

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
"$lo" { yylval.val = 32;  return reg;}
"$hi" { yylval.val = 33;  return reg;}

"sll"   {yylval.op.code = 0;  yylval.op.func = 0;   return opcoders;}/*ops RS*/
"srl"   {yylval.op.code = 0;  yylval.op.func = 2;   return opcoders;}
"sra"   {yylval.op.code = 0;  yylval.op.func = 3;   return opcoders;}
"sllv"  {yylval.op.code = 0;  yylval.op.func = 4;   return opcoders;}
"srlv"  {yylval.op.code = 0;  yylval.op.func = 6;   return opcoders;}
"srav"  {yylval.op.code = 0;  yylval.op.func = 7;   return opcoders;}
"movz"  {yylval.op.code = 0;  yylval.op.func = 10;  return opcodemf;}
"movn"  {yylval.op.code = 0;  yylval.op.func = 11;  return opcodemf;}
"mfhi"  {yylval.op.code = 0;  yylval.op.func = 16;  return opcodemf;}
"mthi"  {yylval.op.code = 0;  yylval.op.func = 17;  return opcodemt;}
"mflo"  {yylval.op.code = 0;  yylval.op.func = 18;  return opcodemf;}
"mtlo"  {yylval.op.code = 0;  yylval.op.func = 19;  return opcodemt;}
"mult"  {yylval.op.code = 0;  yylval.op.func = 24;  return opcoderd;}
"multu" {yylval.op.code = 0;  yylval.op.func = 25;  return opcoderd;}
"div"   {yylval.op.code = 0;  yylval.op.func = 26;  return opcoderd;}/*rs-rt*/
"divu"  {yylval.op.code = 0;  yylval.op.func = 27;  return opcoderd;}/*rs-rt*/
"add"   {yylval.op.code = 0;  yylval.op.func = 32;  return opcoder;}
"addu"  {yylval.op.code = 0;  yylval.op.func = 33;  return opcoder;}
"sub"   {yylval.op.code = 0;  yylval.op.func = 34;  return opcoder;}
"subu"  {yylval.op.code = 0;  yylval.op.func = 35;  return opcoder;}
"and"   {yylval.op.code = 0;  yylval.op.func = 36;  return opcoder;}
"or"    {yylval.op.code = 0;  yylval.op.func = 37;  return opcoder;}
"xor"   {yylval.op.code = 0;  yylval.op.func = 38;  return opcoder;}
"nor"   {yylval.op.code = 0;  yylval.op.func = 39;  return opcoder;}
"slt"   {yylval.op.code = 0;  yylval.op.func = 42;  return opcoder;}
"sltu"  {yylval.op.code = 0;  yylval.op.func = 43;  return opcoder;}
"teq"   {yylval.op.code = 0;  yylval.op.func = 52;  return opcodet;}

"jr"   {yylval.op.code = 0; yylval.op.func = 8; return opcodej;}
"jalr" {yylval.op.code = 0; yylval.op.func = 9; return opcodej;}

"bltz"   {yylval.op.code = 1;  yylval.op.func = 0;  return opcodeb;}
"bgez"   {yylval.op.code = 1;  yylval.op.func = 1;  return opcodeb;}
"teqi"   {yylval.op.code = 1;  yylval.op.func = 12; return opcodet;}
"bltzal" {yylval.op.code = 1;  yylval.op.func = 16; return opcodeb;}
"bgezal" {yylval.op.code = 1;  yylval.op.func = 17; return opcodeb;}

"j"    {yylval.op.code = 2; return opcodej;}
"jal"  {yylval.op.code = 3; return opcodej;}

"beq"    {yylval.op.code = 4;  return opcodebeq;}
"bne"    {yylval.op.code = 5;  return opcodebeq;}
"blez"   {yylval.op.code = 6;  yylval.op.func = 0;  return opcodeb;}
"bgtz"   {yylval.op.code = 7;  yylval.op.func = 0;  return opcodeb;}

"addi"   {yylval.op.code = 8;  return opcodei;} /*ops I*/
"addiu"  {yylval.op.code = 9;  return opcodei;}
"slti"   {yylval.op.code = 10; return opcodei;}
"sltiu"  {yylval.op.code = 11; return opcodei;}
"andi"   {yylval.op.code = 12; return opcodei;}
"ori"    {yylval.op.code = 13; return opcodei;}
"xori"   {yylval.op.code = 14; return opcodei;}
"lui"    {yylval.op.code = 15; return opcodelui;}

"madd"  {yylval.op.code = 28;  yylval.op.func = 0;   return opcoderd;}/*rs-rt*/
"maddu" {yylval.op.code = 28;  yylval.op.func = 1;   return opcoderd;}/*rs-rt*/
"mul"   {yylval.op.code = 28;  yylval.op.func = 2;   return opcoder;}
"msub"  {yylval.op.code = 28;  yylval.op.func = 4;   return opcoderd;}/*rs-rt*/
"msubu" {yylval.op.code = 28;  yylval.op.func = 5;   return opcoderd;}/*rs-rt*/
"clo"   {yylval.op.code = 28;  yylval.op.func = 32;  return opcoder;}/*rd-rs*/
"clz"   {yylval.op.code = 28;  yylval.op.func = 33;  return opcoder;}/*rd-rs*/

"lb"   {yylval.op.code = 32; return opcodel;}/*ops Load-Store*/
"lh"   {yylval.op.code = 33; return opcodel;}
"lwl"  {yylval.op.code = 34; return opcodel;}
"lw"   {yylval.op.code = 35; return opcodel;}
"lbu"  {yylval.op.code = 36; return opcodel;}
"lhu"  {yylval.op.code = 37; return opcodel;}
"lwr"  {yylval.op.code = 38; return opcodel;}
"sb"   {yylval.op.code = 40; return opcodel;}
"sh"   {yylval.op.code = 41; return opcodel;}
"swl"  {yylval.op.code = 42; return opcodel;}
"sw"   {yylval.op.code = 43; return opcodel;}
"swr"  {yylval.op.code = 46; return opcodel;}
"ll"   {yylval.op.code = 48; return opcodel;}
"sc"   {yylval.op.code = 56; return opcodel;}
"syscall" {return syscallOP;}
"nop"     {return NOP;}

{letter}("_"|{letter}|{digit})* { yylval.text = strdup(yytext); return id;}

".int"|".byte" {return t_int;}
":" {return colon;}
"," {return virg;}
"(" {return abreparents;}
")" {return fechaparents;}
"-"{digit}+ { yylval.val = atoi(yytext); return number; }
{digit}+ { yylval.val = atoi(yytext); return number; }
\n { return EOL;}
[ \t] { /* ignore whitespace */ }
"#".* /* ignore comments */
. { printf("\nERRO!\nCaracter desconhecido %c\n", *yytext); }
<<EOF>> {return END_OF_FILE;}
%%
