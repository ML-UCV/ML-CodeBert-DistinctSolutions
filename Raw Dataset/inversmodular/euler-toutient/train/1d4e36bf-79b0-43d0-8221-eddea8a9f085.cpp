#include <vector>
#include <algorithm>
#include <string>
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
#include <fstream>






using namespace std;



ifstream cin("inversmodular.in"); ofstream cout("inversmodular.out");



long long phi(int nr) {

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

 if (nr > 1) {

  ans /= nr;

  ans *= (nr - 1LL);

 }

 return ans;

}



long long lgput(long long n, long long p, long long mod) {

 long long ans = 1;

 while (p) {

  if (p % 2) {

   ans *= n;

   ans = ans % mod;

  }

  n *= n;

  n = n % mod;

  p /= 2;

 }

 return (ans % mod);

}



int main() {



 long long a, n, ans;

 cin >> a >> n;

 cout << lgput(a, phi(n) - 1, n);

 return 0;

}
