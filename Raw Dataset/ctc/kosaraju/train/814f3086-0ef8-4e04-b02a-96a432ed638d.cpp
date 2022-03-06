#include <iostream>
#include <list>
#include <vector>
#include <fstream>
using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");



vector <int> orderedbyf;



void dfs(int start, list<int> ad[],int d[])

{



    d[start] = 1;

    for(auto &child : ad[start])

    {

        if(d[child] == 0)

            dfs(child,ad,d);



    }

    orderedbyf.push_back(start);



}

void dfst(int start, list<int> adt[],int dt[],int nrComp, list <int> scc[])

{





    dt[start] = 1;

    scc[nrComp].push_back(start);

    for(auto &child : adt[start])

    {

        if(dt[child] == 0)

            dfst(child,adt,dt,nrComp,scc);



    }



}

int main()

{

    int n,m,start;

    fin>>n>>m;

    list <int> ad[n+1];

    list <int> adt[n + 1];

    for(int i = 0; i < m; i ++)

    {



        int x,y;

        fin >> x >> y;

        ad[x].push_back(y);

        adt[y].push_back(x);





    }

    int d[n+1]= {0};

    int dt[n+1] = {0};

    list <int> scc [n+1];



    for(int i=1; i<=n; i++)

            if(d[i] == 0)

            {

                start = i;

                dfs(start,ad,d);

            }
    int nrComp = 0;

    for(int i = n - 1; i >= 0; i--)

            if(dt[orderedbyf[i]] == 0)

            {



                nrComp ++;

                dfst(orderedbyf[i],adt,dt,nrComp,scc);

            }



    fout<<nrComp<<"\n";

    for(int i = 1; i <= nrComp;i++)

    {

        for(auto &it: scc[i])

            fout<<it<<" ";

        fout<<"\n";

    }

    return 0;

}
