#include <bits/stdc++.h>

using namespace std;
ifstream fin("swap.in");
ofstream fout("swap.out");

string s1,s2;
queue <int > Q[27];
int N;
int aib [110000];

int prev(int x){
 return x-(x&(-x));
}

int next(int x){
 return x+(x&(-x));
}
int zer(int x){
 return x&(-x);
}

void update(int k,int newv){
 for (;k<=100000;k=next(k)) aib[k]+=newv;
}

int query(int k){
 int rs=0;
 for (;k;k=prev(k)) rs+=aib[k];
 return rs;
}

int main(){
 fin >>s1>>s2;
 N=s1.length();
 for (int i=0;i<s1.length();i++){
  Q[s1[i]-'a'].push(i+1);
 }
 long long rs=0;
 for (int i=0;i<s2.length();i++){
  if (Q[s2[i]-'a'].size()==0) return fout <<-1,0;
  int pos=Q[s2[i]-'a'].front();
  Q[s2[i]-'a'].pop();
  rs+=pos-i-1+((query(N)-query(pos)));
  update(pos,1);
 }
 fout <<rs;
 return 0;
}
