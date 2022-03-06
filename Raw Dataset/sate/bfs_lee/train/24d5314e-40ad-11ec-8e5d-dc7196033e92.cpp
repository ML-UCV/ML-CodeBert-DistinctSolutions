#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define NMAX 30005
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
int n, m, x, y, a, b, d, dist[NMAX], viz[NMAX], inq[NMAX];
vector < pair<int, int> > g[NMAX];
queue <int> q;

void bfs(int st){
    q.push(st);
    dist[st] = 0;
    viz[st] = 1;
    while(!q.empty()){
        int nod = q.front();
        q.pop();
        inq[nod] = 0;
        for(auto it : g[nod]){
            if(!viz[it.first] && !inq[it.first]){
                viz[it.first] = 1;
                dist[it.first] = dist[nod] + it.second;
                q.push(it.first);
                inq[it.first] = 1;
            }
        }
    }
}
int main()
{
    fin >> n >> m >> x >> y;
    for(int i = 1; i <= m; i++){
        fin >> a >> b >> d;
        g[a].push_back({b, d});
        g[b].push_back({a, -d});
    }
    bfs(x);
    fout << dist[y];
    return 0;
}
