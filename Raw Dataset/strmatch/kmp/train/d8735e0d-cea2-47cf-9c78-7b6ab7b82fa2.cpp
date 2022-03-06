#include <bits/stdc++.h>


using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");



string A, B;

int M, N, nr;

int pi[20000005];

int pos[20000005];





void Read()

{

    f>>A;

    f>>B;

}



void make_prefix()

{

    int q = 0;

    for(int i = 2;pi[0] = 1,i <= M;++i)

    {

        while(q && A[q + 1] != A[i])

            q = pi[q];

        if(A[q + 1] == A[i])

            ++q;

        pi[i] = q;

    }

}



void Solve()

{

    int q = 0;

    for(;(A[M] >= 'A' && A[M] <= 'Z') || (A[M] >= 'a' && A[M] <= 'z') || (A[M] >= '0' && A[M] <= '9');++M);

    for(;(B[N] >= 'A' && B[N] <= 'Z') || (B[N] >= 'a' && B[N] <= 'z') || (B[N] >= '0' && B[N] <= '9');++N);

    A.insert(0, " ");

    B.insert(0, " ");



    make_prefix();



    for(int i = 1;i <= N;++i)

    {

        while(q && A[q + 1] != B[i])

            q = pi[q];

        if(A[q + 1] == B[i])

            ++q;

        if(q == M)

        {

            ++nr;

            q = pi[M];

            if(nr <= 1000)

                pos[nr] = i - M;

        }

    }

    g<<nr<<'\n';

    for(int i = 1;i <= min(nr, 1000);++i)

        g<<pos[i]<<" ";

}



int main()

{

    Read();

    Solve();

    return 0;

}
