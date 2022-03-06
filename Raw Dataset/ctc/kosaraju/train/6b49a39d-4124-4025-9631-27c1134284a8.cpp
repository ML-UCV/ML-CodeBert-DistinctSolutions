#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



const int NMAX = 1e5+5;

vector<int> graf[NMAX], grafT[NMAX], sol[NMAX];

int n, m, cnt;

vector<int> postorder;

bool vis[NMAX], visT[NMAX];



void dfs(int nod) {

    vis[nod] = 1;

    for(int i = 0; i < (int)graf[nod].size(); i++) {

        int next = graf[nod][i];

        if(!vis[next]) {

            dfs(next);

        }

    }

    postorder.push_back(nod);

}



void dfsT(int nod) {

    visT[nod] = 1;

    sol[cnt].push_back(nod);

    for(int i = 0; i < (int)grafT[nod].size(); i++) {

        int next = grafT[nod][i];

        if(!visT[next]) {

            dfsT(next);

        }

    }

}



int main()

{

    f >> n >> m;

    while(m--) {

        int x, y;

        f >> x >> y;

        graf[x].push_back(y);

        grafT[y].push_back(x);

    }

    for(int i = 1; i <= n; i++) {

        if(!vis[i]) {

            dfs(i);

        }

    }

    for(int i = postorder.size() - 1; i >= 0; i--) {

        if(!visT[postorder[i]]) {

            cnt++;

            dfsT(postorder[i]);

        }

    }

    g << cnt << '\n';

    for(int i = 1; i <= cnt; i++) {

        for(int j = 0; j < (int)sol[i].size(); j++) {

            g << sol[i][j] << ' ';

        }

        g << '\n';

    }

    return 0;

}
