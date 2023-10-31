#ifndef LISTA_H
#define LISTA_H

typedef struct aluno {
    int codigo;
    char nome[100];
} Aluno;

typedef struct nodo *lista;
typedef struct nodo *pt_nodo;
typedef struct nodo {
    Aluno aluno;
    pt_nodo prox;
} tnodo;

void CriarLista(lista *l);
int ListaVazia(lista *l);
void InserirOrdenado(lista *l, Aluno *aluno);
Aluno RemoverAluno(lista *l, int codigo);
void ImprimirLista(lista *l);

#endif