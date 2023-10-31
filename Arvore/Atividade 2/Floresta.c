#include "Floresta.h"
#include "ArvoreBinariaDePesquisa.h"
#include <stdlib.h>
#include <stdio.h>

static void CriaArvore(TipoDicionario *arvore) {
    *arvore = NULL;
}

void InicializaCategoria(Floresta *floresta) {
    ApontadorCategoria novaCategoria = (ApontadorCategoria)malloc(sizeof(Categoria));
    CriaArvore(&novaCategoria->ArvoreCategoria);
    novaCategoria->ProximaCategoria = *floresta;
    *floresta = novaCategoria;
}

void InsereProduto(Registro produto, Floresta *floresta, int categoria) {
    ApontadorCategoria categoriaAtual = *floresta;

    for (int i = 0; i < categoria; i++) {
        if (categoriaAtual == NULL) {
            printf("Categoria %d não existe na floresta.\n", categoria);
            return;
        }
        categoriaAtual = categoriaAtual->ProximaCategoria;
    }

    Insere(produto, &categoriaAtual->ArvoreCategoria);
}

void PesquisaProduto(Registro *produto, Floresta floresta, int categoria) {
    ApontadorCategoria categoriaAtual = floresta;

    for (int i = 0; i < categoria; i++) {
        if (categoriaAtual == NULL) {
            printf("Categoria %d não existe na floresta.\n", categoria);
            return;
        }
        categoriaAtual = categoriaAtual->ProximaCategoria;
    }

    if (categoriaAtual != NULL) {
        Pesquisa(produto, categoriaAtual->ArvoreCategoria);
    } else {
        printf("Categoria %d não existe na floresta.\n", categoria);
    }
}

void RemoveProduto(Registro produto, Floresta *floresta, int categoria) {
    ApontadorCategoria categoriaAtual = *floresta;

    for (int i = 0; i < categoria; i++) {
        if (categoriaAtual == NULL) {
            printf("Categoria %d não existe na floresta.\n", categoria);
            return;
        }
        categoriaAtual = categoriaAtual->ProximaCategoria;
    }

    if (categoriaAtual != NULL) {
        Retira(produto, &categoriaAtual->ArvoreCategoria);
    } else {
        printf("Categoria %d não existe na floresta.\n", categoria);
    }
}

void CaminhamentoEmOrdem(Floresta floresta, int categoria) {
    ApontadorCategoria categoriaAtual = floresta;

    for (int i = 0; i < categoria; i++) {
        if (categoriaAtual == NULL) {
            printf("Categoria %d não existe na floresta.\n", categoria);
            return;
        }
        categoriaAtual = categoriaAtual->ProximaCategoria;
    }

    if (categoriaAtual != NULL) {
        Central(categoriaAtual->ArvoreCategoria);
    } else {
        printf("Categoria %d não existe na floresta.\n", categoria);
    }
}

void CaminhamentoPreOrdem(Floresta floresta, int categoria) {
    ApontadorCategoria categoriaAtual = floresta;

    for (int i = 0; i < categoria; i++) {
        if (categoriaAtual == NULL) {
            printf("Categoria %d não existe na floresta.\n", categoria);
            return;
        }
        categoriaAtual = categoriaAtual->ProximaCategoria;
    }

    if (categoriaAtual != NULL) {
        PreOrdem(categoriaAtual->ArvoreCategoria);
    } else {
        printf("Categoria %d não existe na floresta.\n", categoria);
    }
}

void CaminhamentoPosOrdem(Floresta floresta, int categoria) {
    ApontadorCategoria categoriaAtual = floresta;

    for (int i = 0; i < categoria; i++) {
        if (categoriaAtual == NULL) {
            printf("Categoria %d não existe na floresta.\n", categoria);
            return;
        }
        categoriaAtual = categoriaAtual->ProximaCategoria;
    }

    if (categoriaAtual != NULL) {
        PosOrdem(categoriaAtual->ArvoreCategoria);
    } else {
        printf("Categoria %d não existe na floresta.\n", categoria);
    }
}