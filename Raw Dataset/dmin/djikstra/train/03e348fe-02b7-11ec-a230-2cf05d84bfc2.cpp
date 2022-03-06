#include <bits/stdc++.h>
using namespace std ;

const int NR = 1505 ;

const long double oo = 100000 ;

const double ER = 0.000000001;

ifstream in ("dmin.in") ;

ofstream out ("dmin.out") ;

vector < pair < int , long double > > v [ NR ] ;

vector < int > way ( NR , 0 ) ;

vector < long double > d ( NR , oo ) ;

int n , m ;

struct cmp {

    inline bool operator() ( const pair < int , long double > i , const pair < int , long double > j ) {

        return i.second > j.second ;

    }

};

priority_queue < pair < int , long double > , vector < pair < int , long double > > , cmp > q ;

void dijkstra ( ) {

    int nod ;

    long double cost ;

    q.push( make_pair ( 1 , 0 ) ) ;

    d [ 1 ] = 0 ;

    way [ 1 ] = 1 ;

    vector < pair < int , long double > > :: iterator it ;

    while ( !q.empty() ) {

            nod = q.top().first;

            cost = q.top().second ;

            q.pop() ;

        if ( d [ nod ] != cost ) continue ;

            for ( it = v [ nod ].begin() ; it != v [ nod ].end() ; ++ it ) {

            if ( d [ nod ] + (*it).second == d [ (*it).first ] || abs ( d [ nod ] + (*it).second - d [ (*it).first ] ) < ER ) {

                way [ (*it).first ] += way [ nod ] ;

                if ( way [ (*it).first ] > 104659 ) way [ (*it).first ] -= 104659 ;

            } else

            if ( d [ nod ] + (*it).second < d [ (*it).first ] ) {

                d [ (*it).first ] = d [ nod ] + (*it).second ;

                q.push( make_pair ( (*it).first , d [ (*it).first ] ) ) ;

                way [ (*it).first ] = way [ nod ] ;

            }

    }

    }

}

int main () {

    int i , j , x , y , z ;

    in >> n >> m ;

    while ( m -- ) {

        in >> x >> y >> z ;

        v [ x ].push_back ( make_pair ( y , log ( z ) ) ) ;

        v [ y ].push_back ( make_pair ( x , log ( z ) ) ) ;

    }

    dijkstra() ;

    for ( i = 2 ; i <= n ; ++ i ) out << way [ i ] << ' ' ;

}
