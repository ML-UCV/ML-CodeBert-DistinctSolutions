#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
vector<pair<int, int>> adj[100001];
queue<int> coada;
int N,M,X,Y,i,j,D,vizitat[100001], dist[100001];


void BFS()
    {
        int i,distanta;
        coada.push(X);
        vizitat[X]=1;

        while (!coada.empty())
        {
            int nodcurent=coada.front();
            coada.pop();
            for (auto vecin: adj[nodcurent])
            {
                i=vecin.first;
                distanta=vecin.second;
                if (!vizitat[i])
                {
                    vizitat[i]=1;
                    dist[i] = dist[nodcurent] + distanta;
                    coada.push(i);

                    if (Y == i)
                    {
                        g<<dist[Y];
                    }
                }
            }
        }
    }
int main()
{
    f>>N>>M>>X>>Y;
    for (int k=0; k<M; k++)
    {
        f>>i>>j>>D;
        if (i>j) swap(i,j);
        adj[i].push_back({j,D});
        adj[j].push_back({i,-D});
    }

    BFS();
}
