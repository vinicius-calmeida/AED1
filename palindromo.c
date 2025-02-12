#include <stdio.h>
#include <string.h>

#define MAX 1010

int main() {
    char s[MAX];

    while (scanf("%s", s) == 1) {
        int cont[256] = {0};
        int aux = 0;

        for (int i = 0; s[i] != '\0'; i++) {
            cont[(unsigned char)s[i]]++;
        }

        for (int i = 0; i < 256; i++) {
            if (cont[i] % 2 != 0) {
                aux++;
            }
        }

        int resultado;
        if (aux <= 1) {
            resultado = 0;
        } else {
            resultado = aux - 1;
        }

        printf("%d\n", resultado);
    }

    return 0;
}
