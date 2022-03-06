#include <bits/stdc++.h>






using namespace std;



const int Nmax = 50000 + 10;



int i , n , ans;

int aib[Nmax];

int nxt[Nmax] , last[30] , crt[30];



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



    fgets(a+1, 50001, stdin); fgets(b+1, 50001, stdin); n = strlen(a+1);



    for (i = n; i ; --i)

    {

        if (!last[b[i]-'a']) crt[b[i]-'a'] = i;

        nxt[last[b[i]-'a']] = i;

        last[b[i]-'a'] = i;

    }



    for (i = n; i ; --i)

    {

        if (!crt[a[i]-'a'])

        {

            printf("-1\n");

            return 0;

        }

        ans += aibQuery(crt[a[i]-'a']);

        aibUpdate(crt[a[i]-'a']);



        crt[a[i]-'a'] = nxt[crt[a[i]-'a']];

    }



    printf("%d\n", ans);



    return 0;

}
