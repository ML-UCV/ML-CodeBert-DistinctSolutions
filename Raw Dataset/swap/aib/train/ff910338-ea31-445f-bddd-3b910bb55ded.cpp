# include <bits/stdc++.h>




using namespace std;



const int Nmax = 50000 + 5;



queue <int> Q[32];

char a[Nmax], b[Nmax];

int N, i, val, aib[Nmax];

long long sol = 0;



void add(int x)

{

    int i;

    for (i = x; i <= N; i += (i&(-i))) aib[i]++;

}

int sum (int x)

{

    int i, s = 0;



    for (i = x - 1; i; i -= (i&(-i))) s += aib[i];



    return s;

}



int main ()



{

    freopen("swap.in","r",stdin);

    freopen("swap.out","w",stdout);



    fgets(a, 50001, stdin);

    fgets(b, 50001, stdin);



    N = strlen(a);



    for (i = 0; i < N; ++i)

        Q[ b[i] - 'a' ].push(i + 1);



    for (i = 0; i < N; ++i)

    {

        if (Q[ a[i] - 'a'].size() == 0)

        {

            printf("-1\n");

            return 0;

        }



        val = Q[a[i] - 'a'].front();

        Q[a[i] - 'a'].pop();



        sol += sum(val);

        add(val);

    }



    printf("%lld\n", 1LL*N * (N - 1) / 2 - sol);



    return 0;

}
