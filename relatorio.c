#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include <stdbool.h>


void menu_selecao_numerica(int* vetor, int* tempos, int* dados){

    int escolha;

    printf("Escolha a quantidade de numeros:\n");
    printf("1. 10\n" );
    printf("2. 100\n" );
    printf("3. 1000\n" );
    printf("4. 10.000\n" );
    printf("5. 100.000\n" );
    scanf("%d", &escolha);

   switch (escolha) {
     case 1:{
       vetor=aloca_vetor(10);
       menu_de_ordem(10, vetor, tempos, dados);
       break;
     }
     case 2:{
       vetor=aloca_vetor(100);
       menu_de_ordem(100, vetor, tempos, dados);
       break;
     }
     case 3:{
       vetor=aloca_vetor(1000);
       menu_de_ordem(1000, vetor, tempos, dados);
       break;
     }
     case 4:{
       vetor=aloca_vetor(10000);
       menu_de_ordem(10000, vetor, tempos, dados);
       break;
     }
     case 5:{
       vetor=aloca_vetor(100000);
       menu_de_ordem(100000, vetor, tempos, dados);
       break;
     }
     default:{
       printf("Operação invalida\n" );
       break;
     }
   }
}

void menu_de_ordem(int quantidade, int* vetor, int* tempos, int* dados) {

      int escolha;
      printf("Escolha o criterio dos numeros:\n");
      printf("1. Numeros crescentes\n" );
      printf("2. Numeros decrescentes\n" );
      printf("3. Numeros randomicos\n" );
      printf("4. Numeros n randomicos\n" );
      scanf("%d", &escolha);

     switch (escolha) {
       case 1:{
         gera_vetor_crescentes(quantidade, vetor);
         menu_selecao_metodos(quantidade, vetor, tempos, dados);
         break;
       }
       case 2:{
         gera_vetor_decrescentes(quantidade, vetor);
         menu_selecao_metodos(quantidade, vetor, tempos, dados);
         break;
       }
       case 3:{
         gera_vetor_randomico(quantidade, vetor);
         menu_selecao_metodos(quantidade, vetor, tempos, dados);
         break;
       }
       case 4:{
         gera_vetor_randomico_n_repetidos(quantidade, vetor);
         menu_selecao_metodos(quantidade, vetor, tempos, dados);
         break;
       }
       default:{
         printf("Operação invalida\n" );
         break;
       }
     }
}


void menu_selecao_metodos(int quantidade, int* vetor, int* tempos, int* dados){

    int escolha;

    printf("Escolha a operação:\n");
    printf("1. Bubble Sort\n" );
    printf("2. Busca Binaria\n" );
    printf("3. Busca Sequencial\n" );
    scanf("%d", &escolha);

   switch (escolha) {
     case 1:{
       bubble_sort(vetor,quantidade, tempos, dados);
       printf("Efetuou: %d trocas\nEfetuou: %d comparacoes\nFez em: %d segundos\n", dados[1], dados[0], tempos[1]-tempos[0]);
       break;
     }
     case 2:{
       bubble_sort1(vetor,quantidade);
       busca_binaria(quantidade,vetor, tempos);
       printf("Fez em: %d segundos\n", tempos[1]-tempos[0]);
       break;
     }
     case 3:{
       busca_sequencial(quantidade,vetor, tempos);
       printf("Fez em: %d segundos\n", tempos[1]-tempos[0]);
       break;
     }
     default:{
       printf("Operação invalida\n" );
       break;
     }
   }
}


int main() {
  int* vetor;
  int tempos[2];
  int dados[2];
  dados[0]=0; //trocas
  dados[1]=0;//comp
  srand(time(NULL));
  menu_selecao_numerica(vetor, tempos, dados);
  return 0;
}
