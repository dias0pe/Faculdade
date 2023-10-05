#include <stdio.h> //printf(), scanf().
#include <math.h> //pow ().

int main() {
float num1;
float num2;
float a;


printf ("\nInforme o cateto b: ");
scanf ("%f", &num1);
printf("O valor é: %f \n\n\n", num1);

printf ("\nInforme o cateto c: ");
scanf ("%f", &num2);
printf("O valor é: %f \n\n\n", num2);




printf("\nA hipotenusa é: %f", sqrt(pow(num1,2)+pow(num2,2)));


return 0;
}