#include <bits/stdc++.h>
#define ll long long
#define cin fin
#define cout fout
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
int n, m, start, end, x, y, result, cost;
vector <pair <int, int> > adj[30005];
bitset <30005> reached;

void dfs(int currNode, int costFromStart) {
    if (currNode == ::end) {
        result = costFromStart;
        return;
    }

    reached[currNode] = 1;
    for (pair <int, int> edge : adj[currNode])
        if (!reached[edge.first])
            if (edge.first < currNode)
                dfs(edge.first, costFromStart - edge.second);
            else
                dfs(edge.first, costFromStart + edge.second);
}

int main() {
    cin >> n >> m >> start >> ::end;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> cost;
        adj[x].push_back(make_pair(y, cost));
        adj[y].push_back(make_pair(x, cost));
    }

    dfs(start, 0);

    cout << result;

    return 0;
}
