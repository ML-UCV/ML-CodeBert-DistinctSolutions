#include<stdio.h>
#include<vector>


using namespace std;







vector<int> ctc[200005];

int num_ctc, n, m;

int ctc_of[200005], viz[200005];

vector<int> graph[200005], graph_t[200005], ordered_list;



void dfs1(int node) {

    if(viz[node])

        return ;



    viz[node] = 1;

    for(auto vecin : graph[node]) {

        dfs1(vecin);

    }

    ordered_list.push_back(node);

}



void dfs2(int node, int index_ctc) {

    if(ctc_of[node])

        return ;



    ctc_of[node] = index_ctc;



    ctc[index_ctc].push_back(node);



    for(auto vecin : graph_t[node]) {

        dfs2(vecin, index_ctc);

    }

}



int main() {

    int a, b;



 freopen("ctc.in","r",stdin);

freopen("ctc.out", "w",stdout);



    scanf("%d%d", &n, &m);

    for(int i = 1; i <= m; i++) {

        scanf("%d%d", &a, &b);

        graph[a].push_back(b);

        graph_t[b].push_back(a);

    }



    for(int i = 1; i <= n; i++) {

        if(!viz[i]) {

            dfs1(i);

        }

    }



    for(int i = n - 1; i >= 0; i--) {

        if(!ctc_of[ordered_list[i]]) {

            dfs2(ordered_list[i], ++num_ctc);

        }

    }



    printf("%d\n", num_ctc);

    for(int i = 1; i <= num_ctc; i++) {

        for(auto node : ctc[i]) {

            printf("%d ", node);

        }

        printf("\n");

    }



    return 0;

}
