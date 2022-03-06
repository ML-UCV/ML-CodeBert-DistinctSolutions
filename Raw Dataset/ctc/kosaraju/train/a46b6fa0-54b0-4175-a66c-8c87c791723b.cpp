#include <iostream>
#include <fstream>
#include <stack>
#include <vector>


using namespace std;



ifstream fin ("ctc.in");

ofstream got ("ctc.out");







vector <unsigned int> g[100005],gt[100005],rez[100005];

stack <unsigned int> s;



unsigned int n,m,nr_ctc;



unsigned int vizitat[100005];



void read()

{

    fin>>n>>m;

    int x,y;

    for(int i=1;i<=m;i++)

    {

        fin>>x>>y;

        g[x].push_back(y);

        gt[y].push_back(x);

    }

}



void dfs(int nod)

{

    vizitat[nod]=1;

    unsigned int i,vecin;

    for(i=0;i<g[nod].size();i++)

    {

        vecin = g[nod][i];

        if(!vizitat[vecin])

            dfs(vecin);

    }

    s.push(nod);

}



void dfs_t(int nod)

{

    vizitat[nod]=2;

    unsigned int i;

    rez[nr_ctc].push_back(nod);

    for(i=0; i<gt[nod].size();i++)

        if(vizitat[gt[nod][i]]==1)

            dfs_t(gt[nod][i]);

}



void kosa()

{

    int i;

    for(i=1;i<=n;i++)

        if(!vizitat[i])

         dfs(i);

    while(!s.empty())

    {



        if(vizitat[s.top()]==1)

        {

            nr_ctc++;

            dfs_t(s.top());

        }

        s.pop();

    }



}



void afisare()

{

    got<<nr_ctc<<'\n';

    int i,j;

    for(i=1;i<=nr_ctc;i++)

    {

        for(j=0;j<rez[i].size();j++)

            got<<rez[i][j]<<" ";

        got<<'\n';

    }

}



int main()

{

    read();

    kosa();

    afisare();

    return 0;

}
