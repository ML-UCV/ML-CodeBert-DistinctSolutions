#include <bits/stdc++.h>
using namespace std;

ifstream in("ctc.in");

ofstream out("ctc.out");

const int NMAX=100005;

bool viz[NMAX];

vector<int>v[NMAX],g[NMAX],sol;

vector<vector<int>>grf;

int n,m,a,b,i;

void dfs(int nod,const auto &ad,int ok){

    viz[nod]=1;

    if(!ok)grf.back().push_back(nod);

    for(int x:ad[nod])

        if(!viz[x])dfs(x,ad,ok);

    if(ok)sol.push_back(nod);

}

int main(){

    in>>n>>m;

    while(m--)

        in>>a>>b,v[a].push_back(b),g[b].push_back(a);

    for(i=1;i<=n;i++)

        if(!viz[i])dfs(i,v,1);

    memset(viz,0,sizeof(viz));

    for(i=sol.size()-1;i>=0;i--)

        if(!viz[sol[i]])

            grf.push_back(vector<int>()),dfs(sol[i],g,0);

    out<<grf.size()<<'\n';

    for(auto x:grf){

        for(auto y:x)

            out<<y<<" ";

        out<<'\n';

    }

}
