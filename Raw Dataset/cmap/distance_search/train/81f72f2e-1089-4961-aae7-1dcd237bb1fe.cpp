#include <bits/stdc++.h>
using namespace std;

typedef long double ld;







typedef pair<long long, long long> pairll;

bool compare(pairll a, pairll b){return a.second<b.second;}

double ans = 2*(1e9);

pairll a[100010];

int n;

set <pairll> box;



int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    ifstream cin ("cmap.in");

    ofstream cout ("cmap.out");

    cin >> n;

    for (int i=1; i<=n; i++) cin >> a[i].first >> a[i].second;

    sort(a+1, a+1+n, compare);

        box.insert(a[1]);

        int left = 1;

        for (int i=2; i<=n; ++i){

            while (left<i && a[i].second - a[left].second > ans)

                box.erase(a[left++]);

            for(set<pairll>::iterator it=box.lower_bound({a[i].first - ans, a[i].second - ans}); it!=box.end() && a[i].first + ans >= it->first; it++)

                ans = min(ans, sqrt(pow(a[i].first - it->first, 2.0)+pow(a[i].second - it->second, 2.0)));

            box.insert(a[i]);

        }

    cout << fixed << setprecision(6) << ans;

    return 0;

}
