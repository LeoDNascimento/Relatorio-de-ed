int buscaSeq(int *array, int size, int valor){

    for(int i = 0; i < size; i++){
        if(array[i] == valor)
            return i;
    }
    
    return false;
}

int buscaBin(int *array, int size, int valor){

    int inicio = 0; 
    int fim = size-1;
    int meio;

    //enquanto tem elementos entre o inicio e o fim
    while(inicio <= fim){
        meio = (inicio + fim)/2;
        if(valor < array[meio])
            fim = meio-1; //busca na metade da esquerda
        else 
            if(valor > array[meio])
                inicio = meio+1; //busca na metade da direita
            else 
                return meio; //caso o elemento do meio seja o selecionado
    }
    return -1; //valor n foi encontrado
}