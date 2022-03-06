#include <bits/stdc++.h>


using namespace std;



const int MAX_N = 250000;

const int MAX_K = log2(MAX_N) + 1;



int T[MAX_K][MAX_N];



int N, M;



int main()

{

    ifstream cin("stramosi.in");

    ofstream cout("stramosi.out");



    cin >> N >> M;



    for(int i = 1; i <= N; ++i)

        cin >> T[0][i];



    int K = log2(N) + 1;



    for(int k = 1; k < K; ++k)

        for(int i = 1; i <= N; ++i)

            T[k][i] = T[k - 1][T[k - 1][i]];



    for(int i = 1; i <= M; ++i)

    {

        int Q, P;

        cin >> Q >> P;



        int k = 0;



        while(P)

        {

            if(P & 1) Q = T[k][Q];



            ++k;

            P = P >> 1;

        }



        cout << Q << '\n';



    }

}
