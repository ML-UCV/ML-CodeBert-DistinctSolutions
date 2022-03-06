#include<fstream>
#include<vector>
#include<cmath>
using namespace std;

ifstream in("stramosi.in");

ofstream out("stramosi.out");



const int NMax = 250000;

vector <int> G[NMax+5];



int N, T, A[20][NMax+5], lg[NMax+5];



void Read() {

    in >> N >> T;

    for (int i = 1; i <= N; i++) {

        in >> A[0][i];

    }



    for (int i = 1; (1<<i) <= N; i++)

            for (int j = 1; j <= N; j++)

        A[i][j] = A[i-1][A[i-1][j]];



}



int Ancestor(int Q, int P) {

    while (P > 0) {

        int K = lg[P];

        P -= 1<<K;

        Q=A[K][Q];

    }



    return Q;

}



void Solve() {

    for (int i = 2; i <= N; i++)

        lg[i] = lg[i/2] + 1;

    while(T--) {

        int P, Q;

        in >> Q >> P;

        out << Ancestor(Q, P) << '\n';

    }

}



int main() {

    Read();

    Solve();

}
