#include <stdio.h>
#include "fila.h"

int main() {
    float numero;
    fila f;

    // Cria a fila
    CriarFila(&f);

    // Leitura de números reais a partir do teclado e enfileiramento
    for (int i = 0; i < TAM; i++) {
        printf("Informe um número real: ");
        scanf("%f", &numero);
        Enfileirar(&f, numero);
    }

    // Imprime a fila
    printf("\nConteúdo da fila:\n");
    ImprimeFila(&f);

    // Grava a fila em um arquivo
    GravaFilaEmArquivo(&f, "fila.txt");

    // Limpa a fila
    CriarFila(&f);

    // Lê a fila do arquivo
    LeFilaDeArquivo(&f, "fila.txt");

    // Imprime a fila lida do arquivo
    printf("\nConteúdo da fila lida do arquivo:\n");
    ImprimeFila(&f);

    return 0;
}