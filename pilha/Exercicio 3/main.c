#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    pilha p;
    CriarPilha(&p);

    while (PilhaCheia(&p) == FALSO) {
        funcionario f;
        printf("\nInforme o CPF do funcionário (sem traços): ");
        scanf("%s", f.cpf);

        printf("Informe o nome: ");
        scanf(" %[^\n]s", f.nome);

        printf("Informe o endereço: ");
        scanf(" %[^\n]s", f.endereco);

        printf("Informe o telefone: ");
        scanf("%s", f.telefone);

        printf("Informe o celular: ");
        scanf("%s", f.celular);

        printf("Informe a data de nascimento (dd/mm/aaaa): ");
        scanf("%s", f.data_nascimento);

        printf("Informe a data de admissão (dd/mm/aaaa): ");
        scanf("%s", f.data_admissao);

        printf("Informe o departamento: ");
        scanf(" %[^\n]s", f.departamento);

        printf("Informe o cargo: ");
        scanf(" %[^\n]s", f.cargo);

        printf("Informe o salário: ");
        scanf("%lf", &f.salario);

        Empilhar(&p, f);
    }

    FILE *file = fopen("funcionarios.bin", "wb");
    if (file != NULL) {
        fwrite(p.vet, sizeof(funcionario), p.topo, file);
        fclose(file);
    }

    printf("\nFuncionários cadastrados: ");
    while (PilhaVazia(&p) == FALSO) {
        funcionario f = Desempilhar(&p);
        printf("\nNome: %s, CPF: %s", f.nome, f.cpf);
    }

    char cpf_pesquisa[12];
    printf("\n\nInforme o CPF para pesquisa: ");
    scanf("%s", cpf_pesquisa);
    PesquisarPorCPF(&p, cpf_pesquisa);

    return 0;
}