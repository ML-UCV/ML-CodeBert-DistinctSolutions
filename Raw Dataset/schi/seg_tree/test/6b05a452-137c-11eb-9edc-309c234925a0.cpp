#include <bits/stdc++.h>


using namespace std;



ifstream in ("schi.in");

ofstream out ("schi.out");



const int MAX = 30001;



int t[3 * MAX], a[MAX], b[MAX];



void create(int p, int st, int dr)

{

    if(st == dr)

    {

        t[p] = 1;

    }

    else

    {

        int m = (st + dr) / 2;

        create(2 * p, st, m);

        create(2 * p + 1, m + 1, dr);

        t[p] = t[2 * p] + t[2 * p + 1];

    }

}



void actualizare(int p, int st, int dr, int c, int poz)

{

    if(st == dr)

    {

        t[p] = 0;

        a[st] = c;

    }

    else

    {

        int m = (st + dr) / 2;

        if(t[2 * p] >= poz)

        {

            actualizare(2 * p, st, m, c, poz);

        }

        else

        {

            actualizare(2 * p + 1, m + 1, dr, c, poz - t[2 * p]);

        }

        t[p] = t[2 * p] + t[2 * p + 1];

    }

}



int main()

{

    int n;

    in >> n;

    for(int i = 1; i <= n; i++)

    {

        in >> b[i];

    }

    create(1, 1, n);

    for(int i = n; i >= 1; i--)

    {

        actualizare(1, 1, n, i, b[i]);

    }

    for(int i = 1; i <= n; i++)

    {

        out << a[i] << "\n";

    }

    return 0;

}
