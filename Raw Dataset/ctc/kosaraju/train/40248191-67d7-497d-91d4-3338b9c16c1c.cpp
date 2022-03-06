#include<algorithm>
#include <fstream>




using namespace std;

ifstream fi("ctc.in");

ofstream fo("ctc.out");

struct nod{

    int x;

    nod*urm;

 };

 nod *L[100003],*LT[100003],*ctc[100003];

 nod*p;

 int viz[100003],vizt[100003],i,j,k,n,m,x,y;

 int st[100003],nc;

void adauga(int i,int j){

  nod*p;

  p=new nod;

  p->x=j;



  p->urm=L[i];

  L[i]=p;

 }

 void adaugat(int i,int j){

  nod*p;

  p=new nod;

  p->x=i;



  p->urm=LT[j];

  LT[j]=p;

 }

 void adaugactc(int i,int j){

  nod*p;

  p=new nod;

  p->x=j;



  p->urm=ctc[i];

  ctc[i]=p;

 }

void dfs(int j){

   nod *p;

   viz[j]=1;

   p=L[j];

   while(p){

    if(viz[p->x]==0)dfs(p->x);

     p=p->urm;

   }

 st[++k]=j;

}

void dfst(int j){

   nod *p;

   adaugactc(nc,j);

   vizt[j]=1;

   p=LT[j];

   while(p){

    if(vizt[p->x]==0)dfst(p->x);

     p=p->urm;

   }

}

int main(){

    fi>>n>>m;

    for(i=1;i<=m;i++){

        fi>>x>>y;

        adauga(x,y);

        adaugat(x,y);

    }

    for(i=1;i<=n;i++)

        if(viz[i]==0)dfs(i);



    for(i=k;i>=1;i--)

        if(vizt[st[i]]==0)

             {nc++;dfst(st[i]);}

    fo<<nc<<'\n';

    for(i=1;i<=nc;i++){

         p=ctc[i];

         while(p){

                fo<<p->x<<" ";

                p=p->urm;

        }

        fo<<'\n';

    }
return 0;

}
