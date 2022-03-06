#include <bits/stdc++.h>

using namespace std;

ifstream fin("inversmodular.in");
ofstream fout("inversmodular.out");


long long Phi(long long n) {
    long long sol = n;

    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;

            sol = (sol / i) * (i - 1);
        }

    if (n != 1)
        sol = (sol / n) * (n - 1);

    return sol;
}

long long lgput(int a, int p, int MOD) {
    int r = 1;
    while(p) {
        if (p % 2)
            r = 1LL * a * r % MOD;

        p /= 2;

        a = 1LL * a * a % MOD;
    }

    return r;
}

int main() {
    long long a, n;
    fin >> a >> n;

    long long p = Phi(n) - 1;

    fout << lgput(a, p, n) << '\n';;
    return 0;
}
