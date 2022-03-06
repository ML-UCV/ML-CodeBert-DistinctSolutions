#include <bits/stdc++.h>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

const int Nmax=30005;

int n, m, a, b, x, y, w;
int D[Nmax];
int Viz[Nmax];
vector<pair<int, int>> G[Nmax];

void BFS(int nod)
{
    for(int i=1; i<=n; i++)
        Viz[i]=0;
    queue<int> Q;
    Q.push(nod);
    Viz[nod]=1;
    D[nod]=0;
    while(!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        for(auto& l:G[x])
        {
            int i=l.first;
            int cost=l.second;
            if(!Viz[i])
            {
                Viz[i]=1;
                D[i]=D[x]+cost;
                Q.push(i);
                if(i==b)
                {
                    fout<<D[b]<<'\n';
                    return;
                }
            }
        }
    }
}

int main()
{
    fin>>n>>m>>a>>b;
    while(m--)
    {
        fin>>x>>y>>w;
        if(x>y)
            swap(x, y);
        G[x].push_back({y, w});
        G[y].push_back({x, -w});
    }
    BFS(a);
}
