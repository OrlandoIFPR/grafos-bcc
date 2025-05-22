
# Introdução à Representação de Grafos em Linguagens de Programação

- Grafos são estruturas fundamentais em ciência da computação, utilizados para modelar relações entre objetos.
- Representar grafos em uma linguagem de programação permite resolver problemas como busca, caminhos mínimos e conexidade.
- Existem diferentes formas de representação, sendo as mais comuns: 
    - matriz de adjacência e 
    - lista de adjacência.
- A escolha da representação depende das operações que serão realizadas e das características do grafo (denso ou esparso).
- Compreender como implementar grafos é essencial para aplicações em redes, algoritmos de roteamento, análise de redes sociais, entre outros.


## Estrutura de Dados para Matriz de Adjacência em C++

```C++
#include <iostream>
using namespace std;

const int MAX_VERTICES = 100; // número máximo de vértices permitido

// Estrutura para armazenar o grafo
struct Grafo {
    int num_vertices;
    int matriz[MAX_VERTICES][MAX_VERTICES]; // matriz de adjacência
};


```

- **Definição da Estrutura**:  
    Utiliza-se uma `struct` chamada `Grafo` para armazenar as informações do grafo.

- **Atributos da Estrutura**:
        - `num_vertices`: armazena o número de vértices presentes no grafo.
        - `matriz[MAX_VERTICES][MAX_VERTICES]`: matriz de adjacência que indica as conexões entre os vértices.  
            - Se `matriz[i][j] == 1`, existe uma aresta entre o vértice `i` e o vértice `j`.
            - Se `matriz[i][j] == 0`, não existe aresta entre esses vértices.
            - Em grafos ponderados, o valor de `matriz[i][j]` representa o peso da aresta entre `i` e `j`. Se não houver aresta, pode-se usar um valor especial (por exemplo, `0` ou `INF`) para indicar a ausência de conexão.

- **Constante `MAX_VERTICES`**:  
    Define o número máximo de vértices que o grafo pode ter, limitando o tamanho da matriz.

- **Vantagens**:
        - Acesso rápido para verificar se existe uma aresta entre dois vértices (`O(1)`).
        - Simples de implementar e manipular.

- **Desvantagens**:
        - Consome muita memória para grafos esparsos, pois a matriz é sempre quadrada de tamanho `MAX_VERTICES x MAX_VERTICES`.

- **Exemplo de utilização do Grafo**:
```C++
Grafo g;
g.num_vertices = 5;
// Inicialização da matriz com zeros
for (int i = 0; i < g.num_vertices; i++)
        for (int j = 0; j < g.num_vertices; j++)
                g.matriz[i][j] = 0;
```

## Tipos Abstratos de Dados (TAD)

- **O que é um TAD?**
    - Modelo para tipos de dados.
    - Define quais dados podem ser armazenados e quais operações podem ser realizadas.
    - Não especifica detalhes de implementação.

- **Por que usar TADs?**
    - Separa a interface (o que o tipo faz) da implementação (como faz).
    - Facilita a reutilização e manutenção do código.
    - Torna o código mais compreensível.

- **Exemplos comuns de TADs:**
    - Pilha (Stack)
    - Fila (Queue)
    - Lista
    - Conjunto (Set)
    - Mapa (Map/Dicionário)
    - Grafo

- **TAD Grafo:**
    - Define operações como:
        - Criar um grafo
        - Adicionar arestas
        - Imprimir o grafo

- **Vantagens dos TADs:**
    - Encapsulam detalhes de implementação.
    - Permitem trocar a implementação sem afetar o restante do programa.
    - Melhoram a modularidade e clareza do código.

## Estrutura de Projeto Utilizando um TAD de Grafo

Uma estrutura básica de projeto em C++ pode ser organizada da seguinte forma:

```
projeto_grafo/
├── src/
│   ├── main.cpp          // Função principal e testes
│   ├── grafo.cpp         // Implementação das funções do TAD Grafo
│   └── grafo.h           // Definição da estrutura e interface do TAD Grafo
```

### Descrição dos Arquivos

- **grafo.h**: Define a estrutura do grafo e declara as funções (interface do TAD).
- **grafo.cpp**: Implementa as funções declaradas em `grafo.h`.
- **main.cpp**: Utiliza o TAD Grafo para criar grafos, adicionar arestas e executar operações.

### Interface (`grafo.h`)

```c++
#ifndef GRAFO_H
#define GRAFO_H

const int MAX_VERTICES = 100;

struct Grafo {
    int num_vertices;
    int matriz[MAX_VERTICES][MAX_VERTICES];
};

void inicializarGrafo(Grafo &g, int n);
void adicionarAresta(Grafo &g, int u, int v, int peso);
void imprimirGrafo(const Grafo &g);

#endif
```

## Explicação do Código do `grafo.h`

- **Guarda de Inclusão (`#ifndef`, `#define`, `#endif`)**:  
    Garante que o conteúdo do arquivo seja incluído apenas uma vez durante a compilação, evitando redefinições.

- **Constante `MAX_VERTICES`**:  
    Define o número máximo de vértices que o grafo pode ter.

- **Estrutura `Grafo`**:  
    - `num_vertices`: armazena a quantidade de vértices do grafo.
    - `matriz[MAX_VERTICES][MAX_VERTICES]`: matriz de adjacência que representa as conexões entre os vértices.

- **Funções Declaradas**:
    - `void inicializarGrafo(Grafo &g, int n);`  
        Inicializa o grafo com `n` vértices e zera a matriz de adjacência.
    - `void adicionarAresta(Grafo &g, int u, int v, int peso);`  
        Adiciona uma aresta entre os vértices `u` e `v` com o peso especificado.
    - `void imprimirGrafo(const Grafo &g);`  
        Imprime a matriz de adjacência do grafo.

### Implementação da Interface no arquivo `grafo.cpp`

```c++
#include <iostream>
#include "grafo.h"
using namespace std;

// Inicializa o grafo com n vértices e sem arestas
void inicializarGrafo(Grafo &g, int n) {
    g.num_vertices = n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            g.matriz[i][j] = 0;
}

// Adiciona uma aresta entre os vértices u e v (grafo não direcionado) com peso
void adicionarAresta(Grafo &g, int u, int v, int peso) {
    if (u >= 0 && u < g.num_vertices && v >= 0 && v < g.num_vertices) {
        g.matriz[u][v] = peso;
        g.matriz[v][u] = peso; 
    }
}

// Imprime a matriz de adjacência com índices de linha e coluna
void imprimirGrafo(const Grafo &g) {
    cout << "Matriz de Adjacência:\n\n";

    // Imprime os índices das colunas
    cout << "    "; // espaço para alinhar com os índices das linhas
    for (int j = 0; j < g.num_vertices; j++) {
        cout << j << "   ";
    }
    cout << "\n";

    // Linha separadora
    cout << "  ";
    for (int j = 0; j < g.num_vertices; j++) {
        cout << "----";
    }
    cout << "-\n";

    // Imprime as linhas da matriz com os índices
    for (int i = 0; i < g.num_vertices; i++) {
        cout << i << " | ";
        for (int j = 0; j < g.num_vertices; j++) {
            cout << g.matriz[i][j] << "   ";
        }
        cout << "\n";
    }
}
```

## Explicação do Código do `grafo.cpp`

### Explicação da função `inicializarGrafo`

A função `inicializarGrafo` serve para configurar um grafo vazio com um número específico de vértices. Ela recebe como parâmetros uma referência para um objeto do tipo `Grafo` e um inteiro `n`, que representa a quantidade de vértices.

- `g.num_vertices = n;`  
  Define o número de vértices do grafo.

- Os dois laços `for` percorrem todas as posições da matriz de adjacência do grafo, que é usada para representar as conexões entre os vértices.
    - Para cada par de vértices `(i, j)`, o valor `g.matriz[i][j]` é definido como `0`, indicando que inicialmente não há arestas entre nenhum par de vértices.

### Explicação da função `adicionarAresta`

A função `adicionarAresta` serve para inserir uma aresta entre dois vértices em um grafo representado por matriz de adjacência, com o peso da aresta. Ela recebe como parâmetros uma referência para um objeto do tipo `Grafo` e três inteiros: `u` (origem), `v` (destino) e `peso`, que representa o valor associado à aresta.

- `g.matriz[u][v] = peso;`  
  Marca a presença de uma aresta do vértice `u` para o vértice `v` na matriz de adjacência, atribuindo o valor do peso.

- Se o grafo for não-direcionado, normalmente também se faz `g.matriz[v][u] = peso;` para indicar que a conexão vale nos dois sentidos.

- Essa função não verifica se já existe uma aresta entre os vértices, apenas adiciona (ou sobrescreve) a conexão com o novo peso.

- É importante garantir que os índices `u` e `v` estejam dentro do intervalo válido de vértices do grafo para evitar acessos inválidos à matriz.
