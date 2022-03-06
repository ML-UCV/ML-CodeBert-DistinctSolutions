#include <bits/stdc++.h>
using namespace std;

ifstream fin ("stramosi.in");

ofstream fout ("stramosi.out");



int n, m, dad, dp [2500003][19], P, Q;

int main (){

    fin >> n >> m;

    for (int i = 1; i <= n; i ++){

        fin >> dad;

        dp [i][0] = dad;

    }

    for (int i = 1; i <= n; i ++)

        for (int k = 1; k <= 18; k ++)

            dp [i][k] = dp [dp [i][k - 1]][k - 1];

    for (int i = 1; i <= m; i ++){

        fin >> Q >> P;

        for (int k = 18; k >= 0; k --)

            if (P & (1 << k))Q = dp [Q][k];

        fout << Q << '\n';

    }

    return 0;

}
