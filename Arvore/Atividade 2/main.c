#include <stdio.h>
#include "Floresta.h"

int main() {
    Floresta floresta = NULL;
    InicializaCategoria(&floresta); // Inicializa a primeira categoria

    int categoria;
    Registro produto;

    while (1) {
        printf("Escolha uma opção:\n");
        printf("1. Inserir produto\n");
        printf("2. Pesquisar produto\n");
        printf("3. Remover produto\n");
        printf("4. Imprimir em ordem\n");
        printf("5. Imprimir em pré-ordem\n");
        printf("6. Imprimir em pós-ordem\n");
        printf("7. Sair\n");

        int escolha;
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Informe a categoria do produto: ");
                scanf("%d", &categoria);
                printf("Informe a chave do produto: ");
                scanf("%d", &produto.Chave);
                InsereProduto(produto, &floresta, categoria);
                break;
            case 2:
                printf("Informe a categoria do produto: ");
                scanf("%d", &categoria);
                printf("Informe a chave do produto a ser pesquisado: ");
                scanf("%d", &produto.Chave);
                PesquisaProduto(&produto, floresta, categoria);
                printf("Resultado da pesquisa: Chave=%d\n", produto.Chave);
                break;
            case 3:
                printf("Informe a categoria do produto: ");
                scanf("%d", &categoria);
                printf("Informe a chave do produto a ser removido: ");
                scanf("%d", &produto.Chave);
                RemoveProduto(produto, &floresta, categoria);
                break;
            case 4:
                printf("Informe a categoria para imprimir em ordem: ");
                scanf("%d", &categoria);
                printf("Imprimindo em ordem:\n");
                CaminhamentoEmOrdem(floresta, categoria);
                break;
            case 5:
                printf("Informe a categoria para imprimir em pré-ordem: ");
                scanf("%d", &categoria);
                printf("Imprimindo em pré-ordem:\n");
                CaminhamentoPreOrdem(floresta, categoria);
                break;
            case 6:
                printf("Informe a categoria para imprimir em pós-ordem: ");
                scanf("%d", &categoria);
                printf("Imprimindo em pós-ordem:\n");
                CaminhamentoPosOrdem(floresta, categoria);
                break;
            case 7:
                return 0;
            default:
                printf("Escolha uma opção válida.\n");
        }
    }

    return 0;
}