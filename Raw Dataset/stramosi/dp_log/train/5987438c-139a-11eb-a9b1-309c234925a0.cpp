#include <bits/stdc++.h>







using namespace std;



ifstream f("stramosi" ".in");

ofstream g("stramosi" ".out");



typedef long long ll;

typedef long double ld;

typedef pair<ll,ll> pi;

typedef pair<ld,ld> pct;



const ll inf = 1LL << 60;

const ll mod = 1e9 + 7;

const ld eps = 1e-9;





void add(ll &a , ll b)

{

    a += b;

    a %= mod;

}



void sub(ll &a, ll b)

{

    a = (a - b + mod) % mod;

}



int n, m, pd[20][250010], x, y;



int main()

{

    f >> n >> m;

    for(int i = 1; i <= n; ++i)

        f >> pd[0][i];

    for(int i = 1; i <= 18; ++i)

        for(int j = 1; j <= n; ++j)

            pd[i][j] = pd[ i - 1 ][ pd[i - 1][j] ];

    while(m--)

    {

        f >> x >> y;

        for(int i = 0; i <= 18; ++i)

            if(y & (1 << i))

                x = pd[i][x];

        g << x << '\n';

    }

    f.close();

    g.close();

    return 0;

}
