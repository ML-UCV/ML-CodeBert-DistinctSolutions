#include <bits/stdc++.h>

using namespace std;

class InParser {
private:
    FILE *fin;
    char *buff;
    int sp;

    char read_ch() {
        ++sp;
        if (sp == 4096) {
            sp = 0;
            fread(buff, 1, 4096, fin);
        }
        return buff[sp];
    }

public:
    InParser(const char* nume) {
        fin = fopen(nume, "r");
        buff = new char[4096]();
        sp = 4095;
    }

    InParser& operator >> (int &n) {
        char c;
        while (!isdigit(c = read_ch()) && c != '-');
        int sgn = 1;
        if (c == '-') {
            n = 0;
            sgn = -1;
        } else {
            n = c - '0';
        }
        while (isdigit(c = read_ch())) {
            n = 10 * n + c - '0';
        }
        n *= sgn;
        return *this;
    }
};

InParser fin("sate.in");
ofstream fout("sate.out");

const int NMAX = 3e4 + 4;
int N, M, X, Y, dp[NMAX];
bool vis[NMAX];
vector<pair<int,int>> G[NMAX];

void min_self(int &a, int b) {
    a = min(a, b);
}

void dfs(int u) {
    vis[u] = true;
    for(const pair<int,int> &v : G[u])
        if(!vis[v.first]) {
            if(v.first > u)
                min_self(dp[v.first], dp[u] + v.second);
            else
                min_self(dp[v.first], dp[u] - v.second);
            dfs(v.first);
        }
}

int main() {
    fin >> N >> M >> X >> Y;
    if(X > Y)
        swap(X, Y);
    memset(dp, 0x3f, sizeof(dp));
    dp[X] = 0;
    while(M--) {
        int u, v, w;
        fin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
        if(u == X)
            dp[v] = w;
    }
    dfs(X);
    fout << dp[Y];
}
