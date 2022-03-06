#include <cstdio>#include <cstring>
#include <vector>
using namespace std;







int n,m;

int E[1024][2];

int sol[128],sol2[128];

int Q[1024];

bool viz[128];

vector <int> Ap[128];





void citire()

{

   freopen("party.in","r",stdin);

   int i,x,y,tip;

   scanf("%d %d",&n,&m);

   for (i=1;i<=m;++i)

   {

 scanf("%d %d %d",&x,&y,&tip);

 switch (tip)

 {

  case 0: {



     E[i][0]=x; E[i][1]=y;

     break;

    }

  case 1: {



     E[i][0]=x; E[i][1]=-y;

     break;

    }

  case 2: {



     E[i][0]=-x; E[i][1]=y;

     break;

    }

  case 3: {



     E[i][0]=-x; E[i][1]=-y;

     break;

    }

 }

 Ap[x].push_back(i); Ap[y].push_back(i);



   }

}



inline int ABS(int x)

{

 if (x<0) return -x;

 return x;

}



bool verif_sol(int x)

{

 int st,dr,y,e,px,py,valx,valy,val,i;

 memset(viz,0,sizeof(viz));

 st=dr=0; Q[st]=x; viz[x]=1;

 while (st<=dr)

    {

  x=Q[st++]; val=sol2[x];

  for (i=0;i<Ap[x].size();++i)

  {

   e=Ap[x][i];

   if (ABS(E[e][0])==x) px=0, py=1; else

   if (ABS(E[e][1])==x) px=1, py=0;





   if (E[e][px]<0) valx=!val; else valx=val;

   if (!valx)

      {

    if (E[e][py]<0) {valy=0; y=-E[e][py];}

       else {valy=1; y=E[e][py];}

    if (sol2[y]==-1)

    {

     sol2[y]=valy;

     if (!viz[y]) { Q[++dr]=y; viz[y]=1;}

    } else

    if (sol2[y]!=valy) return 0;

      }

  }

  viz[x]=0;

 }

 return 1;

}



void afisare()

{

 freopen("party.out","w",stdout);

 int i,nr=0;

 for (i=1;i<=n;++i) nr+=sol[i];

 printf("%d\n",nr);

 for (i=1;i<=n;++i)

  if (sol[i]) printf("%d\n",i);

}



int main()

{

   citire();



   int i;

   for (i=1;i<=n;++i) sol[i]=-1;



   for (i=1;i<=n;++i)

 if (sol[i]==-1)

  {

   sol[i]=1;

   memcpy(sol2,sol,sizeof(sol));

   if (verif_sol(i))

    {

     memcpy(sol,sol2,sizeof(sol));

     continue;

    }



   sol[i]=0;

   memcpy(sol2,sol,sizeof(sol));

   if (verif_sol(i))

    {

     memcpy(sol,sol2,sizeof(sol));

     continue;

    }

  }



 afisare();



   return 0;

}
