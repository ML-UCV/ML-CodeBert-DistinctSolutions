#include <queue>
#include <stack>
#include<stdio.h>
#include<iostream>
using namespace std;



int n,m,v[100000],nrdf[100000],inst[100000];

vector<int> l[100000];

int c,ndf,pozc=0;;



struct Muchie{

       int i,j;

} ;



stack<int> s;



vector<int> comp;



void bloc(int x,int tata){

 int u;

 s.push(x);

  ndf++;

  nrdf[x]=ndf;

  v[x]=ndf;

  inst[x]=1;

  for(int t=0;t<l[x].size();t++){

          int j=l[x][t];

    if(nrdf[j]==0){





     bloc(j,x);



     if(v[x]>v[j])

      v[x]=v[j];

    }

    else

     if(inst[j]){

      if(v[x]>nrdf[j])

       v[x]=nrdf[j];

     }

          }



    if (v[x] == nrdf[x]) {

          do {

              u = s.top();

     comp.push_back(u);

              s.pop();

              inst[u]=0;



          }

          while (u != x);



          c++;

         comp.push_back(-1);

  }



 }

void bloc(){

  int i;

  c=0;

  for(i=0;i<n;i++){

   v[i]=0;

   nrdf[i]=0;



  }

  for(i=0;i<n;i++)

   if(nrdf[i]==0)

    bloc(i,-1);

 }



int main(){



     FILE *f;

     int i,x,y,nrc=0,j;



     f=fopen("ctc.in","r");

     fscanf(f,"%d %d",&n,&m);

     for(i=0;i<m;i++){

         fscanf(f,"%d %d",&x,&y);

         l[x-1].push_back(y-1);



     }

     fclose(f);





     bloc();



     f=fopen("ctc.out","w");

     fprintf(f,"%d",c);



          fprintf(f,"\n",c);

          for(j=0;j<comp.size();j++){

                if(comp[j]>=0)

                   fprintf(f,"%d ",comp[j]+1);

                else

                    fprintf(f,"\n");

          }





     fclose(f);
     return 0;

}
