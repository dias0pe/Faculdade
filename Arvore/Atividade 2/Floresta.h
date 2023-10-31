#ifndef FLORESTA_H
#define FLORESTA_H
#include "ArvoreBinariaDePesquisa.h"

typedef struct Categoria_str *ApontadorCategoria;

typedef struct Categoria_str {
    Apontador ArvoreCategoria;
    ApontadorCategoria ProximaCategoria;
} Categoria;

typedef ApontadorCategoria Floresta;

void InicializaCategoria(Floresta *floresta);
void InsereProduto(Registro produto, Floresta *floresta, int categoria);
void PesquisaProduto(Registro *produto, Floresta floresta, int categoria);
void RemoveProduto(Registro produto, Floresta *floresta, int categoria);
void CaminhamentoEmOrdem(Floresta floresta, int categoria);
void CaminhamentoPreOrdem(Floresta floresta, int categoria);
void CaminhamentoPosOrdem(Floresta floresta, int categoria);

#endif