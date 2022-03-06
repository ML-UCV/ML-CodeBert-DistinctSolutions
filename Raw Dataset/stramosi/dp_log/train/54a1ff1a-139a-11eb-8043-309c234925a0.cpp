#include "bits/stdc++.h"


using namespace std;

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



const int NMAX = 25e4 + 3, NMAXLOG2 = log2(NMAX) + 1;

int n, m, daddy[NMAX], log2from[NMAX], pow2[NMAXLOG2], dp[NMAX][NMAXLOG2 + 2];



void read() {

    fin >> n >> m;

    for (int i = 1; i <= n; i++)

        fin >> daddy[i];

}



void precompute() {

    log2from[1] = 0;

    for (int i = 2; i < NMAX; i++)

        log2from[i] = log2from[i >> 1] + 1;

    pow2[0] = 1;

    for (int i = 1; i <= NMAXLOG2; i++)

        pow2[i] = pow2[i - 1] << 1;

}



void computeDP() {

    for (int i = 1; i <= n; i++)

        dp[i][0] = daddy[i];

    for (int i = 1; i <= n; i++)

        for (int j = 1; j <= NMAXLOG2; j++)

            dp[i][j] = dp[dp[i][j - 1]][j - 1];

}



void query() {

    while (m--) {

        int node, nrancestor;

        fin >> node >> nrancestor;

        while (nrancestor > 0) {

            int p = log2from[nrancestor];

            node = dp[node][p];

            nrancestor -= pow2[p];

        }

        fout << node << '\n';

    }

}



int main() {

    precompute();

    read();

    computeDP();

    query();

    fout.close();

    return 0;

}
