#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    printf("Digite um caractere: ");
    scanf(" %c", &c);

    if (islower(c)) {
        printf("%c é uma letra minúscula.\n", c);
    } else {
        printf("%c não é uma letra minúscula.\n", c);
    }

    return 0;
}

//islower(char c): Retorna 1 se o caractere c for uma letra minúscula e 0 caso contrário.
