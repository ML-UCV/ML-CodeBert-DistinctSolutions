#include <bits/stdc++.h>
using namespace std;



int n, i, j, sol, p, x;

int f[27];

char s[50002], a[50002];

int aib[50002];

int pos[27][50002];

int ind[27];



int main()

{

    freopen("swap.in", "r", stdin);

    freopen("swap.out", "w", stdout);



    fgets(s, 50001, stdin);

    fgets(a, 50001, stdin);

    n = strlen(a + 1);



    for(i = 1; i <= n; i++)

    {

        f[ s[i] - 'a' ]++;

        f[ a[i] - 'a' ]--;

    }



    for(i = 0; i < 26; i++)

        if(f[i] != 0)

        {

            printf("-1");

            return 0;

        }



    for(i = 1; i <= n; i++)

        pos[ s[i] - 'a' ][ ++ind[ s[i] - 'a' ] ] = i;



    for(i = 0; i < 26; i++)

        ind[i] = 1;



    for(i = 1; i <= n; i++)

    {

        p = pos[ a[i] - 'a' ][ ind[ a[i] - 'a' ]++ ];

        sol += p - 1;

        for(j = p - 1; j >= 1; j -= (j & (-j)))

            sol -= aib[j];

        for(j = p; j <= n; j += (j & (-j)))

            aib[j]++;

    }



    printf("%d", sol);



    return 0;

}
