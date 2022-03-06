#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int n, m, x, y, p, viz[1007], sol[1007], ct;

vector <int> g[1007], gt[1007];

stack <int> order;

void convert(int &a)

{

    if(a < 0) a = (((0-a)<<1) | 1);

    else a = (a<<1);

}

void add(const int &a, const int &b)

{

    g[a].push_back(b);

    gt[b].push_back(a);

}

void create()

{

    if(p == 0)

    {

        add((x^1), y);

        add((y^1), x);

    }

    if(p == 1)

    {

        add((x^1), (y^1));

        add(y, x);

    }

    if(p == 2)

    {

        add(x, y);

        add((y^1), (x^1));

    }

    if(p == 3)

    {

        add(x, (y^1));

        add(y, (x^1));

    }

}

void dfsort(const int &nod)

{

    viz[nod] = 1;

    for(int i = g[nod].size()-1; i+1; --i)

    {

        if(!viz[g[nod][i]]) dfsort(g[nod][i]);

    }

    order.push(nod);

}

void dfsat(const int &nod)

{

    viz[nod] = 0;

    if(sol[nod]) printf("check\n");

    sol[nod] = 0;

    sol[(nod^1)] = 1;

    if(nod&1) ++ct;

    for(int i = gt[nod].size()-1; i+1; --i)

    {

        if(viz[gt[nod][i]]) dfsat(gt[nod][i]);

    }

}

void sortare()

{

    int tmp;

    for(int i = 1; i<= n; ++i)

    {

        tmp = (i<<1);

        if(!viz[tmp]) dfsort(tmp);

        tmp = (tmp|1);

        if(!viz[tmp]) dfsort(tmp);

    }

}

void sat()

{

    int tmp;

    while(!order.empty())

    {

        tmp = order.top();

        order.pop();

        if(viz[tmp] && viz[(tmp^1)]) dfsat(tmp);

    }

}

int main()

{

    freopen("party.in", "r", stdin);

    freopen("party.out", "w", stdout);

    scanf("%d %d", &n, &m);

    for(int i = 1; i<= m; ++i)

    {

        scanf("%d %d %d", &x, &y, &p);

        convert(x); convert(y);

        create();

    }

    sortare();

    sat();

    printf("%d\n", ct);

    for(int i = 1; i<= n; ++i)

    {

        if(sol[(i<<1)]) printf("%d\n", i);

    }

    return 0;

}
