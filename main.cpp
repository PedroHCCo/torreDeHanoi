#include "stack.h"
#include <iostream>

using namespace std;

int movimentos = 0;

void imprimirPilha(Stack<int>& p, char nome) {
    Stack<int> temp;
    temp.init(10);
    int val;
    
    cout << nome << ": [";
    
    while (p.pop(&val)) {
        temp.push(val);
    }
    
    bool primeiro = true;
    while (temp.pop(&val)) {
        if (!primeiro) cout << ", ";
        cout << val;
        primeiro = false;
        p.push(val);
    }
    
    cout << "] ";
    temp.destroy();
}

void hanoi(int n, Stack<int>& origem, Stack<int>& destino, Stack<int>& aux, char o, char d, char a) {
    if (n == 1) {
        int disco = 0;
        origem.pop(&disco);
        destino.push(disco);
        movimentos++;
        
        cout << "Mover disco " << disco << " de " << o << " para " << d << "\n";
        
        imprimirPilha(origem, o);
        imprimirPilha(aux, a);
        imprimirPilha(destino, d);
        cout << "\n\n";
        return;
    }
    
    hanoi(n - 1, origem, aux, destino, o, a, d);
    
    int disco = 0;
    origem.pop(&disco);
    destino.push(disco);
    movimentos++;
    
    cout << "Mover disco " << disco << " de " << o << " para " << d << "\n";
    imprimirPilha(origem, o);
    imprimirPilha(aux, a);
    imprimirPilha(destino, d);
    cout << "\n\n";
    
    hanoi(n - 1, aux, destino, origem, a, d, o);
}

int main() {
    int n;
    cout << "Informe o numero de discos (1-10): ";
    cin >> n;

    if (n < 1 || n > 10) {
        cout << "Numero invalido.\n";
        return 0;
    }

    Stack<int> A, B, C;
    
    A.init(10);
    B.init(10);
    C.init(10);

    for (int i = n; i >= 1; i--) {
        A.push(i);
    }

    cout << "Estado inicial:\n";
    imprimirPilha(A, 'A');
    imprimirPilha(B, 'B');
    imprimirPilha(C, 'C');
    cout << "\n\n";

    hanoi(n, A, C, B, 'A', 'C', 'B');

    cout << "Total de movimentos: " << movimentos << "\n";

    A.destroy();
    B.destroy();
    C.destroy();

    return 0;
}
