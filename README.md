# Torre de Hanoi - Implementação com Pilhas

## Descrição
Este projeto é uma implementação em C++ da solução para o quebra-cabeça clássico da Torre de Hanói. O algoritmo utiliza recursividade para resolver o problema e emprega a estrutura de dados Pilha (Stack) para representar as três hastes (Origem, Auxiliar e Destino), garantindo que as regras de movimentação dos discos sejam rigorosamente respeitadas.

## Requisitos
- **Compilador:** GCC (g++) versão 11.0 ou superior.
- **Ambiente/IDE:** Visual Studio Code (VS Code) com a extensão C/C++ instalada, ou qualquer outro terminal com suporte ao GCC.

## Compilação e Execução
Para compilar e executar o projeto via terminal, siga o fluxo principal:

1. Abra o terminal na pasta raiz do projeto.
2. Compile o código principal utilizando o g++:
   `g++ main.cpp -o hanoi`

   *(Nota: caso a estrutura base do projeto possua a implementação da pilha em um arquivo separado como stack.cpp, compile junto: `g++ main.cpp stack.cpp -o hanoi`)*

3. Execute o programa gerado:
   - No Windows: `.\hanoi.exe`
   - No Linux/macOS: `./hanoi`

## Pontos de Análise e Justificativa

**1. Por que a Pilha é a estrutura de dados naturalmente adequada para modelar as hastes deste problema?**

A estrutura de Pilha é a escolha correta porque opera sob o princípio LIFO (Last In, First Out), o que reflete exatamente as restrições mecânicas da Torre de Hanói. As regras do problema determinam que apenas um disco pode ser movido por vez e que somente o disco do topo de uma haste pode ser manipulado. O encapsulamento de uma Pilha, que permite inserção (push) e remoção (pop) apenas na extremidade superior, força estruturalmente o cumprimento dessas regras no código.

**2. Seria possível resolver este problema sem recursão? Se sim, como? Se não, por quê?**

Sim, é perfeitamente possível resolver o problema de forma iterativa sem o uso de recursão. Uma solução iterativa pode ser implementada utilizando laços de repetição (como while ou for) combinados com uma lógica matemática baseada na paridade do número total de discos. Se o número de discos for par, a sequência de movimentos segue um padrão específico entre as hastes; se for ímpar, segue outro. No entanto, a implementação iterativa resulta em um algoritmo substancialmente mais longo e menos intuitivo. A recursividade é mais adequada porque a Torre de Hanói é um problema de natureza recursiva, consistindo em resolver subproblemas menores e idênticos ao problema original.
