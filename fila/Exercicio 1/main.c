#include <stdio.h>
#include "fila.h"

int main() {
    int num;
    fila f;
    CriarFila(&f);

    while (!FilaCheia(&f)) {
        printf("Informe um número inteiro (ou -1 para encerrar): ");
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        Enfileirar(&f, num);
    }

    ImprimeFila(&f);

    printf("Números retirados da fila:\n");
    while (!FilaVazia(&f)) {
        num = Desenfileirar(&f);
        printf("%d\n", num);
    }

    return 0;
}