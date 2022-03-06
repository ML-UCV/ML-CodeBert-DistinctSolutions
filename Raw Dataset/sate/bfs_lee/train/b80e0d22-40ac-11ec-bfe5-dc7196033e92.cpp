#include <fstream>
#include <queue>
#include <vector>

using namespace std;
ifstream in ("sate.in");
ofstream out ("sate.out");

struct muchie
{
    int oras,distanta;
}temp,temp2;

int dist[30002];
vector <int> muo[30002], mud[30002];
queue <int> q;
bool vis[30002];

void bfs(int start)
{
    q.push(start);
    vis[start] = 1;

    while(!q.empty())
    {
        int aux = q.front();

        for(int i = 0; i < muo[aux].size(); i++)
        {
            if(vis[muo[aux][i]] == 0)
            {
                q.push(muo[aux][i]);
                vis[muo[aux][i]] = 1;
                if(muo[aux][i] > aux)
                    dist[muo[aux][i]] = dist[aux] + mud[aux][i];
                else
                    dist[muo[aux][i]] = dist[aux] - mud[aux][i];
            }
        }
        q.pop();
    }
}

void citire(int m)
{
    int a, b, d;
    for (int i = 1 ; i <= m ; i++)
    {
        in >> a >> b >> d;

        muo[a].push_back(b);
        mud[a].push_back(d);

        muo[b].push_back(a);
        mud[b].push_back(d);
    }
}

int main()
{
    int n, m, i, j, x, y;

    in >> n >> m >> x >> y;

    citire(m);

    bfs(x);

    out << max(dist[x]-dist[y],dist[y]-dist[x]);
    return 0;
}
