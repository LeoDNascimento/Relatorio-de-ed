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

    int aux, i, j;
    int h = size/2;

    while(h > 0){
        i = h;
        while(i < size){
            aux = array[i];
            j = i;
            detalhes[0]++;
            while(j >= h && aux < array[j - h]){
                array[j] = array[j - h];
                j -= h;
                detalhes[1]++;
            }
            array[j] = aux;
            i += 1;
        }
    h /= 2;
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

//https://www.youtube.com/watch?v=spywQ2ix_Co QUICK
//https://www.youtube.com/watch?v=RZbg5oT5Fgw&t=2s MERGE









