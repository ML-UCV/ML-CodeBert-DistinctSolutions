#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
vector <pair<int,int>> v[30001];
queue <int> q;
int d[30001];
const int inf=2000000001;
int n,m,x,y;
void bfs()
{
    d[x]=0;
    q.push(x);
    while(!q.empty()){
        int pr=q.front();
        q.pop();
        for(int i=0;i<v[pr].size();i++){
            int k=v[pr][i].first;
            if(d[k]==inf){
                d[k]=(pr>k? d[pr]-v[pr][i].second : d[pr]+v[pr][i].second);
                q.push(k);
            }
        }
    }
}
int main()
{
    f>>n>>m>>x>>y;
    int a,b,c;
    for(int i=1;i<=m;i++){
        f>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    for(int i=1;i<=n;i++)
        d[i]=inf;
    bfs();
    g<<d[y];
    return 0;
}
