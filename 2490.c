#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERDADEIRO 1
#define FALSO 0
#define TAMANHO_MAXIMO 1100

typedef struct Aresta {
    int origem, destino;
    double peso;
} Aresta;

int conjuntoPai[TAMANHO_MAXIMO];
Aresta grafo[TAMANHO_MAXIMO];

int encontrarRaiz(int);
double calcularKruskal(int, int);

int compararArestas(const void *, const void *);

int quantidadeAeroportos;
double limitePeso;

int main() {
    int quantidadeVertices, quantidadeArestas, i;

    while (scanf("%d %d %lf", &quantidadeVertices, &quantidadeArestas, &limitePeso), 
           quantidadeVertices && quantidadeArestas && limitePeso) {
        
        for (i = 0; i < quantidadeArestas; ++i) {
            scanf("%d %d %lf", &grafo[i].origem, &grafo[i].destino, &grafo[i].peso);
        }

        qsort(grafo, quantidadeArestas, sizeof(Aresta), compararArestas);
        printf("%.2lf ", calcularKruskal(quantidadeArestas, quantidadeVertices));
        printf("%d\n", quantidadeAeroportos);
    }

    return 0;
}

int compararArestas(const void *a, const void *b) {
    double diferenca = ((Aresta *)a)->peso - ((Aresta *)b)->peso;

    if (diferenca == 0.0)
        return 0;
    else if (diferenca > 0.0)
        return 1;
    else
        return -1;
}

int encontrarRaiz(int vertice) {
    if (conjuntoPai[vertice] == vertice)
        return vertice;
    
    return encontrarRaiz(conjuntoPai[vertice]);
}

double calcularKruskal(int totalArestas, int totalVertices) {
    int i;
    double custoTotal = 0;

    for (i = 0; i <= totalVertices; ++i)
        conjuntoPai[i] = i;

    quantidadeAeroportos = 0;
    for (i = 0; i < totalArestas; ++i) {
        int raizOrigem = encontrarRaiz(grafo[i].origem);
        int raizDestino = encontrarRaiz(grafo[i].destino);

        if (raizOrigem != raizDestino) {
            conjuntoPai[raizOrigem] = conjuntoPai[raizDestino];

            if (grafo[i].peso > limitePeso) {
                custoTotal += grafo[i].peso + 2;
                ++quantidadeAeroportos;
            } else {
                custoTotal += grafo[i].peso;
            }
        }
    }

    return custoTotal;
}
