#include <bits/stdc++.h>




using namespace std;



ifstream fin ("strmatch.in");

ofstream fout ("strmatch.out");



string A, B;

int M, N, PI[2000002], sol[1 << 10], cnt, q;



void Make_Prefix () {

  for (int i = 2, q = 0; i <= M; i ++) {

    while (q && A[q + 1] != A[i])

      q = PI[q];

    if (A[q + 1] == A[i])

      q ++;

    PI[i] = q;

  }

}



int main () {

  fin >> A >> B;

  M = A.size(), N = B.size();

  for (int i = M; i > 0; i --)

    A[i] = A[i - 1];

  A[0] = ' ';

  for (int i = N; i > 0; i --)

    B[i] = B[i - 1];

  B[0] = ' ';

  Make_Prefix();

  for (int i = 1; i <= N; i ++) {

    while (q && A[q + 1] != B[i])

      q = PI[q];

    if (A[q + 1] == B[i])

      q ++;

    if (q == M) {

      q = PI[M];

      cnt ++;

      if (cnt <= 1000)

        sol[cnt] = i - M;

    }

  }

  fout << cnt << '\n';

  for (int i = 1; i <= min (cnt, 1000); i ++)

    fout << sol[i] << ' ';

  fin.close();

  fout.close();

  return 0;

}
