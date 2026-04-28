# Torre de Hanói - Implementação com Pilhas

## Pontos de Análise e Justificativa

**1. Por que a Pilha é a estrutura de dados naturalmente adequada para modelar as hastes deste problema?** 

A estrutura de Pilha é a escolha correta porque opera sob o princípio LIFO (Last In, First Out), o que reflete exatamente as restrições mecânicas da Torre de Hanói. As regras do problema determinam que apenas um disco pode ser movido por vez e que somente o disco do topo de uma haste pode ser manipulado. O encapsulamento de uma Pilha, que permite inserção (*push*) e remoção (*pop*) apenas na extremidade superior, força estruturalmente o cumprimento dessas regras no código.

**2. Seria possível resolver este problema sem recursão? Se sim, como? Se não, por quê?** 

Sim, é perfeitamente possível resolver o problema de forma iterativa sem o uso de recursão. Uma solução iterativa pode ser implementada utilizando laços de repetição (como *while* ou *for*) combinados com uma lógica matemática baseada na paridade do número total de discos. Se o número de discos for par, a sequência de movimentos segue um padrão específico entre as hastes; se for ímpar, segue outro. No entanto, a implementação iterativa resulta em um algoritmo substancialmente mais longo e menos intuitivo. A recursividade é mais adequada porque a Torre de Hanói é um problema de natureza recursiva, consistindo em resolver subproblemas menores e idênticos ao problema original.
