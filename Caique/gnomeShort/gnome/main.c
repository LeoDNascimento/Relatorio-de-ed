# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <time.h>
# include <stdbool.h>
# define MAX 10


int VectorSort[10] ;
int size = 0;
int troca=0;
int comparacao=0;

void swap(int * ,int *);
void GnomeSort();

int main (void){

clock_t Tempo[2];
Tempo[0] = clock();


aleatorios(VectorSort,10,11);
imprime();

gnome_sort(VectorSort,10);

    Tempo[1] = clock();
    float TempoGasto = (Tempo[1] - Tempo[0]) * 1000.0 / CLOCKS_PER_SEC;


imprime();
printf("Tempo gasto: %f ms.", TempoGasto);
printf("\nTrocas = %d\nComparacoes = %d", troca, comparacao);


 return 0;
}

void gnome_sort(int *array, int size){
   int i, tmp;
   for(i=1; i<size; ){
       if(array[i-1] <= array[i]){
           ++i;
           comparacao++;
       }
       else{
           troca++;
           tmp = array[i];
           array[i] = array[i-1];
           array[i-1] = tmp;
           --i;
           if(i == 0)
               i = 1;
       }
   }
}

bool existe(int valores[], int tam, int valor){
for(int i=0;i<tam;i++){
    if(valores[i]==valor)
        return true;
}
return false;
}

void aleatorios(int VectorSort[],int quantNumeros, int Limite){
srand(time(NULL));
int v;
for(int i=0;i<quantNumeros;i++){
    v=rand()%Limite;
    while(existe(VectorSort,i,v)){
        v=rand()%Limite;
                }
    VectorSort[i]=v;
}

}

void imprime(){
for(int j=0;j<10;j++){
    printf("\n%d", VectorSort[j]);
}
printf("\n");
}

