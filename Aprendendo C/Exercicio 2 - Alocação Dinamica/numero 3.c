#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Veículo
struct Veiculo {
    char chassi[20];
    char marca[50];
    char modelo[50];
    double preco;
};

// Função para alocar dinamicamente um vetor de Veículo
struct Veiculo* criarVetorVeiculo(int n) {
    struct Veiculo *vetor = (struct Veiculo *)malloc(n * sizeof(struct Veiculo));
    if (vetor == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return vetor;
}

// Função para preencher o vetor de Veículo
void preencherVetor(struct Veiculo *vetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o número do chassi do Veículo %d: ", i + 1);
        scanf("%s", vetor[i].chassi);

        printf("Digite a marca do Veículo %d: ", i + 1);
        scanf("%s", vetor[i].marca);

        printf("Digite o modelo do Veículo %d: ", i + 1);
        scanf("%s", vetor[i].modelo);

        printf("Digite o preço do Veículo %d: ", i + 1);
        scanf("%lf", &vetor[i].preco);
    }
}

// Função para imprimir o vetor de Veículo
void imprimirVetor(struct Veiculo *vetor, int n) {
    printf("Vetor de Veículos:\n");
    for (int i = 0; i < n; i++) {
        printf("Veículo %d:\n", i + 1);
        printf("Número do Chassi: %s\n", vetor[i].chassi);
        printf("Marca: %s\n", vetor[i].marca);
        printf("Modelo: %s\n", vetor[i].modelo);
        printf("Preço: %.2lf\n", vetor[i].preco);
    }
}

int main() {
    int n;
    printf("Digite o tamanho inicial do vetor de Veículo: ");
    scanf("%d", &n);

    // Alocação dinâmica de memória para o vetor de Veículo
    struct Veiculo *vetorVeiculo = criarVetorVeiculo(n);

    // Preencher o vetor de Veículo
    preencherVetor(vetorVeiculo, n);

    // Imprimir o vetor de Veículo
    imprimirVetor(vetorVeiculo, n);

    // Realocar o vetor para um tamanho maior
    int novo_tamanho = n + 5;
    vetorVeiculo = (struct Veiculo *)realloc(vetorVeiculo, novo_tamanho * sizeof(struct Veiculo));
    if (vetorVeiculo == NULL) {
        printf("Falha na realocação de memória.\n");
        return 1;
    }

    // Preencher os elementos adicionais
    for (int i = n; i < novo_tamanho; i++) {
        printf("Digite o número do chassi do Veículo %d: ", i + 1);
        scanf("%s", vetorVeiculo[i].chassi);

        printf("Digite a marca do Veículo %d: ", i + 1);
        scanf("%s", vetorVeiculo[i].marca);

        printf("Digite o modelo do Veículo %d: ", i + 1);
        scanf("%s", vetorVeiculo[i].modelo);

        printf("Digite o preço do Veículo %d: ", i + 1);
        scanf("%lf", &vetorVeiculo[i].preco);
    }

    // Imprimir o vetor após a realocação
    imprimirVetor(vetorVeiculo, novo_tamanho);

    // Liberar a memória alocada
    free(vetorVeiculo);

    return 0;
}