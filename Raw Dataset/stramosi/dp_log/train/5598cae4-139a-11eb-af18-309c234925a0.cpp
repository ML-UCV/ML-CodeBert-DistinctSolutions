#include <bits/stdc++.h>
using namespace std;

ifstream fin("stramosi.in");
ofstream fout("stramosi.out");
int n, m;


int rmq[18][250010];
int logaritmi[250010];

void init() {
    logaritmi[1] = 0;
    for(int i=2; i <= n; i++) {
        logaritmi[i] = logaritmi[i / 2] + 1;
    }

    for(int lungime = 1; (1 << lungime) <= n; lungime++) {
        for(int el = 1; el <= n; el++) {
            rmq[lungime][el] = rmq[lungime-1][rmq[lungime-1][el]];
        }
    }
}


void solve() {
 fin >> n >> m;
 for(int i=1; i <= n; i++) {
  fin >> rmq[0][i];
 }
 init();

 while(m--) {
  int a, b;
  fin >> a >> b;
  if(b == 0) {
   fout << a << "\n";
  } else {
   while(b > 0) {
    a = rmq[logaritmi[b & (-b)]][a];
    b -= b & (-b);
   }

   fout << a << "\n";
  }
 }
}


int main() {
 ios_base::sync_with_stdio(0);
 fin .tie(0);
 fout.tie(0);

 int testCases = 1;

 while(testCases--) {
  solve();
 }
}
