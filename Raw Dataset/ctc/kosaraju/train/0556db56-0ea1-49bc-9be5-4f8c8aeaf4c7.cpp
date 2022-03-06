#include <bits/stdc++.h>
using namespace std;

ifstream f("ctc.in");

ofstream g("ctc.out");

const int N=100010;

int n,m,x,y,viz[N],ctc;

vector<int> G[N],GT[N],C[N];

stack <int> st;

void dfs(int nod)

{

    viz[nod]=1;

    for(auto it:G[nod])

        if(!viz[it])

        dfs(it);

    st.push(nod);

}

void dfst(int nod)

{

    viz[nod]=2;

    C[ctc].push_back(nod);

    for(auto it:GT[nod])

        if(viz[it]==1)

    dfst(it);

}

int main()

{

    f>>n>>m;

    for(;m;m--)

    {

        f>>x>>y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }

    for(int i=1;i<=n;i++)

        if(!viz[i])

        dfs(i);

        while(st.size())

        {

            int nodc=st.top();

            if(viz[nodc]==1)

            {

                ctc++;

                dfst(nodc);

            }

           st.pop();

        }

        g<<ctc<<'\n';

        for(int i=1;i<=ctc;i++)

        {

            for(auto it:C[i])

                g<<it<<' ';

            g<<'\n';

        }

    return 0;

}
