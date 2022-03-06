#include <queue>
#include <fstream>
#include <algorithm>
#include <cstring>

#define limit 5000
#define ch buffer[position]
#define Next (++position == limit) ? (fin.read(buffer, limit), position = 0) : 0

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

const int NMAX = 30001;
int position;
char buffer[limit];
int nodes, edges, X, Y;
vector < pair <int, int> > graph[NMAX];
int dist[NMAX];
queue <int> q;

void Read(int &x)
{
    x = 0;
    for (; !('0' <= ch && ch <= '9'); Next);
	for (; ('0' <= ch && ch <= '9'); x = x * 10 + (ch - '0'), Next);
}

int main()
{
    Read(nodes);
    Read(edges);
    Read(X);
    Read(Y);
    for (int i = 1;i <= edges;++i)
    {
        int x, y, d;
        Read(x);
        Read(y);
        Read(d);
        graph[x].push_back(make_pair(y, d));
        graph[y].push_back(make_pair(x, -d));
    }
    q.push(X);
    if (X == Y)
        q.pop();
    while (!q.empty())
    {
        int node = q.front();
        if (node == Y)
            break;
        q.pop();
        for (auto &next : graph[node])
        {
            if (dist[next.first] == 0)
            {
                dist[next.first] = dist[node] + next.second;
                q.push(next.first);
            }
        }
    }
    fout << dist[Y] << "\n";
    fin.close();
    fout.close();
    return 0;
}
