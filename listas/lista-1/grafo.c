#include "grafos.h"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

Grafo* CriaGrafo(int qtdVertices){
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
    g->NumVertices = qtdVertices;
    g->NumArestas = 0;

    g->Ma = (int**)malloc(qtdVertices * sizeof(int*));
    for(int i = 0; i < qtdVertices; i++){
        g->Ma[i] = (int*)malloc(qtdVertices * sizeof(int));
    }

    for(int i = 0; i < qtdVertices; i++){
        for (int j = 0; j < qtdVertices; j++){
            g->Ma[i][j] = 0;
        }
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
            printf("%d ", g->Ma[i][j]);
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
    if (V1 >= 0 && V1 < g->NumVertices && V2 >= 0 && V2 < g->NumVertices && g->Ma[V1][V2] == 1){
        g->Ma[V1][V2] = 0;
        g->Ma[V2][V1] = 0;
        g->NumArestas--;
    }
}

void imprimeAdjacentes(int V, Grafo* g){
    if(V >= 0 && V < g->NumVertices){
        printf("Vertices adjacentes a %d: ", V);
        for(int i = 0; i < g->NumVertices; i++){
            if(g->Ma[V][i] == 1){
                printf("%d ", i);
            }
        }
        printf("\n");
    }
}

void InsereVertices(Grafo* g, int qtdVertices){
    int antigo_total = g->NumVertices;
    int novo_total = antigo_total + qtdVertices;

    // Realoca o vetor de ponteiros (linhas da matriz)
    g->Ma = (int**)realloc(g->Ma, novo_total * sizeof(int*));

    // Realoca cada linha antiga para o novo número de colunas
    for (int i = 0; i < antigo_total; i++) {
        g->Ma[i] = (int*)realloc(g->Ma[i], novo_total * sizeof(int));
        // Inicializa as novas colunas da linha realocada
        for (int j = antigo_total; j < novo_total; j++) {
            g->Ma[i][j] = 0;
        }
    }

    // Aloca as novas linhas
    for (int i = antigo_total; i < novo_total; i++) {
        g->Ma[i] = (int*)calloc(novo_total, sizeof(int));  // zera toda a linha
    }

    // Atualiza o número total de vértices
    g->NumVertices = novo_total;
}