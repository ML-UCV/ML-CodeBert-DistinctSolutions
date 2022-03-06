#include <iostream>
#include <fstream>
#include <vector>
#include <stack>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



const int nmax = 100005;

vector<int> list_vec[nmax], list_rev[nmax], rez[nmax];

int viz[nmax];

stack<int> t;

int comp, n, m;



void dfs1(int start)

{

    viz[start] = 1;

    for(int i : list_vec[start])

    {

        if(!viz[i])

            dfs1(i);

    }

    t.push(start);

}



void dfs2(int start)

{

    viz[start] = 0;

    rez[comp].push_back(start);



    for(int i : list_rev[start])

    {

        if(viz[i])

            dfs2(i);

    }

}

int main()

{

    int u, v, i;

    fin>>n>>m;

    for(i = 1; i <= m; ++i)

    {

        fin>>u>>v;

        list_vec[u].push_back(v);

        list_rev[v].push_back(u);

    }



    for(i = 1; i <= n; ++i)

    {

        if(!viz[i])

            dfs1(i);

    }



    while(!t.empty())

    {

        int temp = t.top();

        t.pop();

        if(viz[temp])

        {

            ++comp;

            dfs2(temp);

        }

    }



    fout<<comp<<'\n';

    for(i = 1; i <= comp; ++i)

    {

        for(int j : rez[i])

            fout<<j<<' ';

        fout<<'\n';

    }



    return 0;

}
