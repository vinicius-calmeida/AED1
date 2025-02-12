#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_PALAVRA 21

struct Item {
    char nome[TAM_MAX_PALAVRA];
    struct Item* prox;
};

struct Item* novoItem(char* nome);
void insere(struct Item** ref_cabeca, char* nome);
void imprime(struct Item* no);

int main(void) {
    int N;
    char *linha;
    size_t tamanho_max_linha = 1000 * (TAM_MAX_PALAVRA + 1);
    
    linha = (char*)malloc(tamanho_max_linha * sizeof(char));
    if (linha == NULL) {
        printf("0");
        return 1;
    }
    struct Item* cabeca = NULL;
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
        fgets(linha, tamanho_max_linha, stdin);
        linha[strcspn(linha, "\n")] = 0;
        cabeca = NULL;
        char *token = strtok(linha, " ");
        while (token != NULL) {
            insere(&cabeca, token);
            token = strtok(NULL, " ");
        }
        imprime(cabeca);
    }

    free(linha);
    return 0;
}

struct Item* novoItem(char* nome) {
    struct Item* novoItem = (struct Item*)malloc(sizeof(struct Item));
    if (novoItem == NULL) {
        printf("Erro: Falha ao alocar memória para novoItem.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(novoItem->nome, nome);
    novoItem->prox = NULL;
    return novoItem;
}

void insere(struct Item** ref_cabeca, char* nome) {
    struct Item* novo_item = novoItem(nome);
    struct Item* anterior = NULL;
    struct Item* atual = *ref_cabeca;

    if (*ref_cabeca == NULL || strcmp(novo_item->nome, atual->nome) < 0) {
        novo_item->prox = *ref_cabeca;
        *ref_cabeca = novo_item;
        return;
    }

    while (atual != NULL && strcmp(atual->nome, novo_item->nome) < 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) {
        novo_item->prox = *ref_cabeca;
        *ref_cabeca = novo_item;
    } else {
        anterior->prox = novo_item;
        novo_item->prox = atual;
    }
}

void imprime(struct Item* no) {
    struct Item* atual = no;
    struct Item* proximo;
  
    while (atual != NULL) {
        printf("%s", atual->nome);
        proximo = atual->prox;
        while (proximo != NULL && strcmp(atual->nome, proximo->nome) == 0) {
            proximo = proximo->prox;
        }
        atual = proximo;
        if (atual != NULL) {
            printf(" ");
        }
    }
    printf("\n");
}
