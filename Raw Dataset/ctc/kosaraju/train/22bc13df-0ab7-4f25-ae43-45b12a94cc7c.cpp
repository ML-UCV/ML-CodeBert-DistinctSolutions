#include <bits/stdc++.h>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



int N, M, K;

vector<int> G[100005], GT[100005], ans[100005], nodes;

bool vis1[100005], vis2[100005];



void DFS1(int node) {

    vis1[node] = 1;

    for (auto it: G[node])

        if (!vis1[it]) DFS1(it);

    nodes.push_back(node);

}

void DFS2(int node) {

    vis2[node] = 1;

    ans[K].push_back(node);

    for (auto it: GT[node])

        if (!vis2[it]) DFS2(it);

}

int main()

{

    f >> N >> M;

    for (int i = 1; i <= M; ++i) {

        int x, y;

        f >> x >> y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }



    for (int i = 1; i <= N; ++i)

        if (!vis1[i]) DFS1(i);



    reverse(nodes.begin(), nodes.end());

    for (auto it : nodes)

        if (!vis2[it]) ++K, DFS2(it);



    g << K << '\n';

    for (int i = 1; i <= K; ++i) {

        for (auto it: ans[i])

            g << it << " ";

        g << '\n';

    }



    return 0;

}
