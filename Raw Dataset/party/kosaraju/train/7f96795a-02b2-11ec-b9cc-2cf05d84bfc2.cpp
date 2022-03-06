#include <fstream>
#include <bitset>
using namespace std;

typedef struct rel{

        int tip,x,y;

        };

int N,M,nr;

bitset<101> inv,viz;

bitset<101> binv,bviz;

bitset<1001> u,bu;

rel v[1001];

bool ok;

ifstream f("party.in");

ofstream g("party.out");

void redu(int i,int val){

     int j;

     if (viz[i] && inv[i]!=val) ok=false;

     viz[i]=1;inv[i]=val;

     if (val==1){

     for (j=1;j<=M;++j)

       if (!u[j])

        if (v[j].x==i || v[j].y==i)

         switch(v[j].tip){

         case 0:u[j]=1;

                break;

         case 1:u[j]=1;

                if (v[j].y==i) redu(v[j].x,1);

                break;

         case 2:u[j]=1;

                if (v[j].x==i) redu(v[j].y,1);

                break;

         case 3:u[j]=1;

                if (v[j].x==i) redu(v[j].y,0);

                  else redu(v[j].x,0);

                break;

                }

          }else{

     for (j=1;j<=M;++j)

       if (!u[j])

        if (v[j].x==i || v[j].y==i)

         switch(v[j].tip){

         case 0:u[j]=1;

                if (v[j].x==i) redu(v[j].y,1);

                  else redu(v[j].x,1);

                break;

         case 1:u[j]=1;

                if (v[j].x==i) redu(v[j].y,0);

                break;

         case 2:u[j]=1;

                if (v[j].y==i) redu(v[j].x,0);

                break;

         case 3:u[j]=1;

              }

              }





         }

void backup(){

     int i;

     ok=true;

     for ( i=1;i<=N;++i)

      bviz[i]=viz[i],binv[i]=inv[i];

     for (i=1;i<=M;++i)

      bu[i]=u[i];

     }

void restore(){

     int i;

     for (i=1;i<=N;++i)

      viz[i]=bviz[i],inv[i]=binv[i];

     for (i=1;i<=M;++i)

      u[i]=bu[i];

     }

int main(){

    int i;

    f>>N>>M;

    for (i=1;i<=M;++i)

      f>>v[i].x>>v[i].y>>v[i].tip;

    for (i=1;i<=M;++i)

      if (v[i].x==v[i].y){

         u[i]=1;

         if (v[i].tip==0) redu(v[i].x,1);

         if (v[i].tip==3) redu(v[i].x,0);}

    for (i=1;i<=N;++i)

      if (!viz[i]){

      backup();

      redu(i,1);

      if (!ok) restore(),redu(i,0);

      }

    for (i=1;i<=N;++i)

     if (inv[i]==1) ++nr;

    g<<nr<<'\n';;

    for (i=1;i<=N;++i)

     if (inv[i]==1) g<<i<<'\n';

    return 0;

}
