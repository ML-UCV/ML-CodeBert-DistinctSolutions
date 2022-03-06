#include<stdio.h>
#include<stdlib.h>
#include<time.h>


struct expresie{int a,b,ok;}v[1005];

int n,m,i,j,A,nr;

bool a[103],ready;



bool eval(expresie x){

if(x.ok == 0)

 return a[x.a]||a[x.b];

else

 if(x.ok == 1){

  if(!a[x.a])

   return (!a[x.b]);

  else

   return true;

  }

else

 if(x.ok == 2){

  if(!a[x.b])

   return (!a[x.a]);

  else

   return true;

 }

else

 return (!(a[x.a] && a[x.b]));



}



int main(){

freopen("party.in","r",stdin);

freopen("party.out","w",stdout);



scanf("%d %d",&n,&m);

srand(time(0));

for(i = 1 ; i <= m ; i++)

 scanf("%d %d %d",&v[i].a,&v[i].b,&v[i].ok);



for(i = 1; i <= n ; i++)

 a[i] = rand()%2;

while(!ready){

ready = true;



for(i = 1; i <= m ; i++)

 if(!eval(v[i])){

  A = rand()%2+1;

  if(A == 1)

   a[v[i].a] = !a[v[i].a];

  else

   a[v[i].b] = !a[v[i].b];

  ready = false;

  }

}



for(i = 1 ; i <= n ;i++)

 if(a[i])nr++;



printf("%d\n",nr);

for(i = 1;i <= n ;i++)

 if(a[i])

  printf("%d\n",i);



return 0;}
