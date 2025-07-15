# Ordenação de Pessoas em C

Este projeto implementa três algoritmos de ordenação em C para ordenar um array de pessoas pelo nome, mostrando o número de comparações, trocas e o tempo médio de execução.

## Algoritmos Escolhidos

### Bubble Sort
O Bubble Sort compara pares de elementos adjacentes e os troca de lugar se estiverem fora de ordem. O processo é repetido até que o array esteja ordenado. É simples, mas pouco eficiente para grandes volumes de dados.

- **Complexidade:**
  - Melhor caso: O(n)
  - Médio e pior caso: O(n²)

### Selection Sort
O Selection Sort percorre o array procurando o menor elemento e o coloca na primeira posição, depois o segundo menor na segunda posição, e assim por diante. Não é estável e também não é eficiente para grandes listas.

- **Complexidade:**
  - Melhor, médio e pior caso: O(n²)

### Insertion Sort
O Insertion Sort constrói a lista ordenada um elemento por vez, inserindo cada novo elemento na posição correta. É eficiente para listas pequenas ou quase ordenadas.

- **Complexidade:**
  - Melhor caso: O(n)
  - Médio e pior caso: O(n²)

## Tabela de Resultados 

| Algoritmo       | Comparações | Trocas | Tempo Médio (ms) |
|-----------------|-------------|--------|------------------|
| Bubble Sort     |    45       |   6    |      0.00        |
| Selection Sort  |    45       |   0    |      0.01        |
| Insertion Sort  |    9        |   0    |      0.01        |

> **Obs:** Os valores acima são exemplos para 10 pessoas. Os resultados reais podem variar conforme a entrada.

## Como Usar
1. Compile com `gcc ordenador.c -o ordenador.exe`
2. Execute com `./ordenador.exe`
3. Informe a quantidade de pessoas e os dados solicitados.

O programa exibirá os resultados de cada algoritmo.
