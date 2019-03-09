void showArray(int *array, int size){
	
	for(int i = 0; i < size; i++){
		if(i == size-1){
			printf("%d\n", array[i]);
		} else {
			printf("%d - ", array[i]);
		}
	}
	
	printf("\n");
}

int* gera_vetor_alt(int size){

	srand(time(NULL));

	int *array = (int *) malloc(size * sizeof(int));

	for (int i = 0; i <= size; i++){
		array[i] = rand() % 100;
	}

	return array;
}
