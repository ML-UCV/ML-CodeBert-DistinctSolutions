#include <bits/stdc++.h>



using namespace std;

ifstream fin ("inv.in");
ofstream fout ("inv.out");

int aib[100005], x, n, sol;

struct nr
{
    int val, poz;
};

nr v[100005];

void update (int poz, int val)
{
    for (int i = poz; i <= n; i += (i&(-i)))
    {
        aib[i] += val;
    }
}

int suma (int poz)
{
    int s = 0;
    for (int i = poz; i > 0; i -= (i&(-i)))
    {
        s = (s + aib[i]) % 9917;
    }

    return s;
}

bool cmp1 (nr a, nr b)
{
    if (a.val > b.val) return false;

    if (a.val == b.val && a.poz > b.poz) return false;

    return true;
}

bool cmp2 (nr a, nr b)
{
    if (a.poz > b.poz) return false;

    return true;
}
int main()
{
    fin >> n;

    for (int i = 1; i <= n; i++)
    {
        fin >> v[i].val;
        v[i].poz = i;
    }

    sort(v + 1, v + n + 1, cmp1);
    for (int i = 1; i <= n; i++)
        v[i].val = i;

    sort(v + 1, v + n + 1, cmp2);

    for (int i = 1; i <= n; i++)
    {
        sol = (sol + suma(v[i].val)) % 9917;
        update(v[i].val, 1);
    }

    fout << ((1LL * n * (n - 1) / 2) % 9917 - sol + 9917) % 9917 << '\n';
    return 0;
}
