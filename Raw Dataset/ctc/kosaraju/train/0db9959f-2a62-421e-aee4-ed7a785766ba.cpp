#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

bool viz[100001];

vector<int> A[100001];

vector<int> T[100001];

vector<int> rez[100001];

stack <int>Q;

int n,m,nm=0;

void dfs1(int nod)

{

    viz[nod]=1;



    vector<int> :: iterator it;

    for(it=A[nod].begin();it!=A[nod].end();it++)

        if(!viz[*it])

            dfs1(*it);

    Q.push(nod);

}

void dfs2(int nod)

{

    viz[nod]=1;

    rez[nm].push_back(nod);

    vector<int> :: iterator it;

    for(it=T[nod].begin();it!=T[nod].end();it++)

        if(!viz[*it])

            dfs2(*it);

}



int main()

{

    fin>>n>>m;

    for(int i=1;i<=m;i++)

    {

        int a,b;;

        fin>>a>>b;

        A[a].push_back(b);

        T[b].push_back(a);

    }

    for(int i=1;i<=n;i++)

        if(viz[i]==0)

            dfs1(i);

    for(int i=1;i<=n;i++)

        viz[i]=0;

    while(!Q.empty())

    {

        int v;

        v=Q.top();

        Q.pop();

        if(!viz[v])

        {

            nm++;

            dfs2(v);

        }

    }

    fout<<nm<<"\n";

    for(int i=1;i<=nm;++i)

    {

        for(auto it:rez[i])

            fout<<it<<" ";

        fout<<'\n';

    }

    return 0;

}
