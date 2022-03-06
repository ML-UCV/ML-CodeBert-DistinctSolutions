#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;



int f[1001], INV1 = 0, INV2 = 0, pos[201][50001], d[50001], LE[50001], C[50001];

char a[50002], b[50002];

int c[50002];

inline void Merge(int st, int mij, int dr){

    int i = st, j = mij + 1, NR = 0;

    while(i <= mij && j <= dr){

        if(d[i] > d[j]){

            c[++NR] = d[j++];

            INV1 = INV1 + mij - i + 1;

        }

        else

            c[++NR] = d[i++];

    }

    while(j <= dr)

        c[++NR] = d[j++];

    while(i <= mij)

        c[++NR] = d[i++];

    for(i = st , j = 1; i <= dr ; ++i, ++j)

        d[i] = c[j];

}

inline void MergeSort(int st, int dr){

    if(st >= dr) return ;

    MergeSort(st, (st + dr) / 2);

    MergeSort((st + dr) / 2 + 1, dr);

    Merge(st, (st + dr) / 2, dr);

}

int main()

{

    freopen("swap.in", "r", stdin);

    freopen("swap.out", "w", stdout);

    scanf("%s", a);

    scanf("%s", b);

    int L = strlen(a);

    for(int i = 0 ; i < L ; ++i)

        ++f[a[i]];

    for(int i = 0 ; i < L ; ++i){

        if(f[b[i]] == 0)

            {printf("-1"); return 0;}

        --f[b[i]];

    }

    for(int i = 0 ; i < L ; ++i)

        pos[a[i]][++LE[a[i]]] = i + 1;

    for(int i = 0 ; i < L ; ++i)

        d[i] = pos[b[i]][++C[b[i]]];

    MergeSort(0, L - 1);

    printf("%d", INV1);

    return 0;

}
