#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição de um livro
typedef struct {
    char titulo[100];
    char autor[100];
    int edicao;
} Livro;

// Definição de um nó da pilha
typedef struct Node {
    Livro livro;
    struct Node *prox;
} Node;

// Definição da pilha
typedef struct {
    Node *topo;
} Pilha;

// Função para criar uma pilha vazia
void criarPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

// Função para empilhar um livro
void empilharLivro(Pilha *pilha, Livro livro) {
    Node *novoNode = (Node *)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Erro: Não foi possível alocar memória para o livro.\n");
        exit(1);
    }
    novoNode->livro = livro;
    novoNode->prox = pilha->topo;
    pilha->topo = novoNode;
}

// Função para desempilhar um livro
Livro desempilharLivro(Pilha *pilha) {
    if (pilha->topo == NULL) {
        printf("Erro: A pilha está vazia.\n");
        exit(1);
    }

    Node *nodeDesempilhado = pilha->topo;
    Livro livro = nodeDesempilhado->livro;
    pilha->topo = nodeDesempilhado->prox;
    free(nodeDesempilhado);
    return livro;
}

// Função para imprimir o conteúdo da pilha na tela
void imprimirPilha(Pilha pilha) {
    Node *atual = pilha.topo;
    printf("Conteúdo da pilha:\n");
    while (atual != NULL) {
        printf("Título: %s, Autor: %s, Edição: %d\n", atual->livro.titulo, atual->livro.autor, atual->livro.edicao);
        atual = atual->prox;
    }
}

// Função para imprimir o conteúdo da pilha em um arquivo binário
void salvarPilhaEmArquivo(Pilha pilha, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro: Não foi possível abrir o arquivo para escrita.\n");
        exit(1);
    }

    Node *atual = pilha.topo;
    while (atual != NULL) {
        fwrite(&(atual->livro), sizeof(Livro), 1, arquivo);
        atual = atual->prox;
    }

    fclose(arquivo);
}

// Função para ler o conteúdo do acervo de um arquivo binário e empilhá-lo
void lerArquivoParaPilha(Pilha *pilha, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro: Não foi possível abrir o arquivo para leitura.\n");
        exit(1);
    }

    Livro livro;
    while (fread(&livro, sizeof(Livro), 1, arquivo) == 1) {
        empilharLivro(pilha, livro);
    }

    fclose(arquivo);
}

// Função para encontrar a posição de um livro na pilha
int encontrarLivro(Pilha pilha, const char *tituloDesejado) {
    Node *atual = pilha.topo;
    int posicao = 0;
    while (atual != NULL) {
        posicao++;
        if (strcmp(atual->livro.titulo, tituloDesejado) == 0) {
            return posicao;
        }
        atual = atual->prox;
    }
    return -1; // Livro não encontrado
}

int main() {
    Pilha pilha;
    criarPilha(&pilha);

    char codigo[10];

    while (1) {
        printf("Informe um código ('fim' para encerrar ou 'imprimir' para imprimir a pilha): ");
        scanf("%s", codigo);

        if (strcmp(codigo, "fim") == 0) {
            break;
        } else if (strcmp(codigo, "imprimir") == 0) {
            imprimirPilha(pilha);
        } else {
            Livro livro;
            strcpy(livro.titulo, codigo);
            printf("Informe o autor: ");
            scanf("%s", livro.autor);
            printf("Informe a edição: ");
            scanf("%d", &livro.edicao);
            empilharLivro(&pilha, livro);
        }
    }

    salvarPilhaEmArquivo(pilha, "acervo.bin");

    Pilha pilhaLida;
    criarPilha(&pilhaLida);
    lerArquivoParaPilha(&pilhaLida, "acervo.bin");

    char tituloDesejado[100];
    printf("Informe o título do livro que deseja encontrar: ");
    scanf("%s", tituloDesejado);
    int posicao = encontrarLivro(pilhaLida, tituloDesejado);

    if (posicao != -1) {
        printf("O livro '%s' está na posição %d da pilha.\n", tituloDesejado, posicao);
    } else {
        printf("O livro '%s' não foi encontrado na pilha.\n", tituloDesejado);
    }

    return 0;
}
