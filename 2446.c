#include <stdio.h>
#include <stdbool.h>
#define MAXM 1001

int V, M;
int c[MAXM];

 int troco(int valor, int moedas);

int main(){
    int V, M, i;
    while(scanf("%d %d", &V, &M) != EOF){
        for(i = 1; i <= M; i++){
            scanf("%d", &c[i]);
        }
         printf("%c\n", troco(V, M) ? 'S' : 'N');
    }
    return 0;
}

int troco(int valor, int moedas){
    if(valor < 0) return false;
    if(valor == 0) return true;
    if(moedas == 0) return false;
    return troco(valor-c[moedas], moedas-1) || troco(valor, moedas-1);
}
