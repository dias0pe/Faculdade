/*
* Arquivo: pilha.h
* Biblioteca de operações para pilha implementada com vetor.
*/

#include <stdio.h>

#define VERDADEIRO 1
#define FALSO 0
#define TAM 5

struct tipo_pilha {
    int vet[TAM];
    int topo;
};

typedef struct tipo_pilha pilha;

// Cria pilha.
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
    if (p->topo < TAM) {
        p->vet[p->topo] = elemento;
        p->topo++;
    }
}
// Remove um elemento da pilha.
int Desempilhar(pilha *p) {
    p->topo--;
    return p->vet[p->topo];
}