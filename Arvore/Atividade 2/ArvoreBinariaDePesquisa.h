#ifndef ARVOREBINARIADEPESQUISA_H
#define ARVOREBINARIADEPESQUISA_H

typedef int TipoChave;

typedef struct {
    TipoChave Chave;
    /* outros componentes */
} Registro;

typedef struct Nodo_str *Apontador;

typedef struct Nodo_str {
    Registro Reg;
    Apontador Esq, Dir;
} Nodo;

typedef Apontador TipoDicionario;

void Inicia(TipoDicionario *Dicionario);
void Insere(Registro x, TipoDicionario *Dicionario);
void Pesquisa(Registro *x, TipoDicionario Dicionario);
void Central(TipoDicionario Dicionario);
void PreOrdem(TipoDicionario Dicionario);
void PosOrdem(TipoDicionario Dicionario);
void Retira(Registro x, TipoDicionario *Dicionario);
void Antecessor(Apontador q, Apontador *r);

#endif