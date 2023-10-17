#include <stdio.h>
#include "fila.h"

void CriarFila(fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

int FilaVazia(fila *f) {
    return (f->inicio == f->fim);
}

int FilaCheia(fila *f) {
    return (f->fim == TAM);
}

void Enfileirar(fila *f, float e) {
    if (!FilaCheia(f)) {
        f->vet[f->fim++] = e;
    } else {
        printf("A fila está cheia. Não é possível enfileirar mais elementos.\n");
    }
}

float Desenfileirar(fila *f) {
    float e;
    if (!FilaVazia(f)) {
        e = f->vet[f->inicio];
        f->inicio++;
        return e;
    } else {
        printf("A fila está vazia. Não é possível desenfileirar elementos.\n");
        return -1.0;  // Valor padrão para indicar erro
    }
}

void ImprimeFila(fila *f) {
    if (FilaVazia(f)) {
        printf("A fila está vazia.\n");
    } else {
        printf("Conteúdo da fila:\n");
        for (int i = f->inicio; i < f->fim; i++) {
            printf("%.2f ", f->vet[i]);
        }
        printf("\n");
    }
}

void GravaFilaEmArquivo(fila *f, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo) {
        for (int i = f->inicio; i < f->fim; i++) {
            fprintf(arquivo, "%.2f\n", f->vet[i]);
        }
        fclose(arquivo);
    } else {
        printf("Não foi possível abrir o arquivo para gravação.\n");
    }
}

void LeFilaDeArquivo(fila *f, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo) {
        float numero;
        while (fscanf(arquivo, "%f", &numero) != EOF && !FilaCheia(f)) {
            Enfileirar(f, numero);
        }
        fclose(arquivo);
    } else {
        printf("Não foi possível abrir o arquivo para leitura.\n");
    }
}