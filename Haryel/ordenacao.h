/*
    Metodo: BubbleSort
*/

int particiona(int*, int, int);

void bubbleSort(int *array, int size, unsigned long int *detalhes){

	int aux = 0;

	for(int i = 0; i < size-1; i++){
		for(int j = 0; j < size-1; j++){
			detalhes[0]++;
			if(array[j] > array[j+1]){
				aux = array[j];
				array[j] = array[j+1];
				array[j+1] = aux;
				detalhes[1]++;
			}
		}
	}
}

/*
    Metodo: SelectionSort
*/

void selectionSort(int *array, int size, unsigned long int *detalhes){

    int menor, troca;

    for(int i = 0; i < size-1; i++){
        menor = i;
        for(int j = i+1; j < size; j++){
            detalhes[0]++;
            if(array[j] < array[menor]){
                menor = j;
            }
        }
        if(i != menor){
            troca = array[i];
            array[i] = array[menor];
            array[menor] = troca;
            detalhes[1]++;
        }
    }
}

/*
    Metodo: GnomeSort
*/

void gnomeSort(int *array, int size, unsigned long int *detalhes){
   
   int i, aux;

   for(int i = 1; i < size;){
       if(array[i-1] <= array[i]){
           ++i;
           detalhes[0]++;
       }
       else{
           detalhes[1]++;
           aux = array[i];
           array[i] = array[i-1];
           array[i-1] = aux;
           --i;
           if(i == 0)
               i = 1;
       }
   }
}

/*
    Metodo: InsertionSort
*/

void insertionSort(int *array, int size, unsigned long int *detalhes){

    int aux, i, j;
    
    for(i = 1; i < size; i++){
        aux = array[i]; //auxiliar recebe o valor da posicao i[1]
        detalhes[0]++;
        for(j = i; (j > 0) && (aux < array[j-1]); j--){ //aux, i, j nesse momento sao o mesmo valor. A comparacao eh feita com entre a posicao atual e sua anterior.
            array[j] = array[j-1]; //a casa anterior eh copiada para a atual ou seja, os maiores sao deslocados para direita
        }   
        array[j] = aux; //aux vai ser o novo valor de J
        detalhes[1]++;
    }
}

/*
    Metodo: ShellSort
    Este metodo consiste em pegar uma variavel h=n/2, onde n eh o tamanho do vetor e iremos fazer as comparacoes de por exemplo, da posicao e da posicao que esta 4 em seguida dela. Ou seja, comparamos array[0] com array[4], array[1] com array[5] etc
    Apos cada interacao dividimos h novamente por 2, ate o h ser igual a um. Nesse momento ele passa por todas as posicoes.
*/

void shellSort(int *array, int size, unsigned long int *detalhes){

    int i = (size - 1)/2;
    int chave, k, aux;

    while(i != 0){
        do{
            chave = 1;
            for(k = 0; k < size - i; ++k){
                detalhes[0]++;
                if(array[k] > array[k + i]){
                    aux = array[k];
                    array[k] = array[k + 1];
                    array[k + i] = aux;
                    chave = 0;
                    detalhes[1]++;
                }
            }
        }while(chave == 0);
        i = i/2;
    }
}

/*
    Metodo: QuickSort
*/

void quickSort(int *array, int inicio, int fim, unsigned long int *detalhes){

    int i, j, pivo, aux;

    i = inicio;
    j = fim-1;
    pivo = array[(inicio + fim) / 2];
  
    while(i <= j){
        while(array[i] < pivo && i < fim){
            detalhes[0]++;
            i++;
        }
        while(array[j] > pivo && j > inicio){
            detalhes[0]++;
            j--;
        }
        if(i <= j){
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            detalhes[1]++;
            i++;
            j--;
        }
    }
    if(j > inicio)
        quickSort(array, inicio, j+1, detalhes);
    if(i < fim){
        quickSort(array, i, fim, detalhes);
    }
}

void merge(int *array, int inicio, int meio, int fim, unsigned long int *detalhes){

    int *vetAux, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    vetAux = (int *) malloc(tamanho * sizeof(int));

    if(vetAux != NULL){
        for(i = 0; i < tamanho; i++){
            if(!fim1 && !fim2){
                detalhes[0]++;
                if(array[p1] < array[p2]){
                    vetAux[i] = array[p1++];
                    detalhes[1]++;
                }
                else{
                    vetAux[i] = array[p2++];
                    detalhes[1]++;
                }
                if(p1 > meio)
                    fim = 1;
                if(p2 > fim)
                    fim2 = 1;
            } else {
                detalhes[0]++;
                if(!fim1){
                    vetAux[i] = array[p1++];
                    detalhes[1]++;
                }
                else{
                    vetAux[i] = array[p2++];
                    detalhes[1]++;
                }
            }
        }
        for(j = 0, k = inicio; j < tamanho; j++, k++){
            array[k] = vetAux[j];
        }
            
    }
    free(vetAux);
}

void mergeSort(int *array, int inicio, int fim, unsigned long int *detalhes){
    int meio;
    if(inicio < fim){
        meio = floor((fim + inicio)/2);
        mergeSort(array, inicio, meio, detalhes);
        mergeSort(array, meio+1, fim, detalhes);
        merge(array, inicio, meio, fim, detalhes);
    }
}









