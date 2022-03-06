#include <bits/stdc++.h>


using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");



const int lim = 400005;

int n,m,t[lim],rang[lim],total,k;

pair < int, int >P[lim];



struct Edge

{

    int x,y,c;

} v[lim];



bool comp(Edge a, Edge b)

{

    return a.c < b.c;

}



void citire()

{

    fin>>n>>m;

    for(int i=1 ; i<=m ; i++)

        fin>> v[i].x >> v[i].y >> v[i].c;

    for(int i=1 ; i<=n ; i++)

        t[i]=i, rang[i]=1;

    sort(v+1, v+m+1, comp);

}



int Root(int x)

{

    if(t[x] == x) return x;

    else return t[x]=Root(t[x]);

}



void unit(int a, int b)

{

    if(rang[a] > rang[b]) t[b]=a;

    else if(rang[a] < rang[b]) t[a]=b;

    else

    {

        t[a]=b;

        rang[a]++;

    }

}



void Kruskal()

{

    for(int i=1 ; i<=m ; i++)

    {

        int r1=Root(v[i].x);

        int r2=Root(v[i].y);

        if(r1 != r2)

        {

            unit(r1,r2);

            total += v[i].c;

            k++;

            P[k].first = v[i].y;

            P[k].second = v[i].x;

        }

    }

}



int main()

{

    citire();

    Kruskal();

    fout<<total<<'\n';

    fout<<k<<'\n';

    for(int i=1 ; i<=k ; i++)

        fout<<P[i].first<<" "<<P[i].second<<'\n';

    return 0;

}
