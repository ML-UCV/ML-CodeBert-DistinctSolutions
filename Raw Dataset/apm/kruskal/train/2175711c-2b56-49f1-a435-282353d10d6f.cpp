#include <fstream>
#include <algorithm>




using namespace std;

ifstream cin("apm.in");

ofstream cout("apm.out");

struct muchie

{

    int cost,a,b;

};

bool cmp(const muchie &x,const muchie &y)

{

    return x.cost<y.cost;

}

muchie d[400005];

int t[200005],h[200005];

int findr(int x)

{

    while(x!=t[x])

        x=t[x];

        return x;

}

void unite(int x,int y)

{ if(h[x]==h[y])

{

    ++h[x];

    t[y]=x;

}

    if(h[x]<=h[y])

    {

        t[x]=t[y];

    }

    else

    {

        t[y]=t[x];

    }

}

pair <int,int> ans[400005];

int main()

{

    int n,m;

    cin>>n>>m;

    for(int i=1; i<=n; ++i)

    {

        t[i]=i;

        h[i]=1;

    }

    for(int i=1; i<=m; ++i)

    {

        int xx;

        cin>>xx;

        d[i].a=xx;

        cin>>xx;

        d[i].b=xx;

        cin>>xx;

        d[i].cost=xx;

    }

    sort(d+1,d+m+1,cmp);

    int costt=0,nrm=0;

    for(int i=1; i<=m; ++i)

    {

        int r1=findr(d[i].a),r2=findr(d[i].b);

        if(r1!=r2)

            unite(r1,r2),costt+=d[i].cost,ans[++nrm].first=d[i].a,ans[nrm].second=d[i].b;

    }

    cout<<costt<<'\n'<<nrm<<'\n';

    for(int i=1; i<=nrm; ++i)

        cout<<ans[i].first<<" "<<ans[i].second<<'\n';

    return 0;

}
