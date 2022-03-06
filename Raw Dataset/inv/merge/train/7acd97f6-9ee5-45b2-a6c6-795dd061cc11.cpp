#include <bits/stdc++.h>
using namespace std;

ifstream f("inv.in");

ofstream g("inv.out");



int n,v[100005],aux[100005],nr;





void mergesort(int l, int r)

{

    if(l >= r)

        return;

    int i, j, loc = l;

    int m = (l + r) / 2;

    mergesort (l, m);

    mergesort (m+1, r);

    i = l;

    j = m + 1;

    while (i <= m && j <= r)

    {

        if (v[i] <= v[j])

        {

            aux[loc++] = v[i++];

        }

        else

        {

            nr = (nr + m - i + 1) % 9917;

            aux[loc++] = v[j++];

        }

    }

    while( i <= m)

    {

        aux[loc++] = v[i++];

    }

    while(j <= r)

    {

        aux[loc++] = v[j++];

    }

    for(int i = l; i <= r; i++)

    {

        v[i] = aux[i];

    }

}



int main()

{

    f >> n;

    for(int i = 1; i <= n; i++)

    {

        f >> v[i];

    }

    mergesort(1, n);

    g << nr;

    f.close();

    g.close();

}
