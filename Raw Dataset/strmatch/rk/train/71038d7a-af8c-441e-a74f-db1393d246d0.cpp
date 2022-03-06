#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;



char a[2000001], b[2000001];

int n, m, nr;

int hash1, hash2, p1, p2, h1, h2;

char match[2000001];



void citire()

{

    freopen("strmatch.in", "r", stdin);

    freopen("strmatch.out", "w", stdout);

    scanf("%s\n %s", a, b);

    n=strlen(a);

    m=strlen(b);

}



void comparare()

{

    p1=p2=1;

    hash1=hash2=0;

    for (int i=0;i<n;i++)

    {

        hash1 = (hash1 * 73 + a[i]) % 100007;

        hash2 = (hash2 * 73 + a[i]) % 100021;

        if (i != 0)

            p1 = (p1 * 73) % 100007,

            p2 = (p2 * 73) % 100021;

    }

    for (int i = 0; i < n; i++)

        h1 = (h1 * 73 + b[i]) % 100007,

        h2 = (h2 * 73 + b[i]) % 100021;

    if (h1 == hash1 && h2 == hash2)

        match[0] = 1, nr++;

    for (int i = n; i < m; i++)

    {

        h1 = ((h1 - (b[i - n] * p1) % 100007 + 100007) * 73 + b[i]) % 100007;

        h2 = ((h2 - (b[i - n] * p2) % 100021 + 100021) * 73 + b[i]) % 100021;

        if (h1 == hash1 && h2 == hash2)

            match[ i - n + 1 ] = 1, nr++;

    }

}



void afisare()

{

    cout<<nr<<'\n';

    nr = 0;

    for (int i = 0; i < m && nr < 1000; i++)

        if (match[i])

        {

            nr++;

            cout<<i<<' ';

        }

}



int main()

{

    citire();

    if (n > m)

    {

        cout<<0;

        return 0;

    }

    comparare();

    afisare();

    return 0;

}
