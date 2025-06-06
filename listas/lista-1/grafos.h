#include <stdio.h>
#include <stdlib.h>

typedef struct Grafo_est{
    int **Ma;
    int NumVertices;
    int NumArestas;
}Grafo;

Grafo* CriaGrafo(int qtdVertices);

void LiberaGrafo(Grafo *g);

void imprimeGrafo(Grafo *g);

void InsereAresta(Grafo* g, int V1, int V2);

void RemoveAresta(Grafo* g, int V1, int V2);

void imprimeAdjacentes(int V, Grafo* g);

void InsereVertices(Grafo* g, int qtdVertices);