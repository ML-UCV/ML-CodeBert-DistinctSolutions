#include<bits/stdc++.h>
using namespace std;



int n,p;

pair<long double,long double> a[100030];

long double d=1e13;

struct cmp {

    bool operator()(int l, int r) {

        return a[l].second<a[r].second;

    }

};

set<int,cmp>S;



long double dist(pair<long double,long double> A, pair<long double,long double> B) {

    return (sqrt((B.first-A.first)*(B.first-A.first)+(B.second-A.second)*(B.second-A.second)));

}



int main() {

    ifstream cin("cmap.in");

    ofstream cout("cmap.out");

    cin>>n;

    for (int i=1; i<=n; ++i) cin>>a[i].first>>a[i].second;

    sort(a+1,a+1+n); p=1; S.insert(1);

    for (int i=2; i<=n; ++i) {

        while (a[i].first-a[p].first>d) {

            S.erase(p); ++p;

        }

        a[0].second=a[i].second-d;

        auto it=S.lower_bound(0);

        for (auto it=S.lower_bound(0); it!=S.end() && abs(a[*it].second-a[i].second)<=d; ++it) {

            long double d2=dist(a[*it],a[i]);

            if (d2<d) d=d2;

        }

        S.insert(i);

    }



    cout<<fixed<<setprecision(10)<<d;



    return 0;

}
