#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



const int NMax = 400005;

int n, m, t[NMax], rang[NMax], k, total;



pair <int, int> muchii_ramase[NMax];



struct Muchie{

    int x, y, cost;

}muchii[NMax];



bool compara(Muchie a, Muchie b)

{

    return a.cost < b.cost;

}



void citire()

{

    fin >> n >> m;

    for(int i = 1; i <= m; i++)

        fin >> muchii[i].x >> muchii[i].y >> muchii[i].cost;

}



int radacina(int k)

{

    if(t[k] == 0)

        return k;

    else

    {

        int x = radacina(t[k]);

        t[k] = x;

        return x;

    }

}



void unire(int x, int y)

{

    if(rang[x] < rang[y])

        t[x] = y;

    else

    {

        t[y] = x;

        if(rang[x] == rang[y])

            rang[x]++;

    }

}



void kruskal()

{

    for(int i = 1; i <= m; i++)

    {

        int tata_x = radacina(muchii[i].x);

        int tata_y = radacina(muchii[i].y);

        if(tata_x != tata_y)

        {

            unire(tata_x, tata_y);



            muchii_ramase[++k].first = muchii[i].x;

            muchii_ramase[k].second = muchii[i].y;

            total += muchii[i].cost;

        }

    }

}



void afisare()

{

    fout << total << '\n' << n - 1 << '\n';

    for(int i = 1; i <= k; i++)

        fout << muchii_ramase[i].first << ' ' << muchii_ramase[i].second << '\n';

}



int main()

{

    citire();

    sort(muchii + 1, muchii + m + 1, compara);

    kruskal();

    afisare();

}
