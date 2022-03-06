#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
vector < pair<int, int> >v[30005];
int dist[30005];
int dfs(int nod)
{
    int i;
    for(i=0; i<v[nod].size(); i++)
        if(dist[v[nod][i].first]==0)
        {
            if(v[nod][i].first>nod)  dist[v[nod][i].first]=dist[nod]+v[nod][i].second;
            else  dist[v[nod][i].first]=dist[nod]-v[nod][i].second;
            dfs(v[nod][i].first);
        }
}
int main()
{
    int n, m, nodi, nodf, a, b, c, i;
    fin >> n >> m >> nodi >> nodf;
    for(i=1; i<=m; i++)
    {
        fin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    dfs(nodi);
    fout << dist[nodf];
    return 0;
}
