#include <bits/stdc++.h>
using namespace std;

ifstream fi("stramosi.in");
ofstream fo("stramosi.out");

const int N = 250005, LG = 19;

vector<int> g[N];
int far[LG][N], lvl[N];

int n, q;

void make_far() {
    for (int lg = 1; lg < LG; ++lg)
    for (int i = 1; i <= n; ++i)
        far[lg][i] = far[lg - 1][far[lg - 1][i]];
}

int get_far(int nod, int lvl) {
    if (lvl > (1 << LG - 1))
        return 0;
    for (int i = 0; i < LG; ++i)
        if ((1 << i) & lvl)
            nod = far[i][nod];
    return nod;
}

int main() {
    fi >> n >> q;
    for (int i = 1; i <= n; ++i)
        fi >> far[0][i];
    make_far();

    while (q--) {
        int nod, lvl;
        fi >> nod >> lvl;
        fo << get_far(nod, lvl) << '\n';
    }

    return 0;
}
