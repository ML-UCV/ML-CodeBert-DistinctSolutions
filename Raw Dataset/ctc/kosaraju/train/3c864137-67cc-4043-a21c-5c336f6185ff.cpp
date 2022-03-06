#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>>& edges, stack<int>& result, vector<int>& visited, int start = 1, int time = 1) {

    visited[start] = time;

    for (auto elem : edges[start]) {

        if (visited[elem] == 0) {

            dfs(edges, result, visited, elem, time);

        }

    }

    result.push(start);

}

void reverseDFS_result(stack<int>& result, vector<int>& visited, vector<vector<int>>& edges) {

    for (int i = 0; i < visited.size(); i++) {

        if (visited[i] == 0) {

            dfs(edges, result, visited, i);

        }

    }

}

void strongComponents(stack<int>& result, vector<vector<int>>& edges) {

    ofstream out("ctc.out");

    int n = result.size();

    int time = 1, visit;

    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++) {

        stack<int> s;

        visit = result.top();

        result.pop();

        if (visited[visit] == 0) {

            dfs(edges, s, visited, visit, time);

        }

        if (!s.empty()) {

            time++;

        }

    }

    vector<vector<int>> strongComponents(time);

    for (int i = 1; i < visited.size(); i++) {

        strongComponents[visited[i]].push_back(i);

    }

    out << time - 2 << "\n";

    for (int i = 1; i < time; i++) {

        for (auto elem : strongComponents[i]) {

            out << elem << " ";

        }

        out << "\n";

    }

    out.close();

    return;

}

int main()

{

    ios_base::sync_with_stdio(false);

    int n, m, s, x, y;

    ifstream in("ctc.in");

    in >> n >> m;

    vector<vector<int>> rEdges(n + 1);

    vector<vector<int>> edges(n + 1);

    for (int i = 0; i < m; i++) {

        in >> x >> y;

        edges[x].push_back(y);

        rEdges[y].push_back(x);

    }

    stack<int> result;

    vector<int> visited(n + 1, 0);

    reverseDFS_result(result, visited, rEdges);
    strongComponents(result, edges);

    in.close();

    return 0;

}
