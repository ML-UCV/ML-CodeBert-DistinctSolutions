#include <fstream>


using namespace std;



ifstream f ("schi.in");

ofstream g ("schi.out");



int tree[4 * 30001 + 13];

int N, M, A[30001], B[30001], pozi, i;

void Update(int nod, int currL, int currR, int pos, int val) {

     if ( currL == currR ) {

          tree[nod] = val;

          return;

     }



     int mid = currL + (currR - currL) / 2;

     if ( pos <= mid ) Update(2 * nod, currL, mid, pos, val);

     else Update(2 * nod + 1, mid + 1, currR, pos, val);



     tree[nod] = tree[2 * nod] + tree[2 * nod + 1];

}



int Query(int nod, int currL, int currR, int val){

     if (currL == currR) return currL;

     int mid = currL + (currR - currL) / 2;

     if (val <= tree[2 * nod]) return Query(2 * nod, currL, mid, val);

     else {

        val -= tree[2 * nod];

        return Query(2 * nod + 1, mid + 1, currR, val);

     }

}



int main() {

    f >> N;

    for (i = 1; i <= N; ++i) {

        Update(1, 1, N, i, 1);

        f >> A[i];

    }

    for (i = N; i >= 1; --i) {

        pozi = Query(1, 1, N, A[i]);

        Update(1, 1, N, pozi, 0);

        B[pozi] = i;

    }

    for (i = 1; i <= N; ++i)

        g << B[i] << '\n';

}
