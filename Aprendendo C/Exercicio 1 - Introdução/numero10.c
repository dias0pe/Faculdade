#include <stdio.h> //printf(), scanf().
#include <math.h> //pow ().

int main() {
float R;
float TT = 3.14;



printf ("\nInforme o Raio: ");
scanf ("%f", &R);
printf("O valor é: %f \n\n\n", R);






printf("\nO comprimento da esfera  é: %f", 2*TT*R );
printf("\nA área da esfera  é: %f", TT*pow(R,2));
printf("\nO volume da esfera  é: %f", 0.75*TT*pow(R,3)); //troquei 3/4 por 0.75


return 0;
}