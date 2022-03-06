#include<fstream>
using namespace std;





struct cerinta

{

 int x, y, z;

}

a[1024];

int p[128];

int n,m,ok,i,x,y,z,Cnt;

int main()

{

     ifstream f("party.in");

  ofstream g("party.out");

  f>>n>>m;

     for(i=1;i<=n;i++)

   p[i]=1;

     for(i=1;i<=m;i++)

   f>>a[i].x>>a[i].y>>a[i].z;

  ok=0;

     while(ok==0)

     {

          ok=1;

          for(i=1;i<=m;i++)

          {

              x=a[i].x,y=a[i].y,z=a[i].z;

              if(z==0)

    if(p[x]==0&&p[y]==0)

    {

     p[x]=1;p[y]=1;

     ok=0;

     break;

    }

                   if(z==1)

                    if(p[x]==0&&p[y]!=0)

     {

      p[y]=0;

      ok=0;

      break;

     }

              if(z==2)

                    if(p[y]==0&&p[x]!=0)

      {

       p[x]=0;

       ok=0;

       break;

     }



              if(z==3)

                    if(p[x]==1&&p[y]==1)

      {

       p[y]=0;

       ok=0;

       break;

     }

}

  }



     for(i=1;i<=n;i++)

            if(p[i])

    Cnt++;

              g<<Cnt<<" ";



     for(i=1;i<=n;i++)

            if(p[i])

      g<<i<<" ";

     return 0;

}
