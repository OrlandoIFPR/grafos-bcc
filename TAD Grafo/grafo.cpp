#include <iostream>
#include <queue>
#include <stack>
#include "grafo.h"
using namespace std;

void inicializarGrafo(Grafo &g, int n) {
    g.num_vertices = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g.matriz[i][j] = 0;
        }
    }
}

void adicionarAresta(Grafo &g, int u, int v, int peso) {
    if (u >= 0 && u < g.num_vertices && v >= 0 && v < g.num_vertices) {
        g.matriz[u][v] = peso;
        g.matriz[v][u] = peso;
    }
}

void imprimirGrafo(const Grafo &g) {
    cout << "Matriz de Adjacencia:\n\n";

    cout << "    ";
    for (int j = 0; j < g.num_vertices; j++) {
        cout << j << "   ";
    }
    cout << "\n";

    cout << "  ";
    for (int j = 0; j < g.num_vertices; j++) {
        cout << "----";
    }
    cout << "-\n";

    for (int i = 0; i < g.num_vertices; i++) {
        cout << i << " | ";
        for (int j = 0; j < g.num_vertices; j++) {
            cout << g.matriz[i][j] << "   ";
        }
        cout << "\n";
    }
}

void buscaEmLargura(const Grafo &g, int inicio) {
    bool visitado[MAX_VERTICES] = {false};
    queue<int> fila;

    visitado[inicio] = true;
    fila.push(inicio);

    cout << "Busca em Largura a partir do vertice " << inicio << ": ";

    while (!fila.empty()) {
        int atual = fila.front();
        fila.pop();
        cout << atual << " ";

        for (int i = 0; i < g.num_vertices; i++) {
            if (g.matriz[atual][i] != 0 && !visitado[i]) {
                visitado[i] = true;
                fila.push(i);
            }
        }
    }

    cout << "\n";
}

void buscaEmProfundidade(const Grafo &g, int inicio) {
    bool visitado[MAX_VERTICES] = {false};
    stack<int> pilha;

    pilha.push(inicio);

    cout << "Busca em profundidade a partir do vertice " << inicio << ": ";

    while (!pilha.empty()) {
        int v = pilha.top();
        pilha.pop();

        if (!visitado[v]) {
            visitado[v] = true;
            cout << v << " ";

            for (int i = g.num_vertices - 1; i >= 0; i--) {
                if (g.matriz[v][i] != 0 && !visitado[i]) {
                    pilha.push(i);
                }
            }
        }
    }

    cout << "\n";
}


