#include <bits/stdc++.h>
using namespace std;

ifstream f("inv.in");

ofstream g("inv.out");

int v[1000001], v_nou[100001], i, inv, n;

void sortare(int v[], int st, int dr)

{

    if ( st < dr )

    {int m;

    m = (st + dr)/2;

    sortare(v,st,m);

    sortare(v,m+1,dr);

    int i,j,nr;

    i = st; j = m+1;

    nr = 0;

    while ( i <=m && j<=dr)

        if (v[i] <= v[j])

            {nr++;

            v_nou[nr] = v[i];

            i++;}

        else

            {nr++;

            v_nou[nr] = v[j];

            j++;

            inv = (inv + m - i + 1)%9917;

            }

    while (i <= m)

        v_nou[++nr] = v[i++];

    while(j <= dr)

        v_nou[++nr] = v[j++];

    i = 1;

    for (j=st; j<=dr ; j++)

        { v[j] = v_nou[i];

          i++;

        }

    }

}

int main()

{ f>>n;

    for(i=1; i<=n; i++)

        f>>v[i];

    sortare(v,1,n);

    g<<inv;

    return 0;

}
