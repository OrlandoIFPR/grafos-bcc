#include <iostream>
#include "grafo.h"

int main() {
    Grafo g;

    inicializarGrafo(g, 5);

    adicionarAresta(g, 0, 1, 4);
    adicionarAresta(g, 0, 4, 3);
    adicionarAresta(g, 1, 2, 2);
    adicionarAresta(g, 1, 3, 3);
    adicionarAresta(g, 1, 4, 2);
    adicionarAresta(g, 2, 3, 4);
    adicionarAresta(g, 3, 4, 1);

    imprimirGrafo(g);

    buscaEmLargura(g, 0);

    buscaEmProfundidade(g, 0);

    return 0;
}
