#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pld = pair<ld, ld>;

const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862;
const int inf_int = 1e9 + 5;
const ll inf_ll = 1e18 + 5;
const int NMax = 25e4 + 5;
const int dx[] = {-1,0,0,+1}, dy[] = {0,-1,+1,0};
const double EPS = 1e-8;

int ancestor[20][NMax], lg[NMax];

inline int getAncestor(int node, int pth, int N) {
    if (pth >= N) {
        return 0;
    }

    for (int exp = lg[pth]; exp >= 0; --exp) {
        if ((1<<exp) <= pth) {
            node = ancestor[exp][node];
            pth -= (1<<exp);
        }
    }

    return node;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        int dad;
        cin >> dad;
        ancestor[0][i] = dad;
        lg[i] = lg[i>>1] + 1;
    }

    for (int exp = 1; (1<<exp) <= N; ++exp) {
        for (int i = 1; i <= N; ++i) {
            ancestor[exp][i] = ancestor[exp - 1][ ancestor[exp - 1][i] ];
        }
    }

    for (int i = 1; i <= M; ++i) {
        int q,p;
        cin >> q >> p;

        cout << getAncestor(q, p, N) << '\n';
    }

    return 0;
}
