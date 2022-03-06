#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
ifstream fin ( "dmin.in" );

ofstream fout ( "dmin.out" );





int N, M, Aport[1502];

double Dist[1502];

vector < pair < int, double > > G[1502];

bitset < 1502 > inQ;

queue < int > Q;



void BellmanFord(){



    for ( int i = 2; i <= N; ++i )

        Dist[i] = 0x3f3f3f3f;



    Aport[1] = 1;

    Q.push ( 1 );

    inQ[1] = 1;



    vector < pair < int, double > > :: iterator it;

    while ( !Q.empty() ){

        int nod = Q.front();

        Q.pop();

        inQ[nod] = 0;



        for ( it = G[nod].begin(); it != G[nod].end(); ++it ){

            if ( Dist[it->first] - (Dist[nod] + it->second) >= 1e-10 ){

                Dist[it->first] = Dist[nod] + it->second;



                Aport[it->first] = Aport[nod];



                if ( !inQ[it->first] ){

                    Q.push ( it->first );

                    inQ[it->first] = 1;

                }

            }

            else if ( abs ( (Dist[nod] + it->second) - Dist[it->first] ) < 1e-10 ){

                Aport[it->first] += Aport[nod];

                Aport[it->first] %= 104659;

            }

        }

    }

}



int main(){



    int x, y, c;



    fin >> N >> M;



    while ( M-- ){

        fin >> x >> y >> c;

        G[x].push_back ( make_pair ( y, log10(c) ) );

        G[y].push_back ( make_pair ( x, log10(c) ) );

    }



    BellmanFord();



    for ( int i = 2; i <= N; ++i )

        fout << Aport[i] << " ";



    return 0;

}
