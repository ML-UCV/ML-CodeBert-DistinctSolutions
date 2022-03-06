#include <algorithm>#include <cstring>#include <fstream>#include <stdio.h>
#include <vector>
using namespace std;
char A[ 50001 ], B[ 50001 ];

int N, XXX, F[ 50001 ], P[ 50001 ];

int sum, arb[ 50001<<2 ];

vector <int> poz[ 26 ];



inline void query( const int &nod, const int &st, const int &dr, const int &a, const int &b ) {



    int mij;



    if( a <= st && dr <= b ) {



        sum += arb[ nod ];

        return;

    }

    mij = (st+dr) / 2;

    if( a <= mij )

        query( nod<<1, st, mij, a, b );

    if( mij < b )

        query( (nod<<1) + 1, mij+1, dr, a, b );

}



inline void update( const int &nod, const int &st, const int &dr, const int &poz ) {



    int mij;



    if( st == dr ) {



        arb[ nod ] = 1;

        return;

    }

    mij = (st+dr) / 2;

    if( poz <= mij )

        update( nod<<1, st, mij, poz );

    else

        update( (nod<<1) + 1, mij+1, dr, poz );

    arb[ nod ] = arb[ nod<<1 ] + arb[ (nod<<1) + 1 ];

}



int main() {



    freopen( "swap.in", "r", stdin );

    freopen( "swap.out", "w", stdout );



    int i, ind;



    fgets( A+1, 50001, stdin);

    fgets( B+1, 50001, stdin);



    N = strlen( A+1 );

    for( i = 1; i <= N; ++i ) {



        ++F[ A[ i ] - 'a' ];

        --F[ B[ i ] - 'a' ];

    }

    for( i = 0; i < 26; ++i )

        if( F[ i ] ) {



            printf( "-1" );

            return 0;

        }

    for( i = 1; i <= N; ++i ) {



        ++F[ B[ i ] - 'a' ];

        poz[ B[ i ] - 'a' ].push_back( i );

    }
    memset( F, 0, sizeof( F ) );

    for( i = 1; i <= N; ++i ) {



        ind = A[ i ] - 'a';

        ++F[ ind ];

        P[ i ] = poz[ ind ][ F[ ind ] - 1 ];

    }
    memset( F, 0, sizeof( F ) );

    for( i = 1; i <= N; ++i ) {



        update( 1, 1, N, P[ i ] );

        sum = 0;

        query( 1, 1, N, 1, P[ i ] );

        XXX += P[ i ] - sum;

    }



    printf( "%d", XXX );



    return 0;

}
