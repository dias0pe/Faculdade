#include <stdio.h>
#include <stdlib.h>
#define TAM 3

typedef int elemento;

#include "pilha.h"

int main() {
int num;
pilha p;

CriarPilha(&p);

while(PilhaCheia(&p) == FALSO) {
    printf("\nInforme um numero inteiro: ");
    scanf("%d", &num);
    Empilhar(&p, num);
}

printf("\nNumeros informados: ");
while(PilhaVazia(&p) == FALSO) {
num = Desempilhar(&p);
printf("\n%d", num);
}

printf("\n");
system("pause");

return 0;
}
