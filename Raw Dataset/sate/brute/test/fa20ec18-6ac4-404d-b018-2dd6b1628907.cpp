#include <fstream>
#define nmax 100030

using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

int n, m, x, y;

int a[nmax], b[nmax], dist[nmax], pasi[30005];

int main()
{
    in>>n>>m>>x>>y;
    for(int i=1; i<=m; i++)
    {
        in>>a[i]>>b[i]>>dist[i];
    }
    pasi[x]=1;
    while(!pasi[y])
    {
        for(int i=1; i<=m; i++)
        {
            if(pasi[a[i]] && !pasi[b[i]])
            {
                pasi[b[i]] = pasi[a[i]] + dist[i];
            }
            else
                if(!pasi[a[i]] && pasi[b[i]])
                {
                    pasi[a[i]] = pasi[b[i]] - dist[i];
                }
        }
    }
    out<<pasi[y]-1;
}
