#include <bits/stdc++.h>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



vector <int> v[100100],sol[100100];

stack <int> s;

int t,indice,inStiva[100100],viz[100100],low[100100];



void Tarjan(int nod)

{

    indice++;

    viz[nod]=indice;

    low[nod]=min(low[nod],indice);

    s.push(nod);

    inStiva[nod]=1;



    for(int i=0;i<v[nod].size();i++)

    {

        int vecin=v[nod][i];

        if(viz[vecin]==0)

        {

            viz[vecin]=1;

            Tarjan(vecin);

            low[nod]=min(low[nod],low[vecin]);

        }

        else if(inStiva[vecin]==1)low[nod]=min(low[nod],low[vecin]);

    }



    if(low[nod]==viz[nod])

    {

        t++;

        while(!s.empty() && s.top()!=nod)

        {

            sol[t].push_back(s.top());

            inStiva[s.top()]=0;

            s.pop();

        }

        if(!s.empty())

        {

            sol[t].push_back(s.top());

            inStiva[s.top()]=0;

            s.pop();

        }

    }

}



int m,n,i,x,y;

int main()

{

    f>>n>>m;

    for(i=1;i<=m;i++)

    {

        f>>x>>y;

        v[x].push_back(y);

    }



    for(i=1;i<=n;i++)low[i]=INT_MAX;

    for(i=1;i<=n;i++)

        if(viz[i]==0)Tarjan(i);



    g<<t<<'\n';

    for(i=1;i<=t;i++)

    {

        for(int j=0;j<sol[i].size();j++)

            g<<sol[i][j]<<" ";

        g<<'\n';

    }

    return 0;

}
