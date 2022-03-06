#include <bits/stdc++.h>


using namespace std;

ifstream in("apm.in");

ofstream out("apm.out");

int n,m,p[400005],h[400005];

vector<pair<int,int>>ans;

struct muchie

{

    int x,y,c;

}v[400005];

bool cmp(muchie a,muchie b)

{

    return a.c<b.c;

}

int find(int x)

{

    int r=x;

    while(p[r]!=r) r=p[r];

    while(p[x]!=r)

    {

        int aux=p[x];

        p[x]=r;

        x=aux;

    }

    return r;

}

void Union(int x,int y)

{

    int rx=find(x);

    int ry=find(y);

    if(rx!=ry)

    {

        if(h[rx]>h[ry]) p[ry]=rx;

        else if(h[rx]<h[ry]) p[rx]=ry;

        else

        {

            p[rx]=ry;

            h[ry]+=h[rx];

        }

    }

}

int apm()

{

    for(int i=1;i<=n;i++) p[i]=i,h[i]=1;

    int cmin=0,k=0;

    for(int i=1;i<=m&&k<n-1;i++)

    {

        if(find(v[i].x)!=find(v[i].y))

        {

            Union(v[i].x,v[i].y);

            cmin+=v[i].c;

            k++;

            ans.push_back({v[i].x,v[i].y});

        }

    }

    return cmin;

}

int main()

{

    in>>n>>m;

    for(int i=1;i<=m;i++)

        in>>v[i].x>>v[i].y>>v[i].c;

    sort(v+1,v+m+1,cmp);

    out<<apm()<<'\n';

    out<<n-1<<'\n';

    for(auto it:ans) out<<it.first<<" "<<it.second<<'\n';

    return 0;

}
