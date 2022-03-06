#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using ull = unsigned long long;
using ll = long long;
using namespace std;


const int MOD = 9917;
const int INF = INT_MAX;
int t, n, swaps, bit[100005];



void update(int i){

    while (i <= n){

        ++bit[i];

        i += (-i & i);

    }

}



int query(int i){

    int ret = 0;

    while (i > 0){

        ret += bit[i];

        i -= (-i & i);

    }

    return ret % MOD;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("inv.in");
    ofstream cout("inv.out");


    cin >> n;

    vector<pair<int,int> > a(n + 1);

    for (int i = 1; i <= n; i++){

        cin >> a[i].first;

        a[i].second = i;

    }

    sort(1 + (a).begin(),(a).end());

    for (int i = n; i > 0; i--){

        update(a[i].second);

        swaps += query(a[i].second - 1);

        swaps %= MOD;

    }
    cout << swaps;
    return 0;
}
