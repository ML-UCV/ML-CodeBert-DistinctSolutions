#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
typedef tuple<int, int, int> triplePair;

ifstream fin("apm.in");
ofstream fout("apm.out");

int n, m, totalCost;
vector<pair<int, int>> graph[maxN], compressed;
bitset<maxN> visited;

class smallestCost {
    public:
        bool operator()(const triplePair &a, const triplePair &b) const {
            return get<0>(a) > get<0>(b);
        }
};
priority_queue<triplePair, vector<triplePair>, smallestCost> available;

void makeAvailable(int node) {
    visited[node] = true;
    for (unsigned i = 0; i < graph[node].size(); ++i) {
        pair<int, int> neighbour = graph[node][i];
        if (!visited[neighbour.first])
            available.emplace(make_tuple(neighbour.second, neighbour.first, node));
    }
}

void calcNextMove() {
    while (!available.empty() && visited[get<1>(available.top())])
        available.pop();
    if (available.empty())
        return;

    triplePair nextMove = available.top();
    available.pop();
    makeAvailable(get<1>(nextMove));

    totalCost += get<0>(nextMove);
    compressed.emplace_back(make_pair(get<2>(nextMove), get<1>(nextMove)));
}

int main() {
    fin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y, cost;
        fin >> x >> y >> cost;
        graph[x].emplace_back(make_pair(y, cost));
        graph[y].emplace_back(make_pair(x, cost));
    }

    makeAvailable(1);
    while (!available.empty())
        calcNextMove();

    fout << totalCost << "\n" << compressed.size() << "\n";
    for (pair<int, int> edge : compressed)
        fout << edge.first << " " << edge.second << "\n";
    return 0;
}
