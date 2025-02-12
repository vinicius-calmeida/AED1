
#include <stdio.h>
 
int main() {
 
    int N, x,hora, minuto, segundo;
    x=3600;//horas em segundos
    
    scanf("%d", &N);
    hora = (N/x); 
    minuto = (N -(x*hora))/60;
    segundo = (N -(x*hora)-(minuto*60));
    
    printf("%d:%d:%d\n",hora,minuto,segundo);
 
    return 0;
}
