#ifndef HASH_H
#define HASH_H

#include "lista.h"

#define TAMANHO 10

typedef struct TabelaHash {
    ListaEncadeada lista[TAMANHO];
} TabelaHash;

unsigned int calcularHash(const char *nome);
void inicializarTabela(TabelaHash *tabela);
void cadastrarFuncionario(TabelaHash *tabela);
void pesquisarFuncionarioPorNome(TabelaHash *tabela);
void pesquisarFuncionarioPorData(TabelaHash *tabela);
void gravarTabelaEmArquivo(TabelaHash *tabela, const char *nomeArquivo);
void lerTabelaDeArquivo(TabelaHash *tabela, const char *nomeArquivo);
void exibirConteudoDaTabela(TabelaHash *tabela);
void excluirFuncionario(TabelaHash *tabela);

#endif  // HASH_H