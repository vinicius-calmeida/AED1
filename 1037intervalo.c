#include <stdio.h>
 
int main() {
    float n=0;
    int c=0;
    scanf("%f", &n);
    if ((n<0)||(n>100))c=0;
    else if ((n>=0)&&(n<=25))c=1;
    else if ((n>25)&&(n<=50))c=2;
    else if ((n>50)&&(n<=75))c=3;
    else if ((n>75)&&(n<=100))c=4;
    switch (c){
        case 0:
        printf("Fora de intervalo\n");
        break;
        
        case 1:
        printf("Intervalo [0,25]\n");
        break;
        
        case 2:
        printf("Intervalo (25,50]\n");
        break;
        
        case 3:
        printf("Intervalo (50,75]\n");
        break;
        
        case 4:
        printf("Intervalo (75,100]\n");
        break;
        
    }
    return 0;
}
