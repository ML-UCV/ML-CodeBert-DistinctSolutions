#include <fstream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

ifstream in("ctc.in");
ofstream out("ctc.out");

bool f[100005], f2[100005];
int n, m, nrCTC, maxim = -5;
vector <int> v[100005], ctc[100005], v2[100005];
stack <int> st;

void dfs(int x) {
    for(unsigned int i = 0; i < v[x].size(); ++i) {
        int y = v[x][i];
        if(f[y] == 0) {
            f[y] = 1;
            dfs(y);
        }
    }
    st.push(x);
}

void dfs2(int x, int &nrMax) {
    ctc[nrCTC].push_back(x);
    for(unsigned int i = 0; i < v2[x].size(); ++i) {
        int y = v2[x][i];
        if(f2[y] == 0) {
            nrMax++;
            f2[y] = 1;
            dfs2(y, nrMax);
        }
    }
}

int main() {

    in >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int x, y;
        in >> x >> y;
        v[x].push_back(y);
        v2[y].push_back(x);
    }

    for(int i = 1; i <= n; ++i) {
        if(f[i] == 0) {
            f[i] = 1;
            dfs(i);
        }
    }

    while(!st.empty()) {
        int x = st.top();
        if(f2[x] == 0) {
            f2[x] = 1;
            int nrMax = 1;
            ++nrCTC;
            dfs2(x, nrMax);
            if(nrMax > maxim)
                maxim = nrMax;
        }
        st.pop();
    }
    out << nrCTC << '\n';
    for(int i = 1; i <= nrCTC; ++i) {
        for(unsigned int j = 0; j < ctc[i].size(); ++j) {
            out << ctc[i][j] << ' ';
        }
        out << '\n';
    }

    return 0;
}
