#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    printf("Digite um caractere: ");
    scanf(" %c", &c);

    if (isupper(c)) {
        printf("%c é uma letra maiúscula.\n", c);
    } else {
        printf("%c não é uma letra maiúscula.\n", c);
    }

    return 0;
}

//isupper(char c): Retorna 1 se o caractere c for uma letra maiúscula e 0 caso contrário.