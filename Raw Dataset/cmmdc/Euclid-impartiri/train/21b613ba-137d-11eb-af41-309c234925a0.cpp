#include <bits/stdc++.h>
using namespace std;



unsigned gcd(unsigned a, unsigned b){

 if (!b) return a;

 return gcd(b, a%b);

}



int main() {

 ifstream cin("cmmdc.in");

 ofstream cout("cmmdc.out");



 unsigned a, b;

 cin >> a >> b;

 if (gcd(a,b)==1)

  cout << 0;

 else

 cout << gcd(a,b);

}
