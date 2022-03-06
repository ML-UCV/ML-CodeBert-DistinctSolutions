#include <vector>
#include <fstream>




using std::vector;



std::ifstream fin("ctc.in");

std::ofstream fout("ctc.out");



int n, m;

bool vis[100010];



vector<int> ad1[100010];

vector<int> ad2[100010];



int nrComp;

vector<int> comp[100010];



int top;

int st[100010];



void dfs1(int node) {

    vis[node] = true;

    for (int i = 0; i < (int) ad1[node].size(); i++)

        if (!vis[ad1[node][i]])

            dfs1(ad1[node][i]);

    st[++top] = node;

}



void dfs2(int node) {

    vis[node] = true;

    comp[nrComp].push_back(node);



    for (int i = 0; i < (int) ad2[node].size(); i++)

        if (!vis[ad2[node][i]])

            dfs2(ad2[node][i]);

}



int main() {

    fin >> n >> m;

    for (int i = 0; i < m; i++) {

        int x, y;

        fin >> x >> y;



        ad1[x].push_back(y);

        ad2[y].push_back(x);

    }



    for (int i = 1; i <= n; i++)

        if (!vis[i])

            dfs1(i);



    for (int i = 1; i <= n; i++)

        vis[i] = false;



    while (top) {

        if (!vis[st[top]]) {

            dfs2(st[top]);

            nrComp++;

        }

        top--;

    }



    fout << nrComp << '\n';

    for (int i = 0; i < nrComp; i++) {

        for (int j = 0; j < (int) comp[i].size(); j++)

            fout << comp[i][j] << ' ';

        fout << '\n';

    }



    fout.close();

    return 0;

}
