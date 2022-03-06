#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string A, B;
vector<int> prefix, ans;

void makePrefix()
{
  int p = 0;
  for (int i = 2; i < A.size(); ++i) {
    while (p && A[p + 1] != A[i])
      p = prefix[p];
    p += (A[p + 1] == A[i]);
    prefix[i] = p;
  }
}

int countMatches()
{
  int p = 0;
  int total = 0;
  for (int i = 1; i < B.size(); ++i) {
    while (p && A[p + 1] != B[i])
      p = prefix[p];
    p += (A[p + 1] == B[i]);
    if (p == (int)A.size() - 1) {
      ++total;
      if (ans.size() < 1000) {
 ans.emplace_back(i - (int)A.size() + 1);
 p = prefix[p];
      }
    }
  }
  return total;
}

int main()
{
  ifstream fileIn("strmatch.in");
  ofstream fileOut("strmatch.out");

  fileIn.sync_with_stdio(false);
  fileIn.tie(0);

  fileIn >> A;
  fileIn >> B;
  A = "#" + A;
  B = "#" + B;

  prefix.resize(A.size());

  makePrefix();
  fileOut << countMatches() << "\n";
  for (auto it : ans)
    fileOut << it << " ";

  return 0;
}
