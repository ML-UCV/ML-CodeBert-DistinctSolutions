#include <fstream>
using namespace std;

ifstream fin("schi.in");
ofstream fout("schi.out");

int v[30001], rasp[30001];
int a[120001];

int poz;

void constr(int nod, int st, int dr)
{
    if (st == dr)
        a[nod] = 1;
    else
    {
        int mij = (st+dr)>>1;
        constr(nod<<1, st, mij);
        constr(nod<<1|1, mij+1, dr);
        a[nod] = a[nod<<1] + a[nod<<1|1];
    }
}

void update(int nod, int st, int dr)
{
    if (st == dr)
        a[nod] = 0;
    else
    {
        int mij = (st+dr)>>1;
        if (poz <= mij)
            update(nod<<1, st, mij);
        else
            update(nod<<1|1, mij+1, dr);
        a[nod] = a[nod<<1] + a[nod<<1|1];
    }
}

int queryk(int n, int k)
{
    int nod = 1, st = 1, dr = n, mij;
    while (st != dr)
    {
        mij = (st+dr)>>1;
        if (k <= a[nod<<1])
        {
            dr = mij;
            nod = nod << 1;
        }
        else
        {
            k = k - a[nod<<1];
            st = mij + 1;
            nod = nod << 1 | 1;
        }
    }
    return st;
}

int main()
{
    int i, n;
    fin >> n;
    constr(1, 1, n);
    for (i = 1; i<=n; i++)
        fin >> v[i];
    for (i = n; i>=1; i--)
    {
        poz = queryk(n, v[i]);
        rasp[poz] = i;
        update(1, 1, n);
    }
    for (i = 1; i<=n; i++)
        fout << rasp[i] << '\n';
    return 0;
}
