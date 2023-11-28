#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Funcionario* criarFuncionario(const char *nome, const char *dataAdmissao, float salario) {
    Funcionario *novoFuncionario = (Funcionario *)malloc(sizeof(Funcionario));
    if (novoFuncionario != NULL) {
        strcpy(novoFuncionario->nome, nome);
        strcpy(novoFuncionario->dataAdmissao, dataAdmissao);
        novoFuncionario->salario = salario;
        novoFuncionario->proximo = NULL;
    }
    return novoFuncionario;
}

void inserirFuncionarioOrdenado(ListaEncadeada *lista, Funcionario *novoFuncionario) {
    if (lista->inicio == NULL || strcmp(lista->inicio->nome, novoFuncionario->nome) > 0) {
        novoFuncionario->proximo = lista->inicio;
        lista->inicio = novoFuncionario;
    } else {
        Funcionario *atual = lista->inicio;
        Funcionario *anterior = NULL;
        while (atual != NULL && strcmp(atual->nome, novoFuncionario->nome) < 0) {
            anterior = atual;
            atual = atual->proximo;
        }
        novoFuncionario->proximo = atual;
        anterior->proximo = novoFuncionario;
    }
}

Funcionario* buscarFuncionario(ListaEncadeada *lista, const char *nome) {
    Funcionario *atual = lista->inicio;
    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        atual = atual->proximo;
    }
    return atual;
}

void listarFuncionarios(ListaEncadeada *lista) {
    Funcionario *atual = lista->inicio;
    while (atual != NULL) {
        printf("Nome: %s, Data de Admissao: %s, Salario: %.2f\n", 
               atual->nome, atual->dataAdmissao, atual->salario);
        atual = atual->proximo;
    }
}

void liberarLista(ListaEncadeada *lista) {
    Funcionario *atual = lista->inicio;
    while (atual != NULL) {
        Funcionario *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    lista->inicio = NULL;
}