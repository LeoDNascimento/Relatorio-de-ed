void doing(int* array, int size){

    system("clear");
    showArray(array, size);
    printf("\nAperte a tecla [ENTER] para continuar . . .\n");
    setbuf(stdin, NULL);
    getchar();
}

void showDetalhes(int* detalhes, int* array, int size, float* tempo){

    system("clear");
    
    showArray(array, size);
    printf("Trocas: %d\n", detalhes[1]);
    printf("Comparacoes: %d\n", detalhes[0]);
    printf("Tempo: %.3f", (tempo[1] - tempo[0])/CLOCKS_PER_SEC);
    printf("\nAperte a tecla [ENTER] para continuar . . .\n");
    
    setbuf(stdin, NULL);
    getchar();
    
}