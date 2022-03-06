#include <fstream>




using namespace std;



ofstream fout("ctc.out");



struct nod

{

    int info;

    nod *urm;

};



nod *g[100001], *gt[100001], *comp[100001];

int n, m;

int viz[100001], stiva[100001], nrc, nr;



void Citire()

{

    ifstream fin("ctc.in");

    int x,y;

    nod *p;

    fin>>n>>m;

    while (m--)

    {

        fin>>x>>y;

        p=new nod; p->info=y; p->urm=g[x]; g[x]=p;

        p=new nod; p->info=x; p->urm=gt[y]; gt[y]=p;

   }

   fin.close();

}





void dfs(int vf)

{

    int i;

    nod *p;

    viz[vf]=1;

    for (p=g[vf];p!=NULL;p=p->urm)

    {

        i=p->info;

        if (!viz[i])

            dfs(i);

    }

    stiva[++nr]=vf;

}



void dfst(int vf)

{

    nod *p;

    int i;

    viz[vf]=0;

    p=new nod; p->info=vf; p->urm=comp[nrc]; comp[nrc]=p;

    for (p=gt[vf];p!=NULL;p=p->urm)

    {

        i=p->info;

        if (viz[i])

            dfst(i);

    }

}



void Afisare()

{

    int i;

    nod *p;

    for (i=1;i<=nrc;i++)

    {

        for (p=comp[i];p!=NULL;p=p->urm)

            fout<<p->info<<" ";

        fout<<"\n";

    }

}

int main()

{



    int i;

    Citire();



    for (i=1;i<=n;i++)

        if (!viz[i])

            dfs(i);



    for (i=n;i>0;i--)

        if (viz[stiva[i]])

        {

            nrc++;

            dfst(stiva[i]);

        }

    fout<<nrc<<"\n";

    Afisare();



    fout.close();

    return 0;

}
