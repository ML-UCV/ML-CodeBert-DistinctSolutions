#include <iostream>
#include <fstream>


using namespace std;



ifstream g("ctc.in");

ofstream o("ctc.out");

int nrc,n,m,n1,n2,viz[100003],stiva[100003],k,sol[2*100003],nr;

struct nod{



int x;

nod *urm;



};



nod *L[100003];

nod *LT[100003];



void uneste(int i, int j)

{

    nod *p;

    p=new nod;

    p->x=j;

    p->urm=L[i];

    L[i]=p;

}



void afisare_lista()

{

    nod *p;

    p=new nod;

    for(int i=1;i<=n;i++)

    {

        p=LT[i];

        while(p)

        {

            o<<p->x<<" ";

            p=p->urm;

        }

        o<<"\n";

    }

}



void DFS(int nod_pornire)

{

    nod *p;

    p=new nod;

    p=L[nod_pornire];

    viz[nod_pornire]=1;

    while(p)

    {

        if(viz[p->x]==0)

            DFS(p->x);

        p=p->urm;

    }

    stiva[++k]=nod_pornire;

}



void unesteT(int i, int j)

{

    nod *p;

    p=new nod;

    p->x=i;

    p->urm=LT[j];

    LT[j]=p;

}



void DFST(int nod_pornire)

{

    sol[++nr]=nod_pornire;

    nod *p;

    p=new nod;

    p=LT[nod_pornire];

    viz[nod_pornire]=1;

    while(p)

    {

        if(viz[p->x]==0)

        {

            DFST(p->x);

        }

        p=p->urm;

    }

}



int main()

{

    g>>n>>m;

    for(int i=1;i<=m;i++)

    {

        g>>n1>>n2;

        uneste(n1,n2);

        unesteT(n1,n2);

    }







    for(int i=1;i<=n;i++)

        if(viz[i]==0)

            DFS(i);



    for(int i=1;i<=n;i++)

        viz[i]=0;



    for(int i=k;i>=1;i--)

    {

        if(viz[stiva[i]]==0)

            {

                DFST(stiva[i]);

                nrc++;

                sol[++nr]=-1;

            }

    }

o<<nrc<<"\n";

for(int i=1;i<=nr;i++)

{

    if(sol[i]!=-1)

        o<<sol[i]<<" ";

    else

        o<<"\n";

}



    return 0;

}
