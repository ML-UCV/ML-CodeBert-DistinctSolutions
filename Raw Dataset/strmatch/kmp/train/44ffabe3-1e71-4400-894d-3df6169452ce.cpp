#include <bits/stdc++.h>
using namespace std;

ifstream fin("strmatch.in");
ofstream fout("strmatch.out");

const int NMAX=2e6;
string A, B;
int ps[2*NMAX+6], k, cnt, q[NMAX+1], vf;

void citire() {
 getline(fin, A);
 A.push_back('#');
 k=A.size();
 getline(fin, B);
 A+=B;
}

void build_ps(string s) {
 int m=(int)s.size();
 ps[0]=0;
 int i=1, cur=0;
 while(i<m) {
  if(s[i]==s[cur]) {
   ++cur;
   ps[i]=cur;
   if(ps[i]==k-1) {
    ++cnt;
    if(cnt<=1000)
     q[++vf]=i-2*k+2;
   }
   ++i;
   continue;
  }
  if(cur==0) {
   ps[i]=0;
   ++i;
   continue;
  }
  cur=ps[cur-1];
 }
}

int main() {
 citire();
 build_ps(A);
 fout<<cnt<<'\n';
 for(int i=1;i<=vf;++i) {
  fout<<q[i]<<' ';
 }
 fout<<'\n';
 return 0;
}
