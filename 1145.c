#include <stdio.h>

int main() {
    int X, Y;
    scanf("%d %d", &X, &Y); // Lê os valores de X e Y

    int count = 1; 

    while (count <= Y) {

        for (int i = 0; i < X; i++) {
            if (count > Y) break; 
            printf("%d", count);
            if (i < X - 1) {
                printf(" "); 
            }
            count++;
        }
        printf("\n"); 
    }

    return 0;
}
