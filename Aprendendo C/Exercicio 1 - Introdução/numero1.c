#include <stdio.h> //printf(), scanf().

int main() {
int num1;
int num2;
int num3;

printf ("\nInforme um numero: ");
scanf ("%d", &num1);
printf("Valor de num: %d \n\n\n", num1);

printf ("\nInforme um numero: ");
scanf ("%d", &num2);
printf("Valor de num: %d \n\n\n", num2);

printf ("\nInforme um numero: ");
scanf ("%d", &num3);
printf("Valor de num: %d \n\n\n", num3);


printf("\nA media entre eles é igual a: %d", (num1 + num2 + num3)/3);
return 0;
}