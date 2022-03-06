#include <bits/stdc++.h>


using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");

int aib[30005], n, m;

int cls[30005],a[30005];

void update(int p, int x )

{

    while(p<=n)

    {

        aib[p] +=x;

        p+=(p & ( - p ));

    }

}

int suma(int p)

{

    int s = 0;

    while(p > 0)

    {

        s+=aib[p];

        p-=( p & ( - p));

    }

    return s;

}



int caut(int p, int s)

{

    int st, dr, poz, mij,su ;

    st = 1;

    dr = p;

    poz = -1;

    while(st <= dr)

    {

        mij = (st + dr) / 2;

        su = suma(mij);

        if(su == s)

        {

            poz = mij;

            dr = mij - 1;

        }

        else if(su > s) dr = mij - 1;

        else st = mij + 1;

    }

    return poz;

}





int main()

{

    int i, x, op,b;

    fin >> n;

    for(i = 1; i <= n; i ++)

    {

        fin >> a[i];

        update(i,1);

    }

    int poz;

    for(i = n ; i >= 1; i--)

    {

        x = a[i];



        poz = caut(n , x);

        update(poz, - 1);

        cls[poz] = i;

    }





    for(i = 1; i <= n ; i++)

    fout << cls[i]<<"\n";

    fin.close();

    fout.close();

    return 0;

}
