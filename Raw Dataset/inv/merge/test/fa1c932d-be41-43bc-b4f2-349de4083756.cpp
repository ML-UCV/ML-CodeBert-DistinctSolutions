#include <bits/stdc++.h>


using namespace std;

int aux[100005], v[100005];

int mmerge(int st, int dr)
{
    int i, j, k, m = (st+dr) / 2;
    long long nr = 0;

    i = k = st; j = m+1;

    while(i <= m && j <= dr)
    {
        if(v[i] <= v[j])
            aux[k++] = v[i++];
        else
        {
            aux[k++] = v[j++];
            nr += m - i + 1;
        }
    }

    while(i <= m) aux[k++] = v[i++];
    while(j <= dr) aux[k++] = v[j++];

    for(k = st; k <= dr; ++k) v[k] = aux[k];

    return nr % 9917;
}

int msort(int st, int dr)
{
    if(st == dr) return 0;
    int m = (st+dr) / 2;

    int a = msort(st, m);
    int b = msort(m+1, dr);
    return (a + b + mmerge(st, dr))%9917;
}

int main()
{
    ifstream fin("inv.in");
    ofstream fout("inv.out");

    int n, i;
    fin >> n;
    for(i = 0; i < n; ++i) fin >> v[i];

    fout << msort(0, n-1);
}
