#include <bits/stdc++.h>




using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



vector<int>v[100001],sol[100001];

int n,m,k,t,low[100001],disc[100001];

bool fol[100001];

stack<int>sk;



void dfs(int nod)

{

    t++;

    sk.push(nod);

    fol[nod]=true;

    disc[nod]=low[nod]=t;

    for(int i=0;i<v[nod].size();++i)

    {



        if(!disc[v[nod][i]])

        {



            dfs(v[nod][i]);

            low[nod]=min(low[nod],low[v[nod][i]]);



        }

        else if(fol[v[nod][i]])low[nod]=min(low[nod],disc[v[nod][i]]);



    }



    if(low[nod]==disc[nod])

    {

        k++;

        while(sk.top()!=nod)

        {

            sol[k].push_back(sk.top());

            fol[sk.top()]=false;

            sk.pop();

        }



        sol[k].push_back(sk.top());

            fol[sk.top()]=false;

            sk.pop();



    }



}



int main()

{

    f>>n>>m;

    for(int i=1;i<=m;++i)

    {

        int x,y;

        f>>x>>y;

        v[x].push_back(y);

    }



    for(int i=1;i<=n;++i)

        if(!disc[i])

        {

            t = 0;

            dfs(i);

        }



    g<<k<<'\n';



    for(int i=1;i<=k;++i)

    {

        for(auto j=0;j<sol[i].size();++j)

        {

            g<<sol[i][j]<<" ";

        }

        g<<'\n';

    }



    return 0;

}
