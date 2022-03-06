#include <bits/stdc++.h>
using namespace std;



typedef long long ll;

typedef pair <int, int> pii;

typedef pair <ll, ll> pll;

typedef vector <int> vi;

typedef vector <pii> vii;

typedef vector <ll> vl;

typedef vector <pll> vll;

typedef queue <int> qi;

typedef queue <pii> qii;

typedef queue <ll> ql;

typedef queue <pll> qll;



const int INF = 0x3f3f3f3f;

const int MOD = 1e9 + 9;

const double EPSILON = 1e-10;

const int NMAX = 2.5e5 + 5;

const int LMAX = 22;



ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



int n, m;

int stramosi[LMAX][NMAX];



void init()

{

    for (int i = 1; i < LMAX; ++i)

        for (int j = 1; j <= n; ++j)

            stramosi[i][j] = stramosi[i - 1][stramosi[i - 1][j]];

}



int query(int q, int p)

{

    int i = 0;



    while (p)

    {

        if (p & 1) q = stramosi[i][q];

        p >>= 1;

        ++i;

    }



    return q;

}



void read()

{

    fin >> n >> m;

    for (int i = 1; i <= n; ++i)

        fin >> stramosi[0][i];

}



int main()

{

    read();

    init();



    while (m--)

    {

        int q, p;

        fin >> q >> p;

        fout << query(q, p) << '\n';

    }



    return 0;

}
