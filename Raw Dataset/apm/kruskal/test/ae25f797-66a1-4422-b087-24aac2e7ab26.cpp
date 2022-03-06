#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;



int n, m, tata[400005];



ifstream fin ("apm.in");

ofstream fout ("apm.out");



struct Muchii{

    int x, y, cost, p;

};

Muchii a[400005];



inline bool Compar (const Muchii A, const Muchii B){

    return A.cost < B.cost;

}



void Read(){

    fin >> n >> m;



    for (int i = 1; i <= m; i++){

        fin >> a[i].x >> a[i].y >> a[i].cost;

        a[i].p = 0;

    }



    sort (a + 1, a + m + 1, Compar);

}



int Find(int x)

{

    int rad, y;

    rad = x;



    while(tata[rad] != 0)

    {

        rad = tata[rad];

    }



    while (x != rad){

        y = tata[x];

        tata[x] = rad;

        x = y;

    }

    return rad;

}



void Union (int x, int y){

    tata[x] = y;

}



void APM (){

    int x, y, sumacosturi = 0, numardemuchii;

    for (int i = 1; i <= m; i++){

        x = Find (a[i].x);

        y = Find (a[i].y);



        if (x != y){

            sumacosturi += a[i].cost;

            Union(x, y);

            a[i].p = 1;

            numardemuchii++;

        }

    }



    fout << sumacosturi << "\n" << n - 1 << "\n";



    for (int i = 1; i <= m; i++){

        if (a[i].p == 1){

            fout << a[i].y << " " << a[i].x << "\n";

        }

    }

}

int main()

{

    Read ();

    APM ();

    return 0;

}
