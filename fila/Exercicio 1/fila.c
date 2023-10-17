#include <stdio.h>
#include "fila.h"

void CriarFila(fila *f) {
    f->inicio = -1;
    f->fim = -1;
}

int FilaVazia(fila *f) {
    return (f->inicio == -1 && f->fim == -1);
}

int FilaCheia(fila *f) {
    return (f->fim == TAM - 1);
}

void Enfileirar(fila *f, elemento e) {
    if (!FilaCheia(f)) {
        if (FilaVazia(f)) {
            f->inicio = 0;
        }
        f->vet[++f->fim] = e;
    } else {
        printf("A fila está cheia. Não é possível enfileirar mais elementos.\n");
    }
}

elemento Desenfileirar(fila *f) {
    elemento e;
    if (!FilaVazia(f)) {
        e = f->vet[f->inicio];
        if (f->inicio == f->fim) {
            f->inicio = -1;
            f->fim = -1;
        } else {
            f->inicio++;
        }
        return e;
    } else {
        printf("A fila está vazia. Não é possível desenfileirar elementos.\n");
        return -1;  // Valor padrão para indicar erro
    }
}

void ImprimeFila(fila *f) {
    if (FilaVazia(f)) {
        printf("A fila está vazia.\n");
    } else {
        printf("Conteúdo da fila:\n");
        for (int i = f->inicio; i <= f->fim; i++) {
            printf("%d ", f->vet[i]);
        }
        printf("\n");
    }
}