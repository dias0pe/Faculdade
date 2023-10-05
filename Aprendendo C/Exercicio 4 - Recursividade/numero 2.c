#include <stdio.h>

// Função recursiva para calcular a soma dos primeiros n números naturais
int somaNaturais(int n) {
    if (n == 1) {
        return 1; // Caso base: a soma do primeiro número natural é 1
    } else {
        return n + somaNaturais(n - 1); // Chamada recursiva para somar os números anteriores
    }
}

int main() {
    int n;

    printf("Digite um valor para n: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("O valor de n deve ser maior ou igual a 1.\n");
    } else {
        int resultado = somaNaturais(n);
        printf("A soma dos primeiros %d números naturais é: %d\n", n, resultado);
    }

    return 0;
}