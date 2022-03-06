#include <bits/stdc++.h>
using namespace std;

ifstream in("inv.in");
ofstream out("inv.out");

const int mod = 9917;

vector< int > v;
int ans;

void nrInv(int left, int mid, int right) {
    vector< int > rez;

    int i = left, j = mid + 1;
    while(i <= mid && j <= right) {
        if(v[i] <= v[j]) {
            ans += j - mid - 1;
            rez.push_back(v[i]);
            ++i;
        } else {
            rez.push_back(v[j]);
            ++j;
        }
    }

    while(j <= right) {
        rez.push_back(v[j]);
        ++j;
    }
    while(i <= mid) {
        rez.push_back(v[i]);
        ++i;
        ans += right - mid;
    }

    ans %= mod;

    for(int i = 0; i < (int)rez.size(); ++i) {
        v[left + i] = rez[i];
    }
}

void merge(int left, int right) {
    if(left == right) {
        return;
    }

    int mid = (left + right) / 2;
    merge(left, mid);
    merge(mid + 1, right);
    nrInv(left, mid, right);
}

int main() {
    ios::sync_with_stdio(false); in.tie(0); out.tie(0);

    int n; in >> n;

    v.resize(n);
    for(auto &x: v) in >> x;

    merge(0, n - 1);

    out << ans % mod << "\n";

    in.close(); out.close();

    return 0;
}
