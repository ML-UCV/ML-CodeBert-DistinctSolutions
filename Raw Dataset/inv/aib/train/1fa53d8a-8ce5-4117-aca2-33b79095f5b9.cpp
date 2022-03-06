#include <bits/stdc++.h>




using namespace std;

ifstream fin("inv.in");
ofstream fout("inv.out");



static const int MOD = 9917;

static const int NMAX = 1e5+5;

int aib[NMAX];
int ind[NMAX];
int v[NMAX];
int n;

int query(int position)
{
    int sum = 0;
    for(int i = position; i>= 1; i-=(i&(-i)))
        sum+=aib[i];
    return sum;
}

void update(int position)
{
    for(int i = position; i<=n; i+=(i&(-i)))
        aib[i]++;
}

bool cmp(const int &a, const int &b)
{
    return v[a] < v[b];
}

int main()
{
    fin >> n;

    for(int i =1; i<=n; ++i)
    {
        fin >> v[i];
        ind[i] = i;
    }
    stable_sort(ind+1,ind+n+1,cmp);

    int sol = 0;
    for(int i = 1; i<=n; ++i)
    {
        int pos = ind[i];

        sol = (sol + pos - query(pos) -1) % MOD;
        update(pos);
    }

    fout << sol;


    return 0;
}
