#include <bits/stdc++.h>


using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");



string pat, txt;



const int d = 73, mod1 = 100007, mod2 = 100021;



vector<int> sol;



void rabin_karp(string pat, string txt, int m1, int m2) {

 int p1 = 0, t1 = 0, p2 = 0, t2 = 0, h1 = 1, h2 = 1;

 int m = pat.size();

 int n = txt.size();

 for(int i = 0; i < m; ++i) {

  p1 = (d * p1 + pat[i]) % m1;

  p2 = (d * p2 + pat[i]) % m2;



  if(i != 0) {

   h1 = (h1 * d) % m1;

   h2 = (h2 * d) % m2;

  }

 }

 for(int i = 0; i < m; ++i) {

  t1 = (d * t1 + txt[i]) % m1;

  t2 = (d * t2 + txt[i]) % m2;

 }

 if(p1 == t1 && p2 == t2) {

  sol.push_back(0);

 }

 for(int i = m; i < n; ++i) {

  t1 = ((t1 - (txt[i - m] * h1) % m1 + m1) * d + txt[i]) % m1;

  t2 = ((t2 - (txt[i - m] * h2) % m2 + m2) * d + txt[i]) % m2;

  if(p1 == t1 && p2 == t2) {

   sol.push_back(i - m + 1);

  }

 }

}



void read() {

 getline(f, pat);



 getline(f, txt);

}



void solve() {

 read();

 rabin_karp(pat, txt, mod1, mod2);

 int nr = sol.size();

 g << nr << '\n';

 for(int i = 0; i < min(nr, 1000); ++i) {

  g << sol[i] << ' ';

 }

}



int main(void) {

 solve();

}
