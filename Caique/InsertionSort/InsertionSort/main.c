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
int info[2] = {0,0};
adere(vetor,10);
imprime(vetor);
insertSort(vetor,10, info);

    Tempo[1] = clock();
    float TempoGasto = (Tempo[1] - Tempo[0]) * 1000.0 / CLOCKS_PER_SEC;


imprime(vetor);
printf("Tempo gasto: %f ms.", TempoGasto);
printf("\n %d   %d", info[0], info[1]);

    return 0;
}
void adere(int vetor[], int tam){
int i;
srand(time(NULL));
   for(i=0; i<tam; i++){
      vetor[i]=rand()%100;

   }


}

void insertSort(int *v, int n, int *info){
    int i, j, aux;
    for(i=1; i<n; i++){
        aux=v[i];
        for(j=i; (j>0) && (aux<v[j-1]); j--)
            v[j]=v[j-1];
             v[j]=aux;
             info[0]++;
             info[1]++;

    }
}

void imprime(int vetor[]){
for(int j=0;j<10;j++){
    printf("\n%d", vetor[j]);
}
printf("\n");
}
