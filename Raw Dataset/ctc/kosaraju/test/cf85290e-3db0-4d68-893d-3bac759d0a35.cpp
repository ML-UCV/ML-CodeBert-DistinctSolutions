#include<fstream>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

int n,i,m,a,b,j,nr;

vector<int>v[100001],vt[100001];

bool viz[100001],Viz[100001];

vector<int>ctc[100001];

stack<int>st;

void dfs(int vf)

{

    viz[vf]=true;

    for(int i=0; i<v[vf].size(); i++)

        if(!viz[v[vf][i]])

        {

            dfs(v[vf][i]);

        }

    st.push(vf);

}

void Dfs(int vf)

{

    Viz[vf]=true;

    for(int i=0; i<vt[vf].size(); i++)

        if(!Viz[vt[vf][i]])

        {

            Dfs(vt[vf][i]);

            ctc[j].push_back(vt[vf][i]);

        }

}

int main()

{

    fin>>n>>m;

    for(i=1; i<=m; i++)

    {

        fin>>a>>b;

        v[a].push_back(b);

        vt[b].push_back(a);

    }

    for(j=1; j<=n; j++)

    {

        if(!viz[j])

            dfs(j);

    }

    while(!st.empty())

    {

        j=st.top();

        st.pop();

        if(!Viz[j])

        {

            Dfs(j);

            nr++;

            ctc[j].push_back(j);

        }

    }

    fout<<nr<<"\n";

    for(i=1; i<=n; i++)

    {

        if(ctc[i].size())

        {

            for(j=0; j<ctc[i].size(); j++)

                fout<<ctc[i][j]<<" ";

            fout<<"\n";

        }

    }

}
