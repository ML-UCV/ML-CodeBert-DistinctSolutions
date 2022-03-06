#include <fstream>
using namespace std;



ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



int stramosi[20][390625 + 10];



int main() {

    int n, m;

    fin >> n >> m;



    for (int i = 1; i <= n; ++i) {

        fin >> stramosi[0][i];



    }



    for (int i = 1; (1 << i) <= n; ++i) {

        for(int j = 1; j <= n; ++j) {

            stramosi[i][j] = stramosi[i - 1][stramosi[i - 1][j]];

        }

    }



    while (m) {

        int q, p;

        fin >> q >> p;

        int poz = 17;

        while (poz >= 0 && p != 0) {

            if (p >= (1 << poz)) {

                q = stramosi[poz][q];

                p -= (1 << poz);

            }

            poz--;

        }

        fout << q << '\n';

        m--;

    }

    return 0;

}
