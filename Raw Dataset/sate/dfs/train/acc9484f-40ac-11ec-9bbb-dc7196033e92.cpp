#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

ifstream cin ("sate.in");
ofstream cout ("sate.out");

vector <pair<int,int> > G[30002];
int v[30002];

void fct (int nod, int dist);

int ok,x,y;
int main()
{
    int n,i,m,a,b,d;
    cin>>n>>m>>x>>y;
    i=1;
    while(i<=m)
    {
        cin>>a>>b>>d;
        G[a].push_back({b,d});
        G[b].push_back({a,d});
        i++;
    }
    fct(x,0);
    return 0;
}
//facem o functie pt nod, distanta de la x la nod
// x nod vecin -> d=dist+second
// x vecin nod -> d=dist-second
// nod x vecin -> d=second-dist
// nod vecin x -> d=dist-second
// vecin nod x -> d=dist+second

void fct (int nod, int dist)
{
    int dis,vecin,i;
    if(ok) return;
    v[nod]=1;
    if(nod==y) {cout<<dist; ok=1; return;}
    for(i=0;i<G[nod].size();i++)
        if(v[G[nod][i].first]==0)
            {
                vecin=G[nod][i].first;
                dis=G[nod][i].second;
                if(x<nod && nod<vecin || x>nod && nod>vecin) fct(vecin, dist+dis);
                else fct(vecin, abs(dist-dis));
            }
}
