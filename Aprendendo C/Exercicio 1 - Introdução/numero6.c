#include <stdio.h> //printf(), scanf().

int main() {
float num1;
float num2;


printf ("\nInforme a temperatura em celsius: ");
scanf ("%f", &num1);
printf("Temperatura igual á: %f \n\n\n", num1);






printf("\nA temperatura em Fahrenheit é: %f", (num1*1.8)+32 );

return 0;
}