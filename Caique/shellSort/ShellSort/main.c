# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <time.h>
# include <stdbool.h>
int main(){

clock_t Tempo[2];
Tempo[0] = clock();

int vetor[10];
int info[2] = {0, 0};
adere(vetor,10);
imprime(vetor);
shellSort(vetor,10, info);

    Tempo[1] = clock();
    float TempoGasto = (Tempo[1] - Tempo[0]) * 1000.0 / CLOCKS_PER_SEC;


imprime(vetor);

printf("Tempo gasto: %f ms.", TempoGasto);
printf("\n %d \n %d", info[0], info[1]);


    return 0;
}
void adere(int vetor[], int tam){
int i, aux=tam;
   for(i=0; i<tam; i++){
      vetor[i]=aux;
      aux--;
   }


}

void shellSort(int *vet, int size, int *info){
    int i, j, value;
    int gap = 1;
    while(gap < size){
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i;
            while (j >= gap && value < vet[j - gap]) {
                vet[j] = vet [j - gap];
                j = j - gap;
                info[0]++;
                info[1]++;
            }
            vet [j] = value;
        }
    }
}

void imprime(int vetor[]){
for(int j=0;j<10;j++){
    printf("\n%d", vetor[j]);
}
printf("\n");
}
