/* Common Data Bus (Barramento) do simulador MIPS32 */
/* Autor : Bruno Cesar, bcesar.g6@gmail.com         */

#include "cdb.h"

void put(word data){
    bus = data; //memcpy?
}

word get(){
    return bus;
}
