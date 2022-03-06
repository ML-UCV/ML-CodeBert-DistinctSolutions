#include <bits/stdc++.h>

using namespace std;


ifstream fin("inversmodular.in");
ofstream fout("inversmodular.out");

long long unsigned phi(long long unsigned n)
{
    long long unsigned nr = n;

    for(long long unsigned i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            while(n % i == 0)
            {
                n /= i;
            }

            nr = (nr / i) * (i - 1);
            cout<<nr<<'\n';
        }
    }

    if(n != 1)
        nr = (nr / n) * (n - 1);

    return nr;
}

long long unsigned log_pow(long long unsigned base, long long unsigned power, long long unsigned &mod)
{
    if(power == 0 || base == 1)
        return 1;
    if(power == 1)
        return base;

    if(power % 2 == 0)
        return log_pow(base * base % mod, power / 2, mod);
    else
        return (log_pow(base, power - 1, mod) * base) % mod;
}

int main()
{
    long long unsigned n, m;
    fin>>n>>m;

    fout<<log_pow(n, phi(m) - 1, m)<<'\n';

    return 0;
}
