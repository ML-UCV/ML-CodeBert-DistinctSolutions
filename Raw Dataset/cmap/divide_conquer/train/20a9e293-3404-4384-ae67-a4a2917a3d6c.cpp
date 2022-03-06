#include <bits/stdc++.h>


using namespace std;



ifstream f("cmap.in");

ofstream g("cmap.out");



typedef long long int ll;

const ll inf = 4e18;

vector <pair <ll, ll > > v,x;

int n;



bool cmp(const pair <ll, ll> &X, const pair <ll, ll> &Y){

    return X.second < Y.second;

}



inline ll pow(ll X){

    return X * X;

}



inline ll modul(ll X){

    return max(X, -X);

}



inline ll distance(const pair <ll, ll> &X, const pair <ll, ll> &Y){

    return pow(X.first - Y.first) + pow(X.second - Y.second);

}



ll solve(int lo, int hi){

    int i,j;

    if(hi - lo <= 3){

        ll dist = inf;

        for(i = lo ; i < hi ; i++)

            for(j = i + 1 ; j < hi ; j++)

                dist = min(dist, distance(v[i], v[j]));

        return dist;

    }

    int mid = (lo + hi) / 2;

    ll dist = min(solve(lo,mid), solve(mid, hi));



    int k = 0;

    for(i = lo ; i < hi ; i++)

        if(modul(v[mid].first - v[i].first) < dist)

            x[k++] = v[i];



    sort(x.begin(), x.begin() + k, cmp);



    for(i = 0 ; i < k ; i++)

        for(j = i + 1 ; j < k && j - i < 8; j++)

            dist = min(dist, distance(x[i], x[j]));

    return dist;

}



int main(){

    int i;

    f >> n;

    x.resize(n);

    v.resize(n);



    for(i = 0 ; i < n ; i++)

        f >> v[i].first >> v[i].second;



    sort(v.begin(), v.end());



    g << fixed << setprecision(21) << sqrt((long double)solve(0,n));





    return 0;

}
