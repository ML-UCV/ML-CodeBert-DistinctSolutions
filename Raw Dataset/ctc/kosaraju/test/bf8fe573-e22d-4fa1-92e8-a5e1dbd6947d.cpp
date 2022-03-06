#include <iostream>
#include <fstream>
#include<stack>
#include<vector>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



vector<int> compcon[100009];

vector<int> v[100009];

vector<int> t[100009];

int viz[100009],nr;

stack<int>s;



void dfs(int n)

{

    viz[n] = 1;

    for(int i=0; i<v[n].size(); i++)

    {

        if(viz[v[n][i]]==0)

            dfs(v[n][i]);

    }

s.push(n);



}





void dfs_t(int n)

{

    compcon[nr].push_back(n);



    viz[n] = 2;



    for(int i=0; i<t[n].size(); i++)

    {

        if(viz[t[n][i]] == 1)

            dfs_t(t[n][i]);

    }

}



int main()

{

    int m,n,x,y;

    f>>n>>m;

    for(int i =1; i <=m ; i++)

    {

        f>>x>>y;

t[y].push_back(x);

        v[x].push_back(y);



    }







    for(int i = 1; i <= n; i++)

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

            dfs_t(n);

        }

        s.pop();

    }

    g<<nr<<"\n";





    for(int i = 1; i <= nr; i++)

    {

        for(int j=0; j<compcon[i].size(); j++)

        {

            g<<compcon[i][j]<<" ";

        }



        g<<"\n";

    }

}
