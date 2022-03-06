#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int NMAX = 100;

const int MMAX = 1000;

int n;

class guests

{

private:

    bool a[NMAX + 5];

public:

    guests(int x = 0)

    {

        memset(a , 0 , sizeof(guests));

    }

    guests operator&(const guests& b)

    {

        guests c;

        for(int i = 1 ; i <= n ; i ++)

            c.a[i] = (a[i] & b.a[i]);

        return c;

    }

    guests operator|(const guests& b)

    {

        guests c;

        for(int i = 1 ; i <= n ; i ++)

            c.a[i] = (a[i] | b.a[i]);

        return c;

    }

    bool operator==(const guests& b)

    {

        for(int i = 1 ; i <= n ; i ++)

            if(a[i] != b.a[i])

                return 0;

        return 1;

    }

    void init(int x = 0 , int y = 0)

    {

        a[x] = a[y] = 1;

    }

    void init(bool b[NMAX + 5])

    {

        for(int i = 1 ; i <= n ; i ++)

            a[i] = b[i];

    }

    int nr_elim()

    {

        int nr = 0 , i;

        for(i = 1 ; i <= n ; i ++)

            nr += a[i];

        return nr;

    }

    void afisare()

    {

        for(int i = 1 ; i <= n ; i ++)

            if(!a[i])

                printf("%d\n" , i);

    }

};

guests t0[MMAX + 5] , t3[2 * MMAX + 5] , sol;

int a[MMAX + 5] , b[MMAX + 5] , l , maxim , k0;

bool elim[NMAX + 5];

vector <int> G[NMAX + 5];

void dfs(int u)

{

    int v , j;

    elim[u] = 1;

    for(j = 0 ; j < G[u].size() ; j ++)

    {

        v = G[u][j];

        if(!elim[v])

            dfs(v);

    }

}

int valid(guests p1 , guests p2)

{

    guests aux;

    aux = (p1 | p2);

    for(int i = 1 ; i <= k0 ; i ++)

        if((aux & t0[i]) == t0[i])

            return 0;

    return 1;

}

void backt(int k , guests p)

{

    if(k == l + 1)

    {

        int aux = p.nr_elim();

        if(n - aux > maxim)

        {

            maxim = n - aux;

            sol = p;

        }

    }

    else

    {

        if(valid(p , t3[k]))

            backt(k + 2 , (p | t3[k]));

        if(valid(p , t3[k + 1]))

            backt(k + 2 , (p | t3[k + 1]));

    }

}

void add(int x)

{

    memset(elim , 0 , sizeof(elim));

    dfs(x);

    t3[++ l].init(elim);

}

int main()

{

    freopen("party.in" , "r" , stdin);

    freopen("party.out" , "w" , stdout);

    int m , i , x , y , type , k3;

    scanf("%d%d" , &n , &m);

    k3 = 0;

    for(i = 1 ; i <= m ; i ++)

    {

        scanf("%d%d%d" , &x , &y , &type);

        if(type == 0)

            t0[++ k0].init(x , y);

        else if(type == 1)

            G[x].push_back(y);

        else if(type == 2)

            G[y].push_back(x);

        else

        {

            a[++ k3] = x;

            b[k3] = y;

        }

    }

    l = 0;

    for(i = 1 ; i <= k3 ; i ++)

    {

        add(a[i]);

        add(b[i]);

    }

    guests p;

    backt(1 , p);

    printf("%d\n" , n - sol.nr_elim());

    sol.afisare();

    return 0;

}
