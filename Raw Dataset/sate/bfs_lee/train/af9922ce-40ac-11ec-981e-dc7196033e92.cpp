#include <bits/stdc++.h>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

const int nmax = 50005;
vector <pair <int, int> > G[nmax];

int n, m, dist[nmax], x, y;
bool viz[nmax];
queue <int> coada;
int main(){
    fin >> n >> m >> x >> y;
    for (int i = 1; i <= m; ++i){
        int x, y, z;
        fin >> x >> y >> z;
        G[x].push_back({y, z});
        G[y].push_back({x, z});
    }
    viz[x] = 1;
    coada.push(x);
    while (!coada.empty()){
        int nod = coada.front();
        coada.pop();
        for (auto it : G[nod]){
            if (viz[it.first] == false){
                if (it.first > nod){
                    dist[it.first] = dist[nod] + it.second;
                }
                else{
                    dist[it.first] = dist[nod] - it.second;
                }
                viz[it.first] = true;
                coada.push(it.first);
            }
        }
    }
    fout << abs(dist[y]);
    fin.close();
    fout.close();
    return 0;
}
