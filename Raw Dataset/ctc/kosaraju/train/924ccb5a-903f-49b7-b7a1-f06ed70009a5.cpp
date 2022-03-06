#include <bits/stdc++.h> //Andrei Alexandru a.k.a Sho10





using namespace std;

long long n,m,s1=0;

vector<long long>g[100005],gr[100005];

bitset<100005>viz;

vector<long long>v,res[100005];

void dfs(long long node){

viz[node]=1;

for(auto it : g[node]){

    if(viz[it]==0){

        dfs(it);

    }

}

v.push_back(node);

}

void dfs2(long long node){

viz[node]=1;

res[s1].push_back(node);

for(auto it : gr[node]){

if(viz[it]==0){

    dfs2(it);

}

}

}

int32_t main(){

ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);;

ifstream cin("ctc.in");

ofstream cout("ctc.out");

cin>>n>>m;

for(long long i=1;i<=m;i++)

{

    long long x,y;

    cin>>x>>y;

    g[x].push_back(y);

    gr[y].push_back(x);

}

for(long long i=1;i<=n;i++)

{

    if(!viz[i]){

            dfs(i);

    }

}

viz.reset();

reverse(v.begin(),v.end());

for(auto it : v){

    if(!viz[it]){

            ++s1;

    dfs2(it);

    }

}

cout<<s1<<'\n';

for(long long i=1;i<=s1;i++)

{

    for(auto it : res[i]){

        cout<<it<<' ';

    }

    cout<<'\n';

}

}
