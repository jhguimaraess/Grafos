#include "grafos.h"

Grafo* CriaGrafo(int qtdVertices){
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
    g->NumVertices = qtdVertices;
    g->NumArestas = 0;

    g->Ma = (int**)malloc(qtdVertices * sizeof(int*));
    for(int i = 0; i < qtdVertices; i++){
        g->Ma[i] = (int*)malloc(qtdVertices * sizeof(int));
    }

    return g;
}

void LiberaGrafo(Grafo *g){
    for (int i = 0; i < g->NumVertices; i++){
        free(g->Ma[i]);
    }
    free(g->Ma);
    free(g);
}

void imprimeGrafo(Grafo *g){
    for (int i = 0; i < g->NumVertices;i++){
        for (int j = 0; j < g->NumVertices; j++){
            print("%d ", g->Ma[i][j]);
        }
        printf("\n");
    }
}

void InsereAresta(Grafo* g, int V1, int V2){
    if (V1 >= 0 && V1 < g->NumVertices && V2 >= 0 && V2 < g->NumVertices && g->Ma[V1][V2] == 0){
        g->Ma[V1][V2] = 1;
        g->Ma[V2][V1] = 1;
        g->NumArestas++;
    }
}

void RemoveAresta(Grafo* g, int V1, int V2){
    if (V1 >= 0 && V1 < g->NumVertices && V2 >= 0 && V2 < g->NumVertices && g->Ma[V1][V2] == 0){
        g->Ma[V1][V2] = 0;
        g->Ma[V2][V1] = 0;
        g->NumArestas--;
    }
}

void imprimeAdjacentes(int V, Grafo* g){
    if(V >= 0 && V < g->NumVertices){
        prinf("Vertices adjacentes a %d: ", V);
        for(int i = 0; i < g->NumVertices; i++){
            if(g->Ma[V][i] == 1){
                printf("%d ", i);
            }
        }
        printf("\n");
    }
}

void InsereVertices(Grafo* g, int qtdVertices){
    int novo_total = g->NumVertices + qtdVertices;

    g->Ma = (int**)realloc(g->Ma, novo_total * sizeof(int*));
    for(int i = 0; i < novo_total; i++){
        g->Ma[i] = (int*)realloc(g->Ma[i], novo_total * sizeof(int));

        for(int j = g->NumVertices; j < novo_total; j++){
            g->Ma[i][j] = 0;
        }
    }

    for(int i = g->NumVertices; i < novo_total; i++){
        g->Ma[i] = (int*)calloc(novo_total, sizeof(int));
    }

    g->NumVertices = novo_total;
}