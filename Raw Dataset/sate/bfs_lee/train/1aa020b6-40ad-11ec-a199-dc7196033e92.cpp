#include <bits/stdc++.h>
#define in "sate.in"
#define out "sate.out"
#define Nmax 30003
using namespace std;
ifstream fin(in);
ofstream fout(out);

struct sate
{
    int nod;
    int dist;
};

int n,m;
int X,Y;
int d[Nmax];
vector <sate> L[Nmax];
queue <int> q;

void Read()
{
    int x,y,cost,i;
    sate s;

    fin >> n >> m >> X >> Y;
    for (i = 1; i <= m; i++)
    {
        fin >> x >> y >> cost;

        s.nod = y;
        s.dist = cost;
        L[x].push_back(s);

        s.nod = x;
        L[y].push_back(s);
    }
}

void Init()
{
    int i;

    for (i = 1; i <= n; i++)
        d[i] = -1;
}

void BFS(int k)
{
    int nod,cost;

    q.push(k);
    d[k] = 0;
    while(!q.empty())
    {
        k = q.front();
        q.pop();
        for (auto i : L[k])
        {
            nod = i.nod;
            cost = i.dist;
            if (d[nod] == -1)
            {
                if (nod > k) d[nod] = d[k] + cost;
                else d[nod] = d[k] - cost;
                q.push(nod);
            }
        }
    }
}

int main()
{
    Read();
    Init();
    BFS(X);
    fout << d[Y] << "\n";

    fin.close();
    fout.close();
    return 0;
}
