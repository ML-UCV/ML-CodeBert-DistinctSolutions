#include <fstream>

using namespace std;

ifstream fin ("schi.in");
ofstream fout ("schi.out");

int n, s = 1, p, k;
int v[30005], a[200005], ans[30005];

void Update(int poz, int val) {
  a[poz] += val;
  if (poz > 1)
  Update(poz / 2, val);
}

int Query(int val, int nod, int sum) {
  if (nod >= s)
  return nod - s + 1;
  if (a[nod * 2] + sum >= val)
  return Query(val, nod * 2, sum);
 return Query(val, nod * 2 + 1, sum + a[nod * 2]);
}

int main() {
  fin >> n;
  for (int i = 1; i <= n; ++i)
    fin >> v[i];
  int cn = n;
  while (cn) {
  cn >>= 1;
  s <<= 1;
  }
  if (s >> 1 == n)
  s >>= 1;
 k = n + 1;
  for (int i = 0; i < n; ++i)
    Update(s + i, 1);
  for (int i = n; i; --i) {
    p = Query(v[i], 1, 0);
    Update(s + p - 1, -1);
    ans[p] = --k;
  }
  for (int i = 1; i <= n; ++i)
  fout << ans[i] << '\n';
  return 0;
}
