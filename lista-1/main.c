#include <stdio.h>
#include <stdlib.h>
#include "grafo.c"


int main(){

    Grafo *g = CriaGrafo(3);
    Grafo* gComplementar;

    imprimeGrafo(g);

    InsereAresta(g, 0, 1);
    InsereAresta(g, 0, 2);

    printf("--------------------\n");

    imprimeGrafo(g);

    printf("\n %d\n ", RetornaSeForCompleta(g));
    
    printf("--------------------\n");

    gComplementar = RetornaGrafoComplementar(g);
    imprimeGrafo(gComplementar);

    printf("--------------------\n");

    InsereVertices(g, 1);
    imprimeGrafo(g);

    return 0;
}
