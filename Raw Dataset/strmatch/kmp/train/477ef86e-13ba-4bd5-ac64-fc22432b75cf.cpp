#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <time.h>
#include <iomanip>
#include <deque>
#include <math.h>
#include <cmath>
#include <assert.h>
#include <stack>
#include <bitset>
#include <random>
#include <chrono>
#include <assert.h>
#include <fstream>






using namespace std;

using ll = long long;





ifstream cin("strmatch.in"); ofstream cout("strmatch.out");







string a, b;

vector <int> ans;







void kmp(string s) {

 int n = s.length();



 vector <int> pi(n);

 for (int i = 1; i < n; i++) {

  int j = pi[i - 1];

  while (j > 0 && s[i] != s[j]) j = pi[j - 1];

  if (s[i] == s[j]) j++;

  pi[i] = j;



  if (j == a.size()) {

   ans.push_back(i - 2 * a.size());

  }

 }



}







int main() {





 cin >> a >> b;



 string s = a + '#' + b;



 kmp(s);



 cout << ans.size() << '\n';

 for (int i = 0; i < min((int)ans.size(), 1000); i++) {

  cout << ans[i] << ' ';

 }



 return 0;

}
