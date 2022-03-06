#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;



typedef tuple<int, int, int> edge;
int n, m, cost, p[200009];

vector<edge> edges;

vector<edge> apm;



int get_set(int node) {

    if (p[node] != node) {

        p[node] = get_set(p[node]);

    }



    return p[node];

}



void reunion_set(int x, int y) {

    p[get_set(x)] = get_set(y);

}



void Kruskal() {

    for (int i = 1; i <= n; ++i) {

        p[i] = i;

    }



    cost = 0;

    for (auto it = edges.begin(); it != edges.end(); ++it) {

        int x = std::get<1>(*it), y = std::get<2>(*it), c = std::get<0>(*it);



        if (get_set(x) != get_set(y)) {

            cost += c;

            apm.push_back(*it);

            reunion_set(x, y);

        }

    }

}



int main() {

    ifstream fin("apm.in");

    ofstream fout("apm.out");

    fin >> n >> m;



    for (int i = 0; i <= m; ++i) {

        int x, y, c;

        fin >> x >> y >> c;



        edges.push_back(edge(c, x, y));

    }



    sort(edges.begin(), edges.end());



    Kruskal();



    fout << cost << "\n";

    fout << (n - 1) << "\n";

    for (auto it = apm.begin(); it != apm.end(); ++it) {

        fout << std::get<1>(*it) << " " << std::get<2>(*it) << "\n";

    }



    fin.close();

    fout.close();

    return 0;

}
