#include <fstream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

ifstream f("ctc.in");

ofstream g("ctc.out");

vector<int>v[100005],v2[100005],sol[100005];

stack<int>st;

int n,m,d[100005],x,y,k,nr;

void dfs1(int nod)

{

    d[nod]=1;

    for(int i=0;i<v[nod].size();i++)

    {

        if(!d[v[nod][i]]) dfs1(v[nod][i]);

    }

    st.push(nod);

}

void dfs2(int nod)

{

    d[nod]=1;

    sol[nr].push_back(nod);

    for(int i=0;i<v2[nod].size();i++)

    {

        if(!d[v2[nod][i]]) dfs2(v2[nod][i]);

    }

}

int main()

{

    f>>n>>m;

    for(int i=1;i<=m;i++)

    {

        f>>x>>y;

        v[x].push_back(y);

        v2[y].push_back(x);

    }

    for(int i=1;i<=n;i++)

    {

        if(!d[i]) dfs1(i);

    }

    memset(d,0,sizeof(d));

    while(!st.empty())

    {

        if(!d[st.top()]) {nr++;dfs2(st.top());}

        st.pop();

    }

    g<<nr<<'\n';

    for(int i=1;i<=nr;i++)

    {

        for(int j=0;j<sol[i].size();j++) g<<sol[i][j]<<" ";

        g<<'\n';

    }

    return 0;

}
