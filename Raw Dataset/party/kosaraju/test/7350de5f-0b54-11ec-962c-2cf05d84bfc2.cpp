#include <queue>
#include <stack>
#include <map>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <algorithm>
#include <bitset>
#include <time.h>
#include <tuple>
#include <fstream>
#include <iomanip>
#include <utility>
#include <list>
using namespace std;
ifstream cin("a.in");
ofstream cout("a.out");

template<class v, class type>
void afis(v Vector, type nr) {
    for_each(Vector.begin(),Vector.end(), [](type x) {
        cout << x << ' ';
    });
}

struct nod {
    list<int> adi;
    list<int> invadi;
};

int n;
nod nod[300];
bitset<300> viz;
vector<vector<int> > ctc;
stack<int> finish;
int nrcomp = 0;
int sol[300];

int neg(int nod) {
    if (nod <= n)
        return nod + n;
    else return nod - n;
}

void edge(const int p1, const int p2) {
    nod[p1].adi.push_back(p2);
    nod[p2].invadi.push_back(p1);
}

void fapedfs(const int start) {
    viz[start] = true;
    for (auto it = nod[start].adi.begin(); it != nod[start].adi.end(); ++it) {
        if (!viz[*it])
            fapedfs(*it);
    }
    finish.push(start);
}

void invdfs(const int start) {
    viz[start] = true;
    ctc[nrcomp].emplace_back(start);
    for (auto it = nod[start].invadi.begin(); it != nod[start].invadi.end(); ++it) {
        if (!viz[*it])
            invdfs(*it);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    clock_t tStart = clock();
    int m, x, y, cod;
    cin >> n >> m;
    while (m--) {
        cin >> x >> y >> cod;

        switch (cod) {
            case 0: {
                edge(neg(x), y);
                edge(neg(y), x);
                break;
            }
            case 1: {
                edge(neg(x), neg(y));
                edge(y, x);
                break;
            }
            case 2: {
                edge(neg(y), neg(x));
                edge(x, y);
                break;
            }
            case 3: {
                edge(x, neg(y));
                edge(y, neg(x));
                break;
            }
        }
    }
    for (int i = 1; i <= 2*n; ++i) {
        if (!viz[i])
            fapedfs(i);
    }

    viz.reset();
    vector<int> temp;
    ctc.push_back(temp);

    while (!finish.empty()) {
        if (!viz[finish.top()]) {
            ctc.push_back(temp);
            ++nrcomp;
            invdfs(finish.top());
        }
        finish.pop();
    }
    for (int i = 0; i <= 2*n; ++i)
        sol[i] = -1;

    int participanti = 0;

    for (int i = nrcomp; i >= 1; --i) {
        if (sol[ctc[i][0]] == -1) {
            for (auto it = ctc[i].begin(); it != ctc[i].end(); ++it) {
                sol[*it] = 1;
                sol[neg(*it)] = 0;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (sol[i] == -1) {
            sol[i] = 1;
        }
        participanti += sol[i];
    }
    cout << participanti << '\n';
    for (int i = 1; i <= n; ++i) {
        if (sol[i])
            cout << i << '\n';
    }

    printf("\nTime taken: %.2fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
}
