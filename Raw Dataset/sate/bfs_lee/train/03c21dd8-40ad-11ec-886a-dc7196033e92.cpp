#include <bits/stdc++.h>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

vector < pair <int,int> > mv[30005];
queue < pair <int,int> > q;
int viz[30005];
int val[30005];
int n,m,x,y,nr;

int BFS(int v){
    int i;

    viz[v]=1;
    q.push(make_pair(v,0));

    while(!q.empty()){
        v=q.front().first;
        q.pop();

        if(v==y)
            return val[v];

        for(i=0;i<mv[v].size();i++){
            if(!viz[mv[v][i].first]){
                viz[mv[v][i].first]=1;

                if(mv[v][i].first>v)
                    val[mv[v][i].first]=val[v]+mv[v][i].second;
                else
                    val[mv[v][i].first]=val[v]-mv[v][i].second;

                q.push(make_pair(mv[v][i].first,val[mv[v][i].first]));
            }
        }
    }
}

int main(){
    int i,a,b;

    fin>>n>>m>>x>>y;

    for(i=1;i<=m;i++){
        fin>>a>>b>>nr;

        mv[a].push_back(make_pair(b,nr));
        mv[b].push_back(make_pair(a,nr));
    }

    fout<<BFS(x);

    return 0;
}
