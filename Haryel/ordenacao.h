/*
    Metodo: BubbleSort
*/

int particiona(int*, int, int);

void bubbleSort(int *array, int size, unsigned long int *detalhes, float* tempo){

	int aux = 0;

    tempo[0] = clock();
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
    tempo[1] = clock();
}

/*
    Metodo: SelectionSort
*/

void selectionSort(int *array, int size, unsigned long int *detalhes, float* tempo){

    int menor, troca;

    tempo[0] = clock();
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
    tempo[1] = clock();
}

/*
    Metodo: GnomeSort
*/

void gnomeSort(int *array, int size, unsigned long int *detalhes, float* tempo){
   
   int i, aux;

   tempo[0] = clock();
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
   tempo[1] = clock();
}

/*
    Metodo: InsertionSort
*/

void insertionSort(int *array, int size, unsigned long int *detalhes, float* tempo){

    int aux, i, j;
    
    tempo[0] = clock();
    for(i = 1; i < size; i++){
        aux = array[i]; //auxiliar recebe o valor da posicao i[1]
        detalhes[0]++;
        for(j = i; (j > 0) && (aux < array[j-1]); j--){ //aux, i, j nesse momento sao o mesmo valor. A comparacao eh feita com entre a posicao atual e sua anterior.
            array[j] = array[j-1]; //a casa anterior eh copiada para a atual ou seja, os maiores sao deslocados para direita
        }   
        array[j] = aux; //aux vai ser o novo valor de J
        detalhes[1]++;
    }
    tempo[1] = clock();
}

/*
    Metodo: ShellSort
    Este metodo consiste em pegar uma variavel h=n/2, onde n eh o tamanho do vetor e iremos fazer as comparacoes de por exemplo, da posicao e da posicao que esta 4 em seguida dela. Ou seja, comparamos array[0] com array[4], array[1] com array[5] etc
    Apos cada interacao dividimos h novamente por 2, ate o h ser igual a um. Nesse momento ele passa por todas as posicoes.
*/

void shellSort(int *array, int size, unsigned long int *detalhes, float* tempo){

    int aux, i, j;
    int h = size/2;

    tempo[0] = clock();
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
    tempo[1] = clock();
}











