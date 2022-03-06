#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



vector<pair<int, pair<int, int> > > muchii;

int n, m, t[200005], cost;

vector<pair<int, int> > apm;



int root(int x) {

    if(!t[x]) return x;

    t[x] = root(t[x]);

    return t[x];

}



int Union(int x, int y) {

    int rx = root(x);

    int ry = root(y);

    if(rx == ry) return 0;



    t[rx] = ry;

    return 1;

}



void citire() {

    fin >> n >> m;

    while(m--) {

        int x, y, c;

        fin >> x >> y >> c;

        muchii.push_back({c, {x, y}});

    }

}



void solve() {

    sort(muchii.begin(), muchii.end());

    for(auto muc: muchii) {

        int x = muc.second.first;

        int y = muc.second.second;

        int c = muc.first;



        if(Union(x, y)) {

            apm.push_back({x, y});

            cost += c;

        }

    }

}



void afis() {

    fout << cost << '\n' << apm.size() << '\n';

    for(auto x: apm) fout << x.first << ' ' << x.second << '\n';

}



int main() {

    citire();

    solve();

    afis();

}
