#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



vector<int> compTareConexe1[200005];

vector<int> gr[200005], gr_transpus[200005];

int n, m, nr, viz[200005], compTareConexe2[200005];

vector<int> ord;



void dfs1(int node)

{

    if(viz[node])

        return ;

    viz[node] = 1;

    for(auto v : gr[node])

        dfs1(v);

    ord.push_back(node);

}



void dfs2(int node, int index)

{

    if(compTareConexe2[node])

        return ;

    compTareConexe2[node] = index;

    compTareConexe1[index].push_back(node);

    for(auto v : gr_transpus[node])

        dfs2(v, index);

}



int main()

{

    ifstream f("ctc.in");

    ofstream g("ctc.out");

    f>>n>>m;

    int x, y;

    for(int i = 0; i <= m; i++)

    {

        f>>x>>y;

        gr[x].push_back(y);

        gr_transpus[y].push_back(x);

    }

    for(int i = 1; i <= n; i++)

        if(!viz[i])

            dfs1(i);

    for(int i = n - 1; i >= 0; i--)

        if(!compTareConexe2[ord[i]])

        {

            nr++;

            dfs2(ord[i], nr);

        }

    g<<nr<<"\n";

    for(int i = 1; i <= nr; i++)

    {

        for(auto j : compTareConexe1[i])

        {

            g<<j<<" ";

        }

        g<<"\n";

    }

    return 0;

}
