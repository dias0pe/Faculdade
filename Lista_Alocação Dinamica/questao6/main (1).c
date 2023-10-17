/* Arquivo: lista.c
* Programa para alistar letras maiúsculas geradas aleatoriamente.
*/
#include <stdio.h> //printf ().
#include <stdlib.h> //system (), srand (), rand ().
#include <time.h> //time ().
typedef char elemento;
#include "lista.h"
void Esperar (long seg);
void ImprimirLista (lista l);
main () {
char c, op = 's', lixo;
int i = 0;
pt_nodo *predecessor = NULL;
lista list;
CriarLista (&list);
srand (time (NULL)); //Gera uma seqüencia pseudo-aleatoria de números inteiros.
do {
c = (char) ((rand () % 26) + 65); //Gera uma letra maiúscula aleatória.
printf ("\n\n%d) Alistando: %c", i++, c);
Alistar (&list, &c);
ImprimirLista (list);
printf ("\n\nDeseja alistar uma nova letra (s/n)? ");
scanf ("%c", &op); scanf ("%c", &lixo);
} while (op == 's');
system ("clear || cls"); ImprimirLista (list); printf ("\n");
do {
printf ("\nInforme a letra a ser substituida: ");
scanf ("%c", &c);
scanf ("%c", &lixo);
predecessor = PesquisarLista (&list, &c);
if (predecessor != NULL) {
printf ("\n\nLetra encontrada na posicao: %p", *predecessor);
Desalistar (predecessor);
printf ("\n\nInforme a letra substituta: ");
scanf ("%c", &c); scanf ("%c", &lixo);
Alistar (predecessor, &c);
ImprimirLista (list);
}
else
printf ("\n\nLetra nao encontrada!");
printf ("\n\nDeseja substituir outra letra (s/n)? ");
scanf ("%c", &op); scanf ("%c", &lixo);
} while (op == 's');
system ("clear || cls"); i = 0; ImprimirLista (list); printf ("\n\n");
while (!ListaVazia (&list)) {
c = Desalistar (&list);
printf ("\n%d) Desalistando: %c", i++, c);
ImprimirLista (list); printf ("\n");
Esperar (2L);
}
printf ("\n\n"); Esperar (6L); //system ("pause");
}
void Esperar (long seg) {
long temp1, temp2;
temp1 = time (NULL); //time (&temp1);
temp2 = time (NULL); //time (&temp2);
while (temp2 - temp1 < seg)
temp2 = time (NULL); //time (&temp2);
}
void ImprimirLista (lista l) {
pt_nodo p = l;
printf ("\nLista = ");
while (p != NULL) {
printf ("%c (%p) -> ", p->e, p);
p = p->prox;
}
printf ("NULL");
}