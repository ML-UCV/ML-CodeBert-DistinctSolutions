#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

ifstream cin("party.in");
ofstream cout("party.out");

int n, m;

vector<vector<int> > gr(200100);
vector<vector<int> > inv(200100);

vector<bool> used(200100);

vector<int> verif;
vector<int> now;

vector<vector<int> > comp(200100);
vector<int> COMP(200100);
int cont = 0;
vector<vector<int> > GR(200100);
vector<int> enter(200100);

queue<int> Q;
vector<int> ord_top;

vector<int> ans(200100);

bool ret = false;

void dfs(int root) {

    used[root] = true;
    for (auto &x : gr[root]) {
        if (!used[x]) {
            dfs(x);
        }
    }
    verif.push_back(root);

}

void DFS(int root) {

    used[root] = true;
    COMP[root] = cont;
    now.push_back(root);
    for (auto &x : inv[root]) {
        if (!used[x]) {
            DFS(x);
        }
    }

}

void bfs() {

    while (!Q.empty()) {

        int Now = Q.front();
        Q.pop();
        ord_top.push_back(Now);

        for (auto &x : GR[Now]) {
            enter[x]--;
            if (!enter[x]) {
                Q.push(x);
            }
        }

    }

}

int val(int nr) {
    if (nr < 0) {
        return n - nr;
    }
    return nr;
}

int OPUS(int nr) {
    if (nr > n) {
        return nr - n;
    }
    return nr + n;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {

        int a, b, t;
        cin >> a >> b >> t;

        int A = val(-a);
        int B = val(-b);
        a = val(a);
        b = val(b);

        int x1, x2, y1, y2;

        if (t == 0) {
            x1 = A;
            x2 = B;
            y1 = b;
            y2 = a;
        }
        if (t == 1) {
            x1 = b;
            x2 = A;
            y1 = a;
            y2 = B;
        }
        if (t == 2) {
            x1 = a;
            x2 = B;
            y1 = b;
            y2 = A;
        }
        if (t == 3) {
            x1 = a;
            x2 = b;
            y1 = B;
            y2 = A;
        }

        gr[x1].push_back(y1);
        gr[x2].push_back(y2);

        inv[y1].push_back(x1);
        inv[y2].push_back(x2);

    }



    for (int i = 1; i <= 2 * n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    for (int i = 1; i <= 2 * n; i++) {
        used[i] = false;
    }

    reverse(verif.begin(), verif.end());

    for (auto &x : verif) {
        if (!used[x]) {
            now.clear();
            cont++;
            DFS(x);
            comp[cont] = now;
        }
    }
    for (int i = n + 1; i <= n; i++) {
        if (COMP[i] == COMP[i - n]) {
            ret = true;

        }
    }



    for (int i = 1; i <= cont; i++) {
        for (auto &x : comp[i]) {
            for (auto &y : gr[x]) {
                if (COMP[y] != i) {
                    GR[i].push_back(COMP[y]);
                    enter[COMP[y]]++;
                }
            }
        }
    }

    for (int i = 1; i <= cont; i++) {
        if (!enter[i]) {
            Q.push(i);
        }
    }

    bfs();
    for (int i = 1; i <= cont; i++) {
        ans[i] = -1;
    }

    for (auto &i : ord_top) {

        if (ans[i] == -1) {
            ans[i] = 0;
        }
        for (auto &x : comp[i]) {
            int opus = OPUS(x);

            if (ans[COMP[opus]] == -1) {
                ans[COMP[opus]] = ans[i] ^ 1;
            } else {
                if (ans[COMP[opus]] == ans[i]) {
                    ret = true;

                }
            }
            for (auto &y : gr[x]) {
                if (COMP[y] == COMP[x]) {
                    continue;
                }
                if (ans[i] == 1) {
                    if (ans[COMP[y]] == 0) {
                        ret = true;

                    }
                    ans[COMP[y]] = 1;
                }
            }

        }

    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (ans[COMP[i]]) {
            cnt++;
        }
    }

    cout << cnt << '\n';
    for (int i = 1; i <= n; i++) {
        if (ans[COMP[i]]) {
            cout << i << '\n';
        }
    }


    return 0;
}
