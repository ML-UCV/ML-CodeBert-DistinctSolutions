#include <stdio.h>#include <cstring>
#include <vector>


using namespace std;







int n, m, i, j, k, sol, p2;

int cor[50010];

int arb[3 * 50010];



char a[50010], b[50010];

vector <int> s1[30], s2[30];



void cit() {

 freopen("swap.in", "r", stdin);

 freopen("swap.out", "w", stdout);



 scanf("%s", a);

 scanf("%s", b);

}



inline int query(int nod, int st, int dr, int ask) {

 if (st == dr) return arb[nod];



 int r = (st + dr) / 2;



 if (ask <= r) return arb[nod] + query(nod * 2, st, r, ask);

 else return arb[nod] + query(nod * 2 + 1, r + 1, dr, ask);

}



void update(int nod, int st, int dr, int left, int right) {

 if (left > dr || right < st) return;



 if (left <= st && dr <= right) {

  arb[nod]++;

  return;

 }



 int r = (st + dr) / 2;

 update(nod * 2, st, r, left, right);

 update(nod * 2 + 1, r + 1, dr, left, right);

}



int cost(int poz) {

 int pozitie = cor[poz] + query(1, 1, p2, cor[poz]);



 update(1, 1, p2, 1, cor[poz] - 1);



 return pozitie - i;

}



void solve() {



 n = strlen(a);

 m = strlen(b);

 for (i = 0; i < n; i++)

  s1[a[i] - 'a'].push_back(i);

 for (j = 0; j < m; j++)

  s2[b[j] - 'a'].push_back(j);





 for (i = 0; i < 30; i++)

  if (s1[i].size() != s2[i].size()) {

   printf("-1\n");

   return;

  }





 for (i = 0; i < 30; i++) {

  k = s2[i].size();

  for (j = 0; j < k; j++)

   cor[s2[i][j]] = s1[i][j];

 }





 p2 = 1;

 while (p2 < n) p2 *= 2;

 for (i = 0; i < n; i++)

  sol += cost(i);

 printf("%d\n", sol);

}



int main() {



 cit();

 solve();



 return 0;

}
