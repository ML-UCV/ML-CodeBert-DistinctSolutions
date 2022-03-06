#include <fstream>
#include <iostream>






using namespace std;

int tati[18 +1][250001];

int n,m;

int main()

{

    ifstream f("stramosi.in");

    ofstream g("stramosi.out");

    f>>n>>m;

    for(int i=1;i<=n;i++)

        f>>tati[1][i];

    for(int i=2;i<=18;i++)

        for(int j=1;j<=n;j++)

            tati[i][j]=tati[i-1][tati[i-1][j]];

    long long q,p;

    for(int i=1;i<=m;i++)

    {

        f>>q>>p;

        int rez=q;

        int poz=1;

        for(long long j=1;p;j=(j<<1),poz++)

        {

            if(p&j)

            {

                p-=j;

                rez = tati[poz][rez];

            }

        }

        g<<rez<<'\n';

    }

    f.close();

    g.close();

    return 0;

}
