#ifndef LISTA_H
#define LISTA_H

typedef struct Funcionario {
    char nome[50];
    char dataAdmissao[11];
    float salario;
    struct Funcionario *proximo;
} Funcionario;

typedef struct ListaEncadeada {
    Funcionario *inicio;
} ListaEncadeada;

Funcionario* criarFuncionario(const char *nome, const char *dataAdmissao, float salario);
void inserirFuncionarioOrdenado(ListaEncadeada *lista, Funcionario *novoFuncionario);
Funcionario* buscarFuncionario(ListaEncadeada *lista, const char *nome);
void listarFuncionarios(ListaEncadeada *lista);
void liberarLista(ListaEncadeada *lista);

#endif  // LISTA_H