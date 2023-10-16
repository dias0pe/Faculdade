/*
* Arquivo: pilha.h
* Biblioteca de operações para pilha implementada com vetor.
*/

#include <stdio.h>
#include <string.h>

#define VERDADEIRO 1
#define FALSO 0
#define TAM 10

// Definindo a estrutura de registro do funcionário
struct tipo_funcionario {
    char cpf[12];
    char nome[50];
    char endereco[100];
    char telefone[15];
    char celular[15];
    char data_nascimento[11];
    char data_admissao[11];
    char departamento[50];
    char cargo[50];
    double salario;
};

typedef struct tipo_funcionario funcionario;

struct tipo_pilha {
    funcionario vet[TAM];
    int topo;
};

typedef struct tipo_pilha pilha;

void CriarPilha(pilha *p) {
    p->topo = 0;
}

int PilhaVazia(pilha *p) {
    return (p->topo == 0);
}

int PilhaCheia(pilha *p) {
    return (p->topo == TAM);
}

void Empilhar(pilha *p, funcionario f) {
    p->vet[p->topo] = f;
    p->topo++;
}

funcionario Desempilhar(pilha *p) {
    p->topo--;
    return p->vet[p->topo];
}

void PesquisarPorCPF(pilha *p, char cpf[12]) {
    int i;
    for (i = p->topo - 1; i >= 0; i--) {
        if (strcmp(p->vet[i].cpf, cpf) == 0) {
            
            printf("Funcionário encontrado:\n");
            printf("Nome: %s\n", p->vet[i].nome);
            printf("CPF: %s\n", p->vet[i].cpf);
            printf("Endereço: %s\n", p->vet[i].endereco);
            printf("Telefone: %s\n", p->vet[i].telefone);
            printf("Celular: %s\n", p->vet[i].celular);
            printf("Data de Nascimento: %s\n", p->vet[i].data_nascimento);
            printf("Data de Admissão: %s\n", p->vet[i].data_admissao);
            printf("Departamento: %s\n", p->vet[i].departamento);
            printf("Cargo: %s\n", p->vet[i].cargo);
            printf("Salário: %.2lf\n", p->vet[i].salario);
            return;
        }
            
        
    }
    printf("Funcionário com CPF %s não encontrado.\n", cpf);
}