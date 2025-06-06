#include <stdio.h>
#include <stdlib.h>

typedef struct Grafo_est{
    int **Ma;
    int NumVertices;
    int NumArestas;
}Grafo;

Grafo* CriaGrafo(Grafo** g, int qtdVertices);