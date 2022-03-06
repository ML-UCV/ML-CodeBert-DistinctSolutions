#include <bits/stdc++.h>
using namespace std;



ifstream in("ctc.in");

ofstream o("ctc.out");

const int NMAX=100005;

int vi[NMAX];

vector<int>v[NMAX],g[NMAX],sol;

vector<vector<int>>gg;

int n,m,a,b,i;

void d(int nod,auto &ad,int ok){

    vi[nod]=1;

    if(!ok)gg.back().push_back(nod);

    for(int x:ad[nod])

        if(!vi[x])d(x,ad,ok);

    if(ok)sol.push_back(nod);

}

int main(){

    in>>n>>m;

    while(m--)

        in>>a>>b,v[a].push_back(b),g[b].push_back(a);

    for(i=1;i<=n;i++)

        if(!vi[i])d(i,v,1);

    memset(vi,0,sizeof(vi));

    for(i=sol.size()-1;i>=0;i--)

        if(!vi[sol[i]])

            gg.push_back(vector<int>()),d(sol[i],g,0);

    o<<gg.size()<<'\n';

    for(auto x:gg){

        for(int y:x)

            o<<y<<" ";

        o<<'\n';

    }

}
