#include <bits/stdc++.h>


using namespace std;

ifstream in("schi.in");

ofstream out("schi.out");

int v[30005], t[30005], c[30005], n;

int query(int i)

{

    int s = 0;

    for(i = i; i > 0; i -= (i & (-i)))

        s += t[i];

    return s;

}



void update(int i, int val)

{

    for(i = i; i <= n; i += (i & (-i)))

        t[i] += val;

}



void citire()

{

    in >> n;

    for(int i = 1; i <= n; i++)

    {

        in >> v[i];

        update(i, 1);

    }

}



void f()

{

    for(int i = n; i >= 1; i--)

    {

        int st = 0, dr = n, rez = 0;

        while(st <= dr)

        {

            int mij = (st + dr) / 2;

            if(query(mij) < v[i])

                st = mij + 1, rez = mij;

            else

                dr = mij - 1;

        }

        rez++;

        c[rez] = i;

        update(rez, -1);

    }

    for(int i = 1; i <= n; i++)

        out << c[i] << '\n';

}



int main()

{

    citire();

    f();

    return 0;

}
