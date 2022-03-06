#include <fstream>
using namespace std;

ifstream f("stramosi.in");

ofstream g("stramosi.out");

int n,m,i,j,x,y,k,afis,s,v[21][250005],pw[21],lg[250005];

char c[10];

int cit()

{

    int r=0,z=0;

    f>>c;

    while(c[r]>='0' && c[r]<='9')

    {

        z=z*10+c[r]-48;

        r++;

    }

    return z;

}

int main()

{

    f>>n>>m;

    pw[0]=1;

    for(i=1;i<=19;i++)

    pw[i]=pw[i-1]*2;

    k=0;

    for(i=1;i<=n;i++)

    if(pw[k]==i)

    {

        lg[i]=k;

        k++;

    }

    else

        lg[i]=k-1;



    for(i=1;i<=n;i++)

    {

        x=cit();

        v[0][i]=x;

    }

    for(i=1;i<=n;i++)

    for(j=1;j<=lg[n];j++)

    {

    v[j][i]=v[j-1][v[j-1][i]];

    if(v[j][i]==0)

    break ;

    }



   for(i=1;i<=m;i++)

    {

        x=cit(); y=cit();

        s=0;

        while(s!=y)

        {

            k=lg[y-s];

            s+=pw[k];

            afis=v[k][x];

            if(afis==0)

            break ;

            x=afis;

        }

        g<<afis<<'\n';

    }





    return 0;

}
