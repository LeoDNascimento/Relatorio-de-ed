#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimevetor(int *vetor){

  for (int i = 0; i < TAM; i++) {
    printf("|%d|", vetor[i]);
  }
  printf("\n");
}

void geravetor(int* vetor){
  for (int i = 0; i < TAM; i++) {
    vetor[i]=rand()%10;
  }
}

void bubble_sort(int *vetor){
  int x, y, aux;

  for (x = 0; x < TAM; x++) {
    for (y = x+1; y < TAM; y++) {

      if (vetor[x]>vetor[y]) {
        aux=vetor[x];
        vetor[x]=vetor[y];
        vetor[y]=aux;
      }
    }
  }

}
int main() {

  int vetor[TAM];

  scanf("%d\n", &tamanho);

  srand(time(NULL));
  geravetor(vetor);
  imprimevetor(vetor);
  bubble_sort(vetor);
  imprimevetor(vetor);
    return 0;
}
