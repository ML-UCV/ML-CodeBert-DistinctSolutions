#include <bits/stdc++.h>
using namespace std;

const int NMAX = 2e2 + 5;

vector<int> stk;
bitset<NMAX> fins, instk;
int hgt, n;

vector<int> g[NMAX];
int lvl[NMAX], low[NMAX], val[NMAX];

int inv(int x) {
    if (x <= n) return n + x;
    if (x > n) return x - n; }

void sat(int u) {
    stk.push_back(u);
    instk[u] = true;
    lvl[u] = low[u] = ++hgt;

    for (auto v: g[u]) {
        if (lvl[v] == 0)
            sat(v);
        if (instk[v])
            low[u] = min(low[u], low[v]); }

    if (lvl[u] == low[u]) {
        int top;
        do {
            top = stk.back();
            stk.pop_back();
            instk[top] = false;

            if (!val[top]) {
                val[top] = 1;
                val[inv(top)] = -1; } }
        while (top != u); } }

int main(void) {
    freopen("party.in", "r", stdin);
    freopen("party.out", "w", stdout);

    int m, x, y, op;

    scanf("%d%d ", &n, &m);
    while (m--) {
        scanf("%d%d%d ", &x, &y, &op);
        switch(op) {
        case 0: {
            g[inv(x)].push_back(y);
            g[inv(y)].push_back(x);
            break; }
        case 1: {
            g[inv(x)].push_back(inv(y));
            g[y].push_back(x);
            break; }
        case 2: {
            g[inv(y)].push_back(inv(x));
            g[x].push_back(y);
            break; }
        case 3: {
            g[x].push_back(inv(y));
            g[y].push_back(inv(x));
            break; } } }

    for (int i = 1; i <= 2 * n; ++i)
        if (lvl[i] == 0)
            sat(i);

    for (int i = 1; i <= n; ++i)
        if (val[i] == 1)
            stk.push_back(i);

    printf("%d\n", stk.size());
    for (auto i: stk)
        printf("%d\n", i);
    printf("\n");

    return 0; }
