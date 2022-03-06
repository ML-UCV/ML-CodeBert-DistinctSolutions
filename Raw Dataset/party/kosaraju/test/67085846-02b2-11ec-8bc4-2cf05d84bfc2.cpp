#include<stdio.h>
#include<string.h>
#include<stack>
#include<vector>
using namespace std;

const int NMAX = 105;

vector <int> graph[NMAX * 2], trans[NMAX * 2];
int n, val[NMAX * 2], vis[NMAX * 2];
stack <int> st;

inline int neg (int x) {
    return x > n ? x - n : x + n;
}

void dfsPlus (int node) {
    vis[node] = 1;
    for(vector <int>::iterator it = graph[node].begin(); it != graph[node].end(); ++ it)
        if(!vis[*it])
            dfsPlus(*it);
    st.push(node);
}

void dfsMinus (int node) {
    vis[node] = 1;
    val[neg(node)] = 1;

    for(vector <int>::iterator it = trans[node].begin(); it != trans[node].end(); ++ it)
        if(!vis[*it])
            dfsMinus(*it);
}

void sau (int x, int y) {
    graph[neg(x)].push_back(y);
    trans[y].push_back(neg(x));

    graph[neg(y)].push_back(x);
    trans[x].push_back(neg(y));
}

int main() {
    freopen("party.in", "r", stdin);
    freopen("party.out", "w", stdout);
    int m, i, j, a, b, c;

    scanf("%d%d", &n, &m);
    for(i = 1; i <= m; ++ i) {
        scanf("%d%d%d", &a, &b, &c);
        if(c == 0)
            sau(a, b);

        if(c == 1)
            sau(a, neg(b));

        if(c == 2)
            sau(neg(a), b);

        if(c == 3)
            sau(neg(a), neg(b));
    }

    for(i = 1; i <= 2 * n; ++ i)
        if(!vis[i])
            dfsPlus(i);

    memset(vis, 0, sizeof(vis));
    while(!st.empty()) {
        if(!vis[st.top()] && !vis[neg(st.top())]) {

            dfsMinus(st.top());
        }
        st.pop();
    }

    c = 0;
    for(i = 1; i <= n; ++ i)
        c += val[i];

    printf("%d\n", c);
    for(i = 1; i <= n; ++ i)
        if(val[i])
            printf("%d\n", i);
    return 0;
}
