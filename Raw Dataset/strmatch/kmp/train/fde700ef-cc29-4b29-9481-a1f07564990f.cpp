#include <stdio.h>
#include <bits/stdc++.h>




using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

ifstream fin ("strmatch.in");
ofstream fout ("strmatch.out");

const int Nmax = 2000666;







int pi[Nmax];
int N, M;
string A,B;

void build_prefix() {
  pi[0] = -1;
  int k = -1;

  for(uint i = 1; i < A.size(); i++) {
    while(k > -1 && A[i] != A[k+1]) { k = pi[k]; }

    if (A[i] == A[k+1]) { k++; }

    pi[i] = k;
  }
}

int main(void) {
  fin >> A >> B;
  N = A.size();
  M = B.size();
  if (N > M) {
    fout << "0\n";
    return 0;
  }

  build_prefix();
  int k = -1;
  int count = 0;
  vi res;
  for(int i = 0; i < M; i++) {
    while(k > -1 && B[i] != A[k+1]) { k = pi[k]; }
    if (B[i] == A[k+1]) { k++; }
    if (k == N-1) {
      count++;
      if (count <= 1000) {
        res.push_back(i-(N-1));
      }
      k = pi[k];
    }
  }

  fout << count << '\n';
  for(auto pos: res) {
    fout << pos << ' ';
  }
  fout << endl;

  return 0;
}
