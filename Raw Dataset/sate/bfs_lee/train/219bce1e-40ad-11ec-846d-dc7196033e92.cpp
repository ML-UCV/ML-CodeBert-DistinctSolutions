#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

vector< pair<int,int> > graf[30005];
int dist[30005];
queue<int> noduri;
int n,m,x,y;

void bfs()
{
    while(!noduri.empty())
    {
        int a=noduri.front();
        noduri.pop();
        for(auto dest:graf[a])
        {
            if(dist[dest.first]==0)
            {
                if(dest.first<a) dist[dest.first] = dist[a]-dest.second;
                else if(dest.first>a) dist[dest.first] = dist[a]+dest.second;
                if(dest.first==y) return;
                noduri.push(dest.first);
            }
        }
    }
}

int main()
{
    int sat1, sat2, d;
    f >> n >> m >> x >> y;

    for(int i=1; i<=m; i++)
    {
        f >> sat1 >> sat2 >> d;
        graf[sat1].push_back({sat2,d});
        graf[sat2].push_back({sat1,d});
    }

    for(int i=1; i<=n; i++)
    {
        dist[i] = 0;
    }
    dist[x] = 0;
    noduri.push(x);
    bfs();
    g << dist[y];

    return 0;
}
