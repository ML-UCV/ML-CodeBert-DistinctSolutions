#include <stdio.h>
#include <stdlib.h>

#define FIN "sate.in"
#define FOUT "sate.out"
#define MAXN 30001
#define MAXM 100100

int n, m, x, y;
bool Used[MAXN];

struct elem
{
    int x, c;
    elem *r;
} * L[MAXN];

void push(int a, int b, int c)
{
    elem *temp = new elem;
    temp->x = b;
    temp->c = c;
    temp->r = L[a];
    L[a] = temp;
}

void citire()
{
    int i, a, b, c;
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (i = 0; i < m; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        push(a, b, c);
        push(b, a, -c);
    }
}

struct coada
{
    int x;
    long long d;
} C[MAXN];

void bf(int s)
{
    int p, u = 0;
    C[u++] = (coada){s, 0};
    Used[s] = 1;

    for (p = 0; p < u; ++p)
    {
        if (C[p].x == y)
            break;
        for (elem *k = L[C[p].x]; k; k = k->r)
            if (!Used[k->x])
                C[u++] = (coada){k->x, C[p].d + k->c}, Used[k->x] = 1;
    }
    printf("%lld\n", C[p].d);
}

int main()
{
    citire();
    bf(x);
    return 0;
}