#include <stdio.h>
#include <stdlib.h>
#include "deque.h" // Inclua a biblioteca do deque


typedef int elemento;

int main() {
    int opcao, pos, novo_elemento;
    deque d;
    CriarDeque(&d);
    

    while (1) {
        printf("\nMenu:");
        printf("\n1. Inserir no início");
        printf("\n2. Inserir no fim");
        printf("\n3. Remover do início");
        printf("\n4. Remover do fim");
        printf("\n5. Atualizar elemento");
        printf("\n0. Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe o elemento a ser inserido no início: ");
                scanf("%d", &novo_elemento);
                InserirInicio(&d, novo_elemento);
                break;
            case 2:
                printf("Informe o elemento a ser inserido no fim: ");
                scanf("%d", &novo_elemento);
                InserirFim(&d, novo_elemento);
                break;
            case 3:
                if (!DequeVazio(&d)) {
                    elemento removido = RemoverInicio(&d);
                    printf("Elemento removido do início: %d\n", removido);
                } else {
                    printf("Deque vazio, nada para remover.\n");
                }
                break;
            case 4:
                if (!DequeVazio(&d)) {
                    elemento removido = RemoverFim(&d);
                    printf("Elemento removido do fim: %d\n", removido);
                } else {
                    printf("Deque vazio, nada para remover.\n");
                }
                break;
            case 5:
                printf("Informe a posição do elemento a ser atualizado: ");
                scanf("%d", &pos);
                printf("Informe o novo valor: ");
                scanf("%d", &novo_elemento);
                AtualizarElemento(&d, novo_elemento, pos);
                break;
            case 0:
                exit(0);
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}