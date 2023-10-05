#include <stdio.h> //printf(), scanf().

int main() {
float num1;
float num2;


printf ("\nInforme seu salario: ");
scanf ("%f", &num1);
printf("O valor é R$: %f \n\n\n", num1);

printf ("\nInforme o quanto de aumento irá receber ");
scanf ("%f", &num2);
printf("O valor é R$: %f \n\n\n", num2);




printf("\nO usuario possui R$: %f", (num2 * (float)num1)+num1);

return 0;
}