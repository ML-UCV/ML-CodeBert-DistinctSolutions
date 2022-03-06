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

        vector<pair<int, double> >::iterator it = TT[node].begin();

        while(it != TT[node].end())

        {

            pair<int, double> neigh = *it;

            if(dist[neigh.first] - 1e-8 > dist[node] + neigh.second)

            {

                dist[neigh.first] = dist[node] + neigh.second;

                paths[neigh.first] = paths[node];

                if(inQueue[neigh.first] == 0)

                {

                    Q.push(neigh.first);

                    inQueue[neigh.first] = 1;

                }

            }

            else

            {

                if(dist[neigh.first] + 1e-8 >= dist[node] + neigh.second)

                {

                    paths[neigh.first] += paths[node];

                    paths[neigh.first] %= 104659 ;

                }

            }



            it++;

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
