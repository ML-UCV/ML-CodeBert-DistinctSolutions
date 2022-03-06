#include <fstream>


using namespace std;



ifstream f ("schi.in");

ofstream g ("schi.out");



int AIB[30001];

int N, A[30001], B[30001], i, step, pos;



void Update(int poz, int val) {

    while (poz <= N) {

        AIB[poz] += val;

        poz = poz + (poz & (-poz));

    }

}



int Querry(int x, int step) {

    int sol = 0;

    while (step) {

        if (step + sol <= N && AIB[step + sol] < x) {

            x -= AIB[step + sol];

            sol += step;

        }

        step >>= 1;

    }

    return sol + 1;

}

int main() {

    f >> N;

    for (i = 1; i <= N; ++i) {

        Update(i, 1);

        f >> A[i];

    }

    step = 1;

    while (step <= N) step <<= 1;

    step >>= 1;

    for (i = N; i >= 1; --i) {

        pos = Querry(A[i], step);

        Update(pos, -1);

        B[pos] = i;

    }

    for (i = 1; i <= N; ++i)

        g << B[i] << '\n';

}
