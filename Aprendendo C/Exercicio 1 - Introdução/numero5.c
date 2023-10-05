#include <stdio.h> //printf(), scanf().

int main() {
float num1;
float num2;


printf ("\nInforme a diagonal maior do Losango: ");
scanf ("%f", &num1);
printf("O lado vale: %f \n\n\n", num1);

printf ("\nInforme a diagonal menor do Losango ");
scanf ("%f", &num2);
printf("O lado vale: %f \n\n\n", num2);




printf("\nA area do losango é: %f", (num2 * (float)num1)/2);

return 0;
}