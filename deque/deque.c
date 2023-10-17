#include <stdio.h>
#include "deque.h"


void CriarDeque(deque *d) {
    d->inicio = 0;
    d->fim = 0;
}

int DequeVazio(deque *d) {
    return (d->inicio == d->fim);
}

int DequeCheio(deque *d) {
    return (d->fim == TAM);
}

void InserirInicio(deque *d, elemento e) {
    if (DequeCheio(d))
        printf("\n ERRO: deque cheio!");
    else {
        if (d->inicio > 0) {
            d->inicio--;
            d->vet[d->inicio] = e;
        } else {
            printf("\n ERRO: impossível inserir no início.");
        }
    }
}

void InserirFim(deque *d, elemento e) {
    if (DequeCheio(d))
        printf("\n ERRO: deque cheio!");
    else {
        d->vet[d->fim] = e;
        d->fim++;
    }
}

elemento RemoverInicio(deque *d) {
    int i;
    elemento e;

    if (DequeVazio(d)) {
        printf("\n ERRO: deque vazio!");
        return -1; // Pode retornar um valor especial para indicar erro.
    }

    e = d->vet[d->inicio];

    for (i = d->inicio; i < d->fim - 1; i++) {
        d->vet[i] = d->vet[i + 1];
    }
    d->fim--;

    return e;
}

elemento RemoverFim(deque *d) {
    if (DequeVazio(d)) {
        printf("\n ERRO: deque vazio!");
        return -1;
    }

    d->fim--;
    return d->vet[d->fim];
}

void AtualizarElemento(deque *d, elemento novo, int pos) {
    if (pos >= d->inicio && pos < d->fim) {
        d->vet[pos] = novo;
    } else {
        printf("\n ERRO: posição não existe!");
        printf("\n Posições válidas: [%d, %d].", d->inicio, d->fim - 1);
    }
}