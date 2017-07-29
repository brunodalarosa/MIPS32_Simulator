/* Header da cache do simulador MIPS32    */
/* Autor Bruno Cesar, bcesar.g6@gmail.com */

#ifndef __CACHE_H
#define __CACHE_H

#define C_TEXTO_SIZE 64 //8192 * sizeof(word) = 32K
#define C_DADOS_SIZE 64 //8192 * sizeof(word) = 32K

#define CACHE_TEXTO 1
#define CACHE_DADOS 0

#define FLAG_WRITE 1
#define FLAG_READ  2
#define FLAG_BLANK -1

#define NUM_LINHA 2048 //4 //2048
#define TAM_LINHA 4 //Numero de palavras

#include "simulador.h"
#include "memoria.h"
#include "utils.h"

typedef union endereco_t endereco;

// NUMERO DE BLOCOS =  TOTAL_MEM / TAM_BLOCO
// NUM_TAG = NUMERO_DE_BLOCOS / NUMERO_DE_LINHA
// NUMERO_DE_LINHA = DEFINIDO

// 1 linha = 4 word ( 16 Bytes)
// 32K / 16 = 2k Linhas //testando com 4 linhas para 64Bytes

//ENDEREÇO DO BLOCO =  Linha * (tam_byte) + tag * (tam_byte + tam_linha)

extern word barr_mem_dados;
extern word barr_mem_texto;

typedef struct{
    unsigned int byte  : 4; //4; //4
    unsigned int linha : 11; //2; //11
    unsigned int tag   : 14; //19; //14
} c_access;

typedef struct{
    word dados;
    int tag : 14;
    unsigned int v   : 1; //Booleano verificador de ativação do Write_back
} c_linha;

union endereco_t{
    unsigned int i;
    c_access end;
};

c_linha* cache_texto;
c_linha* cache_dados;

void cWrite(unsigned int cache_id, endereco addr, unsigned int dado);
unsigned int cRead(unsigned int cache_id, endereco end);
void cacheInit();

#endif /* __CACHE_H */
