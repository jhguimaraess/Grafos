#include <stdio.h>
#include <stdlib.h>
#include "grafo.c"


int main(){

    Grafo *g = CriaGrafo(5);

    imprimeGrafo(g);

    InsereAresta(g, 2, 4);
    InsereAresta(g, 1, 2);
    InsereAresta(g, 1, 0);
    InsereAresta(g, 1, 3);

    printf("------------------------\n");
    imprimeGrafo(g);

    printf("------------------------\n");
    RemoveAresta(g, 2, 4);
    imprimeGrafo(g);

    printf("------------------------\n");
    imprimeAdjacentes(1, g);

    printf("------------------------\n");
    InsereVertices(g, 3);
    imprimeGrafo(g);


    return 0;
}
