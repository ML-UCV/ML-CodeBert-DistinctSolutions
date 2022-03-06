#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

const int MAX = 30005;

int n, m, x, y, a, b, c;
int dist[MAX];
bool viz[MAX];

vector < pair <int, int> > G[MAX];
queue <int> Q;

void bfs(){

    Q.push(x);
    viz[x] = 1;
    dist[x] = 0;
    while(!Q.empty()){
        int nod = Q.front();
        Q.pop();
        for(auto it: G[nod]){

            if(!viz[it.first]){

                viz[it.first] = 1;
                if(nod < it.first){
                    Q.push(it.first);
                    dist[it.first] = dist[nod] + it.second;
                }
                else{
                    Q.push(it.first);
                    dist[it.first] = dist[nod] - it.second;
                }
            }
        }
    }
}

int main()
{
    fin >> n >> m >> x >> y;

    for(int i = 1; i <= m; ++i){
        fin >> a >> b >> c;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }

    bfs();

    fout << dist[y];

    return 0;
}
