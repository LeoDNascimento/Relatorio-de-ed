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

/*bool gera_vetor_n_repetido(int size){

	srand(time(NULL));

	

}*/

int* aloca_vetor(int size){

	int *array;

	array = (int *) malloc(size * sizeof(int));

	if(array == NULL){
		printf("Erro: Sem memoria!\n");
		exit(1);
	}

	return *array;
}

int* gera_vetor_alt(int size){

	srand(time(NULL));

	int *array = aloca_vetor(size);

	for (int i = 0; i <= size; i++){
		array[i] = rand() % 100;
	}

	return array;
}
