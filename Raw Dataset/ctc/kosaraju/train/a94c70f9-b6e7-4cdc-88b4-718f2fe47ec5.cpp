#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <stack>




using namespace std;

ifstream in("ctc.in");

ofstream out("ctc.out");



map<int, vector<int> > components;

void dfs(int node, vector<bool>& uz, vector<vector<int> >&g, stack<int>& nodes);

void dft(int node, vector<bool>& uz, vector<vector<int> >&g, int color);



int n, m;;



int main()

{

    in >> n >> m;



    vector<vector<int> >gn (n + 1, vector<int>());

    vector<vector<int> >gt (n + 1, vector<int>());



    for(int i = 1; i<=m; ++i)

    {

        int x,y;

        in >> x >> y;

        gn[x].push_back(y);

        gt[y].push_back(x);

    }



    vector<bool> uz(n + 1, false);

    stack<int> nodes;



    for(int i = 1; i<=n; ++i)

    {

        if(!uz[i])

        {

            dfs(i, uz, gn, nodes);

        }

    }



    int color = 0;

    while(nodes.size())

    {

        int node = nodes.top();

        nodes.pop();



        if(uz[node])

        {

            ++color;

            dft(node, uz, gt, color);

        }

    }



    out << color << '\n';

    for(int i = 1; i<=color; ++i)

    {

        vector<int> component = components[i];

        for(int j = 0; j < component.size(); ++j)

            out << component[j] << " ";



        out << '\n';

    }





    return 0;

}



void dfs(int node, vector<bool>& uz, vector<vector<int> >&g, stack<int>& nodes)

{

    uz[node] = true;

    for(vector<int>:: iterator it = g[node].begin(); it != g[node].end(); ++it)

    {

        if(!uz[*it])

            dfs(*it, uz, g, nodes);

    }



    nodes.push(node);

}



void dft(int node, vector<bool>& uz, vector<vector<int> >&g, int color)

{

    uz[node] = false;

    components[color].push_back(node);

    for(vector<int>:: iterator it = g[node].begin(); it != g[node].end(); ++it)

    {

        if(uz[*it])

        {

            dft(*it, uz, g, color);

        }

    }

}
