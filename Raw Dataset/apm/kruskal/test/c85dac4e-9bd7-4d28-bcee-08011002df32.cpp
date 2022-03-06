#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream f ( "apm.in" );

ofstream g ( "apm.out" );

const int NMAX = 200000,MMAX=400000;

struct muchie

{

    int i, j, c;

};

int n, m, cost;

muchie M[MMAX+1];

int CC[NMAX + 1];

int NrM[NMAX];

void citire()

{

    f >> n >> m;



    for ( int i = 1; i <= m; i++ )

        f >> M[i].i >> M[i].j >> M[i].c;

}

void afis()

{

    g << cost << '\n'<<n-1<<'\n';



    for ( int i = 1; i < n; i++ )

    {

        int k = NrM[i];

        g << M[k].i << ' ' << M[k].j << '\n';

    }

}

bool comp ( const muchie &a, const muchie &b )

{

    return a.c < b.c;

}

int grupa ( int i )

{

    if ( CC[i] == 0 )

        return i;



    return CC[i] = grupa ( CC[i] );

}

void Kruskal()

{

    sort ( M + 1, M + m + 1, comp );

    int nm = 0;



    for ( int i = 1; i <= m; i++ )

    {

        int ci = grupa ( M[i].i );

        int cj = grupa ( M[i].j );



        if ( ci != cj )

        {

            cost += M[i].c;

            CC[ci] = cj;

            NrM[++nm] = i;

        }



        if ( nm == n - 1 )

            break;

    }

}

int main()

{

    citire();

    Kruskal();

    afis();

    return 0;

}
