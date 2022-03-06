#include <fstream>
#include <vector>
#include <queue>
using namespace std;



ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



int N, M, viz[250002], sol[300005];



vector <int> graph[250002], s;

queue <int> Q;



struct str{

    int val, poz;

};



vector <str> v[250002];



inline void Read() {

    int x, y;



    fin >> N >> M;



    for (int i = 1; i <= N; i++) {

        fin >> x;

        if (!x) {

            Q.push(i);

        }

        else {

            graph[x].push_back(i);

        }

    }



    for (int i = 1; i <= M; i++){

        fin >> x >> y;



        v[x].push_back({y, i});

    }

}



inline void DFS(int node) {

    viz[node] = 1;

    if (!v[node].empty()) {

        int ll = s.size();

        for (auto j : v[node]) {

            if (ll - j.val >= 0)

                sol[j.poz] = s[ll - j.val];

        }

    }

    s.push_back(node);



    for (auto x : graph[node]) {

        if (!viz[x]) {

            DFS(x);

        }

    }

    s.pop_back();

 }



inline void Solve() {

    int z;

    while (!Q.empty()) {

        z = Q.front();

        Q.pop();

        if (viz[z])

            continue;

        s = vector <int> ();

        DFS(z);

    }

}



inline void Write() {

    for (int i = 1; i <= M; i++)

        fout << sol[i] << "\n";

}



int main () {

    Read();

    Solve();

    Write();



    fin.close(); fout.close(); return 0;

}
