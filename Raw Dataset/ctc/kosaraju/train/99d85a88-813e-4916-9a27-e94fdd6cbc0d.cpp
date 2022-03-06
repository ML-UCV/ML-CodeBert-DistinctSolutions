#include <bits/stdc++.h>


using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

int n, m, x, y, fr[100005];
vector<int> a[100005];
vector<int> tr[100005];
vector<int> s;
set<int> comp[100005];

int r;

void dfs(int nod) {
    fr[nod] = 1;

    for(int vecin: a[nod])
        if (!fr[vecin])
            dfs(vecin);

    s.push_back(nod);
}

void Tdfs(int nod) {
    fr[nod] = 1;
    comp[r].insert(nod);

    for(int vecin: tr[nod])
        if (!fr[vecin])
            Tdfs(vecin);
}

int main()
{
    fin >> n >> m;

    while (fin >> x >> y) {
        a[x].push_back(y);
        tr[y].push_back(x);
    }

    for (int i=1;i<=n;++i)
        if (!fr[i])
            dfs(i);

    reverse(s.begin(), s.end());

    memset(fr, 0, sizeof(fr));

    for (int nod: s)
        if (!fr[nod]) {
            r++;
            Tdfs(nod);
        }

    fout << r << "\n";

    for (int i=1;i<=r;++i, fout << "\n")
        for (int it: comp[i])
            fout << it << " ";
}
