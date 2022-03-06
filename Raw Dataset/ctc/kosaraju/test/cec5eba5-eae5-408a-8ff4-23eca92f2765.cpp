#include<fstream>


using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

struct nod{

int info;

nod *urm;

};

nod *l1[100001];

nod *l2[100001];

nod *sol[100001];



int n,m,ct;

int viz1[100001],viz2[100001];

int c[100001],cp,cu;



void citire()

{

    int i,x,y;

    fin>>n>>m;

    for(i=1;i<=m;i++)

    {

        fin>>x>>y;

        nod *p=new nod;

        p->info=y;

        p->urm=l1[x];

        l1[x]=p;



        p=new nod;

        p->info=x;

        p->urm=l2[y];

        l2[y]=p;

    }

}

void dfs1(int i)

{

    viz1[i]=1;

    for(nod *p=l1[i];p!=NULL;p=p->urm)if(viz1[p->info]==0)dfs1(p->info);



    c[++cu]=i;

}

void parc1()

{

    int i;

    for(i=1;i<=n;i++)

    if(viz1[i]==0)dfs1(i);

}

void dfs2(int i)

{

    viz2[i]=1;



    nod *q=new nod;

    q->info=i;

    q->urm=sol[ct];

    sol[ct]=q;



    for(nod *p=l2[i];p!=NULL;p=p->urm)if(viz2[p->info]==0)dfs2(p->info);

}

void parc2()

{

    int j;

    cp=1;

    while(cu>0)

    {

        j=c[cu--];

        if(viz2[j]==0)

        {

            ct++;

            dfs2(j);

        }

    }

}

void afisare(){

    nod *p;

    int i;

    fout<<ct<<"\n";

    for(i=1;i<=ct;i++){

        p=sol[i];

        while(p!=NULL){

            fout<<p->info<<" ";

            p=p->urm;

        }

        fout<<"\n";

    }

}

int main()

{

    citire();

    parc1();

    parc2();

    afisare();

    return 0;

}
