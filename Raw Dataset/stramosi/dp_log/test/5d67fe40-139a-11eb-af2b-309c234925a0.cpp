#include <fstream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;



ifstream f ( "stramosi.in" );

ofstream g ( "stramosi.out" );



int d[17 + 1][250000 + 1], e[17 + 1];



int main()

{ int n, q, i, org, lvl;

    f >> n >> q;

    for ( i = 1; i <= n; i++ )

        f >> d[0][i];

    for ( i = 1; i <= 17; i++){

        for ( int j = 1; j <= n; j++ )

            d[i][j] = d[i - 1][ d[i - 1][j] ];

    }

    for ( i = 1; i <= q; i++ ){

        f >> org >> lvl;

        for ( int j = 0; ( 1 << j ) <= lvl; j++ )

            if ( ( ( lvl >> j ) & 1 ) == 1 )

                org = d[j][org];

        g << org << '\n';

    }

    return 0;

}
