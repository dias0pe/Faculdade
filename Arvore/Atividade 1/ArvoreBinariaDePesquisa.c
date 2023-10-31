#include "ArvoreBinariaDePesquisa.h"
#include <stdio.h>
#include <stdlib.h>

void Inicia(TipoDicionario *Dicionario) {
    *Dicionario = NULL;
}

void Insere(Registro x, TipoDicionario *Dicionario) {
    if (*Dicionario == NULL) {
        *Dicionario = (Apontador)malloc(sizeof(Nodo));
        (*Dicionario)->Reg = x;
        (*Dicionario)->Esq = NULL;
        (*Dicionario)->Dir = NULL;
        return;
    }
    if (x.Chave < (*Dicionario)->Reg.Chave) {
        Insere(x, &(*Dicionario)->Esq);
        return;
    }
    if (x.Chave > (*Dicionario)->Reg.Chave)
        Insere(x, &(*Dicionario)->Dir);
    else
        printf("Registro existente na árvore\n");
}

void Pesquisa(Registro *x, TipoDicionario Dicionario) {
    if (Dicionario == NULL) {
        printf("Erro: Registro não está na árvore\n");
        return;
    }
    if (x->Chave < Dicionario->Reg.Chave) {
        Pesquisa(x, Dicionario->Esq);
        return;
    }
    if (x->Chave > Dicionario->Reg.Chave)
        Pesquisa(x, Dicionario->Dir);
    else
        *x = Dicionario->Reg;
}

void Central(TipoDicionario Dicionario) {
    if (Dicionario != NULL) {
        Central(Dicionario->Esq);
        printf("%d\n", Dicionario->Reg.Chave);
        Central(Dicionario->Dir);
    }
}

void PreOrdem(TipoDicionario Dicionario) {
    if (Dicionario != NULL) {
        printf("%d\n", Dicionario->Reg.Chave);
        PreOrdem(Dicionario->Esq);
        PreOrdem(Dicionario->Dir);
    }
}

void PosOrdem(TipoDicionario Dicionario) {
    if (Dicionario != NULL) {
        PosOrdem(Dicionario->Esq);
        PosOrdem(Dicionario->Dir);
        printf("%d\n", Dicionario->Reg.Chave);
    }
}

void Retira(Registro x, TipoDicionario *Dicionario) {
    Apontador Aux;
    if (*Dicionario == NULL) {
        printf("Erro: Registro não está na árvore\n");
        return;
    }
    if (x.Chave < (*Dicionario)->Reg.Chave) {
        Retira(x, &(*Dicionario)->Esq);
        return;
    }
    if (x.Chave > (*Dicionario)->Reg.Chave) {
        Retira(x, &(*Dicionario)->Dir);
        return;
    }
    if ((*Dicionario)->Dir == NULL) {
        Aux = *Dicionario;
        *Dicionario = (*Dicionario)->Esq;
        free(Aux);
        return;
    }
    if ((*Dicionario)->Esq != NULL) {
        Antecessor(*Dicionario, &(*Dicionario)->Esq);
        return;
    }
    Aux = *Dicionario;
    *Dicionario = (*Dicionario)->Dir;
    free(Aux);
}

void Antecessor(Apontador q, Apontador *r) {
    Apontador Aux = *r;
    if ((*r)->Dir != NULL) {
        Antecessor(q, &(*r)->Dir);
        return;
    }
    q->Reg = (*r)->Reg;
    *r = (*r)->Esq;
    free(Aux);
}