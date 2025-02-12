#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

int main()
{
    int c;
    int v[101];
    int vo, vf, vi;
    int i, j;
  
    while(scanf("%d", &vi) != EOF)
    {
        memset(v, 0, sizeof(v));

        for(j = 0; j < vi; j++)
        {
            scanf("%d %d", &vo, &vf);

            for(i = vo; i <= vf; i++)
                ++v[i];
        }
        c = 0;
        scanf("%d", &j);

        if(v[j])
        {
            for(i = 1; i < j; i++)
            {
                c += v[i];
            }
            printf("%d found from %d to %d\n", j, c, (c + v[j] - 1));
        }
        else
        {
            printf("%d not found\n", j);
        }
    }
    return 0;
}
