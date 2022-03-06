#include <bits/stdc++.h>


using namespace std;

int i, j, aux, n, m, x, y, k;

bool viz[100005], viz2[100005];

vector <int> comp[100005], g[100005], gt[100005];

stack <int> S1, S2;

void dfs(int x)

{

    viz[x] = true;

    for(int i = 0; i < g[x].size(); i ++)

    {

        int aux = g[x][i];

        if(viz[aux] == false)dfs(aux);

    }

    S1.push(x);

}

void dfst(int x)

{

    viz2[x] = true;

    for(int i = 0; i < gt[x].size(); i ++)

    {

        int aux = gt[x][i];

        if(viz2[aux] == false)dfst(aux);

    }

    S2.push(x);

}

int main()

{

    freopen("ctc.in", "r", stdin);

    freopen("ctc.out", "w", stdout);

    scanf("%d %d", &n, &m);

    for(i = 1; i <= m; i ++)

    {

        scanf("%d %d", &x, &y);

        g[x].push_back(y);

        gt[y].push_back(x);

    }

    for(i = 1; i <= n; i ++)

        if(viz[i] == false)dfs(i);

    while(!S1.empty())

    {

        x = S1.top();

        if(viz2[x] == false)

        {

            k ++;

            dfst(x);

            while(!S2.empty())

            {

                comp[k].push_back(S2.top());

                S2.pop();

            }

        }

        S1.pop();

    }

    printf("%d\n", k);

    for(i = 1; i <= k; i ++)

    {

        for(j = 0; j < comp[i].size(); j ++)

            printf("%d ", comp[i][j]);

        printf("%s", "\n");

    }

    return 0;

}
