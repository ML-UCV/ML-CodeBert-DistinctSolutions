#include <bits/stdc++.h>

using namespace std;

void invMod(long long a, long long b, long long &x, long long &y) {
    if (!b)
        x = 1, y = 0;
    else {
        long long x0, y0;

        invMod(b, a % b, x0, y0);

        x = y0;
        y = x0 - (a / b) * y0;
    }
}

int main() {
    ifstream cin("inversmodular.in");
    ofstream cout("inversmodular.out");

    long long a, n, inv, y;
    cin >> a >> n;

    invMod(a, n, inv, y);
    if (inv < 0) inv = n + inv % n;

    cout << inv;
    return 0;
}
