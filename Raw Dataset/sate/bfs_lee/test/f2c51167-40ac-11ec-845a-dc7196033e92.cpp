#include <fstream>

using namespace std;
ifstream cin("sate.in");
ofstream cout("sate.out");
const int MAXN = 50001, MAXM = 500025, INF = -(1 << 31);

int lst[MAXN], vf[MAXM], urm[MAXM], dist[MAXM], d[MAXN], q[MAXN];
int n, m, x, y, nr;
void adauga(int, int, int);
void bfs(int);
int main()
{
    cin >> n >> m >> x >> y;
    for(int i = 1; i <= m; ++i)
    {
        int x1, y1, dis;
        cin >> x1 >> y1 >> dis;
        adauga(x1, y1, dis);
        adauga(y1, x1, dis);
    }
    bfs(x);
    cout << d[y];
    return 0;
}

void adauga(int x, int y, int dis)
{
    ++nr;
    vf[nr] = y;
    dist[nr] = dis;
    urm[nr] = lst[x];
    lst[x] = nr;
}

void bfs(int start)
{
    for(int i = 1; i <= n; ++i)
        d[i] = INF;
    int st = 0, dr = -1;
    q[++dr] = start;
    d[start] = 0;
    while(st <= dr)
    {
        int x = q[st++];
        for(int p = lst[x]; p; p = urm[p])
        {
            int y = vf[p];
            if(d[y] == INF)
            {
                q[++dr] = y;
                if(x < y)
                    d[y] = dist[p] + d[x];
                else
                    d[y] = d[x] - dist[p];
            }
        }
    }
}
