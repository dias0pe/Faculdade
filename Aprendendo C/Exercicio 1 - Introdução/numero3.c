#include <stdio.h> //printf(), scanf().

int main() {
float num1;
int num2;


printf ("\nInforme a cotação atual do dolar: ");
scanf ("%f", &num1);
printf("O valor é R$: %f \n\n\n", num1);

printf ("\nInforme quantos dolares você possui: ");
scanf ("%d", &num2);
printf("O valor é U$: %d \n\n\n", num2);




printf("\nO usuario possui R$: %f", num2 * (float)num1);

return 0;
}