#ifndef STACK_H
#define STACK_H

#include <cstddef>

using namespace std;

struct Node {
    int value;
    Node* next;
};

// Estrutura principal da pilha
struct Stack {
    Node* top;
    size_t size;
    size_t max_size; // 0 significa sem limite
};

// Inicializa a pilha
void init(Stack* stack, size_t max_size);

// Libera todos os nos da pilha
void destroy(Stack* stack);

// Verifica se a pilha esta vazia
bool empty(const Stack* stack);

// Verifica se a pilha esta cheia
bool is_full(const Stack* stack);

// Retorna a quantidade de elementos na pilha
size_t size(const Stack* stack);

// Insere elemento no topo
bool push(Stack* stack, int value);

// Remove elemento do topo e salva em out_value
bool pop(Stack* stack, int* out_value);

// Retorna o elemento do topo sem remover
bool peek(const Stack* stack, int* out_value);

#endif
