#ifndef LISTA_H
#define LISTA_H

#define VERDADEIRO 1
#define FALSO 0
  
struct palavra_sinonimo
{
  
char *palavra;
   
char *sinonimo;
 
};

 
typedef struct palavra_sinonimo elemento;

 
typedef struct TipoNodo *pilha;

typedef struct TipoNodo *pt_nodo;

 
typedef struct TipoNodo
{
  
elemento e;
  
pt_nodo prox;

} nodo;

 
void CriarPilha (pilha * p);

int PilhaVazia (pilha * p);

void Empilhar (pilha * p, elemento * x);

elemento Desempilhar (pilha * p);

pt_nodo * PesquisarPilha (pilha * p, char *x);

 
#endif	/* 
 */
