#include<stdio.h>
#include<queue>


using namespace std;







priority_queue< pair<int, pair<int, int> > > myheap;

vector< pair<int, int> > graph[400005], apm;

bool viz[400005];

int n, m, cost_total;



int main() {

    int a, b, c;



    freopen("apm.in", "r", stdin);

    freopen("apm.out", "w",stdout);



    scanf("%d%d", &n, &m);

    for(int i = 1; i <= m; i++) {

        scanf("%d%d%d", &a, &b, &c);

        graph[a].push_back(make_pair(b, c));

        graph[b].push_back(make_pair(a, c));

    }



    int root = 1;

    viz[root] = true;

    for(auto edge : graph[root]) {

        myheap.push(make_pair(-edge.second, make_pair(root, edge.first)));

    }



    while(!myheap.empty()) {

        pair<int, pair<int, int> > best = myheap.top();

        myheap.pop();



        int cost = best.first;

        int new_node = best.second.second;



        if(!viz[new_node]) {

            viz[new_node] = true;

            apm.push_back(best.second);

            cost_total += -cost;



            for(auto edge : graph[new_node]) {

                myheap.push(make_pair(-edge.second, make_pair(new_node, edge.first)));

            }

        }

    }



    printf("%d\n%d\n", cost_total, n - 1);

    for(auto edge : apm) {

        printf("%d %d\n", edge.first, edge.second);

    }





    return 0;

}
