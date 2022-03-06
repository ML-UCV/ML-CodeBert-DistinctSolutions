#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");

int i,n,m,nod,poz,j,t[18][250001],aux;

int main(){

    fin>>n>>m;

    for(i=1;i<=n;i++)fin>>t[0][i];

    for(i=1,aux=2;aux<=n;i++,aux<<=1)for(j=1;j<=n;j++)t[i][j]=t[i-1][t[i-1][j]];

    for(i=1;i<=m;i++)

    {fin>>nod>>poz;j=0;

        while(poz){if(poz&1)nod=t[j][nod];poz>>=1;j++;};

        fout<<nod<<'\n';

    }

    return 0;

}
