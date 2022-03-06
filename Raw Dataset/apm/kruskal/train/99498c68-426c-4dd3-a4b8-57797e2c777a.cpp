#include <bits/stdc++.h>


using namespace std;



const int NMAX = 400005;

int N, M, TT[NMAX], RG[NMAX], total, k;

pair<int, int> P[NMAX];



struct Edge{

    int x, y, cost;



}V[NMAX];



bool cmp(Edge a, Edge b) {

    return a.cost < b.cost;

}



int Find(int v) {

    if(v == TT[v])

        return v;

    return TT[v] = Find(TT[v]);

}



int Unite(int x, int y) {

    if(RG[x] < RG[y])

        TT[x] = y;

    if(RG[x] > RG[y])

        TT[y] = x;



    if(RG[x] == RG[y]) {

        TT[x] = y;

        RG[y]++;

    }

}



void Solve() {

    for(int i = 1; i <= M; ++i)

        if(Find(V[i].x) != Find(V[i].y)) {

            Unite(Find(V[i].x), Find(V[i].y));

            P[++k].first = V[i].x;

            P[k].second = V[i].y;

            total += V[i].cost;

        }

}



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL), cout.tie(NULL);



    freopen("apm.in", "r", stdin);

    freopen("apm.out", "w", stdout);



    cin >> N >> M;

    for(int i = 1; i <= M; ++i)

        cin >> V[i].x >> V[i].y >> V[i].cost;



    sort(V + 1, V + M + 1, cmp);



    for(int i = 1; i <= M; ++i) {

        TT[i] = i;

        RG[i] = 1;

    }



    Solve();



    cout << total << "\n"

         << N-1 << "\n";

    for(int i = 1; i <= k; ++i)

        cout << P[i].first << " " << P[i].second << "\n";



    return 0;

}
