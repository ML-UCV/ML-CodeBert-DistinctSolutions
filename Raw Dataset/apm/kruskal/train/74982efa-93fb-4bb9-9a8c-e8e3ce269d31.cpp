#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



int Tata[200005], Rank[400005];



pair < int, int > Perechi[400005];



struct elemente

{

    int x, y, cost;



}V[400005];



bool Crescator(elemente a, elemente b)

{

    return a.cost < b.cost;

}



int Gasit( int Nod )

{

    while( Nod != Tata[Nod] )

        Nod = Tata[Nod];



    return Nod;

}



void Unire( int a, int b )

{

    if( Rank[a] < Rank[b] )

        Tata[a] = b;

    else if( Rank[a] > Rank[b] )

        Tata[b] = a;

    else if( Rank[a] == Rank[b] )

    {

        Tata[a] = b;

        Rank[b] ++;

    }

}



int main()

{

    long long Suma = 0;

    int k = 0;

    int vf, muchii;

    fin >> vf >> muchii;

    for(int i = 1; i <= muchii; i ++)

    {

        fin >> V[i].x >> V[i].y >> V[i].cost;

    }

    for(int i = 1; i <= vf; i ++)

    {

        Tata[i] = i;

        Rank[i] = 1;

    }



    sort( V + 1, V + muchii + 1, Crescator );



    for(int i = 1; i <= muchii; i ++)

    {

        int tata_x = Gasit(V[i].x);

        int tata_y = Gasit(V[i].y);



        if( Tata[tata_x] != Tata[tata_y] )

        {

            Unire( tata_x, tata_y );



            Suma += V[i].cost;

            Perechi[++ k].first = V[i].x;

            Perechi[k].second= V[i].y;

        }

    }



    fout << Suma << "\n";



    fout << vf - 1 << "\n";



    for(int i = 1; i < vf; i ++)

    {

        fout << Perechi[i].second << " " << Perechi[i].first << "\n";

    }



    return 0;

}
