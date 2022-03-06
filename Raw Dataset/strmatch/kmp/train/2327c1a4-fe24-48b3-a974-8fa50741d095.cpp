#include <bits/stdc++.h>


using namespace std;



ifstream in("strmatch.in");

ofstream out("strmatch.out");



const int Nmax = 2e6 + 5;

int pi[Nmax], ans[Nmax];

int N;

string S, C;



void preproc()

{

    int K = 0;



    for(int i = 1; i < S.size(); ++i)

    {

        while(K && S[K] != S[i])

            K = pi[K - 1];



        if(S[K] == S[i])

            K++;



        pi[i] = K;



    }

}



void solve()

{

    int K = 0, L = C.size();



    for(int i = 0; i < L

    ; ++i)

    {

        while(K && S[K] != C[i])

            K = pi[K - 1];



        if(S[K] == C[i])

            K++;



        if(K == S.size())

        {

            if(N <= 1000)

                ans[++N] = (i - K + 1);

                else N++;

            K = pi[K - 1];

        }

    }



    out << N << '\n';



    for(int i = 1; i <= min(N,1000); ++i)

        out << ans[i] << " ";



}



int main()

{

    in >> S >> C;



    preproc();

    solve();

    return 0;

}
