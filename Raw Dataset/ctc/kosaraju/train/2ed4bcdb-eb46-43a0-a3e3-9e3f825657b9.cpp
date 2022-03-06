#include    <fstream>
#include    <iostream>
#include    <vector>
#include    <stack>


using namespace std;







ifstream f("ctc.in");

ofstream g("ctc.out");



stack < int > stiva;



vector<int> graf[100005],grafTranspus[100005],componente[100005];



int n, m, nr_componente;

int viz[100005];







void dfs1(int x)

{

    viz[x] = 1;

    for( int i=0; i<graf[x].size(); i++)

    {

        int vecin = graf[x][i];



        if(!viz[vecin])

            dfs1(vecin);

    }

    stiva.push(x);

}



void dfs2(int x)

{

    viz[x] = 2;

    componente[nr_componente].push_back(x);



    for(unsigned int i=0; i<grafTranspus[x].size(); i++)

    {

        int vecin = grafTranspus[x][i];



        if(viz[vecin]==1)

            dfs2(vecin);

    }

}



int main()

{

    f >> n >> m;

    for(int i = 1; i <= m; i++)

    {

        int x,y;

        f >> x >> y;

        graf[x].push_back(y);

        grafTranspus[y].push_back(x);

    }





    for(int i=1; i<=n; i++)

        if(!viz[i])

            dfs1(i);



    while(!stiva.empty())

    {

        int x = stiva.top();



        if (viz[x] == 1)

        {

            nr_componente++;

            dfs2(x);

        }

        stiva.pop();

    }



    g << nr_componente <<"\n";



    for(int i = 1; i <= nr_componente; i++)

    {

        for( int j = 0; j < componente[i].size(); j++)

            g << componente[i][j] <<" ";

        g<<"\n";

    }

    return 0;

}
