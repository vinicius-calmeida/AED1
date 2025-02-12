#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = f->fim = NULL;
}

int filaVazia(Fila *f) {
    return f->inicio == NULL;
}

void enfileirar(Fila *f, int valor) {
    No *novoNo = (No*) malloc(sizeof(No));
    if (novoNo == NULL) {
        exit(1);
    }

    novoNo->valor = valor;
    novoNo->proximo = NULL;

    if (filaVazia(f)) {
        f->inicio = f->fim = novoNo;
    } else {
        f->fim->proximo = novoNo;
        f->fim = novoNo;
    }
}

int desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        exit(1);
    }

    No *temp = f->inicio;
    int valor = temp->valor;

    f->inicio = temp->proximo;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(temp);

    return valor;
}

int main() {
    int numCartas;

    while (scanf("%d", &numCartas) && numCartas != 0) {
        Fila filaCartas;
        inicializarFila(&filaCartas);

        for (int i = 1; i <= numCartas; i++) {
            enfileirar(&filaCartas, i);
        }

        printf("Discarded cards: ");

        int primeiro = 1;
        while (!filaVazia(&filaCartas)) {
            int cartaDescarta = desenfileirar(&filaCartas);

            if (!filaVazia(&filaCartas)) {
                if (!primeiro) {
                    printf(", ");
                }
                printf("%d", cartaDescarta);
                primeiro = 0;

                int cartaMove = desenfileirar(&filaCartas);
                enfileirar(&filaCartas, cartaMove);
            } else {
                printf("\nRemaining card: %d\n", cartaDescarta);
            }
        }
    }

    return 0;
}
