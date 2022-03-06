#include<iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>

using namespace std;

ifstream f("cmap.in");
ofstream g("cmap.out");

pair<long long, long long> v[100006];
pair<long long, long long> a[100006];
pair<long long, long long> b[100006];

long long n, i;

long long distanta(pair<long long, long long> P, pair<long long, long long> Q)
{
    long long rezultat = (P.second - Q.second) * (P.second - Q.second) + (P.first - Q.first) * (P.first - Q.first);

    return rezultat;
}

void ordoneaza(long long st, long long mij, long long dr)
{
    long long i = st;
    long long j = mij + 1;
    long long poz = st - 1;
    while (i <= mij && j <= dr)
    {
        if (v[i].second < v[j].second)
        {
            ++poz;
            a[poz] = v[i];
            ++i;
        }
        else
        {
            ++poz;
            a[poz] = v[j];
            ++j;
        }
    }
    while (i <= mij)
    {
        ++poz;
        a[poz] = v[i];
        ++i;
    }
    while (j <= dr)
    {
        ++poz;
        a[poz] = v[j];
        ++j;
    }
    for (i=st; i<=dr; i++)
    {
        v[i] = a[i];
    }
}

long long cautaPuncte(long long st, long long dr)
{
    long long x, y, z;

    if (dr - st == 1)
    {
        ordoneaza(st, st, dr);
        x = distanta(v[st], v[dr]);
        return x;
    }
    if (dr - st == 2)
    {
        ordoneaza(st, st, st + 1);
        ordoneaza(st, st + 1, dr);
        x = distanta(v[st], v[st+1]);
        y = min(distanta(v[st], v[dr]), distanta(v[st+1], v[dr]));

        return min(x, y);
    }

    long long mij = (st + dr) / 2;

    x = cautaPuncte(st, mij);
    y = cautaPuncte(mij + 1, dr);
    long long rezultat = min(x, y);

    ordoneaza(st, mij, dr);

    long long i,j;

    long long poz = 0;

    for (i=st; i<=dr; i++)
    {
        x = v[mij].first - v[i].first;
        if (abs(x) <= rezultat)
        {
            ++poz;
            b[poz] = v[i];
        }
    }
    for (i=1; i < poz; i++)
    {
        long long mini = min(poz, i + 7);

        for (j=i+1; j <=mini; j++)
        {
            x = distanta(b[i], b[j]);

            rezultat = min(rezultat, x);
        }
    }

    return rezultat;
}

int main()
{
    long long x, y;

    f >> n;

    for (i=1; i<=n; i++)
    {
        f >> x >> y;
        v[i].first = x;
        v[i].second = y;
    }

    sort(v + 1, v + n + 1);

    long long rezultat = cautaPuncte(1, n);

    g << setprecision(6) << fixed << sqrt(rezultat);

    return 0;
}
