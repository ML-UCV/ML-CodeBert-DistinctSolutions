#include <stdio.h>
#include <bits/stdc++.h>



using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

ifstream fin ("evaluare.in");
ofstream fout ("evaluare.out");

string A;

int eval(const string &A, int &p, int lvl);


int termen(const string &A, int &p, int lvl);


int factor(const string &A, int &p, int lvl);

int eval(const string &A, int &p, int lvl) {

  int r = termen(A, p, lvl);
  while(p < A.size() && (A[p] == '-' || A[p] == '+')) {
    if (A[p] == '-') {
      p++;
      r -= termen(A, p, lvl);
    } else {
      p++;
      r += termen(A, p, lvl);
    }
  }

  return r;
}

int termen(const string &A, int &p, int lvl) {

  int r = factor(A, p, lvl);
  while(p < A.size() && (A[p] == '*' || A[p] == '/')) {
    if (A[p] == '*') {
      p++;
      r *= factor(A, p, lvl);
    } else {
      p++;
      r /= factor(A, p, lvl);
    }
  }

  return r;
}

int factor(const string &A, int &p, int lvl) {

  if (p >= A.size()) { return 0; }

  int r = 0;
  if (A[p] == '(') {
    p++;
    r = eval(A, p, lvl+1);
    p++;
  } else {
    while(p < A.size() && A[p] - '0' >= 0 && A[p] - '0' < 10) {
      r = r*10 + A[p] - '0';
      p++;
    }
  }

  return r;
}

int main(void) {
  fin >> A;
  int p = 0;
  int res = eval(A, p, 0);

  fout << res << endl;

  return 0;
}
