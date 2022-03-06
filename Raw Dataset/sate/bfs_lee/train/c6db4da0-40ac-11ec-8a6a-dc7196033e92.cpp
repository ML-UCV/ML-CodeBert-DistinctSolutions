#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream in ("sate.in");
ofstream out ("sate.out");

const int MAXN = 30000;
vector <pair <int, int>> adj[MAXN + 1];
vector <int> vis(MAXN + 1, -1);
queue <int> q;

int N, M, X, Y;

void bfs (int startNode)
{
    q.push(startNode);
    vis[startNode] = 0;

    while (!q.empty())
    {
        int currNode = q.front();
        q.pop();

        for (auto nbh: adj[currNode])
            if (vis[nbh.first] == -1)
            {
                 q.push(nbh.first);
                 vis[nbh.first] = vis[currNode] + 1;
            }
    }
}

int res(int endNode)
{
    int cnt = vis[endNode];
    int currNode = endNode;
    int r = 0;
    while (cnt > 0)
    {
        cnt--;
        int next = currNode;
        for(auto nbh: adj[currNode])
            if (vis[nbh.first] == cnt)
            {
                if (currNode > nbh.first)
                    r +=  nbh.second;
                else
                    r -= nbh.second;
                next = nbh.first;
                break;
            }
        currNode = next;
    }
    return r;
}

int main()
{
    in >> N >> M >> X >> Y;

    int x, y, c;
    for (int i = 0; i < M; ++i)
    {
        in >> x >> y >> c;
        adj[x].push_back({y, c});
        adj[y].push_back({x, c});
    }

    bfs (min(X, Y));

    out << res(max(X, Y)) << "\n";

    return 0;
}
