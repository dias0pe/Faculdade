#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    printf("Digite um caractere: ");
    scanf(" %c", &c);

    if (isdigit(c)) {
        printf("%c é um dígito.\n", c);
    } else {
        printf("%c não é um dígito.\n", c);
    }

    return 0;
}

//isdigit(char c): Retorna 1 se o caractere c for um dígito e 0 caso contrário.