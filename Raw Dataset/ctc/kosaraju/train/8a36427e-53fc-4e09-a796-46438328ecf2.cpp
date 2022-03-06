#include <fstream>
#include <vector>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



bool visited[100001];

vector<int> graph1[100001];

vector<int> graph2[100001];

vector<int> ctc[100001];

int q, k, s[100001];



void dfs1(int node) {

    visited[node] = true;

    for(auto n : graph1[node])

        if(!visited[n])

            dfs1(n);

    s[++k] = node;

}





void dfs2(int node) {

    visited[node] = false;

    ctc[q].push_back(node);

    for(auto n : graph2[node])

        if(visited[n] == 1)

            dfs2(n);

}





int main() {

    int n, m;

    fin >> n >> m;



    for(int i = 1; i <= m; i++) {

        int x, y;

        fin >> x >> y;



        graph1[x].push_back(y);

        graph2[y].push_back(x);

    }



    for(int i = 1; i <= n; i++) {

        if(!visited[i]) {

            dfs1(i);

        }

    }

    for(int i = n; i >= 1; i--) {

        if(visited[s[i]] == 1) {

            q++;

            dfs2(s[i]);

        }

    }



    fout << q << '\n';

    for(int i = 1; i <= q; i++) {

        for(auto node : ctc[i])

            fout << node << ' ';

        fout << '\n';

    }

}
