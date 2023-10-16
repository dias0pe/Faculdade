#define TAM 3
typedef int elemento;

struct tipo_pilha {
    elemento vet[TAM];
    int topo;
};

typedef struct tipo_pilha pilha;


void CriarPilha(pilha *p) {
    p->topo = -1; 
}


int PilhaVazia(pilha *p) {
    return (p->topo == -1); 
}


int PilhaCheia(pilha *p) {
    return (p->topo == TAM - 1);
}


void Empilhar(pilha *p, elemento e) {
    if (PilhaCheia(p)) {
        printf("Erro: Pilha cheia, nao foi possivel empilhar %d\n", e);
    } else {
        p->topo++;
        p->vet[p->topo] = e;
    }
}


elemento Desempilhar(pilha *p) {
    elemento e;
    if (PilhaVazia(p)) {
        printf("Erro: Pilha vazia, nao foi possivel desempilhar\n");
        return -1; 
    } else {
        e = p->vet[p->topo];
        p->topo--;
        return e;
    }
}


void ImprimePilha(pilha *p) {
    printf("Conteudo da pilha:\n");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d\n", p->vet[i]);
    }
}