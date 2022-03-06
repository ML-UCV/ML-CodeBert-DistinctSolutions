#include <iostream>
#include <fstream>

using namespace std;

const int N = 100005, M = 200005;
int n, m, vf[M], urm[M], lst[N], q[N], vf2[M], urm2[M], lst2[N], nr, cnt, st[N], st2[N], nvf[N];
bool viz[N], viz2[N];

ifstream in("ctc.in");
ofstream out("ctc.out");

void adauga(int a, int b)
{
    vf[++nr] = b;
    urm[nr] = lst[a];
    lst[a] = nr;
    vf2[nr] = a;
    urm2[nr] = lst2[b];
    lst2[b] = nr;
}

void dfs(int x)
{
    viz[x] = true;
    for(int p = lst[x]; p != 0; p = urm[p])
    {
        int y = vf[p];
        if(!viz[y])
        {
            dfs(y);
        }
    }
    st[++nr] = x;
}

void dfs2(int x)
{
    viz2[x] = true;
    nvf[cnt]++;
    st2[++nr] = x;
    for(int p = lst2[x]; p != 0; p = urm2[p])
    {
        int y = vf2[p];
        if(!viz2[y])
        {
            dfs2(y);
        }
    }
}

int main()
{
    int x, y;
    in >> n >> m;
    for(int i = 0; i < m; i++)
    {
        in >> x >> y;
        adauga(x, y);
    }
    nr = 0;
    for(int i = 1; i <= n; i++)
    {
        if(viz[i] == 0)
        {
            dfs(i);
        }
    }
    nr = 0;
    cnt = 0;
    for(int i = n; i >= 1; i--)
    {
        if(!viz2[st[i]])
        {
            cnt++;
            dfs2(st[i]);
        }
    }
    out << cnt << "\n";
    int j = 1;
    for (int i = 1; i <= cnt; i++)
    {
        for (int k = 0; k < nvf[i]; k++)
        {
            out << st2[j++] << " ";
        }
        out << "\n";
    }
    return 0;
}
