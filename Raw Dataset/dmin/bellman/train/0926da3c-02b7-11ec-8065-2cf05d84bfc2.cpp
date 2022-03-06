#include <bits/stdc++.h>
using namespace std;



deque <int> Q;

vector <pair <int, double> > G[1501];



double dist[1501];

int n, m, answer[1501];

bool inq[1501];



void bellmanford()

{

    int son, node, i;

    double edge;



    Q.push_back(1);

    inq[1] = 1;

    while(!Q.empty()) {

        node = Q.front();

        Q.pop_front();

        inq[node] = 0;

        for(i=0; i<G[node].size(); ++i) {

            son = G[node][i].first;

            edge = G[node][i].second;

            if(abs(dist[son] - (dist[node] + edge)) < (1e-7)) {

                answer[son] += answer[node];

                if(answer[son] >= 104659) answer[son] -= 104659;

                if(!inq[son]) {

                    inq[son] = 1;

                    Q.push_back(son);

                }

                continue;

            }

            if(dist[son] > dist[node] + edge) {

                dist[son] = dist[node] + edge;

                answer[son] = answer[node];

                if(!inq[son]) {

                    inq[son] = 1;

                    Q.push_back(son); } } } }

}



int main()

{

    freopen("dmin.in", "r", stdin);

    freopen("dmin.out", "w", stdout);



    int i, x, y;

    double z;



    scanf("%d%d", &n, &m);

    for(i=1; i<=m; ++i) {

        scanf("%d%d%lf", &x, &y, &z);

        z = log10(z);

        G[x].push_back({y, z});

        G[y].push_back({x, z});

    }



    for(i=1; i<=n; ++i)

        dist[i] = (1e8);



    dist[1] = 0;

    answer[1] = 1;

    bellmanford();



    for(i=2; i<=n; ++i)

        printf("%d ", answer[i]);



    return 0;

}
