#include <iostream>
#include <algorithm>
#include <ctime>






using namespace std;

int valoare[110];

struct prop{int tip,x,y;} v[1010];

int N,M;



int main(void){



 freopen("party.in","rt",stdin);

 freopen("party.out","wt",stdout);



 scanf("%d%d",&N,&M);



 for (int i=1;i<=M;++i){



  scanf("%d%d%d",&v[i].x,&v[i].y,&v[i].tip);

 }



 fclose(stdin);



 srand(time(NULL));



 for (int i=1;i<=N;++i){



  valoare[i]=rand()%2;

 }



 int ok=1;

 while (ok){



  ok=0;

  for (int i=1;i<=M;++i){

   if (v[i].tip==0){



    if (valoare[v[i].x]==0 && valoare[v[i].y]==0){

     int x=rand()%2;

     if (x){ valoare[v[i].x]=1;} else {valoare[v[i].y]=1;}

     ++ok;

    }

   } else if (v[i].tip==1){



    if (valoare[v[i].x]==0 && valoare[v[i].y]==1){ valoare[v[i].y]=0; ++ok;}

   } else if (v[i].tip==2){

    if (valoare[v[i].y]==0 && valoare[v[i].x]==1){ valoare[v[i].x]=0; ++ok;}

   } else {

    if (valoare[v[i].x]==1 && valoare[v[i].y]==1) {

     ++ok;

     int x=rand()%2;

     if (x){ valoare[v[i].x]=0;} else {valoare[v[i].y]=0;}

    }

   }

  }

 }

 int nrinv=0;



 for (int i=1;i<=N;++i) nrinv+=valoare[i];

 printf("%d\n",nrinv);



 for (int i=1;i<=N;++i)

  if (valoare[i]) printf("%d\n",i);



 fclose(stdout);

 return 0;

}
