/* Header do banco de registradores | simulador MIPS 32 */
/* Autor Bruno Cesar, bcesar.g6@gmail.com               */

#ifndef __REGISTRADORES_H
#define __REGISTRADORES_H

#define REG_V0 2
#define REG_A0 4
#define REG_A1 5
#define REG_A2 6
#define REG_A3 7
#define REG_RA 31
#define REG_LO 32
#define REG_HI 33

#define NUM_REGS 34

#include <stdio.h>
#include "memoria.h"

extern int* regs;

void setReg(int dado, int reg_id);
void registradoresInit();
int getReg(int reg_id);

#endif /* __REGISTRADORES_H */
