#include <iostream>
#include <fstream>




using namespace std;



ifstream in("schi.in");

ofstream out("schi.out");



int placement[30001], v[30001], aib[30001];

int n;



void update(int val, int poz)

{

    for(int i = poz; i <= n; i += i&-i)

        aib[i] += val;

}



int query(int poz)

{

    int s = 0;



    for(int i = poz; i; i -= i&-i)

        s += aib[i];



    return s;

}



int binarySearch(int s)

{

    int l = 1, r = n, poz = -1, mij = n;



    if(query(mij) == s)

        poz = mij;



    while(l <= r)

    {

        mij = (l+r) >> 1;

        int aux = query(mij);



        if(0)

            cout << "mij:" << mij << "  aux:" << aux;



        if(aux == s)

        {

            poz = mij;

            r = mij-1;

        }

        else

        {

            if(aux > s)

                r = mij-1;

            else

                l = mij+1;

        }

    }



    return poz;

}



int main()

{

    in >> n;



    for(int i = 1; i <= n; i++)

    {

        in >> v[i];

        update(1, i);

    }



    if(0)

    {

        for(int i = 1; i <= n; i++)

        {

            cout << i << ' ' << aib[i] << '\n';

        }

    }



    for(int i = n; i; i--)

    {

        int poz = binarySearch(v[i]);



        if(0)

            cout << " poz:" << poz << '\n';



        update(-1, poz);

        placement[poz] = i;

    }



    for(int i = 1; i <= n; i++)

        out << placement[i] << '\n';

    return 0;

}
