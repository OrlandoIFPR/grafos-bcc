const int MAX_VERTICES = 100;

struct Grafo {
    int num_vertices;
    int matriz[MAX_VERTICES][MAX_VERTICES];
};

void inicializarGrafo(Grafo &g, int n);

void adicionarAresta(Grafo &g, int u, int v, int peso);

void imprimirGrafo(const Grafo &g);

void buscaEmLargura(const Grafo &g, int inicio);

void buscaEmProfundidade(const Grafo &g, int inicio);
