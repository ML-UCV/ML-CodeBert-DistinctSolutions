#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("apm.in");

ofstream g("apm.out");



const int NMax=400005;

pair <int,int> P[NMax];

int n,m,total,TT[200005],Rang[200005],cnt;

struct Muchie

{

    int x,y,cost;

} V[NMax];

bool compare(Muchie a,Muchie b)

{

    return a.cost<b.cost;

}

int Find(int nod)

{

    while(TT[nod]!=nod)

        nod=TT[nod];



    return nod;

}

void Unire(int I,int J)

{

    if(Rang[I]<Rang[J])

        TT[I]=J;



    if(Rang[I]>Rang[J])

        TT[J]=I;



    if(Rang[I]==Rang[J])

    {

        TT[I]=J;

        Rang[J]++;

    }

}

int main()

{

    f>>n>>m;



    for(int i=1; i<=n; i++)

    {

        TT[i]=i;

        Rang[i]=1;

    }



    for(int i=1; i<=m; i++)

        f>>V[i].x>>V[i].y>>V[i].cost;



    sort(V+1,V+m+1,compare);



    for(int i=1; i<=m; i++)

    {

        int Tata_x=Find(V[i].x);

        int Tata_y=Find(V[i].y);



        if(Tata_x!=Tata_y)

        {

            Unire(Tata_x,Tata_y);

            P[++cnt].first=V[i].x;

            P[cnt].second=V[i].y;

            total+=V[i].cost;



        }



    }



    g<<total<<'\n'<<n-1<<'\n';

    for(int i=1;i<n;i++)

        g<<P[i].first<<" "<<P[i].second<<'\n';





    return 0;

}
