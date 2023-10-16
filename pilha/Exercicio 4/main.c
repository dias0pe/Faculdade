#include <stdio.h>
#include "pilhacircular.h"

int main() {
    pilha p;
    CriarPilha(&p);

    int opcao, elemento;

    while (1) {
        printf("\n1. Empilhar\n2. Desempilhar\n3. Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (PilhaCheia(&p)) {
                    printf("A pilha está cheia. Elemento será sobrescrito.\n");
                }
                printf("Informe o elemento a ser empilhado: ");
                scanf("%d", &elemento);
                Empilhar(&p, elemento);
                break;
            case 2:
                if (PilhaVazia(&p)) {
                    printf("A pilha está vazia.\n");
                } else {
                    elemento = Desempilhar(&p);
                    printf("Elemento desempilhado: %d\n", elemento);
                }
                break;
            case 3:
                return 0;
            default:
                printf("Opção inválida.\n");
                break;
        }
    }

    return 0;
}