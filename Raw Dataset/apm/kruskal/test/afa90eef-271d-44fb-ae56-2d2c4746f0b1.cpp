#include <fstream>
#include <algorithm>


using namespace std;

ifstream cin("apm.in");

ofstream cout("apm.out");

pair<int,pair<int,int> > muchie[400005];

int t[200005],sz[200005],sum=0,sol[200005];

bool mysort(pair<int,pair<int,int> > a,pair<int,pair<int,int> > b){

    return a.second.second<b.second.second;

}

int daddy(int a){

    if(t[a]==a)

        return a;

    t[a]=daddy(t[a]);

    return t[a];

}

bool same(int a,int b){

    a=daddy(a);

    b=daddy(b);

    return (a==b);

}

void unite(int a,int b){

    a=daddy(a);

    b=daddy(b);

    if(sz[a]<sz[b]){

        t[a]=b;

        sz[b]+=sz[a];

    }

    else{

        t[b]=a;

        sz[a]+=sz[b];

    }

}

int main()

{

    int n,m;

    cin>>n>>m;

    for(int i=1;i<=m;i++){

        cin>>muchie[i].first>>muchie[i].second.first>>muchie[i].second.second;

    }

    sort(muchie+1,muchie+m+1,mysort);

    for(int i=1;i<=n;i++){

        sz[i]=1;

        t[i]=i;

    }

    int cnt=0;

    for(int i=1;i<=m;i++){

        if(same(muchie[i].first,muchie[i].second.first)==true)

            continue;

        sum+=muchie[i].second.second;

        unite(muchie[i].first,muchie[i].second.first);

        sol[++cnt]=i;

    }

    cout<<sum<<"\n"<<n-1<<"\n";

    for(int i=1;i<n;i++){

        cout<<muchie[sol[i]].first<<" "<<muchie[sol[i]].second.first<<"\n";

    }

    return 0;

}
