#include<bits/stdc++.h>
using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



const int DIM = 2e6 + 7;



int N, M, P[DIM], L, Ans[DIM], sol;

char A[DIM], B[DIM];

int main(){



    fin.getline( A + 1, DIM - 5 );

    fin.getline( B + 1, DIM - 5 );

    N = strlen( A + 1 );

    M = strlen( B + 1 );



    L = 0; P[1] = 0;

    for( int i = 2; i <= N; i++ ){

        while( L != 0 && A[i] != A[L + 1] )

            L = P[L];

        if( A[i] == A[L + 1] )

            L++;

        P[i] = L;

    }



    L = 0;

    for( int i = 1; i <= M; i++ ){

        while( L != 0 && B[i] != A[L + 1] )

            L = P[L];

        if( B[i] == A[L + 1] )

            L++;

        if( L == N ){

            Ans[++sol] = i - N;

            L = P[L];

        }

    }



    fout << sol << "\n";

    for( int i = 1; i <= min( sol, 1000 ); i++ )

        fout << Ans[i] << " ";

    return 0;

}
