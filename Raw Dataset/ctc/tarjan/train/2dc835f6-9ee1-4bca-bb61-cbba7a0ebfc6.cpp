#include <fstream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

int n, m, i, j, k, index, ord[100005], niv_min[100005];
vector<int> vec[100005], comp[100005];
stack<int> st;
set<int> s;

void tarjan(int nod) {
    int ind, x;

    ord[nod] = index;
    niv_min[nod] = index;
    index++;
    st.push(nod);
    s.insert(nod);

    for(ind = 0; ind < vec[nod].size(); ind++)
        if(!ord[vec[nod][ind]]) {
            tarjan(vec[nod][ind]);
            niv_min[nod] = min(niv_min[nod], niv_min[vec[nod][ind]]);
        }
        else if(s.find(vec[nod][ind]) != s.end())
            niv_min[nod] = min(niv_min[nod], ord[vec[nod][ind]]);

    if(ord[nod] == niv_min[nod])
        while(!st.empty()) {
            x = st.top();
            st.pop();
            s.erase(x);
            comp[k].push_back(x);
            if(x == nod) {
                k++;
                break;
            }
        }
}

int main() {
    ifstream f("ctc.in");
    ofstream g("ctc.out");

    f >> n >> m;
    while(m) {
        f >> i >> j;

        vec[i].push_back(j);
        m--;
    }
    f.close();

    k = 0;
    index = 1;
    for(i = 1; i <= n; i++)
        if(!ord[i])
            tarjan(i);

    g << k << '\n';
    for(i = 0; i < k; i++, g << '\n')
        for(j = 0; j < comp[i].size(); j++)
            g << comp[i][j] << ' ';
    g.close();

    return 0;
}
