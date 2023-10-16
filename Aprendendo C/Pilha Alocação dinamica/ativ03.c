#ifndef PILHA_H
#define PILHA_H

typedef struct Node {
    Livro livro;
    struct Node *anterior;
    struct Node *proximo;
} Node;

typedef struct {
    Node *topo;
    Node *fundo;
} Pilha;

void criarPilha(Pilha *pilha);
void empilharLivro(Pilha *pilha, Livro livro);
Livro desempilharLivro(Pilha *pilha);
int pilhaVazia(Pilha pilha);

#endif


// as vantagens de uma pilha duplamente encadeada podem não ser necessárias, a menos que haja requisitos específicos para acessar elementos no início e no final da pilha de maneira eficiente. 
//Para a maioria dos casos de uso de pilha comuns, uma pilha simplesmente encadeada pode ser suficiente e mais simples de implementar. 
//Portanto, a escolha entre uma pilha simplesmente encadeada e uma pilha duplamente encadeada depende dos requisitos específicos do seu programa.