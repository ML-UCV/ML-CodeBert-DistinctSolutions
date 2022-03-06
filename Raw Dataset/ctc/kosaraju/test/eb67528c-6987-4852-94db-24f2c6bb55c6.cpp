#include <bits/stdc++.h>


using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");



vector<int> muchie[100005],c[100005],transpus[100005];

queue<int> coada;

int n, m, dist, a[100005], nr_comp;

bool vizitat[100005];



void dfs(int x)

{

    vizitat[x]=1;



    for(unsigned int i=0; i<muchie[x].size(); i++)

        if (!vizitat[muchie[x][i]])

            dfs(muchie[x][i]);



    dist++;

    a[dist]=x;

}







void bfs(int x)

{

    coada.push(x);

    vizitat[x]=1;



    c[nr_comp].push_back(x);



    while(!coada.empty())

    {

        x=coada.front();

        coada.pop();



        for(int i=0; i<transpus[x].size(); i++)

            if (!vizitat[transpus[x][i]])

            {

                coada.push(transpus[x][i]);

                c[nr_comp].push_back(transpus[x][i]);

                vizitat[transpus[x][i]]=1;

            }

    }

}





int main()

{



    fin>>n>>m;

    for(unsigned int i=1; i<=m; i++)

    {

        int x, y;

        fin>>x>>y;

        muchie[x].push_back(y);

        transpus[y].push_back(x);

    }



    for(unsigned int i=1; i<=n; i++)

        if (!vizitat[i])

            dfs(i);



    memset(vizitat,0,sizeof(vizitat));





    for(unsigned int i=dist; i>=1; i--)

        if (!vizitat[a[i]])

        {

            nr_comp++;

            bfs(a[i]);

        }





    fout<<nr_comp<<"\n";

    for(int i=1; i<=nr_comp; i++)

    {

        for(int j=0; j<c[i].size(); j++)

            fout<<c[i][j]<<" ";

        fout<<"\n";

    }



    return 0;

}
