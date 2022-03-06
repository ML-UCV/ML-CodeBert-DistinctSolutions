#include <fstream>
#include <vector>
#include <queue>

using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
int n,m,x,y,i,j,d,marker[30001],sol[30001];
vector <pair <int,int> > a[30001];
queue <int> q;
void bfs()
{
    q.push(x);
    marker[x]=1;
    while(!q.empty())
    {
        int k=q.front();
        for(int i=0; i<a[k].size(); i++)
        {
            int j=a[k][i].first,d=a[k][i].second;
            if(!marker[j])
            {
                marker[j]=1;
                if(k<j) sol[j]=sol[k]+d;
                else sol[j]=sol[k]-d;
                q.push(j);
            }
        }
        q.pop();
    }
}
int main()
{
    f>>n>>m>>x>>y;
    for(int k=1; k<=m; k++)
    {
        f>>i>>j>>d;
        a[i].push_back(make_pair(j,d));
        a[j].push_back(make_pair(i,d));
    }
    bfs();
    g<<sol[y];
    return 0;
}
