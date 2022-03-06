#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

const int N = 3e4 + 1;
int n, m, x, y, d[N];
vector <pair<int, int>> G[N];
queue <int> q;

void bfs(int n)
{
    q.push(n);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(auto y : G[x])
        {
            if(d[y.first] == 0)
            {
                d[y.first] = d[x] + y.second;
                q.push(y.first);
            }
        }
    }
}

int main()
{
    in >> n >> m >> x >> y;

    for(int i=1; i<=m; i++)
    {
        int a, b, dist;
        in >> a >> b >> dist;
        G[a].push_back({b,dist});
        G[b].push_back({a,-dist});
    }

    bfs(x);
    out << d[y] << " ";
    return 0;
}
