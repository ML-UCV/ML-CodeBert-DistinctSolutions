#include <bits/stdc++.h>


using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");

const int nmax = 30005;

int n, aib[nmax], v[nmax], t[nmax];

void update(int p, int x)

{

    while(p <= n)

    {

        aib[p] += x;

        p += (p&(-p));

    }

}

int Query(int p)

{

    int sum = 0;

    while(p > 0)

    {

        sum += aib[p];

        p -= (p&(-p));

    }

    return sum;

}

int Cauta(int x)

{

    int st = 1, dr = n, val, sol = -1;

    while(st <= dr)

    {

        int mid = (st + dr) / 2;

        val = Query(mid);

        if(val == x)

        {

            sol = mid;

            dr = mid - 1;

        }

        else if(val > x)

            dr = mid - 1;

        else

            st = mid + 1;

    }

    return sol;

}

int main()

{

    fin >> n;

    for(int i = 1; i <= n; ++i)

    {

        fin >> v[i];

        update(i, 1);

    }

    for(int i = n; i > 0; i--)

    {

        int p = Cauta(v[i]);

        t[p] = i;

        update(p, -1);

    }

    for(int i = 1; i <= n; ++i)

        fout << t[i] << "\n";

    return 0;

}
