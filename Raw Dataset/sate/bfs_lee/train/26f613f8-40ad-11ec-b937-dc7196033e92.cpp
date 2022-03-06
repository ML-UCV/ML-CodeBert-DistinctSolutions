#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define Nmax 30005
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");

int d[Nmax],viz[Nmax],a,b,D,x,y,N,M,inq[Nmax];
vector<pair<int,int> >v[Nmax];
queue<int>q;
void parc(int nod)
{
    viz[nod] = 1;
   for(int i = 0 ; i < v[nod].size(); i++)
   {
       if(viz[v[nod][i].first] != 1)
       {
            int o = v[nod][i].first;//de unde pot ajunge in i
            if(o < nod)
                d[o] = d[nod] - v[nod][i].second;
            else d[o] = d[nod] + v[nod][i].second;
            if(!inq[v[nod][i].first])
            {
                q.push(v[nod][i].first);
                inq[v[nod][i].first] = 1;
            }
       }
   }
}
int main()
{
    fin >> N >> M >> x >> y;
    for(int i = 1; i <= M; i++)
    {
        fin >> a >> b >> D;
        v[b].push_back({a,D});
        v[a].push_back({b,D});

    }
    q.push(x);
    inq[x] = 1;
    while(!q.empty())
    {
        int p = q.front();
        parc(p);
        q.pop();
        inq[p] = 0;
    }
    fout << d[y];
    return 0;
}
