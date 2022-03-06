#include <iostream>
#include <fstream>


using namespace std;



const int N = 200001;

int n, m, nr, s, nc, q[N], distances[N], c[N];

int vf[2 * N], vf1[2 * N], lst[N], lst1[N], urm[2 * N], urm1[2 * N];

bool viz[N], viz1[N];

int st[N], st1[N];

int varf;



ifstream in("ctc.in");

ofstream out("ctc.out");



void adauga(int x, int y) {

 vf[++nr] = y;

 urm[nr] = lst[x];

 lst[x] = nr;

 vf1[nr] = x;

 urm1[nr] = lst1[y];

 lst1[y] = nr;

}



void dfs(int x) {



 viz[x] = true;

 int y;

 for (int p = lst[x]; p != 0; p = urm[p]) {

  y = vf[p];

  if (!viz[y]) dfs(y);

 }

 st[++varf] = x;

}



void dfs1(int x) {

 viz1[x] = true;

 c[nc]++;

 st1[++nr] = x;

 int y;

 for (int p = lst1[x]; p != 0; p = urm1[p]) {

  y = vf1[p];

  if (!viz1[y]) dfs1(y);

 }

}



struct comp {

 int x, y;

}v[N];





int main() {

 in >> n >> m;

 for (int i = 1; i <= m; i++) {

  in >> v[i].x >> v[i].y;

  adauga(v[i].x, v[i].y);

 }

 for (int i = 1; i <= n; i++)

  if (!viz[i]) dfs(i);

 nr = 0;

 for (int i = n; i >= 1; i--) {

  if (!viz1[st[i]]) {

   nc++;

   dfs1(st[i]);

  }

 }



 int a = 1;

 out << nc << '\n';

 for (int i = 1; i <= nc; i++) {

  for (int j = 1; j <= c[i]; j++)

   out << st1[a++] << ' ';

  out << '\n';

 }

 return 0;

}
