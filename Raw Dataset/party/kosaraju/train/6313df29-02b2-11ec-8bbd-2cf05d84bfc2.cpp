#include <bits/stdc++.h>






using namespace std;



const int NMAX = 2 * 100;



int N, M;

int comp[NMAX], answer[NMAX];

bool used[NMAX];

vector<int> G[NMAX], GT[NMAX], discover, C[NMAX];



inline int idx(int value) {

    if (value < 0)

        return abs(value) + N;

    return value;

}



inline int neg(int value) {

    if (value > N)

        return value - N;

    return value + N;

}



void DFP(int node) {

    used[node] = 1;

    for (auto it : G[node]) {

        if (used[it])

            continue;

        DFP(it);

    }

    discover.emplace_back(node);

}



void DFM(int node, int index) {

    used[node] = 1;

    comp[node] = index;

    C[index].emplace_back(node);

    for (auto it : GT[node]) {

        if (used[it])

            continue;

        DFM(it, index);

    }

}



int main() {

 ios_base::sync_with_stdio(false);



    freopen("party.in", "r", stdin);

    freopen("party.out", "w", stdout);

 freopen("debug.err", "w", stderr);





    int i;



    cin >> N >> M;

    for (i = 1; i <= M; ++i) {

        int x, y, c;

        cin >> x >> y >> c;



        if (c == 0) {

            x = idx(x), y = idx(y);

            G[neg(x)].emplace_back(y);

            G[neg(y)].emplace_back(x);

            GT[y].emplace_back(neg(x));

            GT[x].emplace_back(neg(y));

        } else if (c == 1) {

            x = idx(x), y = neg(idx(y));

            G[neg(x)].emplace_back(y);

            G[neg(y)].emplace_back(x);

            GT[y].emplace_back(neg(x));

            GT[x].emplace_back(neg(y));

        } else if (c == 2) {

            x = neg(idx(x)), y = idx(y);

            G[neg(x)].emplace_back(y);

            G[neg(y)].emplace_back(x);

            GT[y].emplace_back(neg(x));

            GT[x].emplace_back(neg(y));

        } else {

            x = neg(idx(x)), y = neg(idx(y));

            G[neg(x)].emplace_back(y);

            G[neg(y)].emplace_back(x);

            GT[y].emplace_back(neg(x));

            GT[x].emplace_back(neg(y));

        }

    }



    for (i = 1; i <= 2 * N; ++i) {

        if (used[i])

            continue;

        DFP(i);

    }



    reverse(discover.begin(), discover.end());

    memset(used, 0, sizeof(used));

    int index = 0;

    for (auto it : discover) {

        if (used[it])

            continue;

        DFM(it, index++);

    }



    for (i = 1; i <= N; ++i) {

        if (comp[i] == comp[i + N]) {

            cout << "-1\n";

            return 0;

        }

    }



    memset(answer, -1, sizeof(answer));

    for (i = 0; i < index; ++i) {

        for (auto it : C[i]) {

            if (it <= N && answer[it] != -1)

                continue;

            if (it > N && answer[it - N] != -1)

                continue;

            if (it <= N)

                answer[it] = 0;

            else

                answer[it - N] = 1;

        }

    }



    int cnt = 0;

    for (i = 1; i <= N; ++i)

        if (answer[i])

            ++cnt;

    cout << cnt << '\n';

    for (i = 1; i <= N; ++i)

        if (answer[i])

            cout << i << '\n';

    cout << '\n';



 return 0;

}
