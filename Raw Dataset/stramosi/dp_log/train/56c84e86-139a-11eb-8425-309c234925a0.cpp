#include <iostream>
#include <fstream>


using namespace std;



ifstream in ("stramosi.in");

ofstream out ("stramosi.out");



const int N=250001;

const int M=350002;



int t[18][N];

int main()

{

    int n,m,p,q;

    in>>n>>m;

    for (int i=1;i<=n;i++)

        in>>t[0][i];

    for (int i=1;i<18;i++)

        for (int j=1;j<=n;j++)

            t[i][j]=t[i-1][t[i-1][j]];

    for (int k=1;k<=m;k++)

    {

        in>>q>>p;

        int ans=q;

        int i=0;

  while (p)

        {

   if (p%2!=0) ans=t[i][ans];

   p/=2;

   i++;

  }

  out<<ans<<'\n';

    }

    return 0;

}
