#include <fstream>


using namespace std;



int n, aib[30003], a[30003], cls[30003];

ifstream fin("schi.in");

ofstream fout("schi.out");



void Update(int p, int x)

{

    while(p <= n)

    {

        aib[p] += x;

        p+= (p & (-p));

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



int CautareBinara(int p, int s)

{

    int st, dr, mij, poz;

    int suma;

    st = 1;

    dr = p;

    poz = -1;

    while(st <= dr)

    {

        mij = (st + dr) / 2;

        suma = Suma(mij);

        if(suma == s)

        {

            poz = mij;

            dr = mij - 1;

        }

        else

            if(suma > s)

                dr = mij - 1;

            else

                st = mij + 1;

    }

    return poz;

}



int main()

{

    int i, x, poz;

    fin >> n;

    for(i = 1; i <= n; i++)

    {

        fin >> a[i];

        Update(i, 1);

    }

    for(i = n; i >= 1; i--)

    {

        x = a[i];







        poz = CautareBinara(n,x);

        Update(poz,-1);

        cls[poz] = i;

    }



    for(i = 1; i <= n; i++)

        fout << cls[i] << "\n";



    fin.close();

    fout.close();

    return 0;

}
