#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <fstream>




using namespace std;

ifstream fin("apm.in");
ofstream fout("apm.out");

typedef pair<int, int> iPair;

struct DS
{
    int nodeCnt;
    vector<int> father, connected;

    explicit DS(int N) : nodeCnt(N), connected(N + 1, 1), father(N + 1, -1) {}

    int root(int child)
    {
        while (father[child] != -1) child = father[child];

        return child;
    }

    bool Connected(int a, int b)
    {
        return root(a) == root(b);
    }

    void Link(int st, int dr)
    {
        int rootSt = root(st);
        int rootDr = root(dr);
        if (connected[rootSt] > connected[rootDr])
            swap(rootSt, rootDr);
        father[rootSt] = rootDr;
        connected[rootDr] += connected[rootSt];
    }
};


struct Edge {
    int src, dest, cost;

    Edge(int src, int dest, int cost) : src(src), dest(dest), cost(cost) {}

    bool operator<(const Edge &oth) const
    {
        return cost < oth.cost;
    }
};

struct Graph {
    int nodeCnt, edgeCnt;
    DS *ds = nullptr;
    vector <Edge> edges, apmEdges;

    Graph(int V, int E)
    {
        this->nodeCnt = V;
        this->edgeCnt = E;
        edges.reserve(edgeCnt);

        for(int i = 0, a, b, c; i < edgeCnt; ++i)
        {
            fin >> a >> b >> c;
            edges.emplace_back(a, b, c);
        }

        this->ds = new DS(nodeCnt);
    }

    void displayAPM() {
        fout << APM() << '\n';
        fout << apmEdges.size() << '\n';
        for (auto e : apmEdges)
        {
            fout << e.src << " " << e.dest << '\n';
        }
    }

    long long APM()
    {
        sort(edges.begin(), edges.end());

        long long TotalCostAPM = 0, edgesAdded = 0;
        for (auto e : edges)
        {
            if(edgesAdded == nodeCnt - 1) break;
            if (!ds->Connected(e.src, e.dest))
            {
                ds->Link(e.src, e.dest);
                TotalCostAPM += e.cost;
                apmEdges.emplace_back(e);
                edgesAdded++;
            }
        }

        return TotalCostAPM;
    }
};

int main()
{
    int n, m;
    fin >> n >> m;

    Graph graph(n, m);

    graph.displayAPM();
}
