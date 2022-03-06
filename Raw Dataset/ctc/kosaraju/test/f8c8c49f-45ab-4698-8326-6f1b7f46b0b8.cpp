#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int NMAX = 100000;

vector <int> G[NMAX + 5] , T[NMAX + 5] , ctc[NMAX + 5];

int viz[NMAX + 5] , st[NMAX + 5] , top , nr;

void dfs(int u)

{

    int v , j;

    viz[u] = 1;

    for(j = 0 ; j < G[u].size() ; j ++)

    {

        v = G[u][j];

        if(viz[v] == 0)

            dfs(v);

    }

    st[++ top] = u;

}

void dfst(int u)

{

    int v , j;

    viz[u] = 1;

    ctc[nr].push_back(u);

    for(j = 0 ; j < T[u].size() ; j ++)

    {

        v = T[u][j];

        if(viz[v] == 0)

            dfst(v);

    }

}

int main()

{

    freopen("ctc.in" , "r" , stdin);

    freopen("ctc.out" , "w" , stdout);

    int n , m , i , j , x , y;

    scanf("%d%d" , &n , &m);

    for(i = 1 ; i <= m ; i ++)

    {

        scanf("%d%d" , &x , &y);

        G[x].push_back(y);

        T[y].push_back(x);

    }

    for(i = 1 ; i <= n ; i ++)

        if(viz[i] == 0)

            dfs(i);

    memset(viz , 0 , sizeof(viz));

    for(i = top ; i >= 1 ; i --)

        if(viz[st[i]] == 0)

        {

            nr ++;

            dfst(st[i]);

        }

    printf("%d\n" , nr);

    for(i = 1 ; i <= nr ; i ++)

    {

        for(j = 0 ; j < ctc[i].size() ; j ++)

            printf("%d " , ctc[i][j]);

        printf("\n");

    }

    return 0;

}
