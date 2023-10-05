#include <stdio.h>
#include <stdlib.h>

int *alocarMemoria(int n) {
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1); 
    }
    return array;
}


void preencherArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        array[i] = i * 10;
    }
}


void imprimirArray(int *array, int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int *array, n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    array = alocarMemoria(n);

    preencherArray(array, n);


    imprimirArray(array, n);

    free(array);

    return 0;
}