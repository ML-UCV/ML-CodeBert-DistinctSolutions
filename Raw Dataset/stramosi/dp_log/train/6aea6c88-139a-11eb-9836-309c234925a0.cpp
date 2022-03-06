#include <iostream>
#include <fstream>

using namespace std;

int n,m,nr,x,p[250003][20];
ofstream fout("stramosi.out");

void stramos()
{
    int t=x,putere=0;
    while(nr)
    {
        if(nr%2==0)
        {
            nr/=2;
            putere++;
        }
        else
        {
            nr--;
            t=p[t][putere];
        }
    }
    fout<<t<<"\n";
}

void citire()
{
    ifstream fin("stramosi.in");
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>p[i][0];
    for(int i=1;i<=n;i++)
        for(int j=1;j<19;j++)
            p[i][j]=p[p[i][j-1]][j-1];
    for(int i=0;i<m;i++)
    {
        fin>>x>>nr;
        stramos();
    }
}

int main()
{
    citire();
    return 0;
}
