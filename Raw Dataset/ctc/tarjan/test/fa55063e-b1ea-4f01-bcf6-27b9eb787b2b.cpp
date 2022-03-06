#include <bits/stdc++.h>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



vector <int> v[100100],sol[100100];

stack <int> s;

int indice,nr,inStiva[100100],nivel[100100],low[100100];



void Tarjan(int nod)

{

    indice++;

    nivel[nod]=indice;

    low[nod]=min(low[nod],nivel[nod]);

    s.push(nod);

    inStiva[nod]=1;



    for(int i=0;i<v[nod].size();i++)

    {

        int vecin=v[nod][i];

        if(nivel[vecin]==0)

        {

            nivel[vecin]=nivel[nod]+1;

            Tarjan(vecin);

            low[nod]=min(low[nod],low[vecin]);

        }

        else if(inStiva[vecin])low[nod]=min(low[nod],low[vecin]);

    }



    if(low[nod]==nivel[nod])

    {

        nr++;

        while(!s.empty() && s.top()!=nod)

        {

            sol[nr].push_back(s.top());

            inStiva[s.top()]=0;

            s.pop();

        }

        if(!s.empty())

        {

            sol[nr].push_back(s.top());

            inStiva[s.top()]=0;

            s.pop();

        }

    }

}



int n,m,i,j,x,y;

int main()

{

    f>>n>>m;

    for(i=1;i<=m;i++)

    {

        f>>x>>y;

        v[x].push_back(y);

    }



    for(i=1;i<=n;i++)low[i]=INT_MAX;

    for(i=1;i<=n;i++)if(nivel[i]==0)nivel[i]=1,Tarjan(i);



    g<<nr<<'\n';

    for(i=1;i<=nr;i++)

    {

        for(j=0;j<sol[i].size();j++)

            g<<sol[i][j]<<" ";

        g<<'\n';

    }

    return 0;

}
