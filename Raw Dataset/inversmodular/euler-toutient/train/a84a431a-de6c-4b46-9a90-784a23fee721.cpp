#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fast_exp(ll a, ll b, ll MOD){

    if(b==0) return 1;

    if(b==1) return a% MOD;

    if(b%2==1) return a*fast_exp(a, b-1, MOD) % MOD;

    if(b%2==0) return fast_exp(a*a% MOD, b/2, MOD)% MOD;

}

ll phi(ll a){

    ll cur = a;

    for(ll i = 2; i*i<=a; i++){

        if(a%i==0){

            while(a%i==0) a/=i;

            cur = (cur/i)*(i-1);

        }

    }

    if(a>1) cur = cur / a * (a-1);

    return cur;

}

int main(){



    freopen("inversmodular.in", "r", stdin);

    freopen("inversmodular.out", "w", stdout);

    ll n, m;

    scanf("%lld %lld", &n, &m);

    ll x = phi(m)-1, nr = n, ct = 1;

    ct = fast_exp(n, x, m);

    printf("%lld", ct);

}
