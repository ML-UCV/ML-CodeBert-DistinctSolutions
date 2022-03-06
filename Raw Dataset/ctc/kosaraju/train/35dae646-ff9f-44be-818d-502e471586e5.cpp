#include <bits/stdc++.h>
using namespace std;






using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

const int INF = INT_MAX;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);

ll t, n;


struct graph {

    vector<vector<int>> out, in;

    vector<bool> mark;

    vector<int> ord, comp;

    vector<vector<int>> ans;



    graph(int n = 0) {

        out.resize(n + 1);

        in.resize(n + 1);

        mark.resize(n + 1, false);

        comp.resize(n + 1, -1);

        ans.resize(n + 1);

    }



    void add(int from, int to) {

        out[from].push_back(to);

        in[to].push_back(from);

    }



    void dfs_ord(int node) {

        if (mark[node]) return;

        mark[node] = true;



        for (auto next: out[node])

            dfs_ord(next);



        ord.push_back(node);

    }



    void dfs_comp(int node, int c) {

        if (comp[node] != -1) return;

        comp[node] = c;

        ans[c].push_back(node);

        for (auto next: in[node])

            dfs_comp(next, c);

    }

};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("ctc.in");
    ofstream cout("ctc.out");


    int m, from, to;

    cin >> n >> m;

    graph g(n);

    for (int i = 0; i < m; i++) {

        cin >> from >> to;

        g.add(from, to);

    }





    for (int i = 1; i <= n; i++)

        g.dfs_ord(i);

    g.mark.assign(n + 1, false);





    int c = 1;

    for (int i = n - 1; i >= 0; i--) {

        if (g.comp[g.ord[i]] == -1) {

            g.dfs_comp(g.ord[i], c);

            c++;

        }

    }



    cout << --c << '\n';

    for (int i = 1; i <= c; i++) {

        for (auto v: g.ans[i])

            cout << v << " ";

        cout << "\n";

    }

    return 0;
}
