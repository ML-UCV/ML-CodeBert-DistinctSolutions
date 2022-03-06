#include<stdio.h>
#include<stdlib.h>






int e[1004][4],val[104],n,m;



int gaseste(int x)

{int i;





 for(i=x;i<=m;i++)

  {if(e[i][0]==0)

  {if(!(val[e[i][1]]||val[e[i][2]]))

    return i;

   }

   if(e[i][0]==3)

  {if(val[e[i][1]]&&val[e[i][2]])

  return i;

  }

   if(e[i][0]==1)

 {if(!val[e[i][1]]&&val[e[i][2]])

    return i;

 }

   }

 for(i=1;i<x;i++)

  {if(e[i][0]==0)

  {if(!(val[e[i][1]]||val[e[i][2]]))

    return i;

   }

   if(e[i][0]==3)

  {if(val[e[i][1]]&&val[e[i][2]])

  return i;

  }

   if(e[i][0]==1)

 {if(!val[e[i][1]]&&val[e[i][2]])

    return i;

 }

   }



 for(i=1;i<=n;i++)

  if(val[i])

 return m+1;
 i=rand()%m+1;

 return i;

 }
int main()

{int i,a,b,c,x,nr=0;

 freopen("party.in","r",stdin);

 scanf("%d%d",&n,&m);





 for(i=1;i<=m;i++)

  {scanf("%d%d%d",&a,&b,&c);

   if(c==2)

 {e[i][1]=b;

 e[i][2]=a;

 e[i][0]=1;

 }

   else

   {

   e[i][1]=a;

   e[i][2]=b;

   e[i][0]=c;

   }



   }



 do

  {

   i=rand()%m+1;

   x=gaseste(i);

   a=rand()%2;

   if(x!=m+1)

   val[e[x][a+1]]=!val[e[x][a+1]];



   }

   while(x!=m+1);



 freopen("party.out","w",stdout);

 for(i=1;i<=n;i++)

  if(val[i])

 nr++;

 printf("%d\n",nr);

 for(i=1;i<=n;i++)

  if(val[i])

   printf("%d\n",i);

 fclose(stdout);

 return 0;

 }
