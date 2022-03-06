#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <stack>


using namespace std;



const int N = 210;



int noInvit , noCond , typeCond ;



vector < int > edges [ N ];



int varValues [ N ];



stack < int > stk ;

int inStack [ N ];



int low [ N ] , preord [ N ] , nrCr = 1 ,nrSol ;



void CalculateSCC( int node ){

    vector < int >::iterator it ;

    int vec ;



    stk.push( node );

    inStack [ node ] = 1 ;

    low [ node ] = preord [ node ] = nrCr ++ ;



    for ( it = edges [ node ].begin() ; it != edges [ node ].end() ; it++ ){

        vec = *it ;



        if ( !preord [ *it ] ){



            CalculateSCC( *it );

            low[ node ] = min( low [ node ] , low[ *it ] );



        }else{

            if ( inStack [ *it ] ){

                low [ node ] = min ( low [ node ] , low [ *it ] );

            }

        }

    }



    if ( low [ node ] == preord [ node ] ){

        int x ;

        do {

            x = stk.top() ;

            stk.pop() ;

            inStack [ x ] = 0 ;



            if ( x > noInvit ){

                if ( varValues [ x - noInvit ] == -1 ){

                    varValues [ x - noInvit ] = 0 ;

                }

            }else{

                if ( varValues [ x ] == -1 ){

                    varValues [ x ] = 1 ;

                    nrSol++;

                }

            }



        }while ( x != node );



    }



}



int main(){

    int i , x , y , xnot , ynot ;



    freopen("party.in","r",stdin);

    freopen("party.out","w",stdout);



    scanf("%d%d",&noInvit , &noCond );



    for ( i = 0 ; i < noCond ; i++ ){

        scanf("%d%d%d", &x , &y , &typeCond );



        xnot = x + noInvit ;

        ynot = y + noInvit ;



        switch( typeCond ){

        case 0 :

            edges[ xnot ].push_back( y );

            edges[ ynot ].push_back( x );

            break ;

        case 1 :

            edges[ xnot ].push_back( ynot );

            edges[ y ].push_back( x );

            break ;

        case 2 :

            edges[ x ].push_back( y );

            edges[ ynot ].push_back( xnot );

            break ;

        case 3 :

            edges[ x ].push_back( ynot );

            edges[ y ].push_back( xnot );

            break ;

        }

    }



    memset ( varValues , -1 , sizeof varValues );



    for ( i = 1 ; i <= 2 * noInvit ; i ++ ){

        if ( preord [ i ] == 0 )

            CalculateSCC( i );

    }



    printf("%d\n",nrSol);

    for ( i = 1 ; i <= noInvit ; i++ ){

        if ( varValues [ i ] == 1 ){

            printf("%d\n",i);

        }

    }



    return 0;

}
