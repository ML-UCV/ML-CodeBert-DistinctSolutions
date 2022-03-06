#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <fstream>
using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

int n,m,nr;

vector <int> v1[100001],v2[100001],sol[100001];

stack <int> st;

bool viz[100001];

void dfs1(int nod)

{

    viz[nod]=1;

    int i;

    for(i=0;i<v1[nod].size();i++)

    {

        if(!viz[v1[nod][i]])dfs1(v1[nod][i]);

    }

    st.push(nod);

}

void dfs2(int nod)

{

    sol[nr].push_back(nod);

    viz[nod]=1;

    int i;

    for(i=0;i<v2[nod].size();i++)

    {

        if(!viz[v2[nod][i]])dfs2(v2[nod][i]);

    }

}

int main()

{

    fin>>n>>m;

    int i,x,y;

    for(i=1;i<=m;i++)

    {

        fin>>x>>y;

        v1[x].push_back(y);

        v2[y].push_back(x);

    }

    for(i=1;i<=n;i++)

    {

        if(!viz[i])dfs1(i);

    }

    memset(viz,0,sizeof(viz));

    for(i=1;i<=n;i++)

    {

        if(!viz[st.top()])

        {

            nr++;

            dfs2(st.top());

        }

        st.pop();

    }

    fout<<nr<<'\n';

    int j;

    for(i=1;i<=nr;i++)

    {

        for(j=0;j<sol[i].size();j++)fout<<sol[i][j]<<" ";

        fout<<'\n';

    }

}
