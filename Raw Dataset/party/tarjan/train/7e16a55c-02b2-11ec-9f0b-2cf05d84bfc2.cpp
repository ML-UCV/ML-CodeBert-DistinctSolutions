#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <ctime>




using namespace std;



struct op{ int tip,x,y; } a[1005];

int v[105];

int i,n,m,ok,x,nr;



int main(){

 freopen("party.in","r",stdin);

   freopen("party.out","w",stdout);

   scanf("%d%d",&n,&m);

   for(i=1;i<=m;++i) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].tip);



   srand(time(NULL));

   for(i=1;i<=n;++i) v[i]=rand()%2;



   for(ok=1; ok; ){

    ok=0;

    for(i=1;i<=m;++i)

         if(a[i].tip == 0){

          if(!v[a[i].x] && !v[a[i].y]){

             ok=1;

             x=rand()%2;

               if(x) v[a[i].x]=1; else v[a[i].y]=1;

            }

         } else

         if(a[i].tip == 1){

          if(!v[a[i].x] && v[a[i].y]){

             ok=1;

               v[a[i].y]=0;

            }

         }else

         if(a[i].tip == 2){

          if(!v[a[i].y] && v[a[i].x]){

             ok=1;

               v[a[i].x]=0;

            }

         } else

         if(a[i].tip == 3){

          if( v[a[i].x] && v[a[i].y]){

             x=rand()%2;

               if(x) v[a[i].x]=0; else v[a[i].y]=0;

               ok=1;

            }

         }

   }



   for(i=1;i<=n;++i) nr+=v[i];

   printf("%d\n",nr);

   for(i=1;i<=n;++i) if(v[i]) printf("%d\n",i);

   fclose(stdin); fclose(stdout);

   return 0;

}
