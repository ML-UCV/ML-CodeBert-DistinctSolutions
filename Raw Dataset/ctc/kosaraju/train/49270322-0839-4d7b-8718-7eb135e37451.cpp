#include <iostream>
#include <fstream>
#include<stack>
#include<vector>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");







vector<int> conexe[100009];

vector<int> m[100009];

vector<int> t[100009];



int nr;

int viz[100009];

stack<int>s;



void dfs(int n)

{

    viz[n] = 1;

    for(int i=0; i<m[n].size(); i++)

    {

        if(viz[m[n][i]]==0)

            dfs(m[n][i]);

    }

    s.push(n);

}





void dfs_transpus(int n)

{

    conexe[nr].push_back(n);



    viz[n] = 2;

    for(int i=0; i<t[n].size(); i++)

    {

        if(viz[t[n][i]] == 1)

            dfs_transpus(t[n][i]);

    }

}



int main()

{

    int edges,nodes,x,y;

    f>>nodes>>edges;

    for(int i = 1; i <= edges; i++)

    {

        f>>x>>y;



        t[y].push_back(x);



        m[x].push_back(y);

    }







    for(int i = 1; i <= nodes; i++)

    {

        if(viz[i]==0)

            dfs(i);

    }







    while(s.empty()==0)

    {

        int n=s.top();



        if(viz[n]==1)

        {

            nr++;

            dfs_transpus(n);

        }

        s.pop();

    }



    g<<nr<<"\n";





    for(int i = 1; i <= nr; i++)

    {

        for(int j=0; j<conexe[i].size(); j++)

        {

            g<<conexe[i][j]<<" ";

        }



        g<<"\n";

    }

}
