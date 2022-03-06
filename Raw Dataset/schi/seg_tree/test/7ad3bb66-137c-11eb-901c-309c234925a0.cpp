#include <bits/stdc++.h>
using namespace std ;

const int NR = 30005 ;

ifstream in ("schi.in") ;

ofstream out ("schi.out") ;

vector < int > Tree ( NR * 4 ) ;

int sol [ NR * 4 ] , n , v [ NR * 4 ] ;

void query ( int nod , int st , int dr , int x , int i ) {

    if ( st == dr ) {

        sol [ st ] = i ;

        Tree[ nod ] -- ;

        return ;

    }

    int mid = ( st + dr ) >> 1 ;

   if ( x <= Tree [ nod << 1 ] ) query( nod << 1 , st , mid , x , i ) ;

   else query( nod << 1 | 1 , mid + 1 , dr , x - Tree [ nod << 1 ] , i ) ;

    Tree [ nod ] = Tree [ nod << 1 ] + Tree [ nod << 1 | 1 ] ;

}

void update ( int nod , int st , int dr , int pos ) {

    if ( st == dr ) {

        Tree[ nod ] = 1 ;

        return ;

    }

    int mid = ( st + dr ) >> 1 ;

    if ( pos <= mid ) update ( nod << 1 , st , mid , pos ) ;

    else update( nod << 1 | 1 , mid + 1 , dr , pos ) ;

    Tree[ nod ] = Tree[ nod << 1 ] + Tree[ nod << 1 | 1 ] ;

}

int main () {

    int i ;

    in >> n ;

     for ( i = 1 ; i <= n ; ++ i ) {

        in >> v [ i ] ;

        update( 1 , 1 , n , i ) ;

     }

    for ( i = n ; i ; i -- )

        query( 1 , 1 , n , v [ i ] , i ) ;

    for( i =1 ; i <= n ; ++ i ) out << sol [ i ] << '\n' ;

}
