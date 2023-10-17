#include "filacircular.h"

void CriarFila(fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

int FilaVazia(fila *f) {
    return (f->inicio == f->fim);
}

int FilaCheia(fila *f) {
    return ((f->fim + 1) % TAM == f->inicio);
}

void Enfileirar(fila *f, int e) {
    if (!FilaCheia(f)) {
        f->vet[f->fim] = e;
        f->fim = (f->fim + 1) % TAM;  // Avança com tratamento circular
    } else {
        // A fila está cheia, novos elementos irão sobrescrever os mais antigos
        f->vet[f->fim] = e;
        f->fim = (f->fim + 1) % TAM;
        f->inicio = (f->inicio + 1) % TAM;  // Avança a posição de início
    }
}

int Desenfileirar(fila *f) {
    if (!FilaVazia(f)) {
        int e = f->vet[f->inicio];
        f->inicio = (f->inicio + 1) % TAM;  // Avança com tratamento circular
        return e;
    } else {
        return -1;  // Valor padrão para indicar erro
    }
}
