#include <bits/stdc++.h>
using namespace std;
ifstream f("schi.in");
ofstream g("schi.out");
int arbore[3000001], v[300001], solutie[30010];
int val, poz, n, raspuns;

void actualizare(int nod, int st, int dr)
{
    if (st == dr)
    {
        arbore[nod] = val;
        return;
    }
    int mij = (st + dr) / 2;
    if(poz <= mij)
        actualizare(2 * nod, st, mij);
    else
        actualizare(2 * nod + 1, mij + 1, dr);
    arbore[nod] = arbore[2 * nod] + arbore[2 * nod + 1];
}

void interogare(int nod, int st, int dr)
{
    if (st == dr)
    {
        raspuns = st;
        return;
    }
    int mij = (st + dr)/2;
    if (arbore[2 * nod] < val)
    { val = val - arbore[2 * nod];
        interogare(2 * nod + 1, mij + 1, dr);

    }
    else
        interogare(2 * nod, st, mij);
}
int main() {
    f >> n;
    for(int i = 1; i <= n; i++)
    {
        f >> v[i];
        poz = i;
        val = 1;
        actualizare(1, 1, n);
    }
    int i = n;
    while(i >= 1)
    {
        raspuns = 0;
        val = v[i];
        interogare(1, 1, n);
        solutie[raspuns] = i;
        poz = raspuns;
        val = 0;
        actualizare(1,1,n);
        i--;
    }
    for (int i = 1; i <=n ;i++)
        g << solutie[i] << "\n";
    return 0;
}
