#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    printf("Digite um caractere: ");
    scanf(" %c", &c);

    if (isalpha(c)) {
        printf("%c é uma letra.\n", c);
    } else {
        printf("%c não é uma letra.\n", c);
    }

    return 0;
}

// isalpha(char c): Retorna 1 se o caractere c for uma letra e 0 caso contrário.