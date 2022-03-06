#include <bits/stdc++.h>
using namespace std ;

ifstream in ("inversmodular.in") ;

ofstream out ("inversmodular.out") ;

int euclid( int a , int b , int & x , int & y )

{

    if ( !b )

    {

            x = 1 ;

            y = 0 ;

        return a ;

    }

    {

        int x0 , y0 ;

        int u = euclid ( b , a % b , x0 , y0 ) ;

        x = y0 ;

        y = x0 - y0 * ( a / b ) ;

        return u ;

    }



}

int main ()

{

    int a , b , gcd , x , y ;

    in >> a >> b ;

    gcd = euclid( a , b , x , y ) ;

    while ( x < 0 ) x += b ;

    out << x ;

}
