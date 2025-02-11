#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define verdadeiro 1
#define falso 0
#define TAMANHO_MAX 40050
#define TAMANHO_MAX_P 40000

typedef struct {
	int origem, destino, peso;
} aresta;

aresta grafo[TAMANHO_MAX];
int pais[TAMANHO_MAX_P];

//compara duas arestas (para ordenação)
int comparar(aresta *, aresta *);

//algoritmo de Kruskal
int kruskal(int);

//encontra o componente conectado de um vértice
int encontrar_componente(int);

int main(int argc, char **argv)
{
	int roteadores, arestas, i;

	// Loop para ler e processar os casos teste
	while (scanf("%d %d", &roteadores, &arestas), roteadores && arestas)
	{
		// Inicia os arrays
		memset(grafo, 0, sizeof(grafo));
		memset(pais, 0, sizeof(pais));

		// Leitura das arestas
		for (i = 0; i < arestas; ++i)
			scanf("%d %d %d", &grafo[i].origem, &grafo[i].destino, &grafo[i].peso);

		// Ordena as arestas pelo peso
		qsort(grafo, arestas, sizeof(aresta), comparar);

		// Inicia o vetor de pais
		for (i = 1; i <= roteadores; ++i)
			pais[i] = i;

		// Executa o algoritmo de Kruskal e imprime o custo total da MST
		printf("%d\n", kruskal(arestas));
	}

	return 0;
}

//comparação para a função qsort
int comparar(aresta *a, aresta *b)
{
	return a->peso - b->peso;
}

//encontra o componente conectado de um vértice
int encontrar_componente(int i)
{
	if (i == pais[i])
		return i;
	return encontrar_componente(pais[i]);
}

//algoritmo de Kruskal
int kruskal(int arestas)
{
	int i, custo_total, v, u;

	custo_total = 0;

	for (i = 0; i < arestas; ++i)
	{
		v = encontrar_componente(grafo[i].origem);
		u = encontrar_componente(grafo[i].destino);

		if (v != u)
		{
			pais[v] = pais[u];
			custo_total += grafo[i].peso;
		}
	}

	return custo_total;
}
