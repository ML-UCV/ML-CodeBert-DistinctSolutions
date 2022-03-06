#include <bits/stdc++.h>

using namespace std;

int lgput(int a, int b, int mod) {
 int ret = 1;
 while(b) {
  if(b&1) ret = 1ll*ret*a%mod;
  a = 1ll*a*a%mod;
  b>>=1;
 }

 return ret;
}
int main() {



  freopen("inversmodular.in", "r", stdin);
  freopen("inversmodular.out", "w", stdout);


 ios::sync_with_stdio(false);
 cin.tie(0);
 cout.tie(0);

 int a, n;
 cin >> a >> n;

 int phi = n;
 int cop = n;
 if(cop % 2 == 0){
  phi /= 2;
  while(cop % 2 == 0) cop >>= 1;
 }

 int d = 3;
 while(d*d <= cop) {
  if(cop % d == 0) {
   phi /= d;
   phi *= d-1;
  }
  while(cop % d == 0) {
   cop /= d;
  }
  d += 2;
 }

 if(cop != 1) {
  phi /= cop;
  phi *= cop-1;
 }

 cout << lgput(a, phi - 1, n) << '\n';
 return 0;
}
