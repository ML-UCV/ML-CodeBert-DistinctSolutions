#include <cstdio>
#include <vector>
#include <cstring>
#include <string>





using namespace std;

char a[50005], b[50005];
int n, m, FF[40], FS[40], i, LG [40], P[50005], j;
int aib [50005], sol;
vector <int> V[40];
inline int C (char a) {return int(a) - 97;}
inline bool check ()
{
 for (i = C ('a'); i <= C ('z'); i++)
  if (FF[i] != FS[i]) return 1;
 return 0;

}
inline void update (int x) {
 for ( ; x <= n; x += x & -x) ++aib[x];
}
inline int query (int x) {
 int S = 0;
 for ( ; x >= 1; x -= x & -x) S += aib [x];
 return S;
}
int main ()
{
 freopen ("swap.in", "r", stdin);
 freopen ("swap.out", "w", stdout);
 scanf ("%s%s\n", a, b);
 n = strlen (a); m = strlen (b);
 if (n != m) printf ("-1\n");
 for (i = 0; i < n; i++) {
  ++FF[C (a[i])];
  ++FS[C (b[i])];
  V[C (b[i])].push_back (i + 1);
 }
 if (check ()) {
  printf ("-1\n");
  return 0;
 }
 for (i = 0; i < n; i++) {
  P[i + 1] = V[C (a[i])][LG[C (a[i])]];
  LG[C (a[i])]++;
 }
 for (i = 1; i <= n; i++) {
  sol += i - 1 - query (P[i]);
  update (P[i]);
 }
 printf ("%d\n", sol);


}
