#include <stdio.h>
#include "lista.h"

int main() {
    int opcao;
    lista l;
    CriarLista(&l);

    do {
        Aluno aluno;
        printf("Informe o código do aluno: ");
        scanf("%d", &aluno.codigo);
        printf("Informe o nome do aluno: ");
        scanf("%s", aluno.nome);

        InserirOrdenado(&l, &aluno);

        printf("Deseja cadastrar outro aluno? (0 para não, 1 para sim)\n");
        scanf("%d", &opcao);
    } while (opcao == 1);

    printf("\nLista de alunos cadastrados em ordem alfabética:\n");
    ImprimirLista(&l);

    int codigo;
    printf("Informe o código do aluno a ser removido: ");
    scanf("%d", &codigo);

    Aluno alunoRemovido = RemoverAluno(&l, codigo);
    if (alunoRemovido.codigo != -1) {
        printf("Aluno removido: Código: %d, Nome: %s\n", alunoRemovido.codigo, alunoRemovido.nome);
    } else {
        printf("Aluno não encontrado.\n");
    }

    return 0;
}