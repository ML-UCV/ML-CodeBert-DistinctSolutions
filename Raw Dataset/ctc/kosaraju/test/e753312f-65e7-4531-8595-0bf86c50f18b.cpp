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



const ll MOD = 998244353;



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



using Matrix = vvi;



Matrix mult(Matrix a, Matrix b) {

    assert(a[0].size() == b.size());



    Matrix ret(a.size(), vector< int >(b[0].size()));



    for(int i = 0; i < a.size(); ++i) {

        for(int j = 0; j < b[0].size(); ++j) {

            for(int k = 0; k < a[0].size(); ++k) {

                ret[i][j] += ((1ll*a[i][k]*b[k][j])%MOD);

                if(ret[i][j] >= MOD) ret[i][j] -= MOD;

            }

        }

    }



    return ret;

}



const double PI = acos(-1);

const double eps = 1e-7;



const int MAXN = 1e5 + 10;

vi gr[MAXN];

vi gri[MAXN];

int viz[MAXN];

vi v;

vvi ctc;



void dfs1(int node) {

    viz[node] = 1;

    for(auto &x : gr[node]) {

        if(!viz[x])

        dfs1(x);

    }



    v.emplace_back(node);

}



void dfs2(int node) {

    ctc.back().emplace_back(node);



    viz[node] = 0;

    for(auto &x : gri[node]) {

        if(viz[x]) {

            dfs2(x);

        }

    }

}



int main() {
        {freopen("ctc"".in","r",stdin);freopen("ctc"".out","w",stdout);};





    ios::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    cout.precision(12);

    srand(time(NULL));



    int n, m;

    cin >> n >> m;



    for(int i = 0; i < m; ++i) {

        int a, b;

        cin >> a >> b;

        gr[a].emplace_back(b);

        gri[b].emplace_back(a);

    }



    for(int i = 1; i <= n; ++i) {

        if(!viz[i]) {

            dfs1(i);

        }

    }



    reverse((v).begin(),(v).end());



    for(auto &x : v) {

        if(viz[x]) {

            ctc.emplace_back(vi());

            dfs2(x);

        }

    }





    cout << ctc.size() << '\n';

    for(auto &x : ctc) {

        sort((x).begin(),(x).end());

        for(auto &y : x) {

            cout << y << ' ';

        }



        cout << '\n';

    }



    return 0;

}
