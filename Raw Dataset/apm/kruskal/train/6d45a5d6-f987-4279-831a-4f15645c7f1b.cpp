#include <fstream>
#include <algorithm>
using namespace std;

ifstream in("apm.in");

ofstream out("apm.out");

int sef[200001];

struct ura

{

    int x,y,cost;

};

ura v[200001],ans[200001];

bool cmp(ura a,ura b)

{

    return a.cost<b.cost;

}

int sefsuprem (int i)

{

    if(sef[i]==i)

    {

        return i;

    }

    return sef[i]=sefsuprem(sef[i]);

}

int main()

{

    int n,m,i,cnt=0;

    in>>n>>m;

    for(i=1; i<=m; i++)

    {

        in>>v[i].x>>v[i].y>>v[i].cost;

    }

    for(i=1; i<=n; i++)

    {

        sef[i]=i;

    }

    sort(v+1,v+m+1,cmp);

    int k=0;

    for(i=1; i<=m; i++)

    {

        if(sefsuprem(v[i].x)!=sefsuprem(v[i].y))

        {

            sef[sefsuprem(v[i].y)]=v[i].x;

            cnt+=v[i].cost;

            ans[++k].x=v[i].x;

            ans[k].y=v[i].y;

        }

    }

    out<<cnt<<'\n'<<k<<'\n';

    for(i=1; i<=k; i++)

    {

        out<<ans[i].x<<" "<<ans[i].y<<'\n';

    }

    return 0;

}
