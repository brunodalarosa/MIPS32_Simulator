/* Cache do simulador MIPS 32             */
/* Autor Bruno Cesar, bcesar.g6@gmail.com */

#include "cache.h"

word barr_mem_dados;
word barr_mem_texto;

void cpyMemBlock(unsigned int cache_id, endereco addr){
    unsigned int linha = addr.end.linha;
    unsigned int tag = addr.end.tag;
    unsigned int byte = addr.end.byte;

    /* Descobrir o endereço do inicio do bloco de leitura */
    //ENDEREÇO DO BLOCO =  Linha * (tam_byte) + tag * (tam_byte + tam_linha)
    unsigned int block_addr = (linha * TAM_LINHA * sizeof(unsigned int)) + (tag * 16);
    if(cache_id == CACHE_DADOS) block_addr += TEXT_SIZE;

    if(cache_id == CACHE_DADOS){
        if(get_flag(FLAG_DEBUG)) printf("Endereço do bloco movido para cache-dados: %d (linha= %d| tag= %d| byte= %d)\n", block_addr, linha, tag, byte);

        /* Mecanismo Write_back */
        if(cache_dados[linha].v == 1){
            if(get_flag(FLAG_DEBUG)) printf("\n---- Write back ---\n");
            //Faz escrita na memoria na posição de inicio do bloco dos dados antigos (como identificar tag?)
            unsigned int target_block_addr = (linha * TAM_LINHA * sizeof(unsigned int)) + (cache_texto[linha].tag * 16);
            write(target_block_addr, cache_dados[linha].dados, sizeof(unsigned int) * TAM_LINHA);

            cache_dados[linha].v = 0;
        }

        read(barr_mem_dados, block_addr, sizeof(unsigned int) * TAM_LINHA);
        if(get_flag(FLAG_VERBOSE)) printaBloco(barr_mem_dados, TAM_LINHA);

    } else{
        if(get_flag(FLAG_DEBUG)) printf("Endereço do bloco movido para cache-texto: %d (linha= %d| tag= %d| byte= %d)\n", block_addr, linha, tag, byte);

        read(barr_mem_texto, block_addr, sizeof(unsigned int) * TAM_LINHA);
        if(get_flag(FLAG_VERBOSE)) printaBloco(barr_mem_texto, TAM_LINHA);
    }
}

void cWrite(unsigned int cache_id, endereco addr, unsigned int dado){
    if(cache_id == CACHE_TEXTO) launchError(7);

    unsigned int linha = addr.end.linha;
    unsigned int tag = addr.end.tag;
    unsigned int byte = addr.end.byte;

    if(get_flag(FLAG_DEBUG)){
        printf("Printando o bloco da linha %d da cache-dados:\n", linha);
        printaBloco(cache_dados[linha].dados, TAM_LINHA);
    }

    if(cache_dados[linha].tag == tag){
        //hit
        if(get_flag(FLAG_VERBOSE)) printf("HIT - Cache-dados linha %d\n", linha);

    } else{
        //miss
        if(get_flag(FLAG_VERBOSE)) printf("MISS - Cache-dados linha %d\n", linha);
        cpyMemBlock(cache_id, addr);
        cache_dados[linha].dados = barr_mem_dados;
        cache_dados[linha].tag = tag;
    }

    //Escrita na cache
    cache_texto[linha].dados[byte / TAM_LINHA] = dado;
    cache_dados[linha].v = 1; //Verificador de escrita
}


unsigned int cRead(unsigned int cache_id, endereco addr){
    unsigned int linha = addr.end.linha;
    unsigned int tag = addr.end.tag;
    unsigned int byte = addr.end.byte;

    if(cache_id == CACHE_TEXTO){
        if(cache_texto[linha].tag == tag){
            //hit
            if(get_flag(FLAG_VERBOSE)) printf("HIT - Cache-texto linha %d\n", linha);
        } else{
            //miss
            if(get_flag(FLAG_VERBOSE)) printf("MISS - Cache-texto linha %d\n", linha);
            cpyMemBlock(cache_id, addr);
            cache_texto[linha].dados = barr_mem_texto;
            cache_texto[linha].tag = tag;
        }

        return cache_texto[linha].dados[addr.end.byte / TAM_LINHA];

    } else if (cache_id == CACHE_DADOS){
        if(cache_dados[linha].tag == tag){
            //hit
            if(get_flag(FLAG_VERBOSE)) printf("HIT - Cache-dados linha %d\n", linha);

        } else{
            //miss
            if(get_flag(FLAG_VERBOSE)) printf("MISS - Cache-dados linha %d\n", linha);
            cpyMemBlock(cache_id, addr);
            cache_dados[linha].dados = barr_mem_dados;
            cache_dados[linha].tag = tag;
        }

        return cache_dados[linha].dados[byte / TAM_LINHA];
    }
}

/* Função auxiliar: Inicializa o componente Cache */
void cacheInit(){
    int i;

    cache_texto = malloc(NUM_LINHA * sizeof(c_linha)); //32k
    cache_dados = malloc(NUM_LINHA * sizeof(c_linha)); //32k

    for(i = 0; i < NUM_LINHA; i++){
        cache_texto[i].v = 0;
        cache_dados[i].v = 0;

        cache_texto[i].tag = FLAG_BLANK;
        cache_dados[i].tag = FLAG_BLANK;

        cache_dados[i].dados = malloc(TAM_LINHA * sizeof(unsigned int));
        cache_texto[i].dados = malloc(TAM_LINHA * sizeof(unsigned int));
    }

    barr_mem_dados = malloc(sizeof(unsigned int) * 4); //128 Bits
    barr_mem_texto = malloc(sizeof(unsigned int) * 4); //128 Bits

}
