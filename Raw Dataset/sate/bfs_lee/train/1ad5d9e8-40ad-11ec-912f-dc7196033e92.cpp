#include <fstream>
#include <vector>
#include <stdio.h>
#include <queue>

#define limit 30005

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");


vector < pair< int, int> > G[limit];
vector < int > d(limit, -1);
queue < int > q;
int N, M, X, Y, Z;
int A, B, C;

void bfs()
{
    q.push(X);
    d[X]=0;
    for( ; !q.empty() ; q.pop())
    {
        int aux=q.front();
        for(int i = 0 ; i < G[aux].size(); ++ i)
        {
            int nod = G[aux][i].first;
            int cost= G[aux][i].second;
            if(d[nod] == -1)
            {
                d[nod]=d[aux]+cost;
                q.push(nod);
            }
        }
    }

}

int main()
{    fin>>N>>M>>X>>Y;

    for(int i = 1 ; i <= M ; ++ i)
    {
        fin>>A>>B>>C;
        G[A].push_back(make_pair(B, C));
        G[B].push_back(make_pair(A, -C));
    }
    bfs();
   fout<<d[Y];
    return 0;
}
