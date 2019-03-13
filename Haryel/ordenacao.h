/*
    Metodo: BubbleSort
*/

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

int* gnomeSort(int *array, int size, unsigned long int *detalhes, float* tempo){
   
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

   return array;
}

/*
    Metodo: InsertionSort
*/


