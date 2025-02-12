#include <stdio.h>

int main(){
    
    int l=0, c=0, q1=0, q2=0;
    scanf("%d", &l);
    scanf("%d", &c);
    
    q1 = (c*l)+((c-1)*(l-1));
    q2 = (c-1)*2 + (l-1)*2;
    printf("%d\n", q1);
    printf("%d\n", q2);
    return 0;
}
