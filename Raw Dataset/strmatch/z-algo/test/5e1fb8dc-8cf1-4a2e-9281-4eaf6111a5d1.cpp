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







void z(string s) {

 int n = (int)s.length();

 vector<int> z(n);

 for (int i = 1, l = 0, r = 0; i < n; ++i) {

  if (i <= r) z[i] = max(min(z[i - l], r - i + 1), 0);

  while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];

  if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;

 }



 for (int i = 1; i < n; i++) {

  if (z[i] == a.size()) ans.push_back(i - a.size() - 1);

 }

}







int main() {





 cin >> a >> b;



 string s = a + '#' + b;



 z(s);



 cout << ans.size() << '\n';

 for (int i = 0; i < min((int)ans.size(), 1000); i++) {

  cout << ans[i] << ' ';

 }

 return 0;

}
