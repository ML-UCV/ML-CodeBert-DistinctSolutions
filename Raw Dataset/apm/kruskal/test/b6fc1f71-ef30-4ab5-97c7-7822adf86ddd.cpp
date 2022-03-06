#include<bits/stdc++.h>
using namespace std;


ifstream fin( "apm.in");
ofstream fout( "apm.out");

typedef vector<int> vi;

vector<tuple<int,int,int>> edges;

int n, m;
vi link(n+1,0);

int find(int x){
    if(link[x]==x) return x;
    int p=find(link[x]);
    link[x]=p;
    return p;
}

void unite(int x, int y){
    x=find(x), y=find(y);
    link[x]=y;
}

void kruscal(){
    sort(edges.begin(),edges.end());
    int cost=0;
    for(int i=1;i<=n;++i)
        link[i]=i;
    vector<pair<int,int>> ans;
    for(auto &t:edges){
        int x,y,c;
        tie(c,x,y)=t;
        if(find(x)!=find(y))
            unite(x, y), cost+=c, ans.push_back({x,y});
    }
    sort(ans.begin(),ans.end());
    fout<<cost<<"\n"<<ans.size()<<"\n";
    for(auto& x:ans)
        fout<<x.second<<" "<<x.first<<"\n";



}

int main(){
    fin>>n>>m;
    link.resize(n+1,-1);
    for(int i=m;i--;){
        int x,y,c;
        fin>>x>>y>>c;


        edges.push_back(make_tuple(c,x,y));
    }
    kruscal();
}
