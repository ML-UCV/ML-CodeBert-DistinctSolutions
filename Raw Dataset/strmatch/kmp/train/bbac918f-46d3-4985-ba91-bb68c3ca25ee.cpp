#include <bits/stdc++.h>

using namespace std;

ifstream in("strmatch.in");
ofstream out("strmatch.out");

const int dim = (int) (1e6)* 2 + 1;

char a[dim], b[dim];
int pi[dim], sol[dim], nr;

void precalc()
{
    int m = strlen(a + 1);
    pi[1] = 0;
    int k = 0;
    for(int q = 2;q <= m;q++)
    {
        while(k > 0 && a[k + 1] != a[q])
            k = pi[k];
        if(a[k + 1] == a[q])
            k++;
        pi[q] = k;
    }
}

void match()
{
    int n = strlen(b + 1);
    int m = strlen(a + 1);
    precalc();
    int q = 0;
    for(int i = 1;i <= n;i++)
    {
        while(q > 0 && a[q + 1] != b[i])
            q = pi[q];
        if(a[q + 1] ==b[i])
            q++;
        if(q == m)
        {
            ++nr;
            if(nr <= 1000)
                sol[nr] = i - m;
            q = pi[q];
        }
    }
}

int main()
{
    in>>(a + 1)>>(b + 1);
    match();
    out<<nr<<'\n';
    for(int i = 1;i <= nr && i <= 1000;i++)
        out<<sol[i]<<' ';
    return 0;
}
