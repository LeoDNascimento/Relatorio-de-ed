#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include <stdbool.h>

int main() {

int* vetor;
int x, inicio, meio, fim, num=5, achou;
printf("escreva o numero de vetores\n" );
scanf("%d", &x);
vetor=aloca_vetor(x);
gera_vetor_crescentes(x, vetor);
printf("iniciou\n" );


for(int i=0;i<x;i++)
{
if (vetor[i]==num)
{
achou=1;
}
}

if (achou==1)
{
printf("Achou");
}
else
{
printf("Não achou");
}

free(vetor);
  return 0;
}
