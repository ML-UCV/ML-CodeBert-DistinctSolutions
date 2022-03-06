#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
const int oo = 2e9;
int N, M, st, dest;
int dist[30005];
vector<pair <int, int> > G[30005];
queue <int> Q;

int befeu()
{
    Q.push(st);
    dist[st] = 0;
    while(!Q.empty())
    {
        if(dist[dest])
            return dist[dest];
        int cur = Q.front();
        Q.pop();
        for(int i = 0; i < G[cur].size(); ++i)
        {
            if(!dist[G[cur][i].first])
            {
                if(cur < G[cur][i].first)
                    dist[G[cur][i].first] = dist[cur] + G[cur][i].second;
                else
                    dist[G[cur][i].first] = dist[cur] - G[cur][i].second;
                Q.push(G[cur][i].first);
            }
        }
    }
}

int main()
{
    ifstream in ("sate.in");
    ofstream out ("sate.out");

    in>>N>>M>>st>>dest;
    for(int i = 0; i < M; ++i)
    {
        int a, b, c;
        in>>a>>b>>c;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }

    out<<befeu();

}
