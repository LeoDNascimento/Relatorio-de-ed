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

int* aloca_vetor(int size){
	
	int *array = (int *) malloc(size * sizeof(int));

	if(array == NULL){
		printf("Erro: Sem memoria!\n");
		exit(1);
	}

	return array;
}

/*bool existe(int* array, int size, int valor){
	for(int i = 0; i < size; i++){
		if(array[i] == valor)
			return true;
	}
	return false;
}

int* gera_vetor_alt_norepeat(int size){

	srand(time(NULL));

	int *array = aloca_vetor(size);
	int aux;

	for(int i = 0; i < size; i++){
		aux = rand() % 100;
		while(existe(array, i, aux)){
			aux = rand() % 100;
		}
		array[i] = aux;
	}
}*/

int* gera_vetor_alt(int size){

	srand(time(NULL));

	int *array = aloca_vetor(size);

	for (int i = 0; i <= size; i++){
		array[i] = rand() % 100;
	}

	return array;
}
