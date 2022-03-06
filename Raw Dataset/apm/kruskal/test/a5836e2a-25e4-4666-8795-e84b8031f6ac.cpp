#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("apm.in");
ofstream fout("apm.out");

const int NMAX = 200000;

struct Edge
{
    int x, y, c;

    bool operator < (const Edge other) const
    {
        return c < other.c;
    }
};

int N, M;
int dad[NMAX + 5], rnk[NMAX + 5];

vector < Edge > edges;
vector < Edge > apmEdges;

int root(int node)
{
    if(node == dad[node])
        return node;

    return dad[node] = root(dad[node]);
}

void join(int p, int q)
{
    p = root(p);
    q = root(q);

    if(rnk[p] == rnk[q])
        rnk[p]++, dad[q] = p;
    else if(rnk[p] > rnk[q])
        dad[q] = p;
    else
        dad[p] = q;
}

int main()
{
    fin >> N >> M;

    for(int i = 1; i <= N; i++)
        dad[i] = i;

    for(int i = 1; i <= M; i++)
    {
        int from, to, cost; fin >> from >> to >> cost;
        edges.push_back({from, to, cost});
    }

    sort(edges.begin(), edges.end());

    long long APM = 0;

    for(auto it : edges)
        if(root(it.x) != root(it.y))
        {
            join(it.x, it.y);
            APM += it.c;
            apmEdges.push_back(it);
        }

    fout << APM << '\n' << N - 1 << '\n';

    for(auto it : apmEdges)
        fout << it.x << ' ' << it.y << '\n';

    return 0;
}
