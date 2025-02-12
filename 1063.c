#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char dado;
    struct No *proximo;
} No;

void Empilhar(No **topo, char dado) {
    No *novoNo = malloc(sizeof(No));
    if (novoNo == NULL) {
        exit(EXIT_FAILURE);
    }
    novoNo->dado = dado;
    novoNo->proximo = *topo;
    *topo = novoNo;
}

char Desempilhar(No **topo) {
    if (*topo == NULL) {
        exit(EXIT_FAILURE);
    }
    No *remover = *topo;
    char dado = remover->dado;
    *topo = remover->proximo;
    free(remover);
    return dado;
}

int main() {
    int numCaracteres, indiceEntrada, indiceSaida;
    char entrada[27], saida[27];
    No *pilha;

    while (scanf("%d", &numCaracteres) && numCaracteres != 0) {
        for (indiceEntrada = 0; indiceEntrada < numCaracteres; indiceEntrada++) {
            scanf(" %c", &entrada[indiceEntrada]);
        }
        for (indiceEntrada = 0; indiceEntrada < numCaracteres; indiceEntrada++) {
            scanf(" %c", &saida[indiceEntrada]);
        }

        char operacoes[2 * numCaracteres + 1];
        int indiceOperacoes = 0;

        pilha = NULL;
        indiceEntrada = 0;
        indiceSaida = 0;

        while (indiceEntrada < numCaracteres) {
            Empilhar(&pilha, entrada[indiceEntrada]);
            operacoes[indiceOperacoes++] = 'I';

            while (pilha != NULL && pilha->dado == saida[indiceSaida]) {
                Desempilhar(&pilha);
                operacoes[indiceOperacoes++] = 'R';
                indiceSaida++;
            }
            indiceEntrada++;
        }

        while (pilha != NULL && pilha->dado == saida[indiceSaida]) {
            Desempilhar(&pilha);
            operacoes[indiceOperacoes++] = 'R';
            indiceSaida++;
        }

        operacoes[indiceOperacoes] = '\0';

        if (indiceSaida == numCaracteres) {
            printf("%s\n", operacoes);
        } else {
            printf("%s Impossible\n", operacoes);
        }
    }

    return 0;
}
