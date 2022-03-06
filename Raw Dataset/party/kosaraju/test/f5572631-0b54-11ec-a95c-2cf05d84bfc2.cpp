#include<fstream>
using namespace std;

typedef struct celula {

           int nod;

           celula *next;

           }*lista;

lista graf[205],v,tgraf[205];

int x,y,op,n,m,i,stiva[205],st,comp[205],nrc,assign[205];

bool viz[205];



int negat(int x) {

   if (x>n) return x-n;

    else return x+n;

}



void dfs(int nod) {

  viz[nod]=1;

  for (lista p=graf[nod]; p; p=p->next)

   if (viz[p->nod]==0) dfs(p->nod);



  ++st; stiva[st]=nod;



}



void dfs2(int nod) {

  comp[nod]=nrc;

  assign[negat(nod)]=1;

  for (lista p=tgraf[nod]; p; p=p->next)

   if (comp[p->nod]==0) dfs2(p->nod);

}



int main(void) {

    ifstream fin("party.in");

    ofstream fout("party.out");



    fin>>n>>m;



    for (i=1; i<=m; ++i){

        fin>>x>>y>>op;

        if (op==1) y=negat(y);

        else if (op==2) x=negat(x);

        else if (op==3) { x=negat(x); y=negat(y); }



        int xn=negat(x), yn=negat(y);



        v=new celula; v->nod=y; v->next=graf[xn]; graf[xn]=v;

        v=new celula; v->nod=x; v->next=graf[yn]; graf[yn]=v;



        v=new celula; v->nod=xn; v->next=tgraf[y]; tgraf[y]=v;

        v=new celula; v->nod=yn; v->next=tgraf[x]; tgraf[x]=v;

        }





    for (i=1; i<=2*n; ++i)

     if (viz[i]==0) dfs(i);



    for (i=st; i>=1; --i)

     if ( comp[stiva[i]]==0 && comp[negat(stiva[i])]==0 ) { ++nrc; dfs2(stiva[i]); }



     int sol=0;

     for (i=1; i<=n; ++i) sol+=assign[i];

     fout<<sol<<"\n";

     for (i=1; i<=n; ++i)

     if (assign[i]==1) fout<<i<<"\n";





    return 0;

}
