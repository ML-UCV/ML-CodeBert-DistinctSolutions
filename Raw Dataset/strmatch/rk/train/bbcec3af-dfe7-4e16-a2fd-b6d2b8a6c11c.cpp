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







unsigned long long H[2000005];

vector <int> ans;







void rabin_karp(string const& a, string const& b) {

 const unsigned long long base = 167;



 unsigned long long hsrch = 0;

 for (auto& x : a) {

  hsrch *= base;

  hsrch += x;

 }



 unsigned long long pow = 1;

 for (int i = 1; i <= a.size(); i++) pow *= base;



 for (int i = 1; i <= b.size(); i++) {

  H[i] = H[i - 1] * base;

  H[i] += b[i - 1];



  if (i < a.size()) continue;



  unsigned long long hash = H[i] - H[i - a.size()] * pow;



  if (hash == hsrch) ans.push_back(i - a.size());

 }



}







int main() {



 string a, b; cin >> a >> b;



 rabin_karp(a, b);



 cout << ans.size() << '\n';

 for (int i = 0; i < min((int)ans.size(), 1000); i++) {

  cout << ans[i] << ' ';

 }





 return 0;

}
