#include <bits/stdc++.h>


using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



int n, arbI[30005], v[30005], clasament[30005];



void Update(int pozitie, int element)

{

    while(pozitie <= n)

    {

        arbI[pozitie] += element;

        pozitie += (pozitie & (-pozitie));

    }

}



int Suma(int pozitie)

{

    int s = 0;

    while(pozitie > 0)

    {

        s += arbI[pozitie];

        pozitie -= (pozitie & (-pozitie));

    }

    return s;

}



int CautBin(int pozitie, int element)

{

    int stanga, dreapta, mijloc, poz, suma = 0;

    stanga = 1;

    dreapta = pozitie;

    poz = -1;

    while(stanga <= dreapta)

    {

        mijloc = (stanga + dreapta) / 2;

        suma = Suma(mijloc);

        if(suma == element)

        {

            poz = mijloc;

            dreapta = mijloc - 1;

        }

        else if(suma > element)

            dreapta = mijloc - 1;

        else stanga = mijloc + 1;

    }

    return poz;

}



int main()

{

    fin>>n;

    for(int i = 1; i <= n; i++)

    {

        fin >> v[i];

        Update(i, 1);

    }

    for(int i = n; i >= 1; i--)

    {

        int p = CautBin(n, v[i]);

        Update(p, -1);

        clasament[p] = i;

    }



    for(int i = 1; i <= n; i++)

        fout << clasament[i] << "\n";

    return 0;

}
