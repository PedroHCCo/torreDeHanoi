#include "stack.h"

using namespace std;

// Inicializa a pilha com tamanho máximo (0 = sem limite)
void init(Stack* stack, size_t max_size) {
    stack->top = nullptr;
    stack->size = 0;
    stack->max_size = max_size;
}

// Libera todos os nós alocados
void destroy(Stack* stack) {
    Node* current = stack->top;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    stack->top = nullptr;
    stack->size = 0;
}

bool empty(const Stack* stack) {
    return stack->size == 0;
}

bool is_full(const Stack* stack) {
    if (stack->max_size == 0) {
        return false;
    }
    return stack->size >= stack->max_size;
}

size_t size(const Stack* stack) {
    return stack->size;
}

bool push(Stack* stack, int value) {
    if (is_full(stack)) {
        return false;
    }

    Node* node = new Node{value, stack->top};
    stack->top = node;
    stack->size += 1;
    return true;
}

bool pop(Stack* stack, int* out_value) {
    if (empty(stack)) {
        return false;
    }

    Node* node = stack->top;
    if (out_value != nullptr) {
        *out_value = node->value;
    }
    stack->top = node->next;
    delete node;
    stack->size -= 1;
    return true;
}

bool peek(const Stack* stack, int* out_value) {
    if (empty(stack)) {
        return false;
    }
    if (out_value != nullptr) {
        *out_value = stack->top->value;
    }
    return true;
}
