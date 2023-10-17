#ifndef FILA_H
#define FILA_H

#define VERDADEIRO 1
#define FALSO 0
#define TAM 10

struct tipo_funcionario {
    char cpf[12];
    char nome[100];
    char endereco[200];
    char telefone[15];
    char celular[15];
    char dataNascimento[11];
    char dataAdmissao[11];
    char departamento[100];
    char cargo[100];
    float salario;
};

typedef struct tipo_funcionario funcionario;

struct tipo_fila {
    funcionario vet[TAM];
    int inicio, fim;
};

typedef struct tipo_fila fila;

void CriarFila(fila *f);
int FilaVazia(fila *f);
int FilaCheia(fila *f);
void Enfileirar(fila *f, funcionario fnc);
funcionario Desenfileirar(fila *f);
void GravaFilaEmArquivo(fila *f, const char *nomeArquivo);
void LeFilaDeArquivo(fila *f, const char *nomeArquivo);
funcionario PesquisarFuncionarioPorCPF(fila *f, const char *cpf);

#endif