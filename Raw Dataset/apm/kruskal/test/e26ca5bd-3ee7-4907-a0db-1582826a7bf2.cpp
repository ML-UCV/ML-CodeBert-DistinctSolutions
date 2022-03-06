#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



struct muchie

{

    int i, j, c;

};

int n, m,

    cost;



muchie M[400001];

int CC[200001];

int NrM[200000];



void citire()

{

    f >> n >> m;

    for(int i = 1; i <= m; i++)

        f >> M[i].i >> M[i].j >> M[i].c;

}



void afis()

{

    g << cost << '\n';

    g << n - 1 << '\n';

    for(int i = 1; i < n; i++)

        g << M[NrM[i]].i << ' ' << M[NrM[i]].j << '\n';

}



bool comp(const muchie &a, const muchie &b)

{

    return a.c < b.c;

}



int Find(int i)

{

    if(CC[i] == 0)

        return i;

    return CC[i] = Find(CC[i]);

}



void Kruskal()

{

    sort(M + 1, M + m + 1, comp);

    int nm = 0;

    for(int i = 1; i <= m; i++)

    {

        int ci = Find(M[i].i);

        int cj = Find(M[i].j);

        if(ci != cj)

        {

            cost += M[i].c;

            CC[ci] = cj;

            NrM[++nm] = i;

            if(nm == n - 1)

                break;

        }

    }

}



int main()

{

    citire();

    Kruskal();

    afis();

    return 0;

}
