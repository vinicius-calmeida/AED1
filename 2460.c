#include <stdio.h>
#include <stdbool.h>

int main() {
    int N, M;
    
    scanf("%d", &N);
    int fila[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &fila[i]);
    }
    
    scanf("%d", &M);
    bool saiu[100001] = {false};
    
    for (int i = 0; i < M; i++) {
        int ident;
        scanf("%d", &ident);
        saiu[ident] = true;
    }
    
    int primeiro = 1;
    for (int i = 0; i < N; i++) {
        if (!saiu[fila[i]]) {
            if (primeiro) {
                printf("%d", fila[i]);
                primeiro = 0;
            } else {
                printf(" %d", fila[i]);
            }
        }
    }
    printf("\n");
}
