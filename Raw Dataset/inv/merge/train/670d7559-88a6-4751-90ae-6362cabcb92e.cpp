#include <iostream>
#include <fstream>

using namespace std;

ifstream in("inv.in");
ofstream out("inv.out");

int aux[100001];

long long merge(int v[], int st, int dr)
{
    int stanga, dreapta, k, m = (st + dr) / 2;
    stanga = k = st;
    dreapta = m + 1;
    long long r = 0;
    while (stanga <= m && dreapta <= dr)
    {
        if (v[stanga] <= v[dreapta])
        {
            aux[k++] = v[stanga++];
        }
        else
        {
            aux[k++] = v[dreapta++];
            r += m - stanga + 1;
        }
    }
    while (stanga <= m)
    {
        aux[k++] = v[stanga++];
    }
    while (dreapta <= dr)
    {
        aux[k++] = v[dreapta++];
    }
    for (k = st; k <= dr; k++)
    {
        v[k] = aux[k];
    }
    return r;
}

long long mergesort(int v[], int st, int dr)
{
    if (st == dr)
    {
        return 0;
    }
    int m = (st + dr) / 2;
    long long r = 0;
    r += mergesort(v, st, m);
    r += mergesort(v, m + 1, dr);
    r += merge(v, st, dr);
    return r;
}

int main()
{
    int n;
    in>>n;
    int v[n + 1];
    for(int i=1; i<=n; i++)
        in>>v[i];
    out << mergesort(v,1,n)%9917;
    in.close();
    out.close();
    return 0;
}
