#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");

vector <pair<int,int> > muchii[30001];
queue <int>Q;
int N, M, X, Y, i, j, d, viz[30001], dist[30001];

void BFS()
{ Q.push(X);
  viz[X] = 1;
  while( !Q.empty() )
    { int k = Q.front();
       for(int i = 0; i < muchii[k].size(); i++)
           { int j = muchii[k][i].first, d = muchii[k][i].second;
             if( !viz[j] )
                 { viz[j] = 1;
                   if( k < j ) dist[j] = dist[k] + d;
                   else dist[j] = dist[k] - d;
                   Q.push(j);
                 }
           }
      Q.pop();
    }
}

void citire()
{
    f >> N >> M >> X >> Y;
    for(int k = 1; k <= M; k++ )
        {f>>i>>j>>d;
         muchii[i].push_back(make_pair(j,d));
         muchii[j].push_back(make_pair(i,d));
        }
}

int main()
{
    citire();
    BFS();
    g << dist[Y];
    return 0;
}
