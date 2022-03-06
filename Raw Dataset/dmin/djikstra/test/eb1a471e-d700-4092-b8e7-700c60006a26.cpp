#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;



class cmp {

public :



    bool operator ()( pair < int , double > a , pair < int , double > b ){

        return a.second > b.second ;

    }



};





vector < pair < int , double > > muc [ 1510 ];

vector < pair < int , double > >::iterator it ;

priority_queue < pair < int , double > , vector < pair < int , double > > , cmp > que ;

int n ;

double dist [ 1510 ] ;

int nrd[ 1510 ];

int viz [ 1510 ] ;



int comp ( double a , double b ){

    if ( a - b < 1e-10 && a - b > -1e-10 ){

        return 0 ;

    }



    if ( a < b ){

        return -1;

    }

    return 1 ;

}



void djikstra ( ){

    static int i , nod , temp ;



    for ( i = 2 ; i <= n ; i ++ ){

        dist [ i ] = 1e7 ;

    }



    nrd [ 1 ] = 1 ;

    que.push( make_pair( 1 , 0 ) );



    while ( !que.empty() ){



        while ( !que.empty() && viz [ que.top().first ] == 1 ){

            que.pop();

        }



        if ( que.empty() ){

            break ;

        }



        nod = que.top().first;

        que.pop() ;

        viz[ nod ] = 1;



        for ( it = muc [ nod ].begin() ; it != muc [ nod ].end() ; it++ ){



            if ( viz [ it->first ] ){

                continue ;

            }



            temp = comp ( dist [ it->first ] , dist [ nod ] + it->second ) ;

            if ( temp == 0 ){

                nrd [ it -> first ] += nrd [ nod ];

            }else if ( temp == 1 ){

                dist [ it->first ] = dist [ nod ] + it->second ;

                nrd [ it->first ] = nrd [ nod ] ;

                que.push( make_pair( it->first , dist [ it->first ] ) ) ;



            }

            nrd [ it->first ] %= 104659 ;





        }



    }

}



int main(){

    int m , x , y , cost , i ;



    freopen("dmin.in","r",stdin);

    freopen("dmin.out","w",stdout);



    scanf("%d%d",&n,&m);



    for( i = 0 ; i < m ; i ++ ){

        scanf("%d%d%d", &x , &y , &cost );

        muc [ x ].push_back( make_pair( y , log( cost ) ) ) ;

    }



    djikstra( );



    for ( i = 2 ; i <= n ; i ++ ){

        printf("%d ",nrd [ i ] ) ;



    }



    return 0;

}
