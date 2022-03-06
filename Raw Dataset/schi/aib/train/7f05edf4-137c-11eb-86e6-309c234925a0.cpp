#include <bits/stdc++.h>

using namespace std;

int n, v[30005], aint[120005], sol[30005];

void update(int pos, int nod = 1, int st = 1, int dr = n)
{
    if(st == dr)
        ++aint[nod];
    else{
        int m = (st+dr)/2;
        if(pos <= m)
            update(pos, nod*2, st, m);
        else update(pos, nod*2+1, m+1, dr);
        aint[nod] = aint[nod*2] + aint[nod*2+1];
    }
}

int query(int x, int nod = 1, int st = 1, int dr = n)
{
    if(st == dr)
        return st;
    int m = (st+dr)/2;
    if((m-st+1)-aint[nod*2] >= x)
        return query(x, nod*2, st, m);
    return query(x-((m-st+1)-aint[nod*2]), nod*2+1, m+1, dr);
}

int main()
{
    ifstream fin ("schi.in");
    ofstream fout ("schi.out");
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (int i = n; i >= 1; --i){
        int x = v[i];
        int ans = query(x);
        sol[ans] = i;
        update(ans);
    }
    for (int i = 1; i <= n; ++i)
        fout << sol[i] << "\n";
    return 0;
}
