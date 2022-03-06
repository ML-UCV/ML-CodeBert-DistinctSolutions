#include <bits/stdc++.h>

using namespace std;

ifstream fin("apm.in");
ofstream fout("apm.out");

const int MAX_N = 200000;

struct Edge {
    int c, u, v;
};

int n, m;
int tata[MAX_N + 5], cnt[MAX_N + 5];

vector<Edge> edges;
vector<pair<int, int> > ans;

int sum;

inline bool cmp(const Edge &a, const Edge &b) {
    return a.c < b.c;
}

int root(int x) {
    if (tata[x] == x)
        return x;
    return tata[x] = root(tata[x]);
}

void join(int x, int y){
    x = root(x);
    y = root(y);

    if(cnt[x] > cnt[y])
        swap(x, y);

    cnt[y] += cnt[x];
    tata[x] =y;
}

int main() {
    int n, m;
    fin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        fin >> a >> b >> c;
        edges.push_back({c, a, b});
    }

    sort(edges.begin(), edges.end(), cmp);

    for (int i = 1; i <= n; i++) {
        tata[i] = i;
        cnt[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int a = edges[i].u;
        int b = edges[i].v;
        int c = edges[i].c;

        if (root(a) == root(b))
            continue;

        join(a, b);
        sum += c;
        ans.push_back({a, b});
    }

    fout << sum << '\n' << ans.size() << '\n';
    for (auto i : ans)
        fout << i.first << ' ' << i.second << '\n';
    return 0;
}
