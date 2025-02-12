#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

void Empilhar(No **topo, int dado) {
    No *novoNo = malloc(sizeof(No));
    if (novoNo == NULL) {
        exit(EXIT_FAILURE);
    }
    novoNo->dado = dado;
    novoNo->proximo = *topo;
    *topo = novoNo;
}

int Desempilhar(No **topo) {
    if (*topo == NULL) {
        exit(EXIT_FAILURE);
    }
    No *remover = *topo;
    int dado = remover->dado;
    *topo = remover->proximo;
    free(remover);
    return dado;
}

int VerificaSequenciaValida(int *ordemVagoes, int quantidade) {
    No *pilha = NULL;
    int numeroAtual, indiceVagao = 0;

    for (numeroAtual = 1; numeroAtual <= quantidade; numeroAtual++) {
        Empilhar(&pilha, numeroAtual);

        while (pilha != NULL && pilha->dado == ordemVagoes[indiceVagao]) {
            Desempilhar(&pilha);
            indiceVagao++;
        }
    }

    return (pilha == NULL);
}

int main() {
    int quantidadeVagoes, i;
    int ordemVagoes[1000];

    while (scanf("%d", &quantidadeVagoes) && quantidadeVagoes != 0) {
        while (1) {
            for (i = 0; i < quantidadeVagoes; i++) {
                scanf("%d", &ordemVagoes[i]);
                if (ordemVagoes[0] == 0) break;
            }
            if (ordemVagoes[0] == 0) break;

            if (VerificaSequenciaValida(ordemVagoes, quantidadeVagoes)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        printf("\n");
    }

    return 0;
}
