#include <stdio.h> //printf(), scanf().

int main() {
float num1;
float num2;


printf ("\nInforme o salario minimo: ");
scanf ("%f", &num1);
printf("O valor é: %f \n\n\n", num1);

printf ("\nInforme o salario que o usuario ganha ");
scanf ("%f", &num2);
printf("O valor é: %f \n\n\n", num2);




printf("\nO usuario recebe: %f", num2/num1);

return 0;
}