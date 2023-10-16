#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    int num, resto;
    pilha p;
    CriarPilha(&p);

    printf("\nInforme um numero inteiro: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("\nCorrespondente em binario: 0");
        return 0;
    }

    while (num != 0) {
        resto = num % 2;
        Empilhar(&p, resto);
        num /= 2;
    }

    if (PilhaCheia(&p)) {
        printf("\nA representacao binaria possui mais de 5 bits. Os bits mais significativos nao serao processados.");
    }

    printf("\nCorrespondente em binario: ");
    while (PilhaVazia(&p) == FALSO) {
        resto = Desempilhar(&p);
        printf("%d", resto);
    }

    printf("\n");
    system("pause");
    return 0;
}