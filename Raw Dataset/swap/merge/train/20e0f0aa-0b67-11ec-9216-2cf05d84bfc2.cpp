#include <cstdio>
#include <vector>


using namespace std;



int n, i, j, poz, sol, q;

vector <int> t[30];

int ind[30];

char s[50100];

int v[50100], x[50100], st[130100];

int t1[30], t2[30];



void st_update(int nod, int l, int r, int a, int b, int u) {

 int m = (l + r) / 2;

 if (a <= l && r <= b) {

  st[nod] += u;

  return;

 }

 if (a <= m)

  st_update(2 * nod, l, m, a, b, u);

 if (b > m)

  st_update(2 * nod + 1, m + 1, r, a, b, u);

}



void st_query(int nod, int l, int r, int poz) {

 int m = (l + r) / 2;

 q += st[nod];

 if (m == poz && l == r)

  return;

 if (poz <= m)

  st_query(2 * nod, l, m, poz);

 else

  st_query(2 * nod + 1, m + 1, r, poz);



}



int main() {

 freopen("swap.in", "r", stdin);

 freopen("swap.out", "w", stdout);



 fgets(s, 50100, stdin);

 for (i = 0; s[i] != 0; i++) {

  n++;

  v[n] = s[i] - 'a' + 1;

  t1[v[n]]++;

  t[v[n]].push_back(n);

 }



 fgets(s, 50100, stdin);

 for (i = 0; s[i] != 0; i++) {

  x[i + 1] = s[i] - 'a' + 1;

  t1[x[i + 1]]--;

 }



 for (i = 1; i <= 30; i++)

  if (t1[i] != 0) {

   printf("-1\n");

   return 0;

  }





 for (i = 1; i < n; i++) {



  q = 0;

  st_query(1, 1, n, t[x[i]][ind[x[i]]]);

  poz = t[x[i]][ind[x[i]]] + q;

  sol += (poz - i);

  st_update(1, 1, n, 1, poz - q, 1);

  ind[x[i]]++;

  if (ind[x[i]] > t[x[i]].size()) {

   printf("-1\n");

   return 0;

  }

 }



 printf("%d\n", sol);



 return 0;

}
