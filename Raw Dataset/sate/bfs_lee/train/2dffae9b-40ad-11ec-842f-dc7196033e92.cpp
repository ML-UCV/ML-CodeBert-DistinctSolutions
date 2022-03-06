#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

#define lim 30010
int n,m,x,y,a,b,c;
int dist[lim];
bool viz[lim];
struct loc{int sat,d;};
vector <loc> G[lim];



void bfs(int nod)
{
    queue <int> q;
    q.push(nod);
    dist[nod]=0;

    while(!q.empty())
    {
        nod=q.front();
        q.pop();
        for(auto it:G[nod])
        {
            if(!viz[it.sat])
            {
                viz[it.sat]=true;
                if(it.sat>nod)
                {
                    dist[it.sat]=dist[nod]+it.d;
                    q.push(it.sat);
                }
                if(it.sat<nod)
                {
                    dist[it.sat]=dist[nod]-it.d;
                    q.push(it.sat);
                }

                if(it.sat==y)
                {
                    fout<<dist[y];
                    fout.close();
                    return;
                }
            }
        }
    }

}


int main()
{
    fin>>n>>m>>x>>y;

    for(int i=1; i<=m; i++)
    {
        fin>>a>>b>>c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }

    bfs(x);

    fin.close();
    fout.close();
    return 0;
}
