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
string A, B;







int pi[Nmax];


void build_prefix() {
  for(int i = 0; i < A.size(); i++) {


    int k = pi[i];
    while(k > 0 && A[i] != A[k]) {
      k = pi[k];
    }
    if (i == 0 || A[i] != A[k]) {
      pi[i+1] = 0;
    } else {
      pi[i+1] = k+1;
    }
  }
}

int main(void) {
  fin >> A >> B;
  int N = A.size(), M = B.size();
  if (N > M) {
    fout << "0\n";
    return 0;
  }

  build_prefix();
  int count = 0, k = 0;
  vi res;
  for(int i = 0; i < M; i++) {
    while(k > 0 && B[i] != A[k]) {
      k = pi[k];
    }
    if (B[i] == A[k]) {
      k++;
    }
    if (k == N) {
      count++;
      if (count <= 1000) { res.push_back(i-(N-1));}
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
