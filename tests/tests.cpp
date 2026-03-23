#include "stack.h"
#include <cassert>
#include <iostream>

static void test_push_pop_lifo() {
    Stack stack;
    init(&stack, 0);

    assert(empty(&stack));
    assert(!is_full(&stack));

    assert(push(&stack, 10));
    assert(push(&stack, 20));
    assert(push(&stack, 30));

    int value = 0;
    assert(peek(&stack, &value));
    assert(value == 30);

    assert(pop(&stack, &value));
    assert(value == 30);
    assert(pop(&stack, &value));
    assert(value == 20);
    assert(pop(&stack, &value));
    assert(value == 10);

    assert(empty(&stack));
    destroy(&stack);
}

static void test_underflow() {
    Stack stack;
    init(&stack, 0);

    int value = 123;
    assert(!pop(&stack, &value));
    assert(!peek(&stack, &value));

    destroy(&stack);
}

static void test_overflow_com_max() {
    Stack stack;
    init(&stack, 2);

    assert(push(&stack, 1));
    assert(push(&stack, 2));
    assert(is_full(&stack));
    assert(!push(&stack, 3));

    int value = 0;
    assert(pop(&stack, &value));
    assert(value == 2);
    assert(!is_full(&stack));

    destroy(&stack);
}

static void test_size() {
    Stack stack;
    init(&stack, 0);

    assert(size(&stack) == 0);

    assert(push(&stack, 1));
    assert(size(&stack) == 1);
    assert(push(&stack, 2));
    assert(size(&stack) == 2);

    int value = 0;
    assert(pop(&stack, &value));
    assert(size(&stack) == 1);
    assert(pop(&stack, &value));
    assert(size(&stack) == 0);

    destroy(&stack);
}

int main() {
    test_push_pop_lifo();
    test_underflow();
    test_overflow_com_max();
    test_size();

    std::cout << "Todos os testes passaram.\n";
    return 0;
}
