#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>

#define TAM 10
typedef float elemento; // Modificado para números reais (float).

struct tipo_pilha {
    elemento vet[TAM];
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

// Insere um elemento na pilha.
void Empilhar(pilha *p, elemento e) {
    if (p->topo < TAM) {
        p->vet[p->topo] = e;
        p->topo++;
    } else {
        printf("A pilha está cheia. Não é possível empilhar mais elementos.\n");
    }
}

// Retira um elemento da pilha.
elemento Desempilhar(pilha *p) {
    elemento e;
    if (p->topo > 0) {
        p->topo--;
        e = p->vet[p->topo];
    } else {
        printf("A pilha está vazia. Não é possível desempilhar.\n");
        e = (elemento)0; // Valor padrão para evitar problemas.
    }
    return e;
}

// Função para desempilhar os elementos e gravá-los em um arquivo no modo texto.
void DesempilharParaArquivo(pilha *p, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (PilhaVazia(p) == 0) {
        elemento num = Desempilhar(p);
        fprintf(file, "%f\n", num); // Grava o número real no arquivo.
    }

    fclose(file);
}

// Função para ler elementos a partir do arquivo no modo texto e empilhá-los.
void LerDoArquivoEPush(pilha *p, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    elemento num;
    while (fscanf(file, "%f", &num) != EOF) {
        Empilhar(p, num);
    }

    fclose(file);
}

// Função para imprimir o conteúdo da pilha na tela.
void ImprimePilhaTela(pilha *p) {
    if (PilhaVazia(p)) {
        printf("A pilha está vazia.\n");
    } else {
        printf("Conteúdo da pilha:\n");
        pilha temp;
        CriarPilha(&temp);

        while (PilhaVazia(p) == 0) {
            elemento num = Desempilhar(p);
            printf("%0.2f\n", num);
            Empilhar(&temp, num);
        }

        while (PilhaVazia(&temp) == 0) {
            Empilhar(p, Desempilhar(&temp));
        }
    }
}

#endif // PILHA_H