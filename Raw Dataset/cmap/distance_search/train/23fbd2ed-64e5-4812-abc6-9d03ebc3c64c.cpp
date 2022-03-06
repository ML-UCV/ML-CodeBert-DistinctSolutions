#include <bits/stdc++.h>






using namespace std;



ifstream f("cmap.in");

ofstream g("cmap.out");

const int N=100010;

int n,i,k;

pair<double,double> v[N],p;

set<pair<double,double> >M;

double x,y,d,oo=2000000001.0;

inline double dist(pair<double,double> a,pair<double,double> b)

{

    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));

}



int main()

{

    f>>n;

    for(int i=0;i<n;i++)

    {

        f>>x>>y;

        v[i]=make_pair(x,y);

    }

    sort(v,v+n);

    M.insert(make_pair(v[0].second,v[0].first));

    d=2000000001.0*sqrt(2.0);

    for(i=1;i<n;i++)

    {

        p=make_pair(v[i].second,v[i].first);

        while(v[i].first-v[k].first>=d)

        {

            M.erase(make_pair(v[k].second,v[k].first));

            k++;

        }

        set<pair<double,double> >::iterator it=M.lower_bound(make_pair(p.first-d-1.0,-oo));

        for(;it!=M.end()&&it->first-p.first<=d;it++)

            d=min(d,dist(*it,p));

        M.insert(p);



    }

    g<<fixed<<setprecision(10)<<d;

    return 0;

}
