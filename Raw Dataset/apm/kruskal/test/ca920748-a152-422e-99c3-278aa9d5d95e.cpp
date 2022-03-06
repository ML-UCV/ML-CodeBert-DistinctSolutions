#include <bits/stdc++.h>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



int muchii_puse,CT,n,tata[200100],h[200100];



struct MUCHIE

{

    int x,y,cost;

}mch[400100],sol[400100];



int compare(MUCHIE A, MUCHIE B)

{

    return (A.cost<B.cost);

}



int afla_tata(int nod)

{

    while(nod!=tata[nod])nod=tata[nod];

    return nod;

}



int muchie(int nod1,int nod2)

{

    int r1=afla_tata(nod1);

    int r2=afla_tata(nod2);



    if(r1==r2)return 0;



    if(h[r1]<h[r2])tata[r1]=r2;

    else if(h[r2]<h[r1])tata[r2]=r1;

    else tata[r2]=r1,h[r1]++;



    return 1;

}



void kruskal()

{

    int k=1;

    while(muchii_puse<n-1)

    {

        if(muchie(mch[k].x,mch[k].y))

        {

            muchii_puse++;

            CT+=mch[k].cost;

            sol[muchii_puse].x=mch[k].x;

            sol[muchii_puse].y=mch[k].y;

        }

        k++;

    }

}



int m,i;

int main()

{

    f>>n>>m;

    for(i=1;i<=n;i++)tata[i]=i,h[i]=1;

    for(i=1;i<=m;i++)

    {

        f>>mch[i].x>>mch[i].y>>mch[i].cost;

    }



    sort(mch+1,mch+m+1,compare);

    kruskal();



    g<<CT<<'\n';

    g<<muchii_puse<<'\n';

    for(i=1;i<=muchii_puse;i++)

    {

        g<<sol[i].x<<" "<<sol[i].y<<'\n';

    }



    return 0;

}
