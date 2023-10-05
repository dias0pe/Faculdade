#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    printf("Digite um caractere: ");
    scanf(" %c", &c);

    if (isalnum(c)) {
        printf("%c é uma letra ou um dígito.\n", c);
    } else {
        printf("%c não é uma letra ou um dígito.\n", c);
    }

    return 0;
}
//isalnum(char c): Retorna 1 se o caractere c for uma letra ou um dígito e 0 caso contrário.