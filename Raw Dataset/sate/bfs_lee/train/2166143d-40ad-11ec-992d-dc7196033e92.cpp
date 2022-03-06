#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

const int N=30001;
vector<pair<int,int> > a[N];

int d[N],n,m,x0,y0,q[N];
bool viz[N];

void citire()
{
    int x,y,z,i;
    in>>n>>m>>x0>>y0;
    for(i=0; i<m; i++)
    {
        in>>x>>y>>z;
        if (x > y)
        {
            swap(x, y);
        }
        a[x].push_back(make_pair(y, z));
        a[y].push_back(make_pair(x, -z));
    }
}

void BFS(int nod)
{
    int st,dr,i,x,y,p=0,u=-1;
    d[x0]=0;
    q[++u]=nod;
    viz[nod]=1;
    while(p<=u)
    {
        x=q[p++];
        for(size_t i=0; i<a[x].size(); i++)
        {
            y=a[x][i].first;
            if(!viz[y])
            {
                viz[y]=1;
                if(x<y)
                {
                    d[y]=d[x]+a[x][i].second;
                    q[++u]=y;
                }
                else
                {
                    d[y]=d[x]+a[x][i].second;
                    q[++u]=y;
                }
            }
        }
    }
}
int main()
{
    int i,b;
    citire();
    BFS(x0);
    out<<d[y0];
    return 0;
}
