#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
FILE *f = fopen ( "swap.in", "r" );

FILE *g = fopen ( "swap.out", "w" );



int N, AIB[50002], where[30];

char A[50002], B[50002];

vector < int > G[30];



void Update ( int poz ){



    for ( int i = poz; i <= N; i += ( (i) & (-i) ) )

        AIB[i] ++;



}



int Suma ( int N ){



    int sum = 0;



    for ( int i = N; i > 0; i -= ( (i) & (-i) ) )

        sum += AIB[i];



    return sum;

}



int SumaInt ( int st, int dr ){

    return dr - Suma(st-1);

}



int main(){



    int i, poz, lp, ch, moves = 0;



    fscanf ( f, "%s%*c%s", A + 1, B + 1 );



    N = strlen ( A + 1 );



    for ( i = 1; i <= N; ++i )

        G[A[i]-'a'].push_back ( i );

    for ( i = 0; i < 'z' - 'a'; ++i )

        G[i].resize ( G[i].size() );







    for ( i = 1; i <= N; ++i ){

        ch = B[i] - 'a';



        if ( where[ch] == G[ch].size() ){

            fprintf ( g, "-1" );

            return 0;

        }



        poz = G[ch][where[ch]];

        where[ch]++;



        lp = poz;

        poz += SumaInt( poz, i-1 );



        Update ( lp );

        moves += poz - i;

    }



    fprintf ( g, "%d", moves );



    return 0;

}
