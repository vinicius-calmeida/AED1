#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAMANHO_MAXIMO 300

typedef struct Nodo {
    char elemento;
    struct Nodo* proximo;
} Nodo;

typedef struct {
    Nodo* topo;
} EstruturaPilha;

void inicializarPilha(EstruturaPilha* pilha) {
    pilha->topo = NULL;
}

int pilhaEstaVazia(EstruturaPilha* pilha) {
    return pilha->topo == NULL;
}

void empilharElemento(EstruturaPilha* pilha, char elemento) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (novoNodo == NULL) {
        exit(EXIT_FAILURE);
    }
    novoNodo->elemento = elemento;
    novoNodo->proximo = pilha->topo;
    pilha->topo = novoNodo;
}

char desempilharElemento(EstruturaPilha* pilha) {
    if (pilhaEstaVazia(pilha)) {
        exit(EXIT_FAILURE);
    }
    Nodo* nodoTemporario = pilha->topo;
    char elementoRemovido = nodoTemporario->elemento;
    pilha->topo = nodoTemporario->proximo;
    free(nodoTemporario);
    return elementoRemovido;
}

char obterTopo(EstruturaPilha* pilha) {
    if (pilhaEstaVazia(pilha)) {
        exit(EXIT_FAILURE);
    }
    return pilha->topo->elemento;
}

int ehOperador(char caractere) {
    return (caractere == '+' || caractere == '-' || caractere == '*' || caractere == '/' || caractere == '^');
}

int obterPrecedencia(char operador) {
    if (operador == '+' || operador == '-')
        return 1;
    if (operador == '*' || operador == '/')
        return 2;
    if (operador == '^')
        return 3;
    return -1;
}

void converterInfixaParaPosfixa(char *expressaoInfixa, char *resultadoPosfixo) {
    EstruturaPilha pilhaOperadores;
    inicializarPilha(&pilhaOperadores);

    int tamanhoExpressao = strlen(expressaoInfixa);
    int indiceResultado = 0;

    for (int indice = 0; indice < tamanhoExpressao; indice++) {
        char caractereAtual = expressaoInfixa[indice];

        if (isalnum(caractereAtual)) { 
            resultadoPosfixo[indiceResultado++] = caractereAtual;
        } else if (caractereAtual == '(') {
            empilharElemento(&pilhaOperadores, caractereAtual);
        } else if (caractereAtual == ')') {
            while (!pilhaEstaVazia(&pilhaOperadores) && obterTopo(&pilhaOperadores) != '(') {
                resultadoPosfixo[indiceResultado++] = desempilharElemento(&pilhaOperadores);
            }
            if (!pilhaEstaVazia(&pilhaOperadores) && obterTopo(&pilhaOperadores) != '(') {
                exit(EXIT_FAILURE);
            } else {
                desempilharElemento(&pilhaOperadores);
            }
        } else { 
            while (!pilhaEstaVazia(&pilhaOperadores) && obterPrecedencia(caractereAtual) <= obterPrecedencia(obterTopo(&pilhaOperadores))) {
                resultadoPosfixo[indiceResultado++] = desempilharElemento(&pilhaOperadores);
            }
            empilharElemento(&pilhaOperadores, caractereAtual);
        }
    }

    while (!pilhaEstaVazia(&pilhaOperadores)) {
        resultadoPosfixo[indiceResultado++] = desempilharElemento(&pilhaOperadores);
    }

    resultadoPosfixo[indiceResultado] = '\0'; 
}

int main() {
    int quantidadeTestes;
    scanf("%d", &quantidadeTestes);
    getchar(); 

    char resultados[quantidadeTestes][TAMANHO_MAXIMO]; 

    for (int indiceTeste = 0; indiceTeste < quantidadeTestes; indiceTeste++) {
        char expressaoInfixa[TAMANHO_MAXIMO];
        fgets(expressaoInfixa, TAMANHO_MAXIMO, stdin);
        converterInfixaParaPosfixa(expressaoInfixa, resultados[indiceTeste]);
    }

    for (int indiceTeste = 0; indiceTeste < quantidadeTestes; indiceTeste++) {
        printf("%s", resultados[indiceTeste]);
    }

    return 0;
}
