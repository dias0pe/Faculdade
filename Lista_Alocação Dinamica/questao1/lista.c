#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void CriarLista(lista *l) {
    *l = NULL;
}

int ListaVazia(lista *l) {
    return (*l == NULL);
}

void InserirOrdenado(lista *l, Aluno *aluno) {
    pt_nodo p, ultimo = NULL, atual = *l;

    p = (pt_nodo)malloc(sizeof(tnodo));
    p->aluno = *aluno;
    p->prox = NULL;

    if (ListaVazia(l)) {
        *l = p;
    } else {
        while (atual != NULL) {
            if (strcmp(p->aluno.nome, atual->aluno.nome) <= 0) {
                if (ultimo == NULL) {
                    p->prox = *l;
                    *l = p;
                } else {
                    p->prox = atual;
                    ultimo->prox = p;
                }
                return;
            }
            ultimo = atual;
            atual = atual->prox;
        }
        ultimo->prox = p;
    }
}

Aluno RemoverAluno(lista *l, int codigo) {
    Aluno aluno;
    pt_nodo p, anterior = NULL, atual = *l;

    aluno.codigo = -1;  // Código de erro para aluno não encontrado

    while (atual != NULL) {
        if (atual->aluno.codigo == codigo) {
            p = atual;
            if (anterior == NULL) {
                *l = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            aluno = p->aluno;
            free(p);
            break;
        }
        anterior = atual;
        atual = atual->prox;
    }

    return aluno;
}

void ImprimirLista(lista *l) {
    pt_nodo p = *l;
    while (p != NULL) {
        printf("Código: %d, Nome: %s\n", p->aluno.codigo, p->aluno.nome);
        p = p->prox;
    }
}