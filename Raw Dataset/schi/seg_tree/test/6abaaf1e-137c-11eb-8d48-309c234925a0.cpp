#include <fstream>


using namespace std;



ifstream f("schi.in");

ofstream g("schi.out");



struct arbore

{

    int st, dr, val;

};



int n, i, poz[30005], clasament[30005];

arbore a[120005];



void construieste_arbore(const int& p, const int& q, const int& pz)

{

    int mij;



    if(p == q)

    {

        a[pz].st = p;

        a[pz].dr = q;

        a[pz].val = 1;

    }

    else

        if(p < q)

        {

            mij = (p + q) / 2;

            construieste_arbore(p, mij, pz * 2 + 1);

            construieste_arbore(mij + 1, q, pz * 2 + 2);

            a[pz].st = p;

            a[pz].dr = q;

            a[pz].val = a[pz * 2 + 1].val + a[pz * 2 + 2].val;

        }

        else

        {

            a[pz].st = a[pz].dr = -1;

            a[pz].val = 0;

        }

}



int gaseste_pozitia(const int& p, const int& rad)

{

    a[rad].val--;

    if(a[rad].st == a[rad].dr)

        return a[rad].st;

    else

        if(a[rad * 2 + 1].val >= p)

            return gaseste_pozitia(p, rad * 2 + 1);

        else

            return gaseste_pozitia(p - a[rad * 2 + 1].val, rad * 2 + 2);

}



int main()

{

    f >> n;

    for(i = 0; i < n; i++)

        f >> poz[i];

    f.close();



    construieste_arbore(1, n, 0);

    for(i = n - 1; i >= 0; i--)

        clasament[gaseste_pozitia(poz[i], 0)] = i + 1;



    for(i = 1; i <= n; i++)

        g << clasament[i] << '\n';

    g.close();



    return 0;

}
