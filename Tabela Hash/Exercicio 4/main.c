#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main() {
    TabelaHash tabela;
    inicializarTabela(&tabela);

    lerTabelaDeArquivo(&tabela, "funcionarios.bin");

    int opcao;

    do {
        printf("\n1. Cadastrar funcionario\n");
        printf("2. Pesquisar por nome\n");
        printf("3. Pesquisar por data de admissao\n");
        printf("4. Exibir conteudo da tabela\n");
        printf("5. Excluir funcionario\n");
        printf("6. Gravar tabela em arquivo\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarFuncionario(&tabela);
                break;
            case 2:
                pesquisarFuncionarioPorNome(&tabela);
                break;
            case 3:
                pesquisarFuncionarioPorData(&tabela);
                break;
            case 4:
                exibirConteudoDaTabela(&tabela);
                break;
            case 5:
                excluirFuncionario(&tabela);
                break;
            case 6:
                gravarTabelaEmArquivo(&tabela, "funcionarios.bin");
                break;
            case 7:
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 7);

    return 0;
}