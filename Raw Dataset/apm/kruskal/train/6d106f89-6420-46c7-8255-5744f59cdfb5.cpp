#include <bits/stdc++.h>
using namespace std;



vector <int> t;

int _find (int x) {

    if (t[x]==x)

        return x;

    return t[x]=_find(t[x]);

}



void _union (int x, int y) {

    int p1=t[x],

        p2=t[y];

    t[p2]=p1;

}



int main () {

    ifstream fin ("apm.in");

    ofstream fout ("apm.out");

    ios::sync_with_stdio(false);



    int n, m, i, j, c, k;

    fin >> n >> m;

    vector <tuple <int, int, int>> muchii;

    for (k=0; k<m; k++) {

        fin >> i >> j >> c;

        muchii.push_back(make_tuple(i, j, c));

    }

    fin.close();



    sort (muchii.begin(), muchii.end(), [] (const tuple <int, int, int> &a, const tuple <int, int, int> &b) -> bool {

                                            return (get<2>(a))<(get<2>(b));

                                        });

    t.assign(n+1, 0);

    iota(t.begin(), t.end(), 0);



    fout << "                \n"

         << n-1 << '\n';

    int s=0, ct=0;

    auto it=muchii.begin();

    while (it!=muchii.end() && ct<n) {

        if (_find(get<0>(*it)) != _find(get<1>(*it))) {

            _union(get<0>(*it), get<1>(*it));

            s+=get<2>(*it);

            ct++;

            fout << get<0>(*it) << ' ' << get<1>(*it) << '\n';

        }

        ++it;

    }



    fout.seekp(0);

    fout << s;

    fout.close();

    return 0;

}
