#include <bits/stdc++.h>

using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

int n,m,x,y,d[30005];

vector<pair<int,int>>a[30005];

void citire()
{
    in >> n >> m >> x >> y;
    for (int i = 1; i <= m; i++)
    {
        int ai,bi,di;
        in >> ai >> bi >> di;
        a[ai].push_back({bi,di});
        a[bi].push_back({ai,-di});
    }
    for (int i = 1; i <= n; i++)
        d[i] = -1;
}

queue<int>q;

void BFS()
{
    q.push(x);
    d[x] = 0;
    while (!q.empty())
    {
        int nod = q.front();
        q.pop();
        for (int i = 0; i < a[nod].size(); i++)
        {
            int vecin = a[nod][i].first;
            if (d[vecin] == -1)
            {
                d[vecin] = d[nod] + a[nod][i].second;
                q.push(vecin);
            }
        }
    }
}

int main()
{
    citire();
    BFS();
    out << d[y];
    return 0;
}
