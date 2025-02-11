#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int encontrar_posicao(const char *texto, const char *palavra);

int main() {
    char texto[10001];
    char copia_texto[10001];
    char palavras[128][51];
    int **posicoes;
    int num_palavras;

    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0'; 
    strcpy(copia_texto, texto);

    scanf("%d", &num_palavras);

    posicoes = (int **)malloc(num_palavras * sizeof(int *));
    for (int i = 0; i < num_palavras; i++) {
        posicoes[i] = (int *)malloc(10001 * sizeof(int));
    }

    for (int i = 0; i < num_palavras; i++) {
        scanf("%s", palavras[i]);
    }

    for (int i = 0; i < num_palavras; i++) {
        int indice = 0;
        char *token = strtok(copia_texto, " ");
        int posicao_atual = 0; 

        while (token != NULL) {
            int posicao_encontrada = encontrar_posicao(token, palavras[i]);

            if (posicao_encontrada != -1) {
                posicoes[i][indice++] = posicao_atual + posicao_encontrada;
            }

            posicao_atual += strlen(token) + 1;

            token = strtok(NULL, " ");
        }

        if (indice == 0) {
            printf("-1\n"); 
        } else {
            for (int k = 0; k < indice; k++) {
                printf("%d", posicoes[i][k]);
                if (indice > 1 && k != indice-1){
                    printf(" ");
                }
            }
            printf("\n");
        }

        strcpy(copia_texto, texto);
    }

    for (int i = 0; i < num_palavras; i++) {
        free(posicoes[i]);
    }
    free(posicoes);

    return 0;
}

int encontrar_posicao(const char *texto, const char *palavra) {
    const char *encontrado = strstr(texto, palavra);

    if (encontrado) {
        if ((encontrado == texto || isspace(*(encontrado - 1))) &&
            (*(encontrado + strlen(palavra)) == '\0' || isspace(*(encontrado + strlen(palavra))))) {
            return encontrado - texto;
        }
    }
    return -1;
}
