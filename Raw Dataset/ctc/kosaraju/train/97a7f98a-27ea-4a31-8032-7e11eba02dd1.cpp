#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");



vector<int>g[100005];

vector<int>gt[100005];

vector<int>v[100005];

stack<int>s;

int viz[100005];

int n,m,c=0;

void dfs(int k)

{

    viz[k]=1;

    for(int i=0; i<g[k].size(); i++)

    {

        int nod=g[k][i];

        if(viz[nod]==0)

        {

            dfs(nod);

        }

    }

    s.push(k);

}

void dfsgt(int k)

{

    viz[k]=2;

    v[c].push_back(k);

    for(int i=0; i<gt[k].size(); i++)

    {

        int nod=gt[k][i];

        if(viz[nod]==1)

        {

            dfsgt(nod);

        }

    }

}

int main ()

{

    fin>>n>>m;

    for(int i=1; i<=m; i++)

    {

        int x,y;

        fin>>x>>y;

        g[x].push_back(y);

        gt[y].push_back(x);

    }

    for(int i=1; i<=n; i++)

    {

        if(viz[i]==0)

        {

            dfs(i);

        }

    }

    while(s.empty()==0)

    {

        int nod=s.top();

        if(viz[nod]==1)

        {

            c++;

            dfsgt(nod);

        }

        s.pop();

    }

    fout<<c;

    fout<<'\n';

    for(int i=1;i<=c;i++)

    {

        int l=v[i].size();

        for(int j=0;j<l;j++)

        {

            fout<<v[i][j]<<" ";

        }

        fout<<'\n';

    }

    fin.close();

    fout.close();

    return 0;

}
