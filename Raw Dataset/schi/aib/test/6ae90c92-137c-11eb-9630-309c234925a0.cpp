#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using ull = unsigned long long;
using ll = long long;
using namespace std;

const int INF = INT_MAX, maxN = 30005, maxStep = (1 << 15);
ll t, n, aib[maxN], place[maxN], ans[maxN], step;

bool viz[maxN];


void update(ll i, ll val){

    while (i <= n){

        aib[i] += val;

        i += (-i & i);

    }

}



ll query(ll i){

    ll ans = 0;

    while (i > 0){

        ans += aib[i];

        i -= (-i & i);

    }

    return ans;

}


ll binarySearch(ll x){

    step = maxStep;

    ll idx = 0;

    while (step){

        if (idx + step <= n and aib[idx + step] <= x){

            if (x - aib[idx + step] != 0 or viz[idx + step] != true){

                x -= aib[idx + step];

                idx += step;

            }

        }

        step >>= 1;

    }

    viz[idx] = true;

    return idx;

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("schi.in");
    ofstream cout("schi.out");


    cin >> n;

    for (int i = 1; i <= n; i++){

        cin >> place[i];

        update(i, 1);

    }

    for (int i = n; i >= 1; i--){

        ll num = binarySearch(place[i]);

        ans[num] = i;

        update(num, -1);

    }

    for (int i = 1; i <= n; i++)

        cout << ans[i] << "\n";

    return 0;
}
