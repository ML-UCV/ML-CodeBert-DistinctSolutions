#include <bits/stdc++.h>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



vector <int> v[100100],vT[100100];

int nr,t,vectorT[100100],viz[100100];

vector <int> sol[100100];



void DFS(int nod)

{

    viz[nod]=1;

    for(int i=0;i<v[nod].size();i++)

    {

        int vecin=v[nod][i];

        if(viz[vecin]==0)

        {

            viz[vecin]=1;

            DFS(vecin);

        }

    }

    t++;

    vectorT[t]=nod;

}



void DFS_T(int nod)

{

    sol[nr].push_back(nod);

    viz[nod]=0;

    for(int i=0;i<vT[nod].size();i++)

    {

        int vecin=vT[nod][i];

        if(viz[vecin]==1)

        {

            viz[vecin]=0;

            DFS_T(vecin);

        }

    }

}



int n,m,j,i,x,y;

int main()

{

    f>>n>>m;

    for(i=1;i<=m;i++)

    {

        f>>x>>y;

        v[x].push_back(y);

        vT[y].push_back(x);

    }



    for(i=1;i<=n;i++)if(viz[i]==0)DFS(i);

    for(i=n;i>=1;i--)if(viz[vectorT[i]]==1)nr++,DFS_T(vectorT[i]);



    g<<nr<<'\n';

    for(i=1;i<=nr;i++)

    {

        for(j=0;j<sol[i].size();j++)

            g<<sol[i][j]<<" ";

        g<<'\n';

    }

    return 0;

}
