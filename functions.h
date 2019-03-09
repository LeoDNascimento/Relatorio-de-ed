#include <stdbool.h>
//alocar vetor

int* aloca_vetor(int quantidade){
  int* aux;

  aux= (int*) malloc(quantidade * sizeof(int));
  return aux;
}

//gera vetor crescentes

void gera_vetor_crescentes(int final, int*vetor ){

  for (int i = 0; i < final; i++) {
    vetor[i]=i;

  }
  return;
}

//gera vetor decrescentes

void gera_vetor_decrescentes(int final, int*vetor ){
int y;
  y=final;
    for (int i = 0; i < y; i++, final--) {
      vetor[i]=final;
    }
  return;
}

//gerar numeros randomicos
void gera_vetor_randomico(int quantidade, int* vetor){

    for (int i = 0; i < quantidade; i++) {
      vetor[i]=rand()%200000;
    }
    return;
}

bool existe(int* vetor, int tam, int valor){
  for (int i = 0; i < tam; i++) {
    if (vetor[i]==valor)
      return true;
  }
  return false;
}

void gera_vetor_randomico_n_repetidos(int* vetor, int quantNumeros){
  int aux;
  for (int i = 0; i < quantNumeros; i++) {
    aux=rand()%200000;
    while (existe(vetor, i, aux)) {
      aux=rand()%200000;
    }
    vetor[i]=aux;
  }
}
//bubble sort principal
void bubble_sort(int *vetor, int quantidade, int* tempos, int* dados){
  int aux;
  tempos[0]=clock();
  for (int i = 0; i < quantidade; i++) {
    for (int j = i+1; j < quantidade; j++) {
      dados[0]++;
      if (vetor[i]>vetor[j]) {
        aux=vetor[i];
        vetor[i]=vetor[j];
        vetor[j]=aux;
        dados[1]++;
      }
    }
  }
  tempos[1]=clock();
}
//so para ordenar
void bubble_sort1(int *vetor, int quantidade){
  int aux;
  for (int i = 0; i < quantidade; i++) {
    for (int j = i+1; j < quantidade; j++) {

      if (vetor[i]>vetor[j]) {
        aux=vetor[i];
        vetor[i]=vetor[j];
        vetor[j]=aux;

      }
    }
  }
}

//busca sequencial
void busca_sequencial(int *vetor, int quantidade, int* tempos) {

  int num=quantidade-1;
  tempos[0]=clock();
  for(int i=0;i<quantidade;i++)
  {
  if (vetor[i]==num)
  {
  tempos[1]=clock();
  return;
  }
  }
}

//Busca Sequencial
void busca_binaria(int *vetor, int quantidade, int* tempos){

  int esquerda=0;
  int direita= quantidade-1;
  int meio;
  int num=quantidade-1;
tempos[0]=clock();
  while (esquerda<=direita) {
    meio = (esquerda+direita)/2;
     if (num == vetor[meio]) {
       tempos[1]=clock();
       return;
     }
     if (vetor[meio]<num) {
       esquerda=meio+1;
     }
     else{
       direita=meio-1;
     }
  }
  tempos[1]=clock();
}
