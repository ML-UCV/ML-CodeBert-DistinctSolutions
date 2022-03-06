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
    r = a%b;
 while(r!=0) {
  a=b;
  b=r;
  r=a%b;
 }
 if(b==1) {
  fout << 0;
  return 0;
 }
    while(a!=b) {
  if(a>b)
   a-=b;
  else
   b-=a;
 }
 fout << a;
    return 0;
}
