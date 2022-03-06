#include <fstream>
#include <algorithm>


using namespace std;

ifstream cin("apm.in");

ofstream cout("apm.out");

int tata[200005],sz[200005],cost=0,cnt=0;

pair<int,pair<int,int> >edge[400005];

pair<int,int> sol[200005];

int daddy(int a){

    if(a==tata[a])

        return a;

    tata[a]=daddy(tata[a]);

    return tata[a];

}

void unite(int a,int b,int c){

    int aa=a;

    int bb=b;

    a=daddy(a);

    b=daddy(b);

    if(a==b)

        return;

    if(sz[a]>sz[b])

        swap(a,b);

    tata[a]=b;

    sz[b]+=sz[a];

    cost+=c;

    sol[++cnt]=make_pair(aa,bb);

}

int main()

{

    int n,m,a,b,c;

    cin>>n>>m;

    for(int i=1;i<=n;i++){

        tata[i]=i;

        sz[i]=1;

    }

    for(int i=1;i<=m;i++){

        cin>>a>>b>>c;

        edge[i]=make_pair(c,make_pair(a,b));

    }

    sort(edge+1,edge+m+1);

    for(int i=1;i<=m;i++){

        unite(edge[i].second.first,edge[i].second.second,edge[i].first);

    }

    cout<<cost<<"\n"<<n-1<<"\n";

    for(int i=1;i<n;i++)

        cout<<sol[i].first<<" "<<sol[i].second<<"\n";

    return 0;

}
