#include <iostream>
#include "grafo.h"
using namespace std;


// Inicializa o grafo com n v�rtices e sem arestas
void inicializarGrafo(Grafo &g, int n) {
    g.num_vertices = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g.matriz[i][j] = 0;
        }
    }
}

// Adiciona uma aresta entre os v�rtices u e v (grafo n�o direcionado)
void adicionarAresta(Grafo &g, int u, int v, int peso) {
    if (u >= 0 && u < g.num_vertices && v >= 0 && v < g.num_vertices) {
        g.matriz[u][v] = peso;
        g.matriz[v][u] = peso; 
    }
}

// Imprime a matriz de adjac�ncia com �ndices de linha e coluna
void imprimirGrafo(const Grafo &g) {
    cout << "Matriz de Adjac�ncia:\n\n";

    // Imprime os �ndices das colunas
    cout << "    "; // espa�o para alinhar com os �ndices das linhas
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

    // Imprime as linhas da matriz com os �ndices
    for (int i = 0; i < g.num_vertices; i++) {
        cout << i << " | ";
        for (int j = 0; j < g.num_vertices; j++) {
            cout << g.matriz[i][j] << "   ";
        }
        cout << "\n";
    }
}

