#include <fstream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_N = 50002;
const int SIGMA = 27;

int N;
int A[5*MAX_N], cnt_s1[SIGMA], cnt_s2[SIGMA];
queue < int > pos[SIGMA];
char s1[MAX_N], s2[MAX_N];

void update(int node, int left, int right, int x, int val) {
    if(left == right)
        A[node] += val;
    else {
        int ls = 2*node, rs = 2*node + 1, m = (left + right)/2;

        if(x <= m)
            update(ls, left, m, x, val);
        else
            update(rs, m + 1, right, x, val);
        A[node] = A[ls] + A[rs];
    }
}

int query(int node, int left, int right, int x, int y) {
    if(x <= left && right <= y)
        return A[node];
    else {
        int ls = 2*node, rs = 2*node + 1, m = (left + right)/2;

        int ans = 0;
        if(x <= m)
            ans += query(ls, left, m, x, y);
        if(y > m)
            ans += query(rs, m + 1, right, x, y);

        return ans;
    }
}

int main() {
    ifstream f("swap.in");
    ofstream g("swap.out");

    f >> s1;
    f >> s2;

    int len = strlen(s1);
    for(int i = 0; i < len; ++i)
        ++cnt_s1[s1[i] - 'a'];
    for(int i = 0; i < len; ++i)
        ++cnt_s2[s2[i] - 'a'];

    bool ok = 1;
    for(int i = 0; i < SIGMA; ++i)
        if(cnt_s1[i] != cnt_s2[i])
            ok = 0;
    int ans = 0;
    if(ok) {
        for(int i = len; i >= 1; --i)
            s1[i] = s1[i-1];
        for(int i = len; i >= 1; --i)
            s2[i] = s2[i-1];
        for(int i = 1; i <= len; ++i)
            pos[s1[i] - 'a'].push(i);
        for(int i = 1; i <= len; ++i) {
            int p = pos[s2[i] - 'a'].front();
            pos[s2[i] - 'a'].pop();
            int temp;
            if(p < len)
                temp = query(1, 1, len, p + 1, len);
            else temp = 0;
            ans += p + temp - i;
            update(1, 1, len, p, 1);
        }
    }
    else ans = -1;

    g << ans << "\n";

    f.close();
    g.close();

    return 0;
}
