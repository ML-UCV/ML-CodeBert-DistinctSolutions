#include <bits/stdc++.h>
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

int n, X, Y, m;
vector< pair<int, int> > L[30005];
int d[30005]; /// d[i] = distanta de la X la i
int viz[30005];

void Citire()
{
    int x, y, dist;
    fin >> n >> m >> X >> Y;
    while (m--)
    {
        fin >> x >> y >> dist;
        if (x > y) swap(x, y);
        L[x].push_back({y, dist});
        L[y].push_back({x, -dist});
    }
}

void BFS()
{
    int k, i, dist;
    queue<int> q;
    q.push(X);
    viz[X] = 1;
    /// d[X] = 0;
    while (!q.empty())
    {
        k = q.front();
        q.pop();
        for (auto w : L[k])
        {
            i = w.first;
            dist = w.second;
            if (!viz[i])
            {
                viz[i] = 1;
                d[i] = d[k] + dist;
                q.push(i);

                if (i == Y)
                {
                    fout << d[Y] << "\n";
                    return;
                }
            }
        }
    }
}

int main()
{
    Citire();
    BFS();
    return 0;
}
