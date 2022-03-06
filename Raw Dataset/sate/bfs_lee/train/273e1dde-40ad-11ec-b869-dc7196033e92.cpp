#include <bits/stdc++.h>

using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
#define pb push_back
#define pii pair<int, int>
#define x first
#define y second
const int Nmax = 30000 + 5;
int n, m, src, fnl;
int dist[Nmax];
bool viz[Nmax], inq[Nmax];
queue<int>q;
vector<pii> v[Nmax];
int main()
{
    fin >> n >> m >> src >> fnl;
    for(int i = 1, a, b ,c; i <= m; ++i)
    {
        fin >> a >> b >> c;
        v[a].pb({b,c});
        v[b].pb({a,c});
    }
    for(int i =  1; i <=n; ++i)dist[i] = 1 << 30;
    dist[src] = 0;inq[src] = 1;
    q.push(src);
    while(!q.empty())
    {
        int nod = q.front();
        q.pop();
        inq[nod] = 0;
        for(auto i : v[nod])
        {
            if(i.x > nod && dist[i.x] > dist[nod] + i.y)
            {
                dist[i.x] = dist[nod] + i.y;
                if(!inq[i.x])
                {
                    inq[i.x] = 1;
                    q.push(i.x);
                }
            }
            else if(i.x < nod && dist[i.x] > dist[nod] - i.y)
            {
                dist[i.x] =dist[nod] - i.y;
                if(!inq[i.x])
                {
                    inq[i.x] = 1;
                    q.push(i.x);
                }
            }
        }
    }
    fout << dist[fnl];
    return 0;
}
