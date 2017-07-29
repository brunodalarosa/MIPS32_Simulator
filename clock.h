/* Header do Clock do simulador MIPS 32   */
/* Autor Bruno Cesar, bcesar.g6@gmail.com */

#ifndef __CLOCK_H
#define __CLOCK_H

#include "simulador.h"
#include "processador.h"

extern unsigned int ciclo;
extern unsigned int flag_exit;

unsigned int run();

#endif /* __CLOCK_H */
