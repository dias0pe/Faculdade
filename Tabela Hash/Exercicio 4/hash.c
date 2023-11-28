#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

unsigned int calcularHash(const char *nome) {
    unsigned int hash = 0;
    while (*nome) {
        hash += *nome;
        nome++;
    }
    return hash % TAMANHO;
}

void inicializarTabela(TabelaHash *tabela) {
    for (int i = 0; i < TAMANHO; i++) {
        tabela->lista[i].inicio = NULL;
    }
}

void cadastrarFuncionario(TabelaHash *tabela) {
    char nome[50];
    char dataAdmissao[11];
    float salario;

    printf("Digite o nome do funcionario: ");
    scanf("%s", nome);
    printf("Digite a data de admissao no formato dd/mm/aaaa: ");
    scanf("%s", dataAdmissao);
    printf("Digite o salario do funcionario: ");
    scanf("%f", &salario);

    Funcionario *novoFuncionario = criarFuncionario(nome, dataAdmissao, salario);
    if (novoFuncionario != NULL) {
        unsigned int indice = calcularHash(nome);
        inserirFuncionarioOrdenado(&tabela->lista[indice], novoFuncionario);
        printf("Funcionario cadastrado com sucesso!\n");
    } else {
        printf("Erro ao alocar memoria para o funcionario!\n");
    }
}

void pesquisarFuncionarioPorNome(TabelaHash *tabela) {
    char nome[50];
    printf("Digite o nome do funcionario a ser pesquisado: ");
    scanf("%s", nome);

    unsigned int indice = calcularHash(nome);
    Funcionario *encontrado = buscarFuncionario(&tabela->lista[indice], nome);

    if (encontrado != NULL) {
        printf("Funcionario encontrado:\n");
        printf("Nome: %s, Data de Admissao: %s, Salario: %.2f\n", 
               encontrado->nome, encontrado->dataAdmissao, encontrado->salario);
    } else {
        printf("Funcionario nao encontrado!\n");
    }
}

void pesquisarFuncionarioPorData(TabelaHash *tabela) {
    // Implemente a lógica para pesquisar um funcionário por data de admissão
}

void gravarTabelaEmArquivo(TabelaHash *tabela, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb");

    if (arquivo != NULL) {
        fwrite(tabela, sizeof(TabelaHash), 1, arquivo);
        fclose(arquivo);
        printf("Tabela gravada com sucesso!\n");
    } else {
        printf("Erro ao abrir o arquivo para gravacao!\n");
    }
}

void lerTabelaDeArquivo(TabelaHash *tabela, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");

    if (arquivo != NULL) {
        fread(tabela, sizeof(TabelaHash), 1, arquivo);
        fclose(arquivo);
        printf("Tabela lida com sucesso!\n");
    } else {
        printf("Arquivo nao encontrado ou erro ao abrir!\n");
    }
}

void exibirConteudoDaTabela(TabelaHash *tabela) {
    for (int i = 0; i < TAMANHO; i++) {
        printf("Indice %d:\n", i);
        listarFuncionarios(&tabela->lista[i]);
    }
}

void excluirFuncionario(TabelaHash *tabela) {
    char nome[50];
    printf("Digite o nome do funcionario a ser excluido: ");
    scanf("%s", nome);

    unsigned int indice = calcularHash(nome);
    Funcionario *anterior = NULL;
    Funcionario *atual = tabela->lista[indice].inicio;

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL) {
        if (anterior == NULL) {
            // Remover o primeiro elemento da lista
            tabela->lista[indice].inicio = atual->proximo;
        } else {
            // Remover um elemento no meio ou final da lista
            anterior->proximo = atual->proximo;
        }

        free(atual);
        printf("Funcionario excluido com sucesso!\n");
    } else {
        printf("Funcionario nao encontrado!\n");
    }
}