#include<bits/stdc++.h>




using namespace std;

ifstream f("apm.in");

ofstream g("apm.out");

int n, m, rang[200020], dad[200200], sum;

vector<pair<int, int>>ans;

struct mch

{

    int x, y, cost;

}v[500201];

bool cmp(mch a, mch b)

{

    return a.cost<b.cost;

}

int Find(int x)

{

    if(dad[x]==x)

        return x;

    return dad[x]=Find(dad[x]);

}

void Union(int x, int y)

{

    if(rang[y]<rang[x])

    {

        dad[y]=x;

        rang[x]+=rang[y];

    }

    else

    {

        dad[x]=y;

        rang[y]+=rang[x];

    }

}

int main()

{

    f>>n>>m;

    for(int i=1; i<=n; i++)

    {

        rang[i]=1;

        dad[i]=i;

    }

    for(int i=1; i<=m; i++)

        f>>v[i].x>>v[i].y>>v[i].cost;

    sort(v+1, v+m+1, cmp);

    for(int i=1; i<=m; i++)

    {

        if(Find(v[i].x)!=Find(v[i].y))

        {

            Union(Find(v[i].x), Find(v[i].y));

            ans.push_back({v[i].x, v[i].y});

            sum+=v[i].cost;

        }

    }

    g<<sum<<'\n';

    g<<ans.size()<<'\n';

    for(int i=0; i<ans.size(); i++)

        g<<ans[i].first<<' '<<ans[i].second<<'\n';

    return 0;

}
