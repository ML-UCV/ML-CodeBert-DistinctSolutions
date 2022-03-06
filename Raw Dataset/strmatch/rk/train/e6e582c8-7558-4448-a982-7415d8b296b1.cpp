#include <bits/stdc++.h>


using namespace std;

ifstream r("strmatch.in");

ofstream w("strmatch.out");

const int base=73, mod1=100007, mod2=100021;

string a, b;

int n, m, h1, h2, x, y;

char match[2000001];

int main()

{

    r>>a>>b;

    n = a.size();

    m = b.size();

    x = y = 1;

    h1 = h2 = 0;

    for (int i = 0; i < n; i++)

    {

        h1 = (h1 * base + a[i]) % mod1;

        h2 = (h2 * base + a[i]) % mod2;

        if (i != 0)

        {

            x = (x * base) % mod1,

            y = (y * base) % mod2;

        }

    }



    if (n > m)

    {

        w<<0;

        return 0;

    }

    int hash1 = 0, hash2 = 0;

    for (int i = 0; i < n; i++)

    {

        hash1 = (hash1 * base + b[i]) % mod1;

        hash2 = (hash2 * base + b[i]) % mod2;

    }

    int nr = 0;

    if (hash1 == h1 && hash2 == h2)

        match[0] = 1, nr++;



    for (int i = n; i < m; i++)

    {

        hash1 = ((hash1 - (b[i - n] * x) % mod1 + mod1) * base + b[i]) % mod1;

        hash2 = ((hash2 - (b[i - n] * y) % mod2 + mod2) * base + b[i]) % mod2;



        if (hash1 == h1 && hash2 == h2)

        {

            match[ i - n + 1 ] = 1;

            nr++;

        }

    }

    w<<nr<<"\n";

    nr = 0;

    for (int i = 0; i < m && nr < 1000; i++)

    {

        if (match[i])

        {

            nr++;

            w<<i<<" ";

        }

    }

    return 0;

}
