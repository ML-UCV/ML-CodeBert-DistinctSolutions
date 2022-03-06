#include <bits/stdc++.h>
using namespace std;

pair<int64_t, int64_t> euclid(int a, int b) {
    if (b == 0) {
        return make_pair(1, 0);
    }

    auto res = euclid(b, a % b);
    int64_t q = (a / b);

    auto ans = make_pair(res.second, res.first - 1LL * q * res.second);
    return ans;
}

int main() {
    ifstream cin("inversmodular.in");
    ofstream cout("inversmodular.out");

    int a, n; cin >> a >> n;
    int b = n;

    auto res = euclid(a, b);
    int64_t inv = res.first;

    if (inv < 0) {
        inv = (b + inv % b);
    }

    cout << inv << "\n";
}
