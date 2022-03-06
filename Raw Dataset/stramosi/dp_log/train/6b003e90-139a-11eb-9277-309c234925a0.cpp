#include <iostream>
#include <fstream>


using namespace std;



const int MAXN = 250010;

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");

int n, m, matrix[MAXN][20];



void fillMatrix() {

    for (int i = 1; i <= n; i++)

        for (int j = 1; j <= 18; j++)

            matrix[i][j] = matrix[matrix[i][j - 1]][j - 1];

}



void solve() {

    int nr, x, ancestor, ind;

    fin >> n >> m;

    for (int i =1 ; i <= n; i++) {

        fin >> matrix[i][0];

    }

    fillMatrix();

    for (int i = 1; i <= m; i++) {

        fin >> x >> nr;

        ancestor = x;

        ind = 0;

        while(nr) {

            if (nr % 2) {

                ancestor = matrix[ancestor][ind];

            }

            ind++;

            nr = (nr >> 1);

        }

        fout << ancestor << "\n";

    }

}



int main() {

    solve();

    return 0;

}
