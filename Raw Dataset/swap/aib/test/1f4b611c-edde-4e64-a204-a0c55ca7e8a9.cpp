#include <bits/stdc++.h>






using namespace std;



const int Nmax = 50000 + 10;



int i , n , m , ans;

int p[Nmax] , aib[Nmax];



vector < int > g[30];



char a[Nmax] , b[Nmax];



int aibQuery(int i)

{

    int ret = 0;

    for ( ; i ; i -= (i&(-i)))

        ret += aib[i];

    return ret;

}



void aibUpdate(int i)

{

    for ( ; i <= n; i += (i&(-i)))

        aib[i]++;

}



int main()

{

    freopen("swap.in","r",stdin);

    freopen("swap.out","w",stdout);



    fgets(a, 50001, stdin); fgets(b, 50001, stdin); n = strlen(a); m = strlen(b);



    if (n != m)

    {

        printf("-1\n");

        return 0;

    }



    for (i = n - 1; i >= 0; --i)

        g[b[i]-'a'].push_back(i);



    for (i = 0; i < n; ++i)

    {

        if (g[a[i]-'a'].size() == 0)

        {

            printf("-1\n");

            return 0;

        }

        p[i] = g[a[i]-'a'].back() + 1;

        g[a[i]-'a'].pop_back();

    }



    for (i = n - 1; i >= 0; --i)

    {

        ans += aibQuery(p[i]);

        aibUpdate(p[i]);

    }



    printf("%d\n", ans);



    return 0;

}
