#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    int num;
    pilha p;
    CriarPilha(&p);

    while (!PilhaCheia(&p)) {
        printf("\nInforme um numero inteiro: ");
        scanf("%d", &num);
        Empilhar(&p, num);
    }

    printf("\nNumeros informados: ");
    ImprimePilha(&p);

    printf("\n");
    system("pause");
    return 0;
}