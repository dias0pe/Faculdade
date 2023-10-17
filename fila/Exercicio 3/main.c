#include <stdio.h>
#include "fila.h"
#include <string.h>

int main() {
    fila f;
    CriarFila(&f);

    // Leitura de registros de funcionários a partir do teclado e enfileiramento
    for (int i = 0; i < TAM; i++) {
        funcionario fnc;
        printf("Informe os dados do funcionário %d:\n", i + 1);
        printf("CPF: ");
        scanf("%s", fnc.cpf);
        printf("Nome: ");
        scanf("%s", fnc.nome);
        printf("Endereço: ");
        scanf("%s", fnc.endereco);
        printf("Telefone: ");
        scanf("%s", fnc.telefone);
        printf("Celular: ");
        scanf("%s", fnc.celular);
        printf("Data de Nascimento (dd/mm/aaaa): ");
        scanf("%s", fnc.dataNascimento);
        printf("Data de Admissão (dd/mm/aaaa): ");
        scanf("%s", fnc.dataAdmissao);
        printf("Departamento: ");
        scanf("%s", fnc.departamento);
        printf("Cargo: ");
        scanf("%s", fnc.cargo);
        printf("Salário: ");
        scanf("%f", &fnc.salario);
        Enfileirar(&f, fnc);
    }

    // Grava a fila em um arquivo binário
    GravaFilaEmArquivo(&f, "funcionarios.dat");

    // Limpa a fila
    CriarFila(&f);

    // Lê a fila do arquivo binário
    LeFilaDeArquivo(&f, "funcionarios.dat");

    // Imprime a fila
    printf("\nConteúdo da fila:\n");
    for (int i = f.inicio; i < f.fim; i++) {
        printf("Funcionário %d:\n", i - f.inicio + 1);
        printf("CPF: %s\n", f.vet[i].cpf);
        printf("Nome: %s\n", f.vet[i].nome);
        printf("Endereço: %s\n", f.vet[i].endereco);
        printf("Telefone: %s\n", f.vet[i].telefone);
        printf("Celular: %s\n", f.vet[i].celular);
        printf("Data de Nascimento: %s\n", f.vet[i].dataNascimento);
        printf("Data de Admissão: %s\n", f.vet[i].dataAdmissao);
        printf("Departamento: %s\n", f.vet[i].departamento);
        printf("Cargo: %s\n", f.vet[i].cargo);
        printf("Salário: %.2f\n\n", f.vet[i].salario);
    }

    // Pesquisa um funcionário por CPF
char cpfPesquisa[12];
printf("Informe o CPF para pesquisa: ");
scanf("%s", cpfPesquisa);
funcionario encontrado = PesquisarFuncionarioPorCPF(&f, cpfPesquisa);
if (strcmp(encontrado.cpf, "") == 0) {
    printf("Funcionário com CPF %s não encontrado.\n", cpfPesquisa);
} else {
    printf("Funcionário encontrado:\n");
    printf("CPF: %s\n", encontrado.cpf);
    printf("Nome: %s\n", encontrado.nome);
    printf("Endereço: %s\n", encontrado.endereco);
    printf("Telefone: %s\n", encontrado.telefone);
    printf("Celular: %s\n", encontrado.celular);
    printf("Data de Nascimento: %s\n", encontrado.dataNascimento);
    printf("Data de Admissão: %s\n", encontrado.dataAdmissao);
    printf("Departamento: %s\n", encontrado.departamento);
    printf("Cargo: %s\n", encontrado.cargo);
    printf("Salário: %.2f\n", encontrado.salario);
}
    return 0;
}