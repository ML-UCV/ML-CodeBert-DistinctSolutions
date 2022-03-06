#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");







pair <int, int> P[400005];



int N, M, Total, k, TT[400005], RG[400005];



struct miaw

{

    int x,y,c;



} V[400005];



bool cmp(miaw a, miaw b)

{

    return a.c < b.c;

}

int Find(int nod)

{

    while(TT[nod] != nod)

        nod = TT[nod];

    return nod;

}

void Unite(int x,int y)

{

    if(RG[x] < RG[y])

        TT[x] = y;

    if(RG[y] < RG[x])

        TT[y] = x;

    if(RG[x] == RG[y])

    {

        TT[x]=y;

        RG[y]++;

    }

}



void Kruskal()

{

    for(int i=1; i<=M; i++)

    {





        if(Find(V[i].x) != Find(V[i].y))

        {

            Unite(Find(V[i].x), Find(V[i].y));

            k++;

            P[k].first = V[i].x;

            P[k].second = V[i].y;

            Total += V[i].c;

        }

    }

}



int main()

{



    f>>N>>M;

    for(int i=1; i<=M; i++)

        f>> V[i].x >> V[i].y >> V[i].c;



    sort(V+1,V+M+1,cmp);

    for(int i=1; i<=M; i++)

    {

        TT[i]=i;

        RG[i]=1;

    }



    Kruskal();





    g<<Total<<'\n';



    g<<N-1<<'\n';



    for(int i=1; i<=k; i++)

        g<<P[i].first<<" "<<P[i].second<<'\n';



    return 0;

}
