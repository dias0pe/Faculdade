/* Arquivo: hash.h */

#include "lista.h"

typedef struct TipoEntrada {
    char* chave;
    pt_nodo_arvore arvore;
} entrada;

typedef entrada hash[TAM];

void CriarHash(hash h) {
    int i;
    for (i = 0; i < TAM; i++) {
        CriarArvore(&(h[i].arvore));
    }
}

int FuncaoHash(char* chave) {
    int i, soma = 0;
    for (i = 0; chave[i] != '\0'; i++)
        soma += chave[i];
    return (soma % TAM);
}

void InserirHash(hash h, char* chave, elemento* e) {
    int i;
    i = FuncaoHash(chave);
    InserirArvore(&(h[i].arvore), e);
}

pt_nodo_arvore* PesquisarHash(hash h, char* chave) {
    int i;
    pt_nodo_arvore* pred;
    i = FuncaoHash(chave);
    pred = &(h[i].arvore);
    return PesquisarArvore(pred, chave);
}

elemento ExcluirHash(pt_nodo_arvore* p) {
    return DesalocarNodoArvore(p);
}

void LimparHash(hash h) {
    int i;
    for (i = 0; i < TAM; i++) {
        LimparArvore(&(h[i].arvore));
    }
}