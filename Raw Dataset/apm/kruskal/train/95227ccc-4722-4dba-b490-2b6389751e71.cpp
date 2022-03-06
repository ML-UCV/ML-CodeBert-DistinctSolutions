#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



const int MaxN = 200002;

const int MaxM = 400004;



struct Muchie{

    int x, y, cost;

}mu[MaxM], rez[MaxN];

int n, m;

int Tata[MaxN];



void Citire();

bool Compara(const Muchie &a, const Muchie &b);

int Radacina(int nod);

bool Unire(int x, int y);



int main()

{

    Citire();



    int total = 0, k = 0;

    for (int i = 1; i <= m; ++i)

    {

        if (Unire(mu[i].x, mu[i].y))

        {

            rez[++k].x = mu[i].x;

            rez[k].y = mu[i].y;

            total += mu[i].cost;

        }

    }



    fout << total << '\n' << k << '\n';

    for (int i = 1; i <= k; ++i)

    {

        fout << rez[i].x << ' ' << rez[i].y << '\n';

    }

}



bool Unire(int x, int y)

{

    int rx = Radacina(x), ry = Radacina(y);



    if (rx != ry)

    {

        Tata[ry] = rx;

        return true;

    }



    return false;

}



int Radacina(int nod)

{

    if (Tata[nod] == 0) return nod;

    else

    {

        int r = Radacina(Tata[nod]);

        Tata[nod] = r;

        return r;

    }

}



bool Compara(const Muchie &a, const Muchie &b)

{

    return (a.cost < b.cost);

}



void Citire()

{

    fin >> n >> m;

    for (int i = 1; i <= m; ++i)

    {

        fin >> mu[i].x >> mu[i].y >> mu[i].cost;

    }



    sort(mu + 1, mu + m + 1, Compara);

}
