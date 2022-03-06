#include <bits/stdc++.h>







using namespace std;



ifstream f("inversmodular" ".in");

ofstream g("inversmodular" ".out");



typedef long long ll;

typedef long double ld;

typedef pair<int,int> pi;

typedef pair<ll,ll> llp;

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

ll a, b, x,y;



ll gcd(ll a, ll b, ll &x , ll &y)

{

    if(b == 0)

    {

        x = 1;

        y = 0;

        return a;

    }

    ll v = gcd(b, a % b, x, y);

    ll aux = y;

    y = x - (a / b) * y;

    x = aux;

    return v;

}

int main()

{

    f >> a >> b;

    gcd(a,b,x,y);

    g << (x % b + b) % b;

    f.close();

    g.close();

    return 0;

}
