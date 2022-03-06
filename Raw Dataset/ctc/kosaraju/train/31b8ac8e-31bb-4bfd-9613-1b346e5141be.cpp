#include <fstream>
#include <vector>
#include <stack>




using namespace std;



ifstream fin ("ctc.in");

ofstream fout ("ctc.out");



const int NMAX = 100001;

int n, m, nrCTC;

int vizitat[NMAX];

vector<int> g[NMAX], gt[NMAX], ctc[NMAX];

stack<int> s;



void citire() {

    int i, x, y;



    fin >> n >> m;

    for (i = 1; i <= m; i++) {

        fin >> x >> y;

        g[x].push_back(y);

        gt[y].push_back(x);

    }

}



void dfs(int nod) {

    int i;



    vizitat[nod] = 1;

    for (i = 0; i < g[nod].size(); i++) {

        if (vizitat[g[nod][i]] == 0)

            dfs(g[nod][i]);

    }

    s.push(nod);

}



void dfsT(int nod) {

    int i;



    vizitat[nod] = 2;

    ctc[nrCTC].push_back(nod);



    for (i = 0; i < gt[nod].size(); i++) {

        if (vizitat[gt[nod][i]] == 1)

            dfsT(gt[nod][i]);

    }

}



void kosaraju() {

    int i;



    for (i = 1; i <= n; i++)

        if (vizitat[i] == 0)

            dfs(i);



    while (!s.empty()) {

        int nod = s.top();

        if (vizitat[nod] == 1) {

            nrCTC++;

            dfsT(nod);

        }

        s.pop();

    }

}



void tiparire() {

    int i, j;



    fout << nrCTC << '\n';

    for (i = 1; i <= nrCTC; i++) {

        for (j = 0; j < ctc[i].size(); j++)

            fout << ctc[i][j] << ' ';

        fout << '\n';

    }

}



int main() {

    citire();

    kosaraju();

    tiparire();



    fin.close();

    fout.close();



    return 0;

}
