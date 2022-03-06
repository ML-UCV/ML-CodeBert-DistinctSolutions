#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



struct Muchii{

    int x, y, cost;

}muchii[400005];



struct{

    int x, y;

}bune[400005];



int n, m, t[200005], s, k, rang[200005];



bool compare(Muchii a, Muchii b)

{

    return a.cost < b.cost;

}



void citire()

{

    fin >> n >> m;

    for(int i = 1; i <= m; i++)

        fin >> muchii[i].x >> muchii[i].y >> muchii[i].cost;

    sort(muchii + 1, muchii + m + 1, compare);

    for(int i = 1; i <= n; i++)

        rang[i] = 1;

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

    if(rang[x] > rang[y])

        t[y] = x;

    else

    {

        t[x] = y;

        if(rang[x] == rang[y])

            rang[y]++;

    }

}







int main()

{

    citire();

    for(int i = 1; i <= m; i++)

    {

        int tatal_x = radacina(muchii[i].x);

        int tatal_y = radacina(muchii[i].y);

        if(tatal_x != tatal_y)

        {

            unire(tatal_x, tatal_y);

            bune[++k].x = muchii[i].x;

            bune[k].y = muchii[i].y;

            s += muchii[i].cost;

        }

    }

    fout << s << '\n' << n - 1 << '\n';

    for(int i = 1; i <= k; i++)

        fout << bune[i].x << ' ' << bune[i].y << '\n';

}
