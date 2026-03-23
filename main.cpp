#include "stack.h"
#include <iostream>

int main() {
    Stack stack;
    init(&stack, 0);

    std::cout << "Empilhando: 5, 10, 15\n";
    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 15);

    int value = 0;
    if (peek(&stack, &value)) {
        std::cout << "Topo atual: " << value << "\n";
    }

    std::cout << "Desempilhando...\n";
    while (pop(&stack, &value)) {
        std::cout << "Removeu: " << value << "\n";
    }

    if (!pop(&stack, &value)) {
        std::cout << "Underflow: pilha vazia.\n";
    }

    destroy(&stack);
    return 0;
}
