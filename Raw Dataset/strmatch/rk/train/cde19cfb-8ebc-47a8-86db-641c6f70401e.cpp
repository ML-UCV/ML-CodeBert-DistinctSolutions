#include <stdio.h>
#include <bits/stdc++.h>




using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

int P = 97;

const int mod1 = 100103;
const int mod2 = 100109;

ifstream fin ("strmatch.in");
ofstream fout ("strmatch.out");

string A,B;

int main(void) {
  fin >> A >> B;
  int N = A.size(), M = B.size();

  if(M < N) {
    fout << 0 << endl;
    return 0;
  }

  int p1 = 1;
  int p2 = 1;

  int h1 = 0;
  int h2 = 0;
  for(auto a: A) {
    h1 = (h1*P + a) % mod1;
    h2 = (h2*P + a) % mod2;

    p1 = (p1*P) % mod1;
    p2 = (p2*P) % mod2;
  }


  int hb1 = 0;
  int hb2 = 0;
  for(int i = 0; i < N; i++) {
    hb1 = (hb1*P + B[i]) % mod1;
    hb2 = (hb2*P + B[i]) % mod2;
  }

  vi res;
  int result = 0;
  if (hb1 == h1 && hb2 == h2) { res.push_back(0); result++; }

  for(int i = N; i < M; i++) {
    hb1 = ((hb1*P + B[i]) % mod1 - (B[i-N]*p1) % mod1 + mod1) % mod1;
    hb2 = ((hb2*P + B[i]) % mod2 - (B[i-N]*p2) % mod2 + mod2) % mod2;
    if (hb1 == h1 && hb2 == h2) {
      result++;
      if (res.size() < 1000) { res.push_back(i - (N-1)); }
    }
  }

  fout << result << '\n';
  for(auto pos: res) {
    fout << pos << ' ';
  }
  fout << '\n';

  return 0;
}
