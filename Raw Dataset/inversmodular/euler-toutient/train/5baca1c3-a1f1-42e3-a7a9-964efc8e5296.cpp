#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <time.h>
#include <iomanip>
#include <deque>
#include <math.h>
#include <assert.h>
#include <stack>
#include <bitset>
#include <random>
#include <fstream>






using namespace std;
ifstream cin("inversmodular.in"); ofstream cout("inversmodular.out");



long long lgput(long long a, long long b, long long MOD) {

 long long ret = 1LL;

 while (b) {

  if (b & 1LL) ret = (ret * a) % MOD;

  a = (a * a) % MOD;

  b >>= 1LL;

 }



 return (ret % MOD);

}



long long phi(long long nr) {

 long long ans = nr;

 for (long long i = 2; i * i <= nr; i++) {

  if (nr % i) {

   continue;

  }

  while (nr % i == 0) {

   nr /= i;

  }

  ans /= i;

  ans *= (i - 1LL);

 }

 if (nr > 1){

  ans /= nr;

  ans *= (nr - 1LL);

 }

 return ans;

}





long long inv_mod(long long x, long long MOD) {

 return lgput(x, phi(MOD) - 1, MOD);

}



int main() {



 long long a, b;

 cin >> a >> b;

 cout << inv_mod(a, b);



 return 0;

}
