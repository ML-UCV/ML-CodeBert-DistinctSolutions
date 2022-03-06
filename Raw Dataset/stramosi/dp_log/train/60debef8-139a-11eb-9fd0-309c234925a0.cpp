#include <fstream>






using namespace std;

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



int A[19][250003];



int main()

{

    int n, m, i, p, q, p2 = 1, k;

    fin >> n >> m;

    for(i = 1; i <= n; i++) fin >> A[0][i];

    for(k = 1; p2 <= n; k++) {

        for(i = 1; i <= n; i++)

            A[k][i] = A[k - 1][A[k-1][i]];

        p2 *= 2;

    }



    for(i = 1; i <= m; i++){

        fin >> q >> p;

        for(k = 18; k >= 0; k--)

            if(p & (1<<k)) q = A[k][q];

        fout << q << "\n";

    }



    return 0;

}
