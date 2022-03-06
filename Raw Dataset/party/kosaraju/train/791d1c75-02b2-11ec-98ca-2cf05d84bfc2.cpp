#include <stdio.h>
#include <stdlib.h>
#include <time.h>






struct vector

{

 int x,y,z;

}v[101*10];



char use[101];



int main()

{

 int i,pos,N,M,end,ok;



 freopen("party.in","r",stdin);



 scanf("%d%d",&N,&M);

 for(i=1;i<=M;i++) scanf("%d%d%d",&v[i].x,&v[i].y,&v[i].z);



 srand(time(NULL));

 for(i=1;i<=N;i++) use[i]=rand()%2;



 end=0;

 while(!end)

 {

  end=1;

  pos=rand()%M+1;



  for(i=pos;i<=M;i++)

   if(v[i].z==0)

   {

    if(use[v[i].x]==0&&use[v[i].y]==0)

    {

     ok=rand()%2;

     if(ok) use[v[i].x]=1-use[v[i].x];

     else use[v[i].y]=1-use[v[i].y];

     end=0;

     break;

    }

   }

   else

   if(v[i].z==1)

   {

    if(use[v[i].x]==0&&use[v[i].y]!=0)

    {

     ok=rand()%2;

     if(ok) use[v[i].x]=1-use[v[i].x];

     else use[v[i].y]=1-use[v[i].y];

     end=0;

     break;

    }

   }

   else

   if(v[i].z==2)

   {

    if(use[v[i].x]!=0&&use[v[i].y]==0)

    {

     ok=rand()%2;

     if(!ok) use[v[i].x]=1-use[v[i].x];

     else use[v[i].y]=1-use[v[i].y];

     end=0;

     break;

    }

   }

   else

   if(v[i].z==3)

   {

    if(use[v[i].x]==1&&use[v[i].y]==1)

    {

     ok=rand()%2;

     if(ok) use[v[i].x]=1-use[v[i].x];

     else use[v[i].y]=1-use[v[i].y];

     end=0;

     break;

    }

   }



  if(end)

   for(i=1;i<=pos;i++)

    if(v[i].z==0)

    {

     if(use[v[i].x]==0&&use[v[i].y]==0)

     {

      ok=rand()%2;

      if(ok) use[v[i].x]=1-use[v[i].x];

      else use[v[i].y]=1-use[v[i].y];

      end=0;

      break;

     }

    }

    else

    if(v[i].z==1)

    {

     if(use[v[i].x]==0&&use[v[i].y]!=0)

     {

      ok=rand()%2;

      if(ok) use[v[i].x]=1-use[v[i].x];

      else use[v[i].y]=1-use[v[i].y];

      end=0;

      break;

     }

    }

    else

    if(v[i].z==2)

    {

     if(use[v[i].x]!=0&&use[v[i].y]==0)

     {

      ok=rand()%2;

      if(!ok) use[v[i].x]=1-use[v[i].x];

      else use[v[i].y]=1-use[v[i].y];

      end=0;

      break;

     }

    }

    else

    if(v[i].z==3)

    {

     if(use[v[i].x]==1&&use[v[i].y]==1)

     {

      ok=rand()%2;

      if(ok) use[v[i].x]=1-use[v[i].x];

      else use[v[i].y]=1-use[v[i].y];

      end=0;

      break;

     }

    }

 }



 freopen("party.out","w",stdout);



 use[0]=0;

 for(i=1;i<=N;i++) use[0]+=use[i];



 printf("%d\n",use[0]);



 for(i=1;i<=N;i++) if(use[i]) printf("%d\n",i);



 return 0;

}
