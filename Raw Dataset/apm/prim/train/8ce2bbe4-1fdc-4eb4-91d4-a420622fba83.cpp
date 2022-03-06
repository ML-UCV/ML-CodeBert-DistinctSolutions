#include <bits/stdc++.h>


using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");

vector <pair <int, long long> > adj[200001];

bitset <200001> reached;

pair <long long, int> minCost[200001];



void dijkstra(int start) {

    priority_queue <pair <long long, int> > best;

    best.push(make_pair(0, start));



    while (!best.empty()) {

        int front = best.top().second;

        long long cost = -best.top().first;

        best.pop();



        reached[front] = 1;

        for (pair <int, long long> edge : adj[front])

            if (!reached[edge.first])

                if (edge.second <= minCost[edge.first].first) {

                    minCost[edge.first].first = edge.second;

                    minCost[edge.first].second = front;

                    best.push(make_pair(-edge.second, edge.first));

                }

    }

}



void addEdge(int x, int y, int c) {

    adj[x].push_back(make_pair(y, c));

    adj[y].push_back(make_pair(x, c));

}



int main() {

    int n, m, x, y, c;



    fin >> n >> m;

    for (int i = 1; i <= m; i++) {

        fin >> x >> y >> c;

        addEdge(x, y, c);

    }



    for (int i = 2; i <= n; i++)

        minCost[i].first = INT_MAX;



    dijkstra(1);



    long long result = 0;

    for (int i = 1; i <= n; i++)

        result += minCost[i].first;



    fout << result << '\n' << n - 1 << '\n';

    for (int i = 2; i <= n; i++)

        fout << i << ' ' << minCost[i].second << '\n';



    return 0;

}
