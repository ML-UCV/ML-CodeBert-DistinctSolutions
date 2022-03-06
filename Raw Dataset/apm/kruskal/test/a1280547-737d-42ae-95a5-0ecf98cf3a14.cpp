#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
#include <algorithm>


using namespace std;



typedef tuple<int, int, int> T;

typedef pair<int, int> P;



void read(int& n, int& m, vector<T>& utak,vector<P>& fa) {

    ifstream fin("apm.in");

    fin >> n >> m;

    utak.resize(m + 1);

    fa.resize(m + 1);

    for (int i = 1; i <= m; i++) {

        int a, b, c;

        fin >> a >> b >> c;

        utak[i] = make_tuple(c, a, b);

    }

}



void init(int n, vector<P>& fa) {

    for (int i = 1; i <= n; i++) {

        fa[i].first = i;

        fa[i].second = 1;

    }

}



int keres(int k, vector<P>& fa) {

    if (fa[k].first == k)

        return k;

    fa[k].first = keres(fa[k].first, fa);

    return fa[k].first;

}



void kiir(int sum, vector<int> eredmeny, vector<T> utak) {

    ofstream fout("apm.out");

    fout << sum << "\n";

    fout << eredmeny.size() << "\n";

    for (auto& i : eredmeny) {

        fout << get<1>(utak[i]) << " " << get<2>(utak[i]) << "\n";

    }

}



int main() {

    int n, m;

    vector<T> utak;

    vector<P> fa;

    read(n, m, utak, fa);

    sort(utak.begin()+1, utak.end());

    init(n, fa);

    vector<int> eredmeny;

    int sum = 0;

    for (int i = 1; i <= m; i++) {

        int csp1 = keres(get<1>(utak[i]), fa);

        int csp2 = keres(get<2>(utak[i]), fa);

        if (csp1 != csp2) {

            eredmeny.push_back(i);

            sum += get<0>(utak[i]);

            if (fa[csp2].second < fa[csp1].second) {

                fa[csp2].first = csp1;

                fa[csp1].second += fa[csp2].second;

            }

            else {

                fa[csp1].first = csp2;

                fa[csp2].second += fa[csp1].second;

            }

        }

    }

    kiir(sum, eredmeny, utak);

}
