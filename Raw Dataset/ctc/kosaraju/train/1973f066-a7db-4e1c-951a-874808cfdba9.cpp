#include <fstream>
#include <vector>


constexpr auto max_n = 100005;



using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



int n, m, node_order_count, component_count, node_order[max_n], visited[max_n];

vector<vector<int>> graph, transposed_graph, components;



void dfs1(int node)

{

    visited[node] = 1;



    for (int i = 0; i < (int)graph[node].size(); i++)

        if (!visited[graph[node][i]])

            dfs1(graph[node][i]);



    node_order[node_order_count++] = node;

}



void dfs2(const int node)

{

    visited[node] = 2;



    components[component_count].push_back(node);



    for (int i = 0; i < (int)transposed_graph[node].size(); i++)

        if (visited[transposed_graph[node][i]] == 1)

            dfs2(transposed_graph[node][i]);

}



int main()

{

    fin >> n >> m;



    graph.resize(max_n);

    transposed_graph.resize(max_n);

    components.resize(max_n);



    for (int i = 1; i <= m; i++)

    {

        int x, y;

        fin >> x >> y;



        graph[x].push_back(y);

        transposed_graph[y].push_back(x);

    }



    for (auto i = 1; i <= n; i++)

        if (!visited[i])

            dfs1(i);



    for (auto i = node_order_count - 1; i >= 0; i--)

    {

        if (visited[node_order[i]] != 2)

        {

            dfs2(node_order[i]);

            component_count++;

        }

    }



    fout << component_count << "\n";

    for (auto i = 0; i < component_count; i++)

    {

        for (auto node : components[i])

            fout << node << " ";

        fout << "\n";

    }



    fout.close();

    return 0;

}
