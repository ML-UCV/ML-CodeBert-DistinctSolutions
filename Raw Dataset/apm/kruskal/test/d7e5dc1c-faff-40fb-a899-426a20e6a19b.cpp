#include <bits/stdc++.h> //Andrei Alexandru a.k.a Sho10





using namespace std;

long long n,m,p[200005],second[200005],sum=0;

pair<long long,pair<long long,long long>>g[200005];

vector<pair<long long,long long>>ans;

long long caut(long long x){

if(x==p[x]){

    return x;

}else return p[x]=caut(p[x]);

}

void uni(long long x,long long y){

x=caut(x);

y=caut(y);

if(x!=y){

    if(second[x]<second[y]){

        swap(x,y);

    }

    p[y]=x;

    second[x]+=second[y];

}

}

int32_t main(){

ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);;

ifstream cin("apm.in");

ofstream cout("apm.out");

cin>>n>>m;

for(long long i=1;i<=n;i++)

{

    p[i]=i;

}

for(long long i=1;i<=m;i++)

{

    cin>>g[i].second.first>>g[i].second.second>>g[i].first;

}

sort(g+1,g+m+1);

for(long long i=1;i<=m;i++)

{

    long long x=g[i].second.first,y=g[i].second.second;

    if(caut(x)!=caut(y)){

        uni(x,y);

        sum+=g[i].first;

        ans.push_back(make_pair(x,y));

    }

}

cout<<sum<<'\n';

cout<<n-1<<'\n';

for(auto it : ans){

    cout<<it.first<<' '<<it.second<<'\n';

}

}
