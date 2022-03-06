#include <bits/stdc++.h>
#define NMAX 30010
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

int n, m, start, finish;
vector <pair<int, int>> adj[NMAX];
queue <int> q;
int dist[NMAX];

void read(){
    fin>>n>>m>>start>>finish;
    int x, y, c;
    while(m--){
        fin>>x>>y>>c;
        adj[x].push_back({y, c});
        adj[y].push_back({x, -c});
    }
}

int main(){
    read();
    q.push(start);
    while(!q.empty()){
        int nod = q.front();
        q.pop();

        for(auto vecin: adj[nod]){
            if(dist[vecin.first]==0){
                dist[vecin.first] = vecin.second + dist[nod];
                q.push(vecin.first);
            }
        }

    }
    fout<<dist[finish];
    return 0;
}
