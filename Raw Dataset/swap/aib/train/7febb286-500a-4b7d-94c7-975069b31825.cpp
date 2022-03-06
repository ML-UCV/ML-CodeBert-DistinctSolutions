#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;



const int NMAX = 50003;



queue <int> q[26];

int N, aib[NMAX];

char s[NMAX];



inline void AIB_build () {



    int i, j;

    for (i = 1; i <= N; ++i)

        for (j = i; j <= N; j += j & -j)

            ++aib[j];



}



inline void AIB_update (int k) {



    for (; k <= N; k += k & -k)

        --aib[k];



}



inline int AIB_query (int k) {



    int r = 0;

    for (; k; k -= k & -k)

        r += aib[k];

    return r;



}



int main () {



    freopen ("swap.in", "r", stdin);

    freopen ("swap.out", "w", stdout);

    int i, r = 0;

    scanf ("%s", s + 1);

    N = strlen (s + 1);

    for (i = 1; i <= N; ++i)

        q[s[i] - 'a'].push (i);

    scanf ("%s", s + 1);

    if (strlen (s + 1) != N)

        printf ("-1\n"),

        exit (EXIT_SUCCESS);

    AIB_build ();

    for (i = 1; i <= N; ++i) {

        if (q[s[i] - 'a'].empty ())

            printf ("-1\n"),

            exit (EXIT_SUCCESS);

        r += AIB_query (q[s[i] - 'a'].front ()) - 1;

        AIB_update (q[s[i] - 'a'].front ());

        q[s[i] - 'a'].pop ();

    }

    printf ("%d", r);



}
