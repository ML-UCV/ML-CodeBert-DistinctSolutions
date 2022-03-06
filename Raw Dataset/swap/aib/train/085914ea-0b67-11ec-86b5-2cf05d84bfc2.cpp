#include <bits/stdc++.h>

using namespace std;

ifstream fin("swap.in");
ofstream fout("swap.out");

const int NMAX = 50005;

int n;

char s1[NMAX]; char s2[NMAX];
int cnt1[127]; int cnt2[127];

int perm[NMAX];
int aib[NMAX];

vector<int> a[127];
long long swaps = 0;

int bit(int x) { return x & -x; }

void ins(int pos) {

 for( ; pos <= n; pos += bit(pos))
  aib[pos]++;
}

int query(int pos) {

 int sum = 0;
 for( ; pos > 0 ; pos -= bit(pos))
  sum += aib[pos];
 return sum;
}

int main() {

 fin >> s1 + 1 >> s2 + 1;
 n = strlen(s1 + 1);

 for(int i = n ; i >= 1; --i)
  a[s2[i]].push_back(i), cnt2[s2[i]]++;

 for(int i = 1; i <= n ; ++i)
  cnt1[s1[i]]++;

 for(int i = 'a' ; i <= 'z'; ++i) {

  if(cnt1[i] != cnt2[i]) {
   fout << -1 << '\n';
   exit(0);
  }
 }

 for(int i = 1; i <= n ; ++i) {

  perm[i] = a[s1[i]][ a[s1[i]].size() - 1 ];
  a[s1[i]].pop_back();
 }

 for(int i = 1; i <= n ; ++i) {
  swaps += i - 1 - query(perm[i] - 1) ;
  ins(perm[i]);
 }

 fout << swaps << '\n';

 return 0;
}
