#include <bits/stdc++.h>


using namespace std;







int N, M;

vector <int> edg[205], redg[205];

int O, ord[205];

int f[205];

int C, cmp[205];

vector <int> scc[205];

vector <int> sccedg[205];

int g[205];

int ans[205], v[205];

vector <int> party;



inline int node(int x) { return x > 0 ? x : -x + N; }

inline int value(int x) { return x <= N ? x : -x + N; }



void DFS1(int nod)

{

    if(f[nod]) return;

    f[nod] = 1;

    for(auto nxt: edg[nod])

        DFS1(nxt);

    ord[++O] = nod;

}



void DFS2(int nod)

{

    if(f[nod] == 2) return;

    f[nod] = 2;

    cmp[nod] = C;

    scc[C].push_back(nod);

    for(auto nxt: redg[nod])

        DFS2(nxt);

}



void solveDFS(int nod, int fth)

{

    if(ans[nod] == -1)

    {

        ans[nod] = fth;

        for(auto x: scc[nod])

        {

            int rev = node( -value(x) );

            ans[ cmp[rev] ] = 1 ^ fth;

        }

    }

    assert(!fth || (fth == ans[nod]));



    for(auto nxt: sccedg[nod])

    {

        g[nxt]--;

        if(g[nxt] == 0)

            solveDFS(nxt, fth | ans[nod]);

    }

}



int main()

{



    freopen("party.in", "r", stdin);

    freopen("party.out", "w", stdout);





    scanf("%d%d", &N, &M);

    for(int i = 1; i <= M; i++)

    {

        int x, y, op;

        scanf("%d%d%d", &x, &y, &op);

        if(op == 0)

        {

            edg[node(-x)].push_back(y);

            edg[node(-y)].push_back(x);

        }

        else if(op == 1)

        {

            edg[node(-x)].push_back(node(-y));

            edg[node(y)].push_back(node(x));

        }

        else if(op == 2)

        {

            edg[node(x)].push_back(node(y));

            edg[node(-y)].push_back(node(-x));

        }

        else if(op == 3)

        {

            edg[node(x)].push_back(node(-y));

            edg[node(y)].push_back(node(-x));

        }

    }



    for(int i = 1; i <= 2 * N; i++) DFS1(i);

    for(int i = 1; i <= 2 * N; i++)

        for(auto x: edg[i])

            redg[x].push_back(i);

    reverse(ord + 1, ord + 2 * N + 1);

    for(int i = 1; i <= 2 * N; i++)

        if( f[ ord[i] ] != 2 ) ++C, DFS2(ord[i]);



    for(int i = 1; i <= N; i++) assert(cmp[i] != cmp[i + N]);



    for(int i = 1; i <= C; i++) f[i] = 0;

    for(int i = 1; i <= C; i++)

        for(auto nod: scc[i])

            for(auto nxt: edg[nod])

                if(i != cmp[nxt])

                    if(f[ cmp[nxt] ] != i)

                        sccedg[i].push_back(cmp[nxt]), g[ cmp[nxt] ]++, f[ cmp[nxt] ] = i;



    for(int i = 1; i <= C; i++) ans[i] = -1;

    for(int i = 1; i <= C; i++)

        if(ans[i] == -1) solveDFS(i, 0);



    for(int i = 1; i <= C; i++)

        for(auto nod: scc[i])

            v[nod] = ans[i];



    for(int i = 1; i <= N; i++)

        if(v[i])

            party.push_back(i);



    printf("%d\n", party.size());

    for(auto x: party)

        printf("%d\n", x);



    return 0;

}
