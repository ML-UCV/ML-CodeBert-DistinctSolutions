#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;



int n, m, tip, nod, nc, x, y, i, j, k, nr;
int f[220], ctc[220], s[220], t[220];
vector<int> v[220], inv[220];

int nt(int x)
{
    return (x+n)%(2*n);
}

void add(int x, int y)
{
    v[nt(x)].push_back(y);
    v[nt(y)].push_back(x);
    inv[x].push_back(nt(y));
    inv[y].push_back(nt(x));
}

void df1(int nod)
{
    if(f[nod])
        return;
    f[nod]=1;

    for(int i=0; i<v[nod].size(); ++i)
        df1(v[nod][i]);

    s[++s[0]]=nod;
}

void df2(int comp, int nod)
{
    if(f[nod])
        return;
    f[nod]=1;

    ctc[nod]=comp;
    for(int i=0; i<inv[nod].size(); ++i)
        df2(comp, inv[nod][i]);
}

int main()
{
    freopen("party.in", "r", stdin);
    freopen("party.out", "w", stdout);

    scanf("%d%d", &n, &m);
    while(m--)
    {
        scanf("%d%d%d", &x, &y, &tip);
        --x; --y;
        if(tip&1)
            y=nt(y);
        if(tip&2)
            x=nt(x);
        add(x, y);
    }

    for(int i=0; i<2*n; ++i)
        if(!f[i])
            df1(i);

    memset(f, 0, sizeof(f));
    for(int i=2*n; i; --i)
    {
        t[i-1]=2;
        if(!f[s[i]])
            df2(++nc, s[i]);
    }

    for(int i=2*n; i; --i)
    {
        nod=s[i];
        if(t[ctc[nod]]!=2)
            continue;
        t[ctc[nod]]=0;
        t[ctc[nt(nod)]]=1;
    }

    nr=0;
    for(int i=0; i<n; ++i)
        nr+=t[ctc[i]];

    printf("%d\n", nr);
    for(int i=0; i<n; ++i)
        if(t[ctc[i]])
            printf("%d\n", i+1);

    return 0;
}
