#include <iostream>
#include <fstream>#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>






using namespace std;

ifstream f ("cmap.in");

ofstream g ("cmap.out");



typedef long long ll;

typedef vector < pair < ll, ll > > vect;

vect X, V(100005);

const ll INF = 4e18;

int n;



ll dist(const pair < ll, ll > & x, const pair < ll, ll > & y) {

    return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);

}



ll ans(int st, int dr)

{

    if (st >= dr - 1) return INF;

    if (dr - st == 2) return dist(X[st], X[st + 1]);

    int mid = (st + dr) / 2;

    ll best = min(ans(st, mid), ans(mid, dr));

    int m = 0;

    for (int i = st; i < dr; i++)

        if (abs(X[i].second - X[mid].first) <= best)

            V[m++] = X[i];

    for (int i = 0; i < m; i++)

        for (int j = i + 1; j < m && j - i < 8; j++)

            best = min(best, dist(V[i], V[j]));

    return best;

}



int main()

{

    f>>n;

    X.resize(n);

    for (int i = 0; i < n; i++)

        f>>X[i].first>>X[i].second;

    sort(X.begin(), X.end());

    g<<fixed<< setprecision(6)<<sqrt(ans(0, n));

    return 0;

}
