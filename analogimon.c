#include <stdio.h>

#define MAXSIZE 1234

int id[MAXSIZE];
int tam[MAXSIZE];

inline void swap(int *a, int *b);

int parent(int i) {
    if (i == id[i])
        return i;
    else
        return id[i] = parent(id[i]);
}

int qunion(int p, int q) {
    p = parent(p);
    q = parent(q);

    if (p != q) {
        if (tam[p] > tam[q])
            swap(&p, &q);
        id[p] = q;
        tam[q] += tam[p];
    }
    return 0;
}

inline void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(int argc, char **argv) {
    int n, m, a, b;

    while (~scanf("%d %d", &n, &m)) {
        for (int i = 1; i <= n; ++i) {
            tam[i] = 1;
            id[i] = i;
        }

        while (m--) {
            scanf("%d %d", &a, &b);
            qunion(a, b);
        }

        scanf("%d", &a);
        printf("%d\n", tam[parent(a)]);
    }

    return 0;
}
