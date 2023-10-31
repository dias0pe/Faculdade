#ifndef DEQUE_H
#define DEQUE_H

#define VERDADEIRO 1
#define FALSO 0
#define TAM 10 // Tamanho do deque

typedef int elemento;

struct tipo_deque {
    elemento vet[TAM];
    int inicio, fim;
};

typedef struct tipo_deque deque;

// Cria um deque.
void CriarDeque(deque *d);

// Verifica se o deque está vazio.
int DequeVazio(deque *d);

// Verifica se o deque está cheio.
int DequeCheio(deque *d);

// Insere um elemento no início do deque.
void InserirInicio(deque *d, elemento e);

// Insere um elemento no fim do deque.
void InserirFim(deque *d, elemento e);

// Remove um elemento do início do deque.
elemento RemoverInicio(deque *d);

// Remove um elemento do fim do deque.
elemento RemoverFim(deque *d);

// Atualiza um elemento no deque.
void AtualizarElemento(deque *d, elemento novo, int pos);

#endif