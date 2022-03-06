#include <fstream>


using namespace std;



ifstream fin ("stramosi.in");

ofstream fout ("stramosi.out");



int n, m, i, j, p, q, sol;

int d[21][250005];



int main(){

    fin >> n >> m;

    for (i=1; i<=n; i++){

        fin >> d[0][i];

    }

    for (i=1; i<=19; i++){

        for (j=1; j<=n; j++){

            d[i][j] = d[i-1][d[i-1][j]];

        }

    }

    for (i=1; i<=m; i++){

        fin >> q >> p;

        for (j=0; (1<<j)<=p; j++){

            if (p&(1<<j)){

                q = d[j][q];

            }

        }

        fout << q << "\n";

    }

    return 0;

}
