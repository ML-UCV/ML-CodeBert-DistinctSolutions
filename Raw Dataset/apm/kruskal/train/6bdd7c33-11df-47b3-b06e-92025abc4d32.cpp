#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



const int nMax = 200005;

const int mMax = 400005;

int n, m;

int t[nMax];



struct triplet

{

    int x, y, cost, viz;

};

triplet a[mMax];



bool cmp(const triplet A, const triplet B)

{

    return A.cost < B.cost;

}







void Citire()

{

    fin >> n >> m;

    for (int i = 1; i <= m; i++)

        fin >> a[i].x >> a[i].y >> a[i].cost;

    sort(a + 1, a + m + 1, cmp);

}



void Union(int x, int y)

{

    t[y] = x;

}



int Find(int x)

{

    int aux, rad;

    rad = x;

    while (t[rad])

    {

        rad = t[rad];

    }

    while (t[x])

    {

        aux = t[x];

        t[x] = rad;

        x = aux;

    }

    return rad;

}



void Rezolvare()

{

    int cost, v, w, nrc = n,costt = 0;

    for (int i = 1; i <= m and nrc > 1; i++)

    {

        v = a[i].x;

        w = a[i].y;

        v = Find(v);

        w = Find(w);

        if (v != w)

        {

            Union(v, w);

            a[i].viz = 1;

            costt += a[i].cost;

            nrc--;

        }

    }

    fout << costt << "\n";

    fout << n - 1 << "\n";

    for (int i = 1; i <= m; i++)

        if (a[i].viz == 1)

            fout << a[i].x << " " << a[i].y << "\n";

}



int main()

{

    Citire();

    Rezolvare();

    return 0;

}
