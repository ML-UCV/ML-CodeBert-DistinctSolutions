#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int x, y, w;
};

bool compEdge(Edge a, Edge b)
{
    return a.w < b.w;
}

pair<int, vector<Edge>> readGraph(const string& inputPath)
{
    ifstream fin(inputPath);
    int n, m;
    fin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        fin >> edges[i].x >> edges[i].y >> edges[i].w;
        edges[i].x--;
        edges[i].y--;
    }
    fin.close();
    return make_pair(n, edges);
}

int getRoot(const vector<int>& parents, int node)
{
    while (parents[node] != node)
        node = parents[node];
    return node;
}

void setRoot(vector<int>& parents, int node, int root)
{
    int aux;
    while (parents[node] != node)
    {
        aux = parents[node];
        parents[node] = root;
        node = aux;
    }
    parents[node] = root;
}

bool join(vector<int>& parents, int x, int y)
{
    int rootX, rootY;
    rootX = getRoot(parents, x);
    rootY = getRoot(parents, y);
    bool needsJoin = rootX != rootY;
    if (needsJoin)
    {
        parents[rootY] = rootX;
    }
    setRoot(parents, x, rootX);
    setRoot(parents, y, rootX);
    return needsJoin;
}

vector<Edge> computeMST(vector<Edge>& edges, int n)
{
    vector<int> parents(n);
    for (int i = 0; i < n; i++)
        parents[i] = i;
    sort(edges.begin(), edges.end(), compEdge);
    vector<Edge> mst;
    for (auto& edge: edges)
    {
        if (join(parents, edge.x, edge.y))
        {
            mst.push_back(edge);
        }
    }
    return mst;
}

void printMST(const string& outputPath, const vector<Edge>& edges)
{
    ofstream fout(outputPath);
    int cost = 0;
    for (auto& edge: edges)
        cost += edge.w;
    fout << cost << '\n' << edges.size() << '\n';
    for (auto& edge: edges)
        fout << edge.x + 1 << ' ' << edge.y + 1 << '\n';
    fout.close();
}

int main()
{
    pair<int, vector<Edge>> graphData = readGraph("apm.in");
    vector<Edge> mst = computeMST(graphData.second, graphData.first);
    printMST("apm.out", mst);
    return 0;
}
