#include <bits/stdc++.h>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

int n, m, x, y;
vector< pair<int, int> > muchii[30005];
int dist[30005];
int vizit[30005];

void Citire()
{
    int a, b, km;
    fin>>n>>m>>x>>y;
    while(m--)
    {
        fin>>a>>b>>km;
        if(a > b) swap(a, b);
        muchii[a].push_back({b,km});
        muchii[b].push_back({a,-km});
    }
}

void BFS()
{
    int nr, i, distanta;
    queue <int> coada;
    coada.push(x);
    vizit[x]=1;
    while(!coada.empty())
    {
        nr = coada.front();
        coada.pop();
        for( auto w : muchii[nr])
        {
            i = w.first;
            distanta = w.second;
            if(!vizit[i])
            {
                vizit[i] = 1;
                dist[i] = dist[nr] + distanta;
                coada.push(i);
                if(i == y)
                {
                    fout<<dist[y]<<"\n";
                    return;
                }
            }
        }
    }
}

int main()
{
    Citire();
    BFS();
    return 0;
}
