#include <bits/stdc++.h>


using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

const int nmax = 2000005;

const int p = 73;

const int mod1 = 100007;

const int mod2 = 100021;



char a[nmax], b[nmax];

int na, nb;

int hasha1, hasha2, p1, p2;

char match[nmax];

int main()

{

    fin >> a >> b;

    na = strlen(a);

    nb = strlen(b);

    p1 = p2 = 1;

    hasha1 = hasha2 = 0;

    for(int i = 0; i < na; ++i)

    {

        hasha1 = (hasha1 * p + a[i]) % mod1;

        hasha2 = (hasha2 * p + a[i]) % mod2;

        if(i != 0)

        {

            p1 = (p1 * p) % mod1;

            p2 = (p2 * p) % mod2;

        }

    }

    if(na > nb)

    {

        fout << "0\n";

        return 0;

    }

    int hash1 = 0, hash2 = 0;

    for(int i = 0; i < na; ++i)

    {

        hash1 = (hash1 * p + b[i]) % mod1;

        hash2 = (hash2 * p + b[i]) % mod2;

    }

    int nr = 0;

    if(hash1 == hasha1 && hash2 == hasha2)

        match[0] = 1, nr++;

    for(int i = na; i < nb; ++i)

    {

        hash1 = ((hash1 - (b[i - na] * p1) % mod1 + mod1) * p + b[i]) % mod1;

        hash2 = ((hash2 - (b[i - na] * p2) % mod2 + mod2) * p + b[i]) % mod2;

        if(hash1 == hasha1 && hash2 == hasha2)

            match[i - na + 1] = 1, nr++;

    }

    fout << nr << "\n";

    nr = 0;

    for(int i = 0; i < nb && nr < 1000; ++i)

        if(match[i])

            nr++, fout << i << " ";



    return 0;

}
