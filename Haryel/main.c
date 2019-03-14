#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "vetores.h"
#include "ordenacao.h"
#include "menu.h"
#include "functions.h"
#include "buscas.h"

unsigned long int detalhes[] = {0,0};
float tempo[] = {0,0};

int main(){

    int ordenacao_busca;
    int gerar_vetor;
    int opcao_vetor;
    int opcao_tamanho;
    int opcao_ordenacao;
    int opcao_busca;
    int size;
    int *array;
    int valor;
    int posicao;

    srand(time(NULL));
    

    /*
      Primeiro menu. Seleciona o tamanho do vetor. 
    */
   
   do{

        system("clear");

        opcao_tamanho = menu_tamanho();

        switch (opcao_tamanho){
            case 0:
                printf("Ate logo!\n");
                return 0;
            case 1:
                size = 10;
                opcao_tamanho = 0;
                break;
            case 2:
                size = 100;
                opcao_tamanho = 0;
                break;
            case 3:
                size = 1000;
                opcao_tamanho = 0;
                break;
            case 4:
                size = 10000;
                opcao_tamanho = 0;
                break;
            case 5:
                size = 100000;
                opcao_tamanho = 0;
                break;     
        }
    }while(opcao_tamanho != 0);

    /*
        Segundo menu. Seleciona o tipo de vetor que sera criado a partir do tamanho definido no menu anterior
    */

    do{ 

        system("clear");

        opcao_vetor = menu_vetores();

        switch(opcao_vetor){
            case 0:
                printf("Ate logo!\n");
                return 0;
            case 1:
                array = gera_vetor_ord_cre(size);
                doing(array, size);
                opcao_vetor = 0;
                break;
            case 2:
                array = gera_vetor_ord_dec(size);
                doing(array, size);
                opcao_vetor = 0;
                break;
            case 3:
                array = gera_vetor_alt(size);
                doing(array, size);
                opcao_vetor = 0;
                break;
            case 4:
                array = gera_vetor_alt_norepeat(size);
                doing(array, size);
                opcao_vetor = 0;
                break;
        }
    }while(opcao_vetor != 0);
    
    /*
        Terceiro menu. Seleciona o tipo de ordenacao que deve ser aplicada ao vetor anterior.
    */
    
    do{

        system("clear");

        opcao_ordenacao = menu_ordenacao();

        switch(opcao_ordenacao){
            case 0:
                printf("Ate logo!\n");
                free(array);
                return 0;
            case 1:
                selectionSort(array, size, detalhes, tempo);
                showDetalhes(detalhes, array, size, tempo);
                opcao_ordenacao = 0;
                break;
            case 2:
                //quickSort();
                showDetalhes(detalhes, array, size, tempo);
                opcao_ordenacao = 0;
                break;
            case 3:
                //mergeSort();
                showDetalhes(detalhes, array, size, tempo);
                opcao_ordenacao = 0;
                break;
            case 4:
                gnomeSort(array, size, detalhes, tempo);
                showDetalhes(detalhes, array, size, tempo);
                opcao_ordenacao = 0;
                break;
            case 5:
                insertionSort(array, size, detalhes, tempo);
                showDetalhes(detalhes, array, size, tempo);
                opcao_ordenacao = 0;
                break;
            case 6:
                shellSort(array, size, detalhes, tempo);
                showDetalhes(detalhes, array, size, tempo);
                opcao_ordenacao = 0;
                break;
            case 7:
                bubbleSort(array, size, detalhes, tempo);
                showDetalhes(detalhes, array, size, tempo);
                opcao_ordenacao = 0;
                break;
        }

    }while(opcao_ordenacao != 0);

    /*
        Quarto menu. Escolhe o tipo de busca que sera aplicado ao vetor ordenado.
    */
    
    do{

        system("clear");

        opcao_busca = menu_busca();

        switch(opcao_busca){
            case 0:
                printf("Ate logo!\n");
                free(array);
                return 0;
            case 1: 
                valor = solicitaBusca();
                posicao = buscaBin(array, size, valor);
                showBusca(posicao, valor);
                opcao_busca = 0;
                break;
            case 2:
                valor = solicitaBusca();
                posicao = buscaSeq(array, size, valor);
                showBusca(posicao, valor);
                opcao_busca = 0;
                break;
        }

    }while(opcao_busca != 0);

    free(array);
    return 0;
}