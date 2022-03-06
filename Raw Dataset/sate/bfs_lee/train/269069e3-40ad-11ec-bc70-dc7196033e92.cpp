#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <queue>
#define INF (1<<30)
#define pii pair <int, int>
#define x first
#define y second
#define NMAX 30005

using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");

int n, m, X, Y;
int dp[NMAX], inq[NMAX];
vector <pii> v[NMAX];
queue <int> q;

void parc(int nod)
{
    vector <pii> :: iterator it;
    for (it = v[nod].begin(); it != v[nod].end(); it++)
    {
        pii nr = *it;
        int nxt = nr.first;
        int cst = nr.second;
        if (nod < nxt)
        {
            if (dp[nod] + cst < dp[nxt])
            {
                if (!inq[nxt])
                    q.push(nxt), inq[nxt] = 1;
                dp[nxt] = dp[nod] + cst;
            }
        }
        else
            if (dp[nod] - cst < dp[nxt])
            {
                if (!inq[nxt])
                    q.push(nxt), inq[nxt] = 1;
                dp[nxt] = dp[nod] - cst;
            }

    }
}

int main()
{
    fin >> n >> m >> X >> Y;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        fin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++)
        dp[i] = INF;
    dp[X] = 0;
    inq[X] = 1;
    q.push(X);
    while (!q.empty())
    {
        int nod = q.front();
        inq[nod] = 0;
        q.pop();
        parc(nod);
    }
    fout << dp[Y] << "\n";
    return 0;
}
