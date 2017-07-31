/* Componente responsável pelo PC do Simulador MIPS32 */
/* Autor: Bruno Cesar, bcesar.g6@gmail.com            */

#include "pcComponent.h"

unsigned int pc = 0; //PC é inicialzado com 0

/* Executa um passo no PC */
void updatePC(){
    pc += 4;
}

/* Injeta um valor em PC */
void setPC(unsigned int address){
    pc = address;
}

/* Retorna o valor de PC */
unsigned int getPC(){
    return pc;
}
