#include <iostream>
#include <fstream>
#include <queue>
#include <vector>


using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

const int NMAX = 30002;
const int MMAX = 100026;
int N,M,X,Y;
int a,b,c;
int dist[NMAX];
int x[MMAX],y[MMAX],d[MMAX];
void Read()
{
    fin>>N>>M>>X>>Y;
    for(int i=1; i<=M; ++i)
    {
        fin>>a>>b>>c;
        x[i]=a;
        y[i]=b;
        d[i]=c;
    }
}
void Do()
{
    dist[X]=1;
    while(!dist[Y])
    {
        for(int i=1; i<=M; ++i)
        {
            if(dist[x[i]] && !dist[y[i]])
                dist[y[i]]=dist[x[i]]+d[i];
            if(!dist[x[i]] && dist[y[i]])
                dist[x[i]]=dist[y[i]]-d[i];
        }
    }
    fout<<dist[Y]-1;
}
int main()
{
    Read();
    Do();
    return 0;
}
