#include<stdio.h>
#include<stdlib.h>

int compare( const void * a, const void * b )
{
  return ( * ( int* ) b - * ( int* ) a );
}

int main ( )
{
    int d[99999], aux[99999];
    int n, k, i, soma;
 
    while(scanf( "%d %d", &n, &k) != EOF)
    {
        aux[0] = 0;
        d[0]= 0;
        for (i = 1; i < n; i++)
        {
            scanf ("%d", &aux[i] );
            d[i] = aux[i] - aux[i - 1];
        }
        qsort(d, n, sizeof(int), compare);

        soma = 0;
        for (i = k - 1; i < n; i++)
            soma += d[i];
        printf ("%d\n", soma);
    }
    return 0;
}
