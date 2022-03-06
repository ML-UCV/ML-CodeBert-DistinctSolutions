#include <iostream>
#include <fstream>
#include <queue>
#include <string.h>

using namespace std;

vector <pair<int,int> > graf[30001] ;
queue <int> Q ;
int dist[300001] ;
bool viz[300001] ;
int x , y , m , n ;

ifstream fin ("sate.in") ;
ofstream fout("sate.out") ;

void citire ()
{
    int x1 , y1 , c1 , i ;
    fin >> n >> m >> x >> y ;
    for ( i = 1 ; i <= m ; i++ )
    {
        fin >> x1 >> y1 >> c1 ;
        if ( x1 > y1 )
        {
            graf[x1].push_back(make_pair(y1,-c1)) ;
            graf[y1].push_back(make_pair(x1,c1)) ;
        }
        else
        {
            graf[x1].push_back(make_pair(y1,c1)) ;
            graf[y1].push_back(make_pair(x1,-c1)) ;
        }
    }
}

void lee ( int a , int b )
{
    int i ;
    int punct ;
    Q.push(a) ;
    memset(dist,-1,100*sizeof(int)) ;
    memset(viz,false,100*sizeof(bool)) ;
    dist[a] = 0 ;
    viz[a] = true ;
    while ( !Q.empty() )
    {
        punct = Q.front() ;
        Q.pop() ;
        for ( i = 0 ; i < graf[punct].size() ; i++ )
        {
            if ( viz[graf[punct][i].first] == false )
            {
                viz[graf[punct][i].first] = true ;
                dist[graf[punct][i].first] = dist[punct] + graf[punct][i].second ;
                Q.push(graf[punct][i].first) ;
            }
        }
    }
}

int main()
{
    citire() ;
    lee(x,y) ;
    fout << dist[y] ;
}
