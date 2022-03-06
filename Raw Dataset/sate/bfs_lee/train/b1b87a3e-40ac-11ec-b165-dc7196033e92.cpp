#include <fstream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

ifstream cin("sate.in");
ofstream cout("sate.out");

const int N=30001;

int n,m,p,pq,nod1,nod2,dist;
int d[N];
vector< pair<int,int> >v[N];
queue<int>q;

void bfs(int start)
{
    q.push(start);
    d[start]=0;
    while(!q.empty())
    {
        int nod=q.front();
        q.pop();
        for(size_t i=0;i<v[nod].size();i++)
        {
            int el=v[nod][i].first;
            int dst=v[nod][i].second;
            if(d[el]==-1)
            {
                if(el>nod)
                {
                    d[el]=d[nod]+dst;
                }
                else d[el]=d[nod]-dst;
                q.push(el);
            }
        }
    }
}

int main()
{
    cin>>n>>m>>p>>pq;
    for(int i=1;i<=m;i++)
    {
        cin>>nod1>>nod2>>dist;
        v[nod1].push_back(make_pair(nod2,dist));
        v[nod2].push_back(make_pair(nod1,dist));
    }
    memset(d,-1,sizeof(d));
    bfs(p);
    cout<<d[pq];
    return 0;
}
