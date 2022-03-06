#include <fstream>
#include <queue>
#include <vector>
using namespace std;



ifstream fin("apm.in");
ofstream fout("apm.out");

vector <pair <int, int>> v[200001];
int cmin[200001], p[200001];

struct el
{
    int nod, c;
    bool operator <(const el &alt) const
    {
        return c > alt.c;
    }
};

priority_queue<el> q;

int main()
{
    int n, m, i, x, y, c, j;
    int cost = 0;
    el nmin;
    fin >> n >> m;
    for (i = 1; i<=m; i++)
    {
        fin >> x >> y >> c;
        v[x].push_back({y, c});
        v[y].push_back({x, c});
    }
    for (i = 1; i<=n; i++)
        cmin[i] = 1<<30;
    cmin[1] = -(1<<30);
    for (i = 0; i<v[1].size(); i++)
    {
        cmin[v[1][i].first] = min(cmin[v[1][i].first], v[1][i].second);
        p[v[1][i].first] = 1;
        q.push({v[1][i].first, v[1][i].second});
    }
    for (i = 1; i<n; i++)
    {
        while (q.top().c > cmin[q.top().nod])
            q.pop();
        nmin = q.top();
        cost += nmin.c;
        cmin[nmin.nod] = -(1<<30);
        for (j = 0; j<v[nmin.nod].size(); j++)
            if (v[nmin.nod][j].second < cmin[v[nmin.nod][j].first])
            {
                p[v[nmin.nod][j].first] = nmin.nod;
                cmin[v[nmin.nod][j].first] = v[nmin.nod][j].second;
                q.push({v[nmin.nod][j].first, v[nmin.nod][j].second});
            }
    }
    fout << cost << '\n' << n-1 << '\n';
    for (i = 2; i<=n; i++)
        fout << i << ' ' << p[i] << '\n';
    return 0;
}
