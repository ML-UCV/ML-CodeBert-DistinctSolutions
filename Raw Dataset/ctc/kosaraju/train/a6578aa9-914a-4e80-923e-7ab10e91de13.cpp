#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

ifstream f("ctc.in");

ofstream g("ctc.out");



vector <int> G[100005],Gt[100005];

vector <int> ctc[100005];

stack <int> s;

int n,m,x,y;

int viz[100005];

int cnt;

void DFS_T(int nod_curent)

{

    viz[nod_curent]++;

    ctc[cnt].push_back(nod_curent);

    for(vector<int>::iterator nod_vecin=Gt[nod_curent].begin(); nod_vecin!=Gt[nod_curent].end(); ++nod_vecin)

        if(viz[*nod_vecin]==1)

            DFS_T(*nod_vecin);

}

void DFS(int nod_curent)

{

    viz[nod_curent]=true;



    for(vector<int>::iterator nod_vecin=G[nod_curent].begin(); nod_vecin!=G[nod_curent].end(); ++nod_vecin)

        if(!viz[*nod_vecin])

            DFS(*nod_vecin);



    s.push(nod_curent);

}

int main()

{

    f>>n>>m;

    for(int i=1; i<=m; i++)

    {

        f>>x>>y;

        G[x].push_back(y);

        Gt[y].push_back(x);

    }



    for(int i=1; i<=n; i++)

        if(!viz[i])

            DFS(i);



    while(!s.empty())

    {

        int Nod=s.top();



        if(viz[Nod]==1)

        {

            cnt++;

            DFS_T(Nod);

        }

        s.pop();

    }



    g<<cnt<<'\n';

    for(int i=1; i<=cnt; i++)

    {

        for(vector<int>::iterator it=ctc[i].begin(); it!=ctc[i].end(); ++it)

            g<<*it <<" ";



        g<<'\n';

    }





    return 0;

}
