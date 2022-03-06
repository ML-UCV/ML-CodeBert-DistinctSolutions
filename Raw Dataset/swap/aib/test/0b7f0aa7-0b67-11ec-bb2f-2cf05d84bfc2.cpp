#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;



char s1[50010], s2[50010];

int aib[50010], n;

queue <int> poz[32];



inline void add (int x)

{

    for (int i = x; i <= n; i += i & (-i))

        ++aib[i];

}



inline int searchh (int x)

{

    int rez = 0;

    for (int i = x - 1; i; i -= i & (-i))

        rez += aib[i];



    return rez;

}



int main ()

{

    freopen ("swap.in", "r", stdin);

    freopen ("swap.out", "w", stdout);



    fgets (s1, 50001, stdin);

    fgets (s2, 50001, stdin);



    n = strlen (s1);

    for (int i = 0; i < n; ++i)

        poz[s2[i] - 'a'].push (i + 1);



    int nr = 0;

    for (int i = 0; i < n; ++i)

    {

        if (!poz[s1[i] - 'a'].size ())

        {

            printf ("-1\n");

            return 0;

        }



        int x = poz[s1[i] - 'a'].front ();

        poz[s1[i] - 'a'].pop ();



        nr += searchh (x);

        add (x);

    }



    long long rez = 1LL * n * (n - 1) / 2LL;

    rez -= 1LL * nr;



    nr = (int) rez;

    printf ("%d\n", nr);



    return 0;

}
