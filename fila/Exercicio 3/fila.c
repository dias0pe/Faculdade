#include <stdio.h>
#include <string.h>
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

void Enfileirar(fila *f, funcionario fnc) {
    if (!FilaCheia(f)) {
        f->vet[f->fim++] = fnc;
    } else {
        printf("A fila de funcionários está cheia. Não é possível enfileirar mais elementos.\n");
    }
}

funcionario Desenfileirar(fila *f) {
    funcionario fnc;
    if (!FilaVazia(f)) {
        fnc = f->vet[f->inicio];
        f->inicio++;
        return fnc;
    } else {
        printf("A fila de funcionários está vazia. Não é possível desenfileirar elementos.\n");
        strcpy(fnc.cpf, "");
        return fnc;
    }
}

void GravaFilaEmArquivo(fila *f, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo) {
        fwrite(f->vet + f->inicio, sizeof(funcionario), f->fim - f->inicio, arquivo);
        fclose(arquivo);
    } else {
        printf("Não foi possível abrir o arquivo para gravação.\n");
    }
}

void LeFilaDeArquivo(fila *f, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo) {
        fseek(arquivo, 0, SEEK_END);
        long tamanho = ftell(arquivo);
        rewind(arquivo);
        int numFuncionarios = tamanho / sizeof(funcionario);
        fread(f->vet, sizeof(funcionario), numFuncionarios, arquivo);
        f->inicio = 0;
        f->fim = numFuncionarios;
        fclose(arquivo);
    } else {
        printf("Não foi possível abrir o arquivo para leitura.\n");
    }
}

funcionario PesquisarFuncionarioPorCPF(fila *f, const char *cpf) {
    funcionario fnc;
    strcpy(fnc.cpf, "");
    
    for (int i = f->inicio; i < f->fim; i++) {
        if (strcmp(f->vet[i].cpf, cpf) == 0) {
            return f->vet[i];
        }
    }

    return fnc;
}
