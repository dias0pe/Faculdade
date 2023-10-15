#define VERDADEIRO 1
#define FALSO 0

struct tipo_pilha {
elemento vet[TAM];
int topo;
};

typedef struct tipo_pilha pilha;

//Cria pilha.
void CriarPilha(pilha *p) {
    p->topo = -1;
}

//Verifica se a pilha est� vazia.
int PilhaVazia(pilha *p) {
    return(p->topo == -1);
}

//Verifica se a pilha est� cheia.
int PilhaCheia(pilha *p) {
    return(p->topo == TAM);
}

//Insere um elemento na pilha.
void Empilhar(pilha *p, elemento e) {
    p->vet[p->topo] = e;
    p->topo++;
}

//Retira um elemento na pilha.
elemento Desempilhar(pilha *p) {
    p->topo--;
    return p->vet[p->topo];
}
