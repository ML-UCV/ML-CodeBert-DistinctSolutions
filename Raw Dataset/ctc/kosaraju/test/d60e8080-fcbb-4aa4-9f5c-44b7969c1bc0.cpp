#include <stdio.h>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

int n, m, ctc;

stack <int> st;

vector <int> v1[100005];
vector <int> v2[100005];
vector <int> ans[100005];
vector<int> comp;

void dfs1(int);
void dfs2(int);

bool viz[100005], viz1[100005], viz2[100005];


int main(int argc, const char * argv[]) {

    FILE *f = fopen("ctc.in","r");
    FILE *g = fopen("ctc.out", "w");
    fscanf(f, "%d %d\n", &n, &m);
    while (m--) {
        int x, y;
        fscanf(f, "%d %d\n", &x, &y);
        v1[x].push_back(y);
        v2[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        if (!viz1[i]) {
            dfs1(i);
        }
    }

    while (!st.empty()) {
        if (!viz2[st.top()]) {
            ++ctc;
            dfs2(st.top());
        }
        st.pop();
    }
    fprintf(g, "%d\n",ctc);
    for (int i = 1; i <= ctc; ++i) {
        for (auto it:ans[i])
            fprintf(g, "%d ", it);
        fprintf(g, "\n");
    }
    return 0;
}

void dfs1(int node) {
    viz1[node] = 1;
    for (auto it:v1[node])
        if (viz1[it] == 0) {
            dfs1(it);
        }
    st.push(node);
}

void dfs2(int node) {
    viz2[node] = 1;
    ans[ctc].push_back(node);

    for (auto it:v2[node])
        if (viz2[it] == 0) {
            dfs2(it);
        }
}
