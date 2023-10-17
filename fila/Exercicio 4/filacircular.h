#ifndef FILACIRCULAR_H
#define FILACIRCULAR_H

#define VERDADEIRO 1
#define FALSO 0
#define TAM 5

struct tipo_fila {
    int vet[TAM];
    int inicio, fim;
};

typedef struct tipo_fila fila;

void CriarFila(fila *f);
int FilaVazia(fila *f);
int FilaCheia(fila *f);
void Enfileirar(fila *f, int e);
int Desenfileirar(fila *f);

#endif