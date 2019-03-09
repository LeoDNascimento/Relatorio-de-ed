#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "vetores.h"
#include "ordenacao.h"
#include "menu.h"
#include "functions.h"

int detalhes[] = {0,0};

int main(){

    int ordenacao_busca;
    int gerar_vetor;
    int opcao_vetor;
    int opcao_tamanho;
    int opcao_ordenacao;
    int opcao_busca;
    int size;
    int *array;
    srand(time(NULL));
    

    /*
      Primeiro menu. Seleciona o tamanho do vetor. 
    */
   
   do{

        system("cls || clear");

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
                size = 1000000;
                opcao_tamanho = 0;
                break;     
        }
    }while(opcao_tamanho != 0);

    /*
        Segundo menu. Seleciona o tipo de vetor que sera criado a partir do tamanho definido no menu anterior
    */

    do{ 

        system("clear || cls");

        opcao_vetor = menu_vetores();

        switch(opcao_vetor){
            case 0:
                printf("Ate logo!\n");
                return 0;
            case 1:
                //gerar_vetor_ord_crescente();
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

        system("cls || clear");

        opcao_ordenacao = menu_ordenacao();

        switch(opcao_ordenacao){
            case 0:
                printf("Ate logo!\n");
                free(array);
                return 0;
            case 1:
                selectionSort(array, size, detalhes);
                showDetalhes(detalhes, array, size);
                opcao_ordenacao = 0;
                break;
            case 2:
                //quickSort();
                break;
            case 3:
                //mergeSort();
                break;
            case 4:
                //gnomeSort();
                break;
            case 5:
                //insertionSort();
                break;
            case 6:
                //shellSort();
                break;
            case 7:
                bubbleSort(array, size, detalhes);
                showDetalhes(detalhes, array, size);
                opcao_ordenacao = 0;
                break;
        }

    }while(opcao_ordenacao != 0);

    /*
        Quarto menu. Escolhe o tipo de busca que sera aplicado ao vetor ordenado.
    */
    
    do{

        system("cls || clear");

        opcao_busca = menu_busca();

        switch(opcao_busca){
            case 0:
                printf("Ate logo!\n");
                free(array);
                return 0;
            case 1: 
                //buscaBin();
                break;
            case 2:
                //buscaSeq();
                break;
        }

    }while(opcao_busca != 0);

    free(array);
    return 0;
}