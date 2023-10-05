#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Pessoa
struct Pessoa {
    char CPF[12];
    char nome[100];
    double salario;
};

// Função para alocar dinamicamente um vetor de Pessoa e inicializar os campos
struct Pessoa* criarVetorPessoa(int n) {
    struct Pessoa *vetor = (struct Pessoa *)calloc(n, sizeof(struct Pessoa));
    if (vetor == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return vetor;
}

// Função para preencher o vetor de Pessoa
void preencherVetor(struct Pessoa *vetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o CPF da Pessoa %d: ", i + 1);
        scanf("%s", vetor[i].CPF);

        printf("Digite o nome da Pessoa %d: ", i + 1);
        scanf("%s", vetor[i].nome);

        printf("Digite o salário da Pessoa %d: ", i + 1);
        scanf("%lf", &vetor[i].salario);
    }
}

// Função para imprimir o vetor de Pessoa
void imprimirVetor(struct Pessoa *vetor, int n) {
    printf("Lista de Pessoas:\n");
    for (int i = 0; i < n; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("CPF: %s\n", vetor[i].CPF);
        printf("Nome: %s\n", vetor[i].nome);
        printf("Salário: %.2lf\n", vetor[i].salario);
    }
}

int main() {
    int n;
    printf("Digite o tamanho do vetor de Pessoa: ");
    scanf("%d", &n);

    // Alocação dinâmica de memória para o vetor de Pessoa
    struct Pessoa *vetorPessoa = criarVetorPessoa(n);

    // Preencher o vetor de Pessoa
    preencherVetor(vetorPessoa, n);

    // Imprimir o vetor de Pessoa
    imprimirVetor(vetorPessoa, n);

    // Liberar a memória alocada com calloc
    free(vetorPessoa);

    return 0;
}