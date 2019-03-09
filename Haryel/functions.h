void doing(int* array, int size){

    system("cls || clear");
    showArray(array, size);
    printf("\nAperte a tecla [ENTER] para continuar . . .\n");
    setbuf(stdin, NULL);
    getchar();
}

void showDetalhes(int* detalhes, int* array, int size){

    system("cls || clear");
    
    showArray(array, size);
    printf("Trocas: %d\n", detalhes[0]);
    printf("Comparacoes: %d\n", detalhes[1]);
    printf("\nAperte a tecla [ENTER] para continuar . . .\n");
    
    setbuf(stdin, NULL);
    getchar();
    
}