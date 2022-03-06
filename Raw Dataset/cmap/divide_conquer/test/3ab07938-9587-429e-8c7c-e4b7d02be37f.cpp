#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>




using namespace __gnu_pbds;
using namespace std;







typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef long long ll;
typedef unsigned long long ull;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< vll > vvll;
typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef vector< pll > vpll;
typedef long double ld;
typedef vector< ld > vld;

const ll MOD2 = 1e9 + 7;
const int MOD = 1e9 + 7;

const ull infull = numeric_limits<unsigned long long>::max();

void fix(int &x, ll MOD) {
    x = (x % MOD);
    if(x < 0) x += MOD;
    return;
}

ll lgput(ll a, ll b, ll MOD) {
    ll ret = 1;
    a %= MOD;
    while(b) {
        if(b&1) ret = ret*a % MOD;
        a = a*a % MOD;
        b >>= 1;
    }

    return ret;
}

ll inv(ll a, ll MOD) {
    return lgput(a, MOD-2, MOD);
}

struct f {
    int a, b;
    f(int _a = 0, int _b = 0) : a(_a) ,b(_b) {}
    ll eval(int x) {
        return 1ll*x*a + b;
    }
};

int binarySearch(int x, vi &v) {
    int pos = 0;
    int l = 1, r = (int)((v).size());
    while(l <= r) {
        int m = l + r >> 1;
        if(v[m] <= x) {
            pos = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return pos;
}

struct pt {
    int x, y, id;
};

struct cmp_x {
    bool operator()(const pt & a, const pt & b) const {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
};

struct cmp_y {
    bool operator()(const pt & a, const pt & b) const {
        return a.y < b.y;
    }
};

int n;
vector<pt> a;

double mindist;
pair<int, int> best_pair;

void upd_ans(const pt & a, const pt & b) {
    double dist = sqrt(1ll*(a.x - b.x)*(a.x - b.x) + 1ll*(a.y - b.y)*(a.y - b.y));
    if (dist < mindist) {
        mindist = dist;
        best_pair = {a.id, b.id};
    }
}
vector<pt> t;

void rec(int l, int r) {
    if (r - l <= 3) {
        for (int i = l; i < r; ++i) {
            for (int j = i + 1; j < r; ++j) {
                upd_ans(a[i], a[j]);
            }
        }
        sort(a.begin() + l, a.begin() + r, cmp_y());
        return;
    }

    int m = (l + r) >> 1;
    int midx = a[m].x;
    rec(l, m);
    rec(m, r);

    merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, t.begin(), cmp_y());
    copy(t.begin(), t.begin() + r - l, a.begin() + l);

    int tsz = 0;
    for (int i = l; i < r; ++i) {
        if (abs(a[i].x - midx) < mindist) {
            for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)
                upd_ans(a[i], t[j]);
            t[tsz++] = a[i];
        }
    }
}

int main() {




        {freopen("cmap"".in","r",stdin);freopen("cmap"".out","w",stdout);};


    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(12);
    srand(time(NULL));

    cin >> n;
    a.resize(n);

    for(int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }

    t.resize(n);
    sort(a.begin(), a.end(), cmp_x());
    mindist = 1E20;
    rec(0, n);

    cout << setprecision(12) << fixed << mindist << '\n';
    return 0;
}
