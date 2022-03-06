#include <fstream>
#include <cstring>
#include <queue>




using namespace std;



ifstream fin ("swap.in");

ofstream fout ("swap.out");



deque < int > H[30];



int v[50001], n, s, A[50001];



char s1[50001], s2[50001];



void update (int p, int x) {

    for (; p <= n; p += (p & -p))

        A[p] += x;

}



int querry (int p) {

    int r = 0;

    for (; p >= 1; p -= (p & -p))

        r += A[p];

    return r;

}



int main () {

    fin >> s1 + 1 >> s2 + 1;

    for (int i = 1; s1[i] != 0; ++i, ++n) {

        H[s1[i] - 'a' + 1].push_back (i);

    }

    for (int i = 1; i <= n; ++i) {

        if (H[s2[i] - 'a' + 1].empty ()) {

            fout << "-1";

            return 0;

        }

        int nod = H[s2[i] - 'a' + 1].front ();

        H[s2[i] - 'a' + 1].pop_front ();

        s += nod - querry (nod) - 1;

        update (nod, 1);

    }

    fout << s;

    return 0;

}
