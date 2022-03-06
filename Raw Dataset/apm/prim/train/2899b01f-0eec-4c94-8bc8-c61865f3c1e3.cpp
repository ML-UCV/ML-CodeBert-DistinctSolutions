#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
ifstream f ("apm.in");
ofstream g ("apm.out");
int n, m;
vector < pair<int, int>> *vec;
int x, y, c;
int *d, *t, *viz;
int s;
void citire()
{
    f >> n >> m;
    vec = new vector < pair<int, int>>[n + 1];
    for (int i = 1; i <= m; ++i)
    {
        f >> x >> y >> c;
        vec[x].push_back ({y, c});
        vec[y].push_back ({x, c});
    }
    f.close();
}
void golire_alocare_dinamica()
{
    d=new int[n+1];
    t=new int[n+1];
    viz=new int[n+1];
    for (int i = 1; i <= n; ++i)
    {
        d[i] = INT_MAX;
        t[i] = 0;
        viz[i] = 0;
    }
}
void afisare()
{
    s = 0;
    for (int i = 1; i <= n; i++)
        s += d[i];
    g << s << '\n' << n - 1 << '\n';
    for (int i = 1; i <= n; i++)
        if (t[i] != 0)
            g << t[i] << " " << i << '\n';
    g.close();
}
void prim()
{
    s = 1;
    d[s] = 0;

    priority_queue < pair <int, int>> q;
    q.push ({-d[s], s});
    while (!q.empty() )
    {
        x = q.top().second;
        q.pop();
        viz[x] = 1;
        for (auto i : vec[x])
        {
            y = i.first;
            c = i.second;
            if (viz[y] == 0 && d[y] > c)
            {
                t[y] = x;
                d[y] = c;
                q.push ({-d[y], y});
            }
        }
    }
}
int main()
{
    citire();

    golire_alocare_dinamica();

    prim();

    afisare();

    return 0;
}
