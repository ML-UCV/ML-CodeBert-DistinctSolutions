#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("ctc.in");
ofstream g("ctc.out");

vector <int>v[100003],vt[100003],sol[100003];
int N,M,S,nr,postord[100003],viz[100003];

void DF(int x)
{
    viz[x] = 1;
    for(int k = 0 ; k < v[x].size() ; k++)
        if( viz[ v[x][k] ] == 0 )
            DF( v[x][k] );
    nr++;
    postord[nr] = x;
}

void DFT(int x,int s)
{
    viz[x] = 0;
    sol[s].push_back(x);
    for(int k = 0 ; k < vt[x].size() ; k++)
        if( viz[ vt[x][k] ] == 1 )
            DFT( vt[x][k] , s );
}

void TareConex()
{
    int i;
    for( i = 1 ; i <= N ; i++)
        if( viz[i] == 0 )
           DF(i);
    for( i = N ; i >= 1 ; i--)
        if( viz[ postord[i] ] == 1 )
        {
            S++;
            DFT(postord[i],S);
        }
    g<<S<<'\n';
    for( i = 1 ; i <= S ; i++)
    {
        for(int k = 0 ; k < sol[i].size() ; k++)
            g<<sol[i][k]<<' ';
        g<<'\n';
    }
}

int main()
{
    int x,y;
    f>>N>>M;
    for(int i = 1 ; i <= M ; i++)
    {
        f>>x>>y;
        v[x].push_back(y);
        vt[y].push_back(x);
    }
    TareConex();
    return 0;
}
