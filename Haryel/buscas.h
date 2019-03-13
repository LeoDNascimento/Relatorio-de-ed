int buscaSeq(int *array, int size, int valor, float* tempo){

    tempo[0] = clock();
    for(int i = 0; i < size; i++){
        if(array[i] == valor)
            return i;
    }
    tempo[1] = clock();
    
    return false;
}

/*int buscaBin(int *array, int size, int valor){



}*/