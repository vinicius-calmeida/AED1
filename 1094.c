#include <stdio.h>

int main() {
    int n, quantia, totalCobaias = 0;
    int totalCoelhos = 0, totalRatos = 0, totalSapos = 0;
    char tipo;
    float percCoelhos, percRatos, percSapos;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &quantia, &tipo);
        totalCobaias += quantia;
        if (tipo == 'C') {
            totalCoelhos += quantia;
        } else if (tipo == 'R') {
            totalRatos += quantia;
        } else if (tipo == 'S') {
            totalSapos += quantia;
        }
    }
    percCoelhos = (totalCoelhos * 100.0) / totalCobaias;
    percRatos = (totalRatos * 100.0) / totalCobaias;
    percSapos = (totalSapos * 100.0) / totalCobaias;
    printf("Total: %d cobaias\n", totalCobaias);
    printf("Total de coelhos: %d\n", totalCoelhos);
    printf("Total de ratos: %d\n", totalRatos);
    printf("Total de sapos: %d\n", totalSapos);
    printf("Percentual de coelhos: %.2f %%\n", percCoelhos);
    printf("Percentual de ratos: %.2f %%\n", percRatos);
    printf("Percentual de sapos: %.2f %%\n", percSapos);
    return 0;
}
