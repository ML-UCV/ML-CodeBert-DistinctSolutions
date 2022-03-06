#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
std::ifstream in("ctc.in");

std::ofstream out("ctc.out");

const int NMAX = 100000;

std::vector<int>g[NMAX + 3],gt[NMAX + 3];

std::vector<int>sol[NMAX + 3];

std::stack<int>st;

int viz[NMAX + 3];

int visit[NMAX + 3];

int ans;

void tpsort(int x)

{

    viz[x] = 1;

    for(int i = 0;i < g[x].size();i++)

    {

        if(!viz[g[x][i]])

            tpsort(g[x][i]);

    }

    st.push(x);

}

void dfs(int u)

{

    visit[u] = 1;

    sol[ans].push_back(u);

    for(int i = 0;i < gt[u].size();i++)

    {

        if(!visit[gt[u][i]])

            dfs(gt[u][i]);

    }

}

int main()

{

    int n,m,u,v,x;

    in>>n>>m;

    for(int i = 1;i <= m;i++)

    {

        in>>u>>v;

        g[u].push_back(v);

        gt[v].push_back(u);

    }

    for(int i = 1;i <= n;i++)

    {

        if(!viz[i])

            tpsort(i);

    }

    while(!st.empty())

    {

        x = st.top();

        st.pop();

        if(!visit[x])

        {

            ans++;

            dfs(x);

        }

    }

    out<<ans<<'\n';

    for(int i = 1;i <= ans;i++)

    {

        for(int j = 0;j < sol[i].size();j++)

            out<<sol[i][j]<<' ';

        out<<'\n';

    }

    return 0;

}
