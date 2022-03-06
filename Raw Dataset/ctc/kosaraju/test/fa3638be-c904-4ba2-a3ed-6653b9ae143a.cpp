#include <fstream>


using namespace std;



const int NMAX = 100000;



struct nod

{

    int x;

    nod *next;

};



nod *G[NMAX + 1],

    *GT[NMAX + 1],

    *CTC[NMAX + 1];



int n,m,nrc,

    nr,post[NMAX + 1];



bool viz[NMAX + 1];



ifstream f("ctc.in");

ofstream g("ctc.out");



void add(nod *&cap_1st,int nod_ad)

{

    nod *p;

    p = new nod;

    p -> x = nod_ad;

    p -> next = cap_1st;

    cap_1st = p;

}



void citireGraf()

{

    int x,y;

    f>>n>>m;

    for(int i=1;i<=m;i++)

    {

        f>>x>>y;

        add(G[x],y);

        add(GT[y],x);

    }

}



void DFS(int vf)

{

    viz[vf] = 1;

    for(nod *p = G[vf]; p != NULL; p = p -> next)

        if(viz[p->x] == 0)

            DFS(p->x);

    post[++nr] = vf;

}



void DFSt(int vf)

{

    viz[vf] = 0;

    add(CTC[nrc], vf);

    for(nod *p = GT[vf]; p!=NULL;p = p ->next)

        if(viz[p->x] == 1)

            DFSt(p->x);

}



void componente()

{

    for(int i=1;i<=n;i++)

        if(viz[i] == 0)

            DFS(i);



    for(int i=n;i>=1;i--)

        if(viz[post[i]] == 1)

        {

            nrc++;

            DFSt(post[i]);

        }

}



void afis()

{

    g<<nrc<<'\n';

    for(int i=1;i<=nrc;i++)

    {

        for(nod *p = CTC[i]; p!=NULL; p = p -> next)

            g<< p->x <<' ';

        g<<'\n';

    }

}

int main()

{

    citireGraf();

    componente();

    afis();

    return 0;

}
