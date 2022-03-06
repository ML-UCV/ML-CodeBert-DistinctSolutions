#include <iostream>
#include <fstream>


using namespace std;



ifstream in("schi.in");

ofstream out("schi.out");



const int dim = 30005;



int a[dim],n,aib[dim],rasp[dim];



void update(int poz,int val)

{

    while (poz <= n)

    {

        aib[poz] += val;

        poz += poz& (-poz);

    }

}



int main()

{

    in >> n;

    int log = 1;

    while (log <= n)

    {

        log *= 2;

    }

    log /= 2;

    for (int i=1; i<=n; i++)

    {

        in >> a[i];

        update(i,1);

    }



    for (int i=n; i>=1; i--)

    {

        int baza = 0;

        int off = log,s = 0,ok = 0,rap = 0;

        a[i]--;

        while (off >= 1)

        {

            while (baza + off > n)

            {

                off /= 2;

            }

            s += aib[baza + off];

            if (s <= a[i])

            {

                baza += off;

            }

            else if (s > a[i])

            {

                s -= aib[baza + off];

            }

            off /= 2;

        }

        rasp[baza+1] = i;

        update(baza+1, -1);

    }

    for (int i=1; i<=n; i++)

    {

        out << rasp[i] << "\n";

    }

    return 0;

}
