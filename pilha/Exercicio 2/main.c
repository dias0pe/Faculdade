#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"




int main() {
    pilha p;
    CriarPilha(&p);
    elemento num;
    char arquivo[] = "numeros.txt";

    printf("Empilhando números reais:\n");
    for (int i = 0; i < TAM; i++) {
        printf("Informe um número real: ");
        scanf("%f", &num);
        Empilhar(&p, num);
    }

    // Desempilhar e gravar no arquivo.
    DesempilharParaArquivo(&p, arquivo);
    printf("Elementos desempilhados e gravados em '%s'.\n", arquivo);

    // Limpa a pilha, lê do arquivo e empilha novamente.
    CriarPilha(&p);
    LerDoArquivoEPush(&p, arquivo);
    printf("Elementos lidos do arquivo '%s' e empilhados novamente.\n", arquivo);

    // Imprimir o conteúdo da pilha na tela.
    
    
    printf("Conteúdo da pilha:\n");
    ImprimePilhaTela(&p);

    return 0;
}