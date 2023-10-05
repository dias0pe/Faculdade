#include <stdio.h> //printf(), scanf().

int main() {
int num1;
int num2;


printf ("\nInforme o ano de nascimento: ");
scanf ("%d", &num1);
printf("O ano de nascimento é: %d \n\n\n", num1);

printf ("\nInforme o ano atual: ");
scanf ("%d", &num2);
printf("O ano atual é: %d \n\n\n", num2);




printf("\nA idade do usuario  é igual a: %d", num2 - num1 );
printf("\nA idade do usuario em 2050  é igual a: %d", 2050 - num1 );
return 0;
}