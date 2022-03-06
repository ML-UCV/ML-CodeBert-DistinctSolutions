#include <bits/stdc++.h>

using namespace std;

ifstream fin  ("sate.in");
ofstream fout ("sate.out");

const int INF = (1<<30);
const int MAXN = 30005;

int dist[MAXN];
vector < pair<int, int> > v[MAXN];
int n, m, x, y, st, dr, sum;

void bfs(int start, int finish){
    for(int i=1; i<=n; i++)
        dist[i]=INF;
    dist[start]=0;

    queue <int> q; int nod, nxt, cst;
    q.push(start);
    while(!q.empty()){
        nod = q.front();
        q.pop();

        if(nod == finish)
            break;

        for(int i=0; i<v[nod].size(); i++){
            nxt = v[nod][i].first;
            cst = v[nod][i].second;

            if(dist[nxt] == INF){

                if(nxt < nod)
                    dist[nxt] = dist[nod] - cst;
                else
                    dist[nxt] = dist[nod] + cst;

                q.push(nxt);
            }
        }
    }
}

int main (){
    fin>>n>>m>>x>>y; if(x > y) swap(x, y);
    while(m--){
        fin>>st>>dr>>sum;
        v[st].push_back({dr, sum});
        v[dr].push_back({st, sum});
    }

    bfs(x, y);
    fout<<dist[y];
    return 0;
}
