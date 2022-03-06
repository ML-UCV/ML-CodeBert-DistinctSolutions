#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n;
vector< pair<ll, ll> > v, r, a(100005);

ll dist(pair<ll, ll> a, pair<ll, ll> b)
{
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

ll rec(ll st, ll dr)
{
    if(dr-st <= 1)
        return 2000000000000000000ll;
    if(dr-st == 2){
        if(r[st] > r[st+1])
            swap(r[st], r[st+1]);
        return dist(v[st], v[st+1]);
    }
    ll m = (st+dr)/2;
    ll ans = min(rec(st, m), rec(m, dr));

    merge(r.begin()+st, r.begin()+m, r.begin()+m, r.begin()+dr, a.begin());
    copy(a.begin(), a.begin()+(dr-st), r.begin()+st);
    int vf = 0;
    for (ll i = st; i < dr; ++i)
        if(abs(r[i].second-v[i].first) <= ans)
            a[vf++] = r[i];

    for (ll i = 0; i < vf-1; ++i)
        for (ll j = i+1; j < vf && j-i < 8; ++j)
            ans = min(ans, dist(a[i], a[j]));
    return ans;
}

int main()
{
    ifstream fin ("cmap.in");
    ofstream fout ("cmap.out");
    fin >> n;
    for (ll i = 1; i <= n; ++i){
        ll x, y;
        fin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    for (vector< pair<ll, ll> >::iterator it = v.begin(); it != v.end(); ++it)
        r.push_back({it->second, it->first});
    fout << fixed << setprecision(10) << sqrt(rec(0, n)) << "\n";
    return 0;
}
