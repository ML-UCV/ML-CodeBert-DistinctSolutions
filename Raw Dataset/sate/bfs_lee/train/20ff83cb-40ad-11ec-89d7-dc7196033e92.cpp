#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin ("sate.in");
ofstream fout ("sate.out");

int n, m, X, Y;
vector <vector <pair <int, int>>> v;
vector <int> d;
vector <bool> seen;

void Read ();
void BFS (int node);

int main()
{
    Read ();
    BFS(X);
    fout << d[Y];

    fin.close();
    fout.close();

    return 0;
}

void Read ()
{
    fin >> n >> m >> X >> Y;
    v = vector <vector <pair <int, int>>> (n + 1);
    seen = vector <bool> (n + 1);
    d = vector <int> (n + 1);
    for (int i = 1; i <= m; i++)
    {
        int x, y, cost;
        fin >> x >> y >> cost;
        v[x].push_back({y, cost});
        v[y].push_back({x, -cost});
    }
}

void BFS (int node)
{
    queue <int> Q;
    seen[node] = true;
    Q.push(node);

    while (!Q.empty())
    {
        int x = Q.front();

        for (auto it : v[x])
        {
            if (!seen[it.first])
            {
                seen[it.first] = true;
                Q.push(it.first);
                d[it.first] = d[x] + it.second;
            }
        }
        Q.pop();
    }
}
