const int MAX_VERTICES = 100; // n�mero m�ximo de v�rtices permitido

// Estrutura para armazenar o grafo
struct Grafo {
    int num_vertices;
    int matriz[MAX_VERTICES][MAX_VERTICES]; // matriz de adjac�ncia
};

// Inicializa o grafo com n v�rtices e sem arestas
void inicializarGrafo(Grafo &g, int n);

// Adiciona uma aresta entre os v�rtices u e v (grafo n�o direcionado)
void adicionarAresta(Grafo &g, int u, int v, int peso);

// Imprime a matriz de adjac�ncia
void imprimirGrafo(const Grafo &g);
