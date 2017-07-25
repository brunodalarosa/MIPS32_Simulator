/* Common Data Bus (Barramento) do simulador MIPS32 */
/* Autor : Bruno Cesar, bcesar.g6@gmail.com         */

#include "cdb.h"

/* Verifica se uma estação de reserva está a espera de um dado, se sim atualiza */
int check_er(estacao_reserva* er, unsigned int dado, unsigned int source_id){
    if(er->qj == source_id){
        er->vj = dado;
        er->qj = 0;
        if(get_flag(FLAG_DEBUG)) printf("> Stremado para %s->vj = %d\n", ER_nomes[identificaER(er)-1], dado);
    }

    if(er->qk == source_id){
        er->vk = dado;
        er->qk = 0;
        if(get_flag(FLAG_DEBUG)) printf("> Stremado para %s->vk = %d\n", ER_nomes[identificaER(er)-1], dado);
    }
}

/* Função que transmite um dado para os outros componentes através do CDB */
void stream(unsigned int dado, unsigned int source_id){

    /* Primeiro passo verificar todas as ER procurando as que precisam deste dado */
    if(identificaER(er_add1)  != source_id) check_er(er_add1, dado, source_id);
    if(identificaER(er_add2)  != source_id) check_er(er_add2, dado, source_id);
    if(identificaER(er_add3)  != source_id) check_er(er_add3, dado, source_id);
    if(identificaER(er_mult1) != source_id) check_er(er_mult1, dado, source_id);
    if(identificaER(er_mult2) != source_id) check_er(er_mult2, dado, source_id);
    if(identificaER(er_load1) != source_id) check_er(er_load1, dado, source_id);
    if(identificaER(er_load2) != source_id) check_er(er_load2, dado, source_id);

    /* Segundo passo: Enviar dado ao destino */
    int reg = identificaREG(source_id);
    if(reg > 32) launchError(8);
    if(reg != -1) regs[reg] = dado;

    if(get_flag(FLAG_DEBUG)) printaRegs(0, NULL);
}
