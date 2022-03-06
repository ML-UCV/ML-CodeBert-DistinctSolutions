#include <bits/stdc++.h>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



vector <int> v[100100],sol[100100];

stack <int> s;

int nr,indice,low[100100],nivel[100100],inStiva[100100];



void Tarjan(int nod)

{

    indice++;

    nivel[nod]=indice;

    low[nod]=nivel[nod];

    inStiva[nod]=1;

    s.push(nod);



    for(int i=0;i<v[nod].size();i++)

    {

        int vecin=v[nod][i];

        if(nivel[vecin]==0)

        {

            Tarjan(vecin);

            low[nod]=min(low[nod],low[vecin]);

        }

        else if(inStiva[vecin]==1)low[nod]=min(low[nod],low[vecin]);

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



int n,m,i,x,y;

int main()

{

    f>>n>>m;

    for(i=1;i<=m;i++)

    {

        f>>x>>y;

        v[x].push_back(y);

    }



    for(i=1;i<=n;i++)if(nivel[i]==0)Tarjan(i);

    g<<nr<<'\n';

    for(i=1;i<=nr;i++)

    {

        for(int j=0;j<sol[i].size();j++)

            g<<sol[i][j]<<" ";

        g<<'\n';

    }

    return 0;

}
