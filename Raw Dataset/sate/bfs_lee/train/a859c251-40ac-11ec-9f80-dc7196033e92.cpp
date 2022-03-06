#include <bits/stdc++.h>

using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

const int N = 3e4 + 1;
int n, m, x, y, dist, start, finish, d[N]; /// d[i] = dist. de la satul start la satul i
vector<pair<int, int>> c[N];

void bfs(){
    queue<int> q;
    q.push(start);
    d[start] = 0;
    while(!q.empty()){
        int sat = q.front();
        for(pair<int, int> y: c[sat]){
            if(d[y.first] == -1){
                if(y.first > sat)
                    d[y.first] = d[sat] + y.second;
                else
                    d[y.first] = d[sat] - y.second;

                q.push(y.first);
            }
        }

        q.pop();
    }
}

int main(){
    f >> n >> m >> start >> finish;
    for(int i = 0; i < m; i++){
        f >> x >> y >> dist;
        c[x].push_back({y, dist});
        c[y].push_back({x, dist});
    }

    f.close();
    for(int i = 1; i <= n; i++)
        d[i] = -1;

    bfs();
    g << d[finish];
    g.close();
}
