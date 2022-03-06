#include <cstdio>
#include <cstring>


using namespace std;
char A[50005];

char B[50005];



int P[50005], C[50005];

int M[50005][30], L[30];

int D[50005];

int N, Res;



    void add (int p, int e)

    {

         while (p <= N) D[p] += e, p += p ^(p&(p - 1));

    }



    int query (int p)

    {

         int ret = 0;

         for (int i = p; i;) ret += D[i], i -= i ^(i&(i - 1));

         return ret;

    }



    void solve ()

    {

         int i, ok = 0;

         for (i = 1; i <= N; ++i) C[i] = ++L[A[i] - 'a'];

         for (i = 1; i <= N; ++i) M[++M[0][B[i] - 'a']][B[i] - 'a'] = i;

         for (i = 1; i <= N; ++i) P[i] = M[C[i]][A[i] - 'a'];

         for (i = 1; i <= N; ++i)

             if (!P[i]) {

                 printf ("-1\n");

                 return;

             }



         for (i = 1; i <= N; ++i) add(i, 1);

         for (i = 1; i <= N; ++i)

         {

             add (P[i], -1);

             Res += query(P[i] - 1);

         }

         printf ("%d\n", Res);

    }



    int main ()

    {

        freopen ("swap.in", "r", stdin);

        freopen ("swap.out", "w", stdout);



        fgets (A , 50001, stdin);

        fgets (B , 50001, stdin);

        N = strlen (A + 1);

        solve ();



        return 0;

    }
