#include <bits/stdc++.h>

using namespace std;

ifstream fin ("sate.in");
ofstream fout ("sate.out");

int n, m, Start, Final;
vector<pair<int, int> >L[30005];
/// L[i].first = j (satul cu care are drum)
/// L[i].second = d (distanta de la i la j)
int viz[30005], d[30005];
queue<int> q;

void Citire()
{
    int x, y, dist;
    fin >> n >> m >> Start >> Final;
    for (int i = 1; i <= m; i++)
    {
        fin >> x >> y >> dist;
        if (x > y)
            swap(x, y);
        L[x].push_back({y, dist});
        L[y].push_back(make_pair(x, -dist));
    }
}

void BFS()
{
    int x, y, dist;
    q.push(Start);
    viz[Start] = 1;
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        for (auto i : L[x])
        {
            y = i.first;
            dist = i.second;
            if (!viz[y])
            {
                viz[y] = 1;
                d[y] = d[x] + dist;
                q.push(y);

                if (y == Final)
                {
                    fout << d[Final] << "\n";
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
