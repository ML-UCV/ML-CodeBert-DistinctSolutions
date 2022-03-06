#include<fstream>
#include<cstdlib>
using namespace std;

ifstream f("party.in");

ofstream g("party.out");

int c[1001],n,m,i,nr;

struct inv

{

    int x,y;

    int c;

};

inv v[1001];

int verificare(int k)

{



    if(k==0)

      return c[v[i].x]||c[v[i].y];

    if(k==1)

      return c[v[i].x]||!c[v[i].y];

    if(k==2)

      return c[v[i].y]||!c[v[i].x];

    if(k==3)

      return c[v[i].x]+c[v[i].y]!=2;

    return 0;

}

int main()

{



    f>>n>>m;

    for(i=1;i<=m;i++)

      f>>v[i].x>>v[i].y>>v[i].c;

    for(i=1;i<=n;i++)

      c[i]=1;

    for(i=1;i<=m;i++)

    {



        if(!verificare(v[i].c))

        {

            int a=rand()%2;

            if(a==1)

              c[v[i].y]=!c[v[i].y];

            else

              c[v[i].x]=!c[v[i].x];

            i=0;

        }

    }

    for(i=1;i<=n;i++)

      if(c[i])

        ++nr;

    g<<nr<<"\n";

    for(i=1;i<=n;++i)

      if(c[i])

        g<<i<<"\n";

    return 0;

}
