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





ifstream cin("inversmodular.in"); ofstream cout("inversmodular.out");
void euclid(long long a, long long b, long long& d, long long& x, long long& y) {

 if (b == 0) {

  d = a;

  x = 1; y = 0;

  return;

 }



 long long x0, y0;

 euclid(b, a % b, d, x0, y0);

 x = y0;

 y = x0 - (a / b) * y0;

}







int main() {



 long long a, n, d, x, y;

 cin >> a >> n;



 euclid(a, n, d, x, y);



 x = (x % n + n) % n;

 cout << x;



 return 0;

}
