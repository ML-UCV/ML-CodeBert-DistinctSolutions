#include <bits/stdc++.h>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



const int Nmax=400005;



int n, m, Total, T[Nmax], cnt;



struct Muchie

{

    int x, y, cost;

}G[Nmax];



Muchie A[Nmax];



bool compare(Muchie a, Muchie b)

{

    return a.cost < b.cost;

}



void citire()

{

    fin>>n>>m;

    for(int i=1; i<=m; i++)

    {

        fin>>G[i].x>>G[i].y>>G[i].cost;

    }

    for(int i=1; i<=n; i++)

        T[i]=i;

    sort(G+1, G+m+1, compare);

}



int leaga(int a, int b)

{

    T[a]=T[b];

}



int radacina(int a)

{

    if(a==T[a]) return a;

    else return T[a]=radacina(T[a]);

}



void Kruskal()

{

    int r1, r2;

    for(int i=1; i<=m; i++)

    {

        r1= radacina(G[i].x);

        r2= radacina(G[i].y);

        if(r1!=r2)

        {

            Total+=G[i].cost;

            A[++cnt]=G[i];

            leaga(r1, r2);

        }

    }

}



int main()

{

    citire();

    Kruskal();

    fout<<Total<<'\n';

    fout<<cnt<<'\n';

    for(int i=1; i<n; i++)

        fout<<A[i].y<<" "<<A[i].x<<'\n';

}
