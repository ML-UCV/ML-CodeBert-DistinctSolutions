#include <stdio.h>
#include <stdlib.h>
#include <time.h>






struct vector

{

 int x,y,z;

}v[101*10];



char fol[101];



int main()

{

 int i,pos,N,M,end;



 freopen("party.in","r",stdin);



 scanf("%d%d",&N,&M);

 for(i=1;i<=M;i++)

 {

  scanf("%d%d%d",&v[i].x,&v[i].y,&v[i].z);

  if(v[i].z==2)

  {

   v[i].z=v[i].x;

   v[i].x=v[i].y;

   v[i].y=v[i].z;

   v[i].z=1;

  }

 }



 srand(time(NULL));

 for(i=1;i<=N;i++) fol[i]=rand()%2;



 end=0;

 while(!end)

 {

  end=1;

  pos=rand()%M+1;



  for(i=pos;i<=M;i++)

   if(v[i].z==0)

   {

    if(fol[v[i].x]==0&&fol[v[i].y]==0)

    {

     end=0;

     break;

    }

   }

   else

   if(v[i].z==1)

   {

    if(fol[v[i].x]==0&&fol[v[i].y]!=0)

    {

     end=0;

     break;

    }

   }

   else

   if(v[i].z==3)

   {

    if(fol[v[i].x]==1&&fol[v[i].y]==1)

    {

     end=0;

     break;

    }

   }



  if(end)

   for(i=1;i<=pos;i++)

    if(v[i].z==3)

    {

     if(fol[v[i].x]==1&&fol[v[i].y]==1)

     {

      end=0;

      break;

     }

    }

    else

    if(v[i].z==0)

    {

     if(fol[v[i].x]==0&&fol[v[i].y]==0)

     {

      end=0;

      break;

     }

    }

    else

    if(v[i].z==1)

    {

     if(fol[v[i].x]==0&&fol[v[i].y]!=0)

     {

      end=0;

      break;

     }

    }



  if(!end)

  {

   pos=rand()%2;

   if(pos) fol[v[i].x]=!fol[v[i].x];

   else fol[v[i].y]=!fol[v[i].y];

  }

 }



 freopen("party.out","w",stdout);



 fol[0]=0;

 for(i=1;i<=N;i++) fol[0]+=fol[i];

 printf("%d\n",fol[0]);

 for(i=1;i<=N;i++)

  if(fol[i]) printf("%d\n",i);



 return 0;

}
