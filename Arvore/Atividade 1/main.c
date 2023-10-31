#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinariaDePesquisa.h"

int main() {
    Registro x;
    TipoDicionario Dicionario;
    Inicia(&Dicionario);

    printf("Informe a chave (digite um número negativo para encerrar): ");
    scanf("%d", &x.Chave);

    while (x.Chave >= 0) {
        Insere(x, &Dicionario);
        printf("Informe a chave (digite um número negativo para encerrar): ");
        scanf("%d", &x.Chave);
    }

    printf("Imprimindo em ordem central:\n");
    Central(Dicionario);

    printf("Imprimindo em pré-ordem:\n");
    PreOrdem(Dicionario);

    printf("Imprimindo em pós-ordem:\n");
    PosOrdem(Dicionario);

    printf("Pesquisa de um elemento na árvore:\n");
    Registro pesquisa;
    printf("Informe a chave a ser pesquisada: ");
    scanf("%d", &pesquisa.Chave);
    Pesquisa(&pesquisa, Dicionario);
    printf("Resultado da pesquisa: Chave=%d\n", pesquisa.Chave);

    printf("Remoção de um elemento da árvore:\n");
    Registro remocao;
    printf("Informe a chave a ser removida: ");
    scanf("%d", &remocao.Chave);
    Retira(remocao, &Dicionario);

    printf("Imprimindo em ordem central após a remoção:\n");
    Central(Dicionario);

    return 0;
}