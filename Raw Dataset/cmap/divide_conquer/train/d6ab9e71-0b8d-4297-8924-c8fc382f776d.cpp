#include <bits/stdc++.h>
using namespace std;

ifstream in("cmap.in");

ofstream out("cmap.out");



using ll = long long;

using ull = unsigned long long;

using ui = unsigned int;





const int NMax = 1e5 + 5;

const ll inf = 1e18 + 5;

const int mod = 100003;

using zint = int;



int N;

pair<ll,ll> v[NMax],aux[NMax];



ll solve(int,int);

ll dist(pair<ll,ll>,pair<ll,ll>);



int main() {

    in>>N;

    for (int i=1;i <= N;++i) {

        in>>v[i].first>>v[i].second;

    }



    sort(v+1,v+N+1);



    out<<fixed<<setprecision(6)<<sqrt(solve(1,N))<<'\n';



    in.close();out.close();

    return 0;

}



ll solve(int st,int dr) {

    if (st >= dr) {

        return inf;

    }

    if (st == dr-1) {

        ll ans = dist(v[st],v[dr]);

        if (v[st].second > v[dr].second) {

            swap(v[st],v[dr]);

        }

        return ans;

    }



    int mij = (st+dr)>>1, abscisa = v[mij].first;

    ll ans = min(solve(st,mij),solve(mij+1,dr));



    int nrAux = 0,i = st,j = mij+1;

    while (i <= mij || j <= dr) {

        if (j > dr || i <= mij && v[i].second < v[j].second) {

            aux[++nrAux] = v[i++];

        }

        else {

            aux[++nrAux] = v[j++];

        }

    }



    for (int i=st;i <= dr;++i) {

        v[i] = aux[i-st+1];

    }



    nrAux = 0;

    ll root = sqrt(ans);

    for (int i=st;i <= dr;++i) {

        if (abs(v[i].first - abscisa) <= root) {

            aux[++nrAux] = v[i];

        }

    }



    for (int i=1;i <= nrAux;++i) {

        for (int j=i+1;j <= nrAux && j <= i+7;++j) {

            ans = min(ans, dist(aux[i],aux[j]));

        }

    }



    return ans;

}



ll dist(pair<ll,ll> p1,pair<ll,ll> p2) {

    ll dx = (p1.first - p2.first),

        dy = (p1.second - p2.second);

    return dx*dx + dy*dy;

}
