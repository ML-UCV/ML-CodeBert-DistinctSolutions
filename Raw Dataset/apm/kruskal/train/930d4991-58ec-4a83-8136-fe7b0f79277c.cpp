#include <bits/stdc++.h>






using namespace std;



int n , m, cost;

vector<tuple<int, int, int>> edges, apm;

int root[200010];



int get_set(int x) {

    if (x != root[x])

        root[x] = get_set(root[x]);

    return root[x];

}



int main()

{

    cost = 0;

    ifstream fin("apm.in");

    fin >> n >> m;

    for (int i = 1, x, y, c; i <= m; ++i) {

        fin >> x >> y >> c;

        root[i] = i;

        edges.push_back(make_tuple(c, x, y));

    }

    fin.close();



    sort(edges.begin(), edges.end());

    for (auto &edge : edges) {

        int c = get<0>(edge), x = get<1>(edge), y = get<2>(edge);

        if (get_set(x) != get_set(y)) {

            cost += c;

            apm.push_back(edge);

            if (apm.size() == n - 1)

                break;

            root[get_set(x)] = get_set(y);

        }

    }



    ofstream fout("apm.out");

    fout << cost << endl << n - 1 << endl;

    for (auto &edge : apm) {

        fout << get<1>(edge) << ' ' << get<2>(edge) << endl;

    }

    fout.close();

    return 0;

}
