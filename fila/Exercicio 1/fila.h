#ifndef FILA_H
#define FILA_H

#define VERDADEIRO 1
#define FALSO 0
#define TAM 3

typedef int elemento;

struct tipo_fila {
    elemento vet[TAM];
    int inicio, fim;
};

typedef struct tipo_fila fila;

void CriarFila(fila *f);
int FilaVazia(fila *f);
int FilaCheia(fila *f);
void Enfileirar(fila *f, elemento e);
elemento Desenfileirar(fila *f);
void ImprimeFila(fila *f);

#endif