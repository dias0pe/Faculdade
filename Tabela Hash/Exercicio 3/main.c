#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERDADEIRO 1
#define FALSO 0

struct palavra_sinonimo {
    char *palavra;
    char *sinonimo;
};

typedef struct palavra_sinonimo elemento;

typedef struct TipoNodoArvore {
    elemento e;
    struct TipoNodoArvore *esq;
    struct TipoNodoArvore *dir;
} nodo_arvore;

typedef nodo_arvore* pt_nodo_arvore;

void CriarArvore(pt_nodo_arvore* a) {
    *a = NULL;
}

void InserirArvore(pt_nodo_arvore* a, elemento* e) {
    if (*a == NULL) {
        *a = (pt_nodo_arvore)malloc(sizeof(nodo_arvore));
        (*a)->e = *e;
        (*a)->esq = NULL;
        (*a)->dir = NULL;
    } else {
        if (strcmp(e->palavra, (*a)->e.palavra) < 0)
            InserirArvore(&((*a)->esq), e);
        else
            InserirArvore(&((*a)->dir), e);
    }
}

pt_nodo_arvore* PesquisarArvore(pt_nodo_arvore* a, char* chave) {
    if (*a == NULL || strcmp(chave, (*a)->e.palavra) == 0)
        return a;
    if (strcmp(chave, (*a)->e.palavra) < 0)
        return PesquisarArvore(&((*a)->esq), chave);
    else
        return PesquisarArvore(&((*a)->dir), chave);
}

elemento DesalocarNodoArvore(pt_nodo_arvore* p) {
    elemento x;
    pt_nodo_arvore aux = *p;
    if ((*p)->dir == NULL) {
        *p = (*p)->esq;
    } else if ((*p)->esq == NULL) {
        *p = (*p)->dir;
    } else {
        pt_nodo_arvore pai = *p;
        aux = (*p)->esq;
        while (aux->dir != NULL) {
            pai = aux;
            aux = aux->dir;
        }
        (*p)->e = aux->e;
        p = &(pai->dir);
    }
    x = aux->e;
    free(aux);
    return x;
}

void LimparArvore(pt_nodo_arvore* a) {
    if (*a != NULL) {
        LimparArvore(&((*a)->esq));
        LimparArvore(&((*a)->dir));
        free(*a);
        *a = NULL;
    }
}

void CadastrarDicionario(pt_nodo_arvore* a) {
    char op, lixo, termo[256];
    int i = 0, tam;
    elemento e;
    
    do {
        printf("\n\n\n%d) Informe uma palavra: ", i);
        scanf("%s", termo);
        tam = strlen(termo) + 1;
        e.palavra = (char *)malloc(sizeof(char) * tam);
        strcpy(e.palavra, termo);

        printf("\n%d) Informe o sinonimo da palavra: ", i++);
        scanf("%s", termo);
        tam = strlen(termo) + 1;
        e.sinonimo = (char *)malloc(sizeof(char) * tam);
        strcpy(e.sinonimo, termo);

        InserirArvore(a, &e);

        scanf("%c", &lixo);

        printf("\n\nDeseja inserir uma nova palavra (s/n)? ");
        scanf("%c", &op);
    } while (op == 's');
}

void PesquisarDicionario(pt_nodo_arvore* a) {
    char op, lixo, palavra[256];
    pt_nodo_arvore* pt;

    do {
        printf("\n\n\nInforme uma palavra: ");
        scanf("%s", palavra);
        scanf("%c", &lixo);

        pt = PesquisarArvore(a, palavra);

        if (*pt) {
            printf("\nPalavra: %s", (*pt)->e.palavra);
            printf("\nSinonimo: %s", (*pt)->e.sinonimo);
        } else
            printf("\nPalavra nao encontrada!");

        printf("\n\nDeseja realizar uma nova pesquisa (s/n)? ");
        scanf("%c", &op);
    } while (op == 's');
}

void ExcluirPalavra(pt_nodo_arvore* a) {
    char op, lixo, palavra[256];
    int i = 0;
    elemento e;
    pt_nodo_arvore* pt;

    do {
        printf("\n\n\n%d) Informe uma palavra: ", i++);
        scanf("%s", palavra);
        scanf("%c", &lixo);

        pt = PesquisarArvore(a, palavra);

        if (*pt) {
            e = DesalocarNodoArvore(pt);

            printf("\nPalavra: %s", e.palavra);
            printf("\nSinonimo: %s", e.sinonimo);
            printf("\nExclusao realizada com sucesso!");
        } else
            printf("\nPalavra nao encontrada!");

        printf("\n\nDeseja excluir uma nova palavra (s/n)? ");
        scanf("%c", &op);
    } while (op == 's');
}

int main() {
    pt_nodo_arvore arvore = NULL;

    printf("\nC A D A S T R O!\n\n\n");
    CadastrarDicionario(&arvore);

    system("clear || cls");

    printf("\nP E S Q U I S A!\n\n\n");
    PesquisarDicionario(&arvore);

    system("clear || cls");

    printf("\nE X C L U S A O!\n\n\n");
    ExcluirPalavra(&arvore);

    LimparArvore(&arvore);

    printf("\n\n");
    system("pause");
    return 0;
}