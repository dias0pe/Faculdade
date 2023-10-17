#include <stdio.h>
#include "filacircular.h"

int main() {
    int num;
    fila f;
    CriarFila(&f);

    printf("Insira os números na fila. Digite 0 para parar.\n");

    while (1) {
        if (FilaCheia(&f)) {
            printf("A fila está cheia. Substituindo o número: %d\n", Desenfileirar(&f));
        }

        printf("Insira um número inteiro (0 para parar): ");
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        Enfileirar(&f, num);
    }

    // Desenfileirar e imprimir os elementos
    printf("\nDesenfileirando:\n");
    while (!FilaVazia(&f)) {
        num = Desenfileirar(&f);
        printf("%d\n", num);
    }

    return 0;
}