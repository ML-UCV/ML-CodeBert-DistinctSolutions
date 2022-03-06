#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>




using namespace std ;



const long long MOD1 = 1e9 + 7 ;

const long long MOD2 = 1e9 + 9 ;

const long long BASE = 91 ;

vector < int > v ;



int main ()

{

    ifstream in ( "strmatch.in" ) ;

    ofstream out ( "strmatch.out" ) ;



    string inp1 , inp2 ;

    long long hash11 , hash12 , hash21 , hash22, n , m , nr = 0 ;

    long long p1 , p2 , i ;



    in >> inp1 >> inp2 ;

    n = inp1.size () ;

    m = inp2.size () ;



    if ( n > m )

    {

        out << 0 ;

        return 0 ;

    }



    hash11 = hash12 = hash21 = hash22 = 0 ;

    p1 = p2 = 1 ;



    for ( i = 0 ; i < n ; ++ i )

    {

        hash11 = ( hash11 * BASE + inp1 [ i ] ) % MOD1 ;

        hash12 = ( hash12 * BASE + inp1 [ i ] ) % MOD2 ;



        hash21 = ( hash21 * BASE + inp2 [ i ] ) % MOD1 ;

        hash22 = ( hash22 * BASE + inp2 [ i ] ) % MOD2 ;



        if ( i )

        {

            p1 = ( p1 * BASE ) % MOD1 ;

            p2 = ( p2 * BASE ) % MOD2 ;

        }

    }



    if ( hash11 == hash21 && hash12 == hash22 )

        v.push_back ( 0 ) , ++ nr ;



    for ( i = n ; i < m ; ++ i )

    {

        hash21 = ( ( hash21 - ( 1LL * inp2 [ i - n ] * p1 ) % MOD1 + MOD1 ) * BASE + inp2 [ i ] ) % MOD1 ;

        hash22 = ( ( hash22 - ( 1LL * inp2 [ i - n ] * p2 ) % MOD2 + MOD2 ) * BASE + inp2 [ i ] ) % MOD2 ;



        if ( hash11 == hash21 && hash12 == hash22 )

        {

            ++ nr ;

            if ( v.size () < 1000 )

                v.push_back ( i - n + 1 ) ;

        }

    }



    out << nr << '\n' ;

    for ( i = 0 ; i < v.size () ; ++ i )

        out << v [ i ] << ' ' ;



    return 0 ;

}
