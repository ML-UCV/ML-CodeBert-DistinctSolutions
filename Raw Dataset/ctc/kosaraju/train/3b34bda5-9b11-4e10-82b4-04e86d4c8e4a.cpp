#include <bits/stdc++.h>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



int N, M, ans;

vector<int> G[100005], GT[100005], nodes, ctc[100005];

bool vis[100005];



void DFS1(int node) {

   vis[node] = 1;

   for (auto it: G[node])

      if (!vis[it]) DFS1(it);

   nodes.push_back(node);

}

void DFS2(int node) {

   vis[node] = 1;

   ctc[ans].push_back(node);

   for (auto it: GT[node])

      if (!vis[it]) DFS2(it);

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

        if (!vis[i]) DFS1(i);

    reverse(nodes.begin(), nodes.end());

    memset(vis, 0, sizeof(vis));



    for (auto it : nodes)

      if (!vis[it]) ++ans, DFS2(it);



    g << ans << '\n';

    for (int i = 1; i <= ans; ++i) {

        for (auto it : ctc[i])

            g << it << " ";

        g << '\n';

    }



    return 0;

}
