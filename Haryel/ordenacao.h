/*
    Metodo: BubbleSort
*/

void bubbleSort(int *array, int size, int *detalhes){

	int aux = 0;

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
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

void selectionSort(int *array, int size, int *detalhes){

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
