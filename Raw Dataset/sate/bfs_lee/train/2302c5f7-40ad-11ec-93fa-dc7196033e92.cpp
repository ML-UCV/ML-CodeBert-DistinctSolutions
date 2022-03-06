#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
int dist[30005];
vector <int>V[30005];
int n,m,x,y;

void BFS(int k)
{ queue<int> C;
    C.push(k);
    dist[k]=0;
    vector<int>::iterator it;
    while(!C.empty())
    { k=C.front(); C.pop();
        for(it=V[k].begin();it!=V[k].end();++it,++it)
            if(dist[*it]==-1)
        {
            C.push(*it);
            if(*it>k)
                dist[*it]=dist[k]+*(it+1);
            else dist[*it]=dist[k]-*(it+1);

            if(*it==y)
                return;
        }
    }
}

int main()
{
    fin>>n>>m>>x>>y;
    int i,a,b,z;
    for(i=1;i<=n;++i)
        dist[i]=-1;
    for(i=1;i<=m;++i)
    { fin>>a>>b>>z;
        V[a].push_back(b);
        V[a].push_back(z);
         V[b].push_back(a);
        V[b].push_back(z);
    }
    BFS(min(x,y));
   fout<<dist[max(x,y)];
        return 0;
}
