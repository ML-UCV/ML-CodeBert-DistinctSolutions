#include <fstream>
#include <deque>
#include <cstring>


using namespace std;

const char iname[] = "swap.in";

const char oname[] = "swap.out";

ifstream fin(iname);

ofstream fout(oname);

deque <int> Q[300];

int i, lg, lg2, n, ANS, sol;

int j_s1[300], j_s2[300], P[50004];

int H[50004 * 3];

char s1[50004], s2[50004];

inline void update (int n, int l, int r, int p, int v){

 if (l == r){H[n] = v; return;}

 int m = (l + r) / 2, L = n << 1, R = L | 1;

 if (p <= m) update (L, l, m, p, v);

 else

  update (R, m + 1, r, p, v);

 H[n] = H[L] + H[R];

}

inline int query (int n, int l, int r, int i, int j){

 if (i <= l && r <= j) return H[n];

 int m = (l + r) / 2; int sol = 0;

 if (i <= m) sol += query(2 * n, l, m, i, j);

 if (j > m) sol += query(2 * n + 1, m + 1, r, i, j);

 return sol;

}

int main()

{

 fin >> s1; lg = strlen(s1);

 for (i = 0; i < lg; ++i)

  ++j_s1[(int)s1[i]],

  Q[(int)s1[i]].push_back(i + 1);

 fin >> s2; lg2 = strlen(s2);

 if (lg != lg2){fout << -1 << '\n'; return 0;}

 for (i = 0; i < lg; ++i)

 {

  ++j_s2[(int)s2[i]];

  P[++n] = Q[s2[i]][0];

  Q[s2[i]].pop_front();

 }

 for (i = 0; i < lg; ++i)

 {

  if (j_s1[(int)s1[i]] != j_s2[(int)s1[i]]){

   fout << -1 << '\n'; return 0;

  }

 }

 update (1, 1, n, P[1], 1);

 for (i = 2; i <= n; ++i)

 {

  update (1, 1, n, P[i], 1);

  ANS += query (1, 1, n, P[i] + 1, n);

 }

 fout << ANS << '\n';

 return 0;

}
