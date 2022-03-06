#include <bits/stdc++.h>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

vector < pair<int,int> > graf[100100];
queue <int> Q;
int n,m,x1,ye,x,y,d,viz[30100],dist[30100];

void bfs(int q){
    viz[q] = 1;
    Q.push(q);
    while(!Q.empty()){
        int t = Q.front();
        Q.pop();
        viz[t] = 1;
        for (int i=0; i<graf[t].size(); i++){
            int nodc = graf[t][i].first;
            int dis = graf[t][i].second;
            if (!viz[nodc]){
                if (t > nodc) //daca satul e mai la stanga de precedent, scadem dist
                    dist[nodc] = dist[t] - dis;
                else
                    dist[nodc] = dist[t] + dis;
                Q.push(nodc);
            }
            if (nodc == ye){
                fout << dist[nodc];
                return;
            }
        }
    }
}

int main()
{
    fin >> n >> m >> x1 >> ye;
    for (int i=0; i<m; i++){
        fin >> x >> y >> d;
        graf[y].push_back(make_pair(x,d));
        graf[x].push_back(make_pair(y,d));
    }

    bfs(x1);


    return 0;
}
