#include <bits/stdc++.h>


using namespace std;

ifstream fin ("apm.in");

ofstream fout ("apm.out");



const int MAXN = 2e5 + 5, MAXM = 4e5 + 5;

int n, m, tree[MAXN];

struct edge {

    int node1, node2, cost;

};



bool compareByCost(edge i, edge j) {

    return (i.cost < j.cost);

}



int findRoot(int node) {

    if (node == tree[node])

        return node;

    tree[node] = findRoot(tree[node]);

    return tree[node];

}



int main() {

    fin.tie(0);

    fout.tie(0);

    ios::sync_with_stdio(0);

    fin >> n >> m;

    vector<edge> graph(m);

    for (int i = 0; i < m; i++)

        fin >> graph[i].node1 >> graph[i].node2 >> graph[i].cost;

    sort(graph.begin(), graph.end(), compareByCost);

    for (int i = 1; i <= n; i++)

        tree[i] = i;



    long long totalCost = 0;

    vector<pair<int, int> > minTree;

    for (int i = 0; i < m; i++) {

        int rootA = findRoot(graph[i].node1);

        int rootB = findRoot(graph[i].node2);

        if (rootA != rootB) {

            minTree.push_back(make_pair(graph[i].node1, graph[i].node2));

            totalCost += graph[i].cost;

            tree[min(rootA, rootB)] = tree[max(rootA, rootB)];



        }

    }



    fout << totalCost << "\n" << n - 1 << "\n";

    for (int i = 0; i < n - 1; i++)

        fout << minTree[i].first << " " << minTree[i].second << "\n";

    return 0;

}
