#ifndef HASH_H
#define HASH_H

#include "lista.h"
  
#define TAM 3
  
typedef struct TipoEntrada
{
  
char *chave;
   
pilha topo;
 
} entrada;

 
typedef entrada hash[TAM];

 
void CriarHash (hash h);

int FuncaoHash (char *chave);

void InserirHash (hash h, char *chave, elemento * e);

pt_nodo * PesquisarHash (hash h, char *chave);

elemento ExcluirHash (pt_nodo * p);

void LimparHash (hash h);

 
#endif	/* 
 */
