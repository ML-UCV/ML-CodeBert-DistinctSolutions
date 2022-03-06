#include <bits/stdc++.h>
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");
int n,m,p,y;

vector<pair<int, int> > g[30100];
int v[30100];


void bfs(int x){

    list<int> q;

    q.push_back(x);
    v[x] = 0;

    while(!q.empty()){

        x = q.front();
        q.pop_front();

        for(int i = 0; i < g[x].size(); i++){
            if(v[(g[x][i]).first] == -1){
                q.push_back((g[x][i]).first);

                if((g[x][i]).first > x)
                    v[(g[x][i]).first] = v[x] + (g[x][i]).second;
                else
                    v[(g[x][i]).first] = v[x] - (g[x][i]).second;
            }
        }

    }

}


int main(){
    fin >> n>>m >>p>>y;
    int t1,t2, d;
    for(int i = 0; i<m; i++){
        fin >>t1>>t2>>d;
        g[t1].push_back(make_pair(t2, d));
        g[t2].push_back(make_pair(t1, d));
    }
    memset(v, -1, sizeof(v));
    bfs(p);
    fout << v[y];
}
