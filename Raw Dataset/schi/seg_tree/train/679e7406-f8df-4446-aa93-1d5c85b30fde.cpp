#include <iostream>
#include <fstream>


using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");



int n, m, val, pos, rez;

int v[30002],sol[30002], Arbore[4 * 30002];





void update(int nod, int stanga, int dreapta)

{

    if (stanga == dreapta)

    {

        Arbore[nod] = val;

        return;

    }

    int mij = (stanga + dreapta) / 2;

    if (pos <= mij)

        update(2 * nod, stanga, mij);

    else

        update(2 * nod + 1, mij + 1, dreapta);

    Arbore[nod] = Arbore[2*nod]+Arbore[2*nod+1];

}



void query(int nod, int stanga, int dreapta)

{

    if (stanga==dreapta)

    {

        rez = stanga;

        return;

    }

    int mij = (stanga + dreapta) / 2;

    if (Arbore[2 * nod] >= val)

        query(2 * nod, stanga, mij);

    else

    {

        val = val - Arbore[2 * nod];

        query(2 * nod + 1, mij + 1, dreapta);

    }

}



int main()

{

    fin >> n;

    for (int i = 1; i <= n; i++)

    {

        fin >> v[i];

        pos = i;

        val = 1;

        update(1, 1, n);

    }

    for (int i = n; i >= 1; i--)

    {

        rez = 0;

        val = v[i];

        query(1, 1, n);

        sol[rez] = i;

        pos = rez;

        val = 0;

        update(1, 1, n);

    }

    for (int i = 1; i <= n; i++)

        fout << sol[i] << "\n";



    return 0;

}
