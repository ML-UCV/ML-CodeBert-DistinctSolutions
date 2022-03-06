#include <iostream>
#include <vector>
#include <fstream>
#include <deque>
#include <bitset>


using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

bitset<100005> iq;

deque<int> q;

vector <int> L[100005],aux;

vector< vector<int> > sol;

int low[100005],niv[100005],g,n,m,i,x,y;

void dfs(int nod)

{

    iq[nod]=1;

    niv[nod]=++g;

    low[nod]=g;

    q.push_back(nod);

    for(auto it:L[nod])

    {

        if(niv[it]==0)

        {

            dfs(it);

            low[nod]=min(low[nod],low[it]);

        }

        else if(iq[it]==1)

        {

            low[nod]=min(low[nod],low[it]);



        }

    }

    if(low[nod]==niv[nod])

    {

        aux.clear();

        int x=0;

        while(x!=nod)

        {

            x=q.back();

            iq[x]=0;

            q.pop_back();

            aux.push_back(x);

        }

        sol.push_back(aux);

    }

}

int main()

{

    fin>>n>>m;

    for(i=1; i<=m; i++)

    {

        fin>>x>>y;

        L[x].push_back(y);

    }

    for(i=1; i<=n; i++)

    {

        if(niv[i]==0)

        {

            dfs(i);

        }

    }

    fout<<sol.size()<<"\n";

    for(auto &vec:sol)

    {

        for(auto &it:vec)

            fout<<it<<" ";

        fout<<"\n";

    }

}
