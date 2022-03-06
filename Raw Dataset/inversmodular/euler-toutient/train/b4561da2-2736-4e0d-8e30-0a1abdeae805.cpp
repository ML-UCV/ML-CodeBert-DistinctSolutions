#include <bits/stdc++.h>
typedef unsigned long long ul;
typedef long long ll;
using namespace std;


ll a, n, x;



ll phiCalc(ll n)

{

    ll phi = n;

    for (ll p = 2; p * p <= n; p++)

    {

        if (n % p == 0)

        {

            while (n % p == 0) n /= p;

            phi -= phi / p;



        }

    }

    if (n > 1) phi -= phi / n;

    return phi;

}



ll expon(ll b, ll p)

{

    if (p == 0) return 1;

    else if (p == 1) return b % n;

    else if (p % 2 == 0) return expon((b * b) % n, p / 2) % n;

    else if (p % 2 == 1) return (b % n) * (expon((b * b) % n, (p - 1) / 2) % n);

}


int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
ifstream cin("inversmodular.in");
ofstream cout("inversmodular.out");


cin >> a >> n;




cout << expon(a, phiCalc(n) - 1) % n << "\n";




return 0;
}
