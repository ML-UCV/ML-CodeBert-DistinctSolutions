#include <stdio.h>
#include <vector>


using namespace std;

vector<int> ctc[200005], A[200005], A_tr[200005], ordered_list;

int num_ctc = 0, n, m;

int ctc_of[200005], viz[200005];



void dfs1(int node) {

    if(viz[node])

        return;

    viz[node] = 1;

    for(int vecin : A[node]) {

        dfs1(vecin);

    }

    ordered_list.push_back(node);

}



void dfs2(int node, int index_ctc)

{

    if(ctc_of[node])

        return;

    ctc_of[node] = index_ctc;



    ctc[index_ctc].push_back(node);

    for(int vecin : A_tr[node]) {

        dfs2(vecin, index_ctc);

    }

}



int main() {

    int i;

    freopen("ctc.in", "r", stdin);

    freopen("ctc.out", "w", stdout);

    scanf("%d %d", &n, &m);

    for(i=1;i<=m;i++) {

        int a,b;

        scanf("%d %d", &a, &b);

        A[a].push_back(b);

        A_tr[b].push_back(a);

    }

    for(i=1;i<=n;i++) {

        if(!viz[i])

            dfs1(i);

    }

    for(i=n-1;i>=0;i--) {

        if(!ctc_of[ordered_list[i]]) {

            dfs2(ordered_list[i], ++num_ctc);

        }

    }



    printf("%d\n", num_ctc);

    for(i=1;i<=num_ctc;i++) {

        for(int node : ctc[i]) {

            printf("%d ", node);

        }

        printf("\n");

    }



}
