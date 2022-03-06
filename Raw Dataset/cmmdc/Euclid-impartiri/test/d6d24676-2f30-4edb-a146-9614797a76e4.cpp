#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
ifstream fin("cmmdc.in");
ofstream fout("cmmdc.out");

int main() {
 ios::sync_with_stdio(false);
 cin.tie(0);

    int a, b, r;
    fin >> a >> b;
 while(b!=0) {
  r = a%b;
  a=b;
  b=r;
 }
 if(a==1) {
  fout << 0;
  return 0;
 }
 fout << a;
    return 0;
}
