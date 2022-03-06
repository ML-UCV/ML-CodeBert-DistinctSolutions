#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



int vf, muchii, ct;

long long Suma;

int Tata[200005], Dimensiune[200005];



pair < int, int > Perechi[400005];



struct elemente

{

    int x, y, cost;



} V[400005];



inline bool cmp( elemente a, elemente b )

{

    return a.cost < b.cost;

}



inline int Find( int Nod )

{

    if( Nod != Tata[Nod] )

        Tata[Nod] = Find(Tata[Nod]);

    return Tata[Nod];

}



void Unire( int x, int y )

{

    x = Find(x);

    y = Find(y);



    if( Dimensiune[x] < Dimensiune[y] )

    {

        Dimensiune[y] += Dimensiune[x];

        Tata[x] = y;

    }

    else

    {

        Dimensiune[x] += Dimensiune[y];

        Tata[y] = x;

    }



}



void Kruskal()

{



    for( int i = 1; i <= muchii; ++ i )

    {

        int tata_x = Find(V[i].x);

        int tata_y = Find(V[i].y);



        if( tata_x != tata_y )

        {

            Unire( tata_x, tata_y );



            Suma += V[i].cost;

            Perechi[++ ct].first = V[i].x;

            Perechi[ct].second = V[i].y;

        }

    }



}



int main()

{

    fin >> vf >> muchii;

    for( int i = 1; i <= muchii; ++ i )

        fin >> V[i].x >> V[i].y >> V[i].cost;



    sort( V + 1, V + muchii + 1, cmp );



    for(int i = 1; i <= vf; ++ i)

        Tata[i] = i, Dimensiune[i] = 1;



    Kruskal();



    fout << Suma << "\n" << ct << "\n";

    for(int i = 1; i <= ct; ++ i)

        fout << Perechi[i].second << " " << Perechi[i].first << "\n";



    return 0;

}
