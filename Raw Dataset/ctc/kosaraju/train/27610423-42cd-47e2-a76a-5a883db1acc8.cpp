#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



const int maxn = 1e5+5;



int n, m, x, y, k, bn;

int viz[maxn];

int member[maxn];



vector <int> nod[maxn], tr[maxn], ans[maxn];

stack <int>L;



void visit(int x) {

    viz[x] = 1;

    for(auto u : nod[x]) {

        if(viz[u] == 0) {

            visit(u);

        }

    }

    L.push(x);

}



void assgn(int u) {

    ans[k].push_back(u);

    member[u] = k;

    viz[u] = 2;

    for(auto v : tr[u]) {

        if(viz[v] == 1) {

            assgn(v);

        }

    }

}



int main()

{

    int i;

    f >> n >> m;

    for(i = 1; i <= m; i ++) {

        f >> x >> y;

        nod[x].push_back(y);

        tr[y].push_back(x);

    }

    for(i = 1; i <= n; i ++) {

        if(viz[i] == 0) {

            visit(i);

        }

    }



    while(!L.empty()) {

        auto u = L.top();

        if(viz[u] == 1) {

            ++k;

            assgn(u);

        }

        L.pop();

    }



    g << k << '\n';

    for(i = 1; i <= k; i ++) {

        for(auto u : ans[i]) {

            g << u << ' ';

        }

        g << '\n';

    }



    f.close(); g.close();

    return 0;

}
