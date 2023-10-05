#include <stdio.h>

// Função recursiva para calcular a potência de um número
int calcularPotencia(int base, int expoente) {
    if (expoente == 0) {
        return 1; // Qualquer número elevado a 0 é 1
    } else if (expoente < 0) {
        return 1.0 / (base * calcularPotencia(base, -expoente - 1)); // Trata expoente negativo
    } else {
        return base * calcularPotencia(base, expoente - 1);
    }
}

int main() {
    int base, expoente;

    printf("Digite a base (inteiro): ");
    scanf("%d", &base);

    printf("Digite o expoente (inteiro): ");
    scanf("%d", &expoente);

    int resultado = calcularPotencia(base, expoente);

    printf("%d elevado a %d é igual a %d\n", base, expoente, resultado);

    return 0;
}