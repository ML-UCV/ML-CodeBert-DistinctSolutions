#include <bits/stdc++.h>
using namespace std;





typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

ifstream fin("inversmodular.in");
ofstream fout("inversmodular.out");

ll a, n, inv, ins;

void euclid(ll &x, ll &y, ll a, ll b) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }

    euclid(x, y, b, a % b);
    ll aux = x;
    x = y;
    y = aux - y * (a / b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    fin >> a >> n;

    euclid(inv, ins, a, n);

    if (inv < 0) {
        inv = inv + n;
    }
    fout << inv;

    return 0;
}
