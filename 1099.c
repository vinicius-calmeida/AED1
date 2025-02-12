#include <stdio.h>


int soma_impares(int x, int y) {
    int soma = 0;

    if (x > y) {
        int temp = x;
        x = y;
        y = temp;
    }

    for (int i = x + 1; i < y; i++) {
        if (i % 2 != 0) {
            soma += i;
        }
    }
    return soma;
}

int main() {
    int n;
    scanf("%d", &n); 

    for (int caso = 0; caso < n; caso++) {
        int x, y;
        scanf("%d %d", &x, &y); 

        int resultado = soma_impares(x, y);

        printf("%d\n", resultado);
    }

    return 0;
}
