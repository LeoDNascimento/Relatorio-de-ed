void doing(int* array, int size, int* detalhes, int tam){

    system("cls || clear");
    showArray(array, size);
    showDetalhes(detalhes, tam);
    printf("\nAperte a tecla [ENTER] para continuar . . .\n");
    setbuf(stdin, NULL);
    getchar();
}

void showDetalhes(int* detalhes, int size){

    printf("Trocas: %d\n", detalhes[0]);
    printf("Comparacoes: %d\n", detalhes[1]);

}