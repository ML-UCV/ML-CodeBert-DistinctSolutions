#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
using namespace std ;



ofstream fout ( "dmin.out" ) ;



int N , M , paths[1600] , inQueue[1600] ;

double dist[1600] ;

vector < pair < int , double > > TT[1600] ;

queue < int > Q ;





void read()

{

    int x , y , cost ;

    freopen ( "dmin.in" , "r" , stdin ) ;

    scanf ( "%d %d" , &N , &M ) ;

    for ( int i = 1 ; i <= M ; i++ )

    {

        scanf ( "%d %d %d" , &x , &y , &cost ) ;

        TT[x].push_back( make_pair( y , log(cost) ) ) ;

        TT[y].push_back( make_pair( x , log(cost) ) ) ;

    }

    for ( int i = 2 ; i <= N ; i++ )

        dist[i] = 1e40 ;

}



void bellman_ford()

{

    Q.push(1);

    inQueue[1] = 1;

    paths[1] = 1;



    while(!Q.empty())

    {

        int node = Q.front();

        Q.pop();

        for ( vector < pair < int , double > > :: iterator it = TT[node].begin() ; it != TT[node].end() ; ++it )

        {

            int current = it->first ;

            if( dist[current] - 0.0000001 > dist[node] + it->second )

            {

                dist[current] = dist[node] + it->second;

                paths[current] = paths[node];

                if(inQueue[current] == 0)

                {

                    Q.push(current);

                    inQueue[current] = 1;

                }

            }

            else

            {

                if(dist[current] + 0.0000001 >= dist[node] + it->second )

                {

                    paths[current] += paths[node];

                    paths[current] %= 104659 ;

                }



            }

        }

    }



    for ( int i = 2 ; i <= N ; i++ )

        fout << paths[i] << ' ' ;

}





int main()

{

    read() ;

    bellman_ford() ;

    return 0;

}
