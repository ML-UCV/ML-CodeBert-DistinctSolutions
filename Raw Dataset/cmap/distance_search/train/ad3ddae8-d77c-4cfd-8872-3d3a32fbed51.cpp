#include <bits/stdc++.h>
using namespace std;

ifstream f("cmap.in");

ofstream g("cmap.out");

pair<int,int> p[100010];

set<pair<int,int> > q;

double dist(pair<int,int>,pair<int,int>);

int n,i,j,x,y,D;

double d;

int main()

{

    f>>n;

    for(i=1;i<=n;i++)

    {

        f>>x>>y;

        p[i]={x,y};

    }

    sort(p+1,p+n+1);

    d=dist(p[1],p[2]);

    q.insert({p[1].second,p[1].first});

    q.insert({p[2].second,p[2].first});

    j=1;

    for(i=3;i<=n;i++)

    {

        pair<int,int> P={p[i].second,p[i].first};

        while((double)(p[i].first-p[j].first)>=d)

        {

            q.erase({p[j].second,p[j].first});

            j++;

        }

        D=d+1;

        pair<int,int> Q={P.first-D,-1000000001};

        auto it=upper_bound(q.begin(),q.end(),Q);

        while(it!=q.end()&&it->first-P.first<D)

        {

            d=min(d,dist(P,*it));

            it++;

        }

        q.insert(P);

    }

    g<<fixed<<setprecision(10)<<d;

    return 0;

}

double dist(pair<int,int> u,pair<int,int> v)

{

    return sqrt(1.0*(u.first-v.first)*(u.first-v.first)+1.0*(u.second-v.second)*(u.second-v.second));

}
