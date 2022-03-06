#include <fstream>
#include <vector>


using namespace std;



ifstream cin("strmatch.in");

ofstream cout("strmatch.out");



vector<int> kmp(string s) {

  int n = (int) s.size(), j = 0;

  vector<int> sol(n);

  for (int i = 1; i < n; i++) {

    while (j && s[i] != s[j]) {

      j = sol[j - 1];

    }

    if (s[i] != s[j]) {

      sol[i] = 0;

    } else {

      sol[i] = ++j;

    }

  }

  return sol;

}



int main() {

  string s, t;

  cin >> s >> t;

  vector<int> a = kmp(s + "." + t), b;

  int n = (int) s.size();

  for (int i = n + 1; i < (int) a.size(); i++) {

    if (a[i] == n) {

      b.push_back(i - 2 * n);

    }

  }

  cout << (int) b.size() << "\n";

  if ((int) b.size() > 1000) {

    b.resize(1000);

  }

  for (auto &i : b) {

    cout << i << " ";

  }

  cout << "\n";

}
