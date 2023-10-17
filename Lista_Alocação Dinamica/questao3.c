Ela é vantajosa em situações em que o acesso bidirecional e as operações de inserção/remoção eficientes são importantes, mas pode ser excessiva em termos de memória e complexidade para casos mais simples.
lista.h
/* Arquivo: lista.h
* Biblioteca de operações para lista duplamente encadeada.
*/
#define VERDADEIRO 1
#define FALSO 0

typedef struct nodo *lista;
typedef struct nodo *pt_nodo;

typedef struct aluno {
    int codigo;
    char nome[100];
} aluno;

typedef struct nodo {
    aluno e;
    pt_nodo prox;
    pt_nodo ant;
} tnodo;

void CriarLista(lista *l);
int ListaVazia(lista *l);
void InserirInicio(lista *l, aluno *x);
void InserirFim(lista *l, aluno *x);
aluno RemoverInicio(lista *l);
aluno RemoverFim(lista *l);
int PesquisarLista(lista *l, int codigo, pt_nodo *posicao);