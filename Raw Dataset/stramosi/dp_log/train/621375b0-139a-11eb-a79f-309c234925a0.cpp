#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
ifstream fin("stramosi.in");
ofstream fout("stramosi.out");
vector <int> g[250005];
int n,m,i,j,tata,d[250005][22],p,q;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>tata;
        d[i][0]=tata;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=18;j++)
            d[i][j]=d[d[i][j-1]][j-1];
    for(i=1;i<=m;i++)
    {
        fin>>q>>p;

        for(j=18;j>=0;j--)
            if(p & (1<<j))
                q=d[q][j];
        fout<<q<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
