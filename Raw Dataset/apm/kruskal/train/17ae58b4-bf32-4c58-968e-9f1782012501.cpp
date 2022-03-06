#include <algorithm>
#include <iostream>
#include <fstream>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



struct Muchie

{

    int Cost, x, y;

};

Muchie V[400001];

pair <int,int> Pr[400001];

long long Sum, k;

int Tt[400001], Rg[400001], N, M;

void Citire()

{

    f >> N >> M;

    for (int i = 1; i <= M; i++ )

        f >> V[i].x >> V[i].y >> V[i].Cost;

}

int Cmp ( Muchie a1, Muchie a2 )

{

    return a1.Cost < a2.Cost;

}

int VerificareTata(int nod)

{

    while ( Tt[nod] != nod)

        nod = Tt[nod];

    return nod;

}

int Unire( int a1, int a2)

{

    if( Rg[a1] > Rg[a2] )

        Tt[a2] = a1;

    if( Rg[a1] < Rg[a2] )

        Tt[a1] = a2;

    if( Rg[a1] == Rg[a2] )

    {

        Tt[a1] = a2;

        Rg[a2] ++;

    }

}

void Afisare()

{

    g << Sum << endl << k << endl;

    for (int i = 1 ; i<=k ; i++ )

        g << Pr[i].first << " " << Pr[i].second << endl;

}

int main()

{

    Citire();

    sort( V+1, V+M+1, Cmp);

    for ( int i = 1; i <= N; i++ )

    {

        Tt[i] = i;

        Rg[i] = 1;

    }

    for ( int i = 1; i <= M ; i++ )

    {

        int tatax = VerificareTata(V[i].x);

        int tatay = VerificareTata(V[i].y);

        if ( tatax != tatay )

        {

            Unire(tatax, tatay);

            Pr[++k].first = V[i].x;

            Pr[k].second = V[i].y;

            Sum = Sum + V[i].Cost;

        }

    }

    Afisare();

    return 0;

}
