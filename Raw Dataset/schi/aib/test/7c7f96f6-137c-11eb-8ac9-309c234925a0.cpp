#include <iostream>
#include <fstream>


using namespace std;



const int N = 30002;



int AIB[N], *v, *sol;



void Update ( int poz, int x )

{

    while ( poz < N )

    {

        AIB[poz] += x;

        poz = poz + (poz & (-poz));

    }

}



int Suma (int poz)

{

    int s = 0, i = poz;

    while (i > 0)

    {

        s += AIB[i];

        i = i - (i & (-i));

    }

    return s;

}





int Cautare(int st,int dr,int p,int x)

{

    if ( st > dr )

        return p;

    int m = (st + dr)/2;

    if(Suma(m) >= x)

    {

        p = m;

        dr = m - 1;

    }

    else

        st = m + 1;

    return Cautare(st, dr,p, x);

}



int main()

{

    ifstream in ("schi.in");

    ofstream out ("schi.out");



    int poz, n, i;



    in >> n;

    v = new int [n + 1];

    sol = new int [n + 1];

    for ( i = 1; i <= n; i++ )

    {

        Update(i, 1);

        in >> v[i];

    }



    for(i = n ; i > 0; i--)

    {

        poz = Cautare (1, n,0, v[i]);

        sol[poz] = i;

        Update(poz, -1);

    }



    for(i = 1; i <= n; i++)

        out << sol[i] << '\n';



    delete( v );

    delete( sol );



    in.close();

    out.close();



    return 0;

}
