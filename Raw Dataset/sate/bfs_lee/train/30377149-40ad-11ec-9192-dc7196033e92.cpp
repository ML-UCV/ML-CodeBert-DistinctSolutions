#include <cstdio>

using namespace std;

FILE *f, *g;

int k;

int lst[30009];

int urm[200050];
int val[200050];

int nod[200050];

void add(int a, int b, int d)
{
    k ++;

    urm[k] = lst[a];
    nod[k] = b;
    val[k] = d;

    lst[a] = k;
}

int m, n, x, y;

void readFile()
{
    f = fopen("sate.in", "r");

    fscanf(f, "%d%d%d%d", &m, &n, &x, &y);

    int i, a, b, d;
    for(i = 1; i <= n; i ++)
    {
        fscanf(f, "%d%d%d", &a, &b, &d);

        add(a, b,  d);
        add(b, a, -d);
    }

    fclose(f);
}

int que[30009];
bool inQue[30009];

bool viz[30009];

int dist[30009];

int rez;

void bfs(int start)
{
    int st = 1, dr = 0;

    que[++ dr] = start;

    int nd;
    int d = 0;

    int p;

    while(st <= dr)
    {
        nd = que[st];
        d = dist[st];

        st ++;

        viz[nd] = 1;

        for(p = lst[nd]; p != 0; p = urm[p])
        {
            if(viz[nod[p]] == 0)
            {
                if(nod[p] == y)
                {
                    rez = d + val[p];

                    return;
                }

                viz[nod[p]] = 1;

                que[++ dr] = nod[p];
                dist[dr] = d + val[p];
            }
        }
    }
}

void solve()
{
    bfs(x);
}

void printFile()
{
    g = fopen("sate.out", "w");

    fprintf(g, "%d\n", rez);

    fclose(g);
}

int main()
{
    readFile();

    solve();

    printFile();

    return 0;
}
