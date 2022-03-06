#include <bits/stdc++.h>






using namespace std;

ifstream f("cmap.in");

ofstream g("cmap.out");

constexpr int nmax=1e5+5;

int n;

pair <int,int> a[nmax];

set<pair<int,int>> v;

double distanta(pair <int, int > a,pair <int, int > b)

{

    return sqrt(1LL*(a.first-b.first)*(a.first-b.first)+1LL*(a.second-b.second)*(a.second-b.second));

}

int main()

{

    f>>n;

    for(int i=1; i<=n; i++)

    {

        f>>a[i].first>>a[i].second;

    }

    sort(a+1,a+n+1);

    double sol=2e9;

    int ind=1;

    for(int i=1; i<=n;i++)

    {

        while(!v.empty() && a[i].first-a[ind].first>=sol)

        {

            v.erase({a[ind].second,a[ind].first});

            ind++;

        }

        int y_Down=a[i].second-(int )(sol);

        int y_Up=a[i].second+(int )(sol);

        set<pair <int, int > >::iterator d=v.lower_bound({y_Down,1e9});

        set<pair <int, int > >::iterator u=v.lower_bound({y_Up,1e9});

        for(set<pair <int, int > >::iterator it=d; it!=u;it++)

        {

            pair <int, int > nr=*it;

            swap(nr.first,nr.second);

            double ans=distanta(nr,a[i]);

            sol=min(sol,ans);

        }

        v.insert({a[i].second,a[i].first});

    }

    g<<setprecision(6)<<fixed;

    g<<sol<<'\n';

    return 0;

}
