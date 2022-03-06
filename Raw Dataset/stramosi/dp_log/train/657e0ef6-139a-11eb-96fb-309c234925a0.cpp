#include <iostream>
#include <fstream>


using namespace std;

ifstream fin ("stramosi.in");

ofstream fout ("stramosi.out");



int N, M, logn, i, j, k, a[ 18 ][ 250001 ], Q, P;



int main()

{

    fin >> N >> M;

    for ( i = 1; i <= N; i++ )

    {

        fin >> a[ 0 ][ i ];

    }

    for ( logn = 1, k = 0; logn < N; logn <<= 1, k++ );

    logn >>= 1;

    k--;

    for ( i = 1; i <= k; i++ )

    {

        for ( j = 1; j <= N; j++ )

        {

            a[ i ][ j ] = a[ i - 1 ][ a[ i - 1 ][ j ] ];

        }

    }

    for ( i = 1; i <= M; i++ )

    {

        fin >> Q >> P;

        while ( P > 0 )

        {

            for ( logn = 1, k = 0; logn <= P; logn <<= 1, k++ );

            logn >>= 1;

            k--;

            Q = a[ k ][ Q ];

            P -= logn;

        }

        fout << Q << '\n';

    }

    return 0;

}
