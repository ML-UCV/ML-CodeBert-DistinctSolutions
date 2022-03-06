#include <fstream>
#include <algorithm>




using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



struct muchie

{

    int x, y, cost;

};



int tata[400005], c, ct, n, m;

muchie v[400005], w[400005];



bool Compara(muchie a, muchie b)

{

    return a.cost < b.cost;

}



void Citire()

{

  int i;

  fin >> n >> m;

  for (i = 1; i <= n; i++)

     tata[i] = i;

  for (int i = 1; i <= m; i++)

      fin >> v[i].x >> v[i].y >> v[i].cost;

}



int Rad(int x)

{

    if (tata[x] != x)

        tata[x] = Rad(tata[x]);

    return tata[x];

}



void Unire(int x, int y)

{

    x = Rad(x);

    y = Rad(y);

    if (x != y)

        if (x < y)

            tata[y] = x;

        else

            tata[x] = y;

}



int Pivotare(muchie a[],int s, int d)

{

    int i = s, j = d, pasi = 0, pasj = 1;

    muchie aux;

    while (i < j)

    {

        if (a[i].cost > a[j].cost)

        {

            aux = a[i];

            a[i] = a[j];

            a[j] = aux;

            pasi = 1 - pasi;

            pasj = 1 - pasj;

        }

        i = i + pasi;

        j = j + pasj;

    }

    return i;

}





void QS(muchie a[], int s, int d)

{

    if (s < d)

    {

        int p = Pivotare(a, s, d);

        QS(a, s, p - 1);

        QS(a, p + 1, d);

    }

}





int main()

{

    int i;

    Citire();



    sort(v + 1, v + m + 1, Compara);

    for (i = 1; i <= m; i++)

        if (Rad(v[i].x) != Rad(v[i].y))

        {

            Unire(v[i].x, v[i].y);

            c += v[i].cost;

            w[++ct].x = v[i].x,

            w[ct].y = v[i].y;

        }



    fout << c << '\n' << ct << '\n';



    for (int i = 1; i <= ct; i++)

        fout << w[i].x << ' ' << w[i].y << '\n';



    return 0;

}
