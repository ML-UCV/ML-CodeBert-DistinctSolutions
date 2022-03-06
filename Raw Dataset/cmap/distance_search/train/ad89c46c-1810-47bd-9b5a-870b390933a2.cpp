#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair <ll,ll> pii;







int n, st = 1;

pii a[100010];

set<pii> S;

double ans = 2*(1e9);



bool cmp(pii a, pii b){return a.second < b.second;}

double dist(pii a, pii b){

    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));

}



int main(){

    ifstream cin ("cmap.in");

    ofstream cout ("cmap.out");

    cin >> n;

    for (int i=1; i<=n; i++) cin >> a[i].first >> a[i].second;

    sort(a+1, a+1+n, cmp);

    S.insert(a[1]);

    for (int i=2; i<=n; i++){

        while (st < i && a[i].second - a[st].second > ans)

            S.erase(a[st++]);

        for (set<pii>::iterator it = S.lower_bound({a[i].first - ans, a[i].second - ans}); it != S.end() && a[i].first + ans >= it->first; it++)

            ans = min(ans, dist(a[i], *it));

        S.insert(a[i]);

    }

    cout << fixed << setprecision(6) << ans;

    return 0;

}
