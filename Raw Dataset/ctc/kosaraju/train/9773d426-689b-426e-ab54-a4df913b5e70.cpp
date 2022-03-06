#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>







using namespace std;

int v, e;
int nodeColor[100001];
int nrSCC = 0;

vector <int> graph[100001];
vector <int> graphTransposed[100001];
vector <int> SCC[100001];
stack <int> st;

void read();
void DFS(int);
void DFStranspose(int);
void Kosaraju();
void topologicalSort();
void write();

int main() {

    read();

    Kosaraju();

    write();

    return 0;
}

void read()
{
    freopen("ctc.in", "r", stdin);

    scanf("%d%d", &v , &e);

    int x, y;

    for (int i = 1; i <= e; i++)
    {
        scanf("%d%d", &x, &y);

        graph[x].push_back(y);
        graphTransposed[y].push_back(x);
    }
}

void Kosaraju()
{
    topologicalSort();

    while (!st.empty())
    {
        int node = st.top();
        printf("%d ", node);

        if (nodeColor[node] == 1)
        {
            ++nrSCC;
            DFStranspose(node);
        }
        st.pop();
    }
}

void topologicalSort()
{
    for (int i = 1; i <= v; i++)
    {
        if (nodeColor[i] == 0)
            DFS(i);
    }
}

void DFS(int node)
{
    nodeColor[node] = 1;

    for (unsigned int i = 0; i < graph[node].size(); i++)
    {
        int neighbour = graph[node][i];

        if (nodeColor[neighbour] == 0)
            DFS(neighbour);
    }

    st.push(node);
}

void DFStranspose(int node)
{
    nodeColor[node] = 2;
    SCC[nrSCC].push_back(node);

    for (unsigned int i = 0; i < graphTransposed[node].size(); i++)
    {
        int neighbour = graphTransposed[node][i];

        if (nodeColor[neighbour] == 1) {
            DFStranspose(neighbour);
        }
    }
}

void write()
{
    freopen("ctc.out", "w", stdout);

    printf("%d\n", nrSCC);

    for (int i = 1; i <= nrSCC; i++)
    {
        for (auto j = SCC[i].begin(); j != SCC[i].end(); ++j)
            printf("%d ", *j);
        printf("\n");
    }

    fclose(stdout);
}
