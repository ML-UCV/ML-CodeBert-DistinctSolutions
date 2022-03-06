#include <iostream>
#include <fstream>

using namespace std;

const int N=250001;
const int L=30;
int s[L][N];
int stramos(int x, int p)
{
    int poz=17;
    while(poz>=0 && p!=0)
    {
        if(p>=(1<<poz))
        {
            x=s[poz][x];
            p=p-(1<<poz);

        }
        poz--;
    }
    return x;
}

int main()
{
    int n,m,t[N],i,x,y,tt,j;

    ifstream f("stramosi.in");
    ofstream g("stramosi.out");
    f>>n>>m;
    for(i=1; i<=n; i++)
    {
        f>>t[i];
        s[0][i]=t[i];

    }
    for(int i=1; (1<<i)<=n ; i++)
    {

        for(int j=1; j<=n; j++)
        {

            s[i][j]=s[i-1][s[i-1][j]];

        }

    }

    for(int i=0; (1<<i)<=n ; i++)
    {

        for(int j=1; j<=n; j++)
        {




        }


    }


    for(i=1; i<=m; i++)
    {
        f>>x>>y;
         g<<stramos(x,y)<<'\n';

    }
    g.close();

    return 0;
}
