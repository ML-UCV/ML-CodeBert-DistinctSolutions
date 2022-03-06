#include <bits/stdc++.h>

using namespace std;

ifstream fin ("schi.in");
ofstream fout ("schi.out");

const int MAX = 1e5 + 14;

int v [MAX];
int tree [MAX << 2];
int ans [MAX];

void build (int nod, int st, int dr)
{
    if (st == dr) tree [nod] = 1;
    else
    {
        int mij = (st + dr) >> 1;
        build(nod * 2, st, mij);
        build(nod * 2 + 1, mij + 1, dr);
        tree [nod] = tree[nod << 1] + tree [nod << 1 | 1];
    }
}

void update (int nod, int st, int dr, int pos, const int ind)
{
    if (st == dr)
    {
        tree[nod] = 0;
        ans[st] = ind;
    }
    else {
        int mij = (st + dr) >> 1;
        if (pos <= tree[nod << 1])
            update (nod * 2, st, mij, pos, ind);
        else
            update (nod * 2 + 1, mij + 1, dr, pos - tree[nod << 1], ind);
        tree [nod] = tree[nod << 1] + tree [nod << 1 | 1];
    }
}

int main() {
    int n;
    fin >> n;
    for (int i = 1; i <= n; ++ i)
        fin >> v [i];
    build(1, 1, n);
    for (int i = n; i >= 1; -- i)
    {
        update(1, 1, n, v [i], i);
    }
    for (int i = 1; i <= n; ++ i)
        fout << ans [i] << '\n';
    return 0;
}
