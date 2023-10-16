/*
* Arquivo: pilhacircular.h
* Biblioteca de operações para pilha circular implementada com vetor.
*/

#include <stdio.h>

#define TAM 10

struct tipo_pilha {
    int vet[TAM];
    int topo;
};

typedef struct tipo_pilha pilha;

// Cria pilha circular.
void CriarPilha(pilha *p) {
    p->topo = 0;
}

// Verifica se a pilha está vazia.
int PilhaVazia(pilha *p) {
    return (p->topo == 0);
}

// Verifica se a pilha está cheia.
int PilhaCheia(pilha *p) {
    return (p->topo == TAM);
}

// Insere um elemento na pilha.
void Empilhar(pilha *p, int elemento) {
    p->vet[p->topo] = elemento;
    p->topo = (p->topo + 1) % TAM; // Circular
}

// Remove um elemento da pilha.
int Desempilhar(pilha *p) {
    int elemento = p->vet[(p->topo - 1 + TAM) % TAM]; // Circular
    p->topo = (p->topo - 1 + TAM) % TAM; // Circular
    return elemento;
}