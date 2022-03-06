#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;



const int Nmax = 102;



vector <int> G[2 * Nmax], GT[2 * Nmax];

int sol[2 * Nmax];

int vis[2 * Nmax];

int postorder[2 * Nmax];



int N, M, P, EXIST_SOL = 1;



inline int neg( int x )

{

    if ( x > N )

            return x - N;

    else

            return x + N;

}



void DFS( int nod )

{

    vis[nod] = 1;



    for ( auto x: G[nod] )

            if ( !vis[x] )

                    DFS( x );



    postorder[ ++P ] = nod;

}



void DFST( int nod )

{

    if ( sol[nod] ) EXIST_SOL = 0;



    vis[nod] = 0;

    sol[ neg( nod ) ] = 1;



    for ( auto x: GT[nod] )

            if ( vis[x] )

                    DFST( x );

}



void SAT2()

{

    for ( int i = 1; i <= 2 * N; ++i )

            if ( !vis[i] )

                    DFS( i );



    for ( int i = P; i >= 1; i-- )

    {

        int nod = postorder[i];



        if ( vis[nod] && vis[ neg( nod ) ] )

                DFST( nod );

    }

}



int main()

{

    ifstream f("party.in");

    ofstream g("party.out");



    f >> N >> M;



    for ( int i = 1, tip, x, y; i <= M; ++i )

    {

        f >> x >> y >> tip;



        switch( tip )

        {

            case 0:

                    break;



            case 1:

                    y = neg( y );



                    break;



            case 2:

                    x = neg( x );



                    break;





            case 3:

                    x = neg( x );

                    y = neg( y );



                    break;



            default: break;

        }



        G[ neg( x ) ].push_back( y );

        G[ neg( y ) ].push_back( x );



        GT[y].push_back( neg( x ) );

        GT[x].push_back( neg( y ) );

    }



    SAT2();



    if ( EXIST_SOL )

    {

        g << count( sol + 1, sol + N + 1, 1 ) << "\n";



        for ( int i = 1; i <= N; ++i )

                if( sol[i] )

                        g << i << "\n";

    }

    else

    {

        g << "0\n";

    }



    return 0;

}
