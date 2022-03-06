#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");

pair<int, int> coresp[250100];

vector<int> lant[250100];

bool f[250100];

int v[250100], lung[250100];

int n, m, a, l;



void build(int i) {

    coresp[i] = make_pair(l, lung[l]++);

    lant[l].push_back(i);



    if (i == 0)

        return;



    if (coresp[v[i]].first) {

        int nou = coresp[v[i]].first;

        int sf = lung[nou];



        for (int h = coresp[v[i]].second; h < sf; h++)

            lant[l].push_back(lant[nou][h]), lung[l]++;



        return;

    }



    build(v[i]);

}



int main() {

    fin >> n >> m;

    for (int i = 1; i <= n; i++) {

        fin >> a;

        v[i] = a;

        f[a] = true;

    }



    for (int i = 1; i <= n; i++)

        if (!f[i]) {

            ++l;

            build(i);

        }



    for (int i = 1; i <= m; i++) {

        int q, p;

        fin >> q >> p;

        fout << lant[coresp[q].first][min(lung[coresp[q].first] - 1, coresp[q].second + p)] << '\n';

    }

    return 0;

}
