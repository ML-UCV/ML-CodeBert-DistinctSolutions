#include <bits/stdc++.h>


using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



int n, aib[30005], a[30005], cls[30005];



void Update(int p, int x)

{

    while(p <= n)

    {

        aib[p] += x;

        p += (p & (-p));

    }

}



int Suma(int p)

{

    int s = 0;

    while(p > 0)

    {

        s += aib[p];

        p -= (p & (-p));

    }

    return s;

}



int CB(int p, int x)

{

    int st, dr, mij, poz, suma = 0;

    st = 1;

    dr = p;

    poz = -1;

    while(st <= dr)

    {

        mij = (st + dr) / 2;

        suma = Suma(mij);

        if(suma == x)

        {

            poz = mij;

            dr = mij - 1;

        }

        else if(suma > x)

            dr = mij - 1;

        else st = mij + 1;

    }

    return poz;

}



int main()

{

    int i, p;

    fin >> n;

    for(i = 1; i <= n; i++)

    {

        fin >> a[i];

        Update(i, 1);

    }

    for(i = n; i >= 1; i--)

    {

        p = CB(n, a[i]);

        Update(p, -1);

        cls[p] = i;

    }

    for(i = 1; i <= n; i++)

        fout << cls[i] << "\n";

    fin.close();

    fout.close();

    return 0;

}
