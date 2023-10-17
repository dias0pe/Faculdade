#ifndef FILA_H
#define FILA_H

#define VERDADEIRO 1
#define FALSO 0
#define TAM 10

struct tipo_fila {
    float vet[TAM];
    int inicio, fim;
};

typedef struct tipo_fila fila;

void CriarFila(fila *f);
int FilaVazia(fila *f);
int FilaCheia(fila *f);
void Enfileirar(fila *f, float e);
float Desenfileirar(fila *f);
void ImprimeFila(fila *f);
void GravaFilaEmArquivo(fila *f, const char *nomeArquivo);
void LeFilaDeArquivo(fila *f, const char *nomeArquivo);

#endif