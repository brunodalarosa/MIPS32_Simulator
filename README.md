/*       README do simulador MIPS 32        */
/*  Autor Bruno Cesar, bcesar.g6@gmail.com  */
/*    Simulador versão 1.0 - 30/07/2017     */

 --- Bruno Cesar Puli Dala Rosa, RA 95378 ---

Este é um simulador da arquitetura MIPS 32 que implementa o algoritmo de Tomasulo,
o simulador foi desenvolvido como um trabalho da disciplina de Arquitetura II e
seu uso é simples: ./simulador [opções] <entrada>. O argumento "-h" exibe uma seção de ajuda.

A pasta /programas_teste contém 6 programas de entrada para testar o simulador:

simple<1,2,3>.txt: São testes que não implementam nenhum algoritmo especifico.
                   o objetivo foi testar diferentes instruções implementadas no
                   simulador.

fat.txt: Implementa um algoritmo de calculo de fatorial. O usuário deve inserir
         um número e o programa computa e imprime na tela o seu fatorial.

multiplicador.txt: Implementa uma espécie de calculador de tabuadas, o usuário deve
                   inserir X e Y. O programa imprime Y * 1...X na tela.

fibo.txt: Implementa um algoritmo para calculo de números da sequencia Fibonacci.
          O usuário deve inserir a quantidade de números da sequencia que serão impressos na tela.

OBS.: Algumas entradas muito grandes para os programas podem resultar em saídas
      erradas, isso ocorre graças ao limite do tamanho de uma palavra de 4 Bytes.
