#include <cstdio>
using namespace std;

const int NMAX = 250000;

int t[NMAX + 5] , d[18][NMAX + 5] , log[NMAX + 5] , n;

inline void dinamica()

{

    int i , j;

    for(j = 1 ; j <= n ; ++ j)

        d[0][j] = t[j];

    for(i = 1 ; (1 << i) <= n ; ++ i)

        for(j = n ; j - (1 << i) >= 1 ; -- j)

            d[i][j] = d[i - 1][d[i - 1][j]];

}

inline void gen_log()

{

    int i , b = 1;

    log[1] = 0;

    for(i = 2 ; i <= n ; i ++)

        if((b << 1) == i)

        {

            log[i] = log[b] + 1;

            b = (b << 1);

        }

        else

            log[i] = log[i - 1];

}

int query(int x , int y)

{

    int l = log[y];

    if((1 << l) == y)

        return d[l][x];

    return query(d[l][x] , y ^ (1 << l));

}

int main()

{

    freopen("stramosi.in" , "r" , stdin);

    freopen("stramosi.out" , "w" , stdout);

    int q , i , x , y;

    scanf("%d%d" , &n , &q);

    for(i = 1 ; i <= n ; ++ i)

        scanf("%d" , &t[i]);

    dinamica();

    gen_log();

    for(i = 1 ; i <= q ; ++ i)

    {

        scanf("%d%d" , &x , &y);

        printf("%d\n" , query(x , y));

    }

    return 0;

}
