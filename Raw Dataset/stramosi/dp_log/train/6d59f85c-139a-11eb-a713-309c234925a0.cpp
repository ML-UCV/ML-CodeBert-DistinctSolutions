#include<bits/stdc++.h>
using namespace std ;

ifstream f ( "stramosi.in" ) ;

ofstream g ( "stramosi.out" ) ;

const int NR = 250001 ;

int rmq [ 20 ][ NR ] ;



int main ()

{

    int nod , nr , q , k , n , lg ; f >> n >> q ;

    int i , j ;

    for ( i = 1 ; i <= n ; ++ i ) f >> rmq [ 0 ][ i ] ;

    for ( k = 1 ; ( 1 << k ) <= n ; k ++ ) ;

    for ( i = 1 ; ( 1 << i ) <= n ; ++ i )

    for ( j = 1 ; j <= n ; j ++ )

    rmq [ i ][ j ] = rmq [ i - 1 ][ rmq [ i - 1 ][ j ] ] ;

    while ( q -- )

    {

        f >> nod >> nr ;

        lg = k ;

        while ( nod && lg -- ) if ( ( 1 << lg ) & nr ) nod = rmq [ lg ][ nod ] ;

        g << nod << "\n" ;

    }

    f.close() ;

    g.close() ;

    return 0 ;

}
