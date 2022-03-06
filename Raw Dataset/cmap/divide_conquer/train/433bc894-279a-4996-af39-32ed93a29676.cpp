#include<fstream>
#include<algorithm>
#include<math.h>
#include<iomanip>
using namespace std;

ifstream fin("cmap.in");

ofstream fout("cmap.out");

struct punct{

   double x,y;

}p[100001],aux[100001],v[100001];

int n,i;

double inf=4e18;

int comp(punct a,punct b){

    if (a.x>b.x) return 0;

    if (a.x==b.x && a.y>b.y) return 0;

    return 1;

}

double dist(punct a,punct b){

    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);

}

double exp(int st,int dr){

   double val1,val;

   int mij,i,j,nraux=0,nrv=0;

   if (st>dr) return inf;

   if (dr-st==1) return dist(p[st],p[st+1]);

   if (dr-st==2){

       val1=dist(p[st],p[st+1]);

       val1=min(val1,dist(p[st+1],p[st+2]));

       val1=min(val1,dist(p[st],p[st+2]));

       return val1;

   }

   mij=(st+dr)/2;

   val=min(exp(st,mij),exp(mij,dr));

   i=st;j=mij+1;

   while(i<=mij && j<=dr)

     if (p[i].y<=p[j].y){

         nraux++;

         aux[nraux]=p[i];

         i++;

     }

       else

        if (p[i].y>p[j].y){

            nraux++;

            aux[nraux]=p[j];

            j++;

        }

   while(i<=mij){

     nraux++;

     aux[nraux]=p[i];

     i++;

   }

   while(j<=dr){

     nraux++;

     aux[nraux]=p[j];

     j++;

   }

   for (i=1;i<=nraux;i++)

     if (fabs(aux[i].x-p[mij].x)<=val){

         nrv++;

         v[nrv]=aux[i];

     }

   for (i=1;i<=nrv;i++)

        for (j=i+1;j<=nrv && j-i<8;j++)

          val=min(val,dist(v[i],v[j]));

   return val;

}

int main(){

   fin>>n;

   for (i=1;i<=n;i++)

    fin>>p[i].x>>p[i].y;

   fin.close();

   sort(p+1,p+n+1,comp);

   fout<<fixed<<setprecision(6)<<sqrt(exp(1,n));

   fout.close();

   return 0;

}
