#include <bits/stdc++.h>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



int n,m,total,k;

int tata[400005],rang[400005];

pair<int,int> P[400005];



struct Muchie

{

    int x,y,cost;

}v[400005];



bool Compare(Muchie a,Muchie b)

{

    return a.cost < b.cost;

}



void Read()

{

    f>>n>>m;

    for(int i=1;i<=m;i++)

    {

        f>>v[i].x>>v[i].y>>v[i].cost;

    }



    sort(v+1,v+m+1,Compare);



    for(int i=1;i<=n;i++)

    {

        tata[i]=i;

        rang[i]=1;

    }

    f.close();

}



int Find(int nod)

{

    while(tata[nod] != nod)

        nod = tata[nod];

    return nod;

}



void Uneste(int x,int y)

{

    if(rang[x] < rang[y])

        tata[x] = y;

    if(rang[x] > rang[y])

        tata[y] = x;

    if(rang[x] == rang[y])

    {

        tata[x]=y;

        rang[y]++;

    }

}



void Solve()

{

    for(int i=1;i<=m;i++)

    {

        int tata_x = Find(v[i].x);

        int tata_y = Find(v[i].y);



        if(tata_x != tata_y)

        {

            Uneste(tata_x,tata_y);

            P[++k].first = v[i].x;

            P[k].second = v[i].y;

            total += v[i].cost;

        }

    }

}



void Afisare()

{

    g<<total<<"\n";

    g<<k<<"\n";

    for(int i=1;i<=k;i++)

    {

        g<<P[i].first<<" "<<P[i].second<<"\n";

    }

    g.close();

}

int main()

{

    Read();

    Solve();

    Afisare();

    return 0;

}
