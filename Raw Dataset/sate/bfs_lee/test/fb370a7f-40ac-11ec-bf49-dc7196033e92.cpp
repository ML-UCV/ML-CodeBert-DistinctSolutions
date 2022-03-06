#include <fstream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
const int NMAX=30000;
struct graf
{
    int nod, distanta;
};
vector <graf>G[NMAX+5];
queue <int>q;
bool viz[NMAX+5];
int s[NMAX+5];
int x, y;
string sir;
void bfs(int nod)
{
    int i;
    viz[nod]=1;
    s[nod]=0;
    q.push(nod);
    while(!q.empty())
    {
        nod=q.front();
        q.pop();
        for(i=0;i<G[nod].size();++i)
        {
             if(viz[G[nod][i].nod]==0)
             {
               s[G[nod][i].nod]=G[nod][i].distanta+s[nod];
               q.push(G[nod][i].nod);
               viz[G[nod][i].nod]=1;
             }
        }
        if(s[y]!=0)
        {
              fout<< s[y]<<"\n";
              exit(0);
        }
    }
}
int main()
{
    int n, m, a, b, d, i, j, nr;
    graf aux;
    fin>>n>>m>>x>>y;
   fin.get();
    for(int k=1;k<=m;++k)
    {
        getline(fin, sir);
        d=0;
        a=0;
        b=0;
        for(j=0;j<sir.size();j++)
        {
            if(sir[j]>='0' and sir[j]<='9')
            {
                nr=0;
                for(i=j;i<sir.size();i++)
                {
                    if(sir[i]>='0' and sir[i]<='9')
                        nr=nr*10+(sir[i]-'0');
                    else
                    {
                        j=i;
                        break;
                    }
                }
                if(a==0)
                    a=nr;
                else
                    {
                        if(b==0)
                            b=nr;
                        else
                        {
                            d=nr;
                            break;
                        }
                    }
            }
        }
        aux.distanta=d;
        aux.nod=b;
        G[a].push_back(aux);
        aux.distanta=-d;
        aux.nod=a;
        G[b].push_back(aux);
    }
    bfs(x);



    return 0;
}
