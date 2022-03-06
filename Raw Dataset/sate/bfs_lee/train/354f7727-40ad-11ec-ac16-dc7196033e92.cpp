#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
int x, y, n, cost[30001];
vector <pair<int, int> > g[30001];
void citire()
{
    int m, i, j, c;
    fin>>n>>m>>x>>y;
    while(m)
    {
        m--;
        fin>>i>>j>>c;
        g[i].push_back(make_pair(j, c));
        g[j].push_back(make_pair(i, -c));
    }
    fin.close();
}
void bfs()
{
    queue <int> q;
    int k;
    vector <pair<int, int> > :: iterator it;
    q.push(x);
    cost[x]=1;
    while(!q.empty())
    {
        k=q.front();
        q.pop();
        for(it=g[k].begin(); it!=g[k].end(); it++)
            if(cost[it->first]==0)
            {
                cost[it->first]=cost[k]+it->second;
                if(it->first==y)
                    return;
                q.push(it->first);
            }
    }
}
int main()
{
    citire();
    bfs();
    fout<<cost[y]-1;
    return 0;
}
