/* Banco de registradores | simulador MIPS 32 */
/* Autor Bruno Cesar, bcesar.g6@gmail.com     */

#include "registradores.h"

int* regs = NULL;

/* Inicializa os registradores */
void registradoresInit(){
    regs = calloc(NUM_REGS, sizeof(int));
    regs[29] = MEM_SIZE; //$sp : ponteiro de pilha inicializa no fim da memória
}

/* Insere um dado no registrador */
void setReg(int dado, int reg_id){
    regs[reg_id] = dado;
}

/* retorna o dado no registrador */
int getReg(int reg_id){
    return regs[reg_id];
}
