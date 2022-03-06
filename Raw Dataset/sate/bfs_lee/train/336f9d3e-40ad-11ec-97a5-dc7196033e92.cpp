#include <fstream>
#include <iostream>
#include <vector>
#include <queue>

#define maxn 30005
#define INF 0x3f3f3f3f

using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

vector < pair <int, int > > v[maxn];
queue <int> Q;
int n, m, l, r;
int dist[maxn], inQueue[maxn];

int BFS(){

    for(int i = 1; i <= n; ++i) dist[i] = INF;

    Q.push(l);
    dist[l] = 0;

    while(!Q.empty()){

        int u = Q.front();
        Q.pop();

        for(int i = 0; i < v[u].size(); ++i){

            int nod = v[u][i].first;
            int distance = v[u][i].second;

            if(dist[nod] > dist[u] + distance){
                dist[nod] = dist[u] + distance;
                Q.push(nod);
            }
        }
    }

    g << dist[r] << '\n';
}

int main (){

    f >> n >> m >> l >> r;
    for (int i = 1; i <= m; ++i){
        int x, y, d;
        f >> x >> y >> d;

        v[x].push_back(make_pair(y, d));
        v[y].push_back(make_pair(x, -d));
    }

    BFS();

}
