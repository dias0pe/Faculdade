#include <stdio.h> //printf(), scanf().

int main() {
float num1;
float num2;


printf ("\nInforme seu peso: ");
scanf ("%f", &num1);
printf("Seu peso é: %f \n\n\n", num1);






printf("\nSe engordar 15 porcento: %f", (num1*0.15)+num1);
printf("\nSe engordar 20 porcento: %f", (num1*0.20)+num1);

return 0;
}